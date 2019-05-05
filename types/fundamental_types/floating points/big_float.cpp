
#include <algorithm>
#include <vector>
#include <iostream>
#include <tr1/memory>
#include <iomanip>

const int base = 10000;

class Mantissa {
    public:
        Mantissa() : data(new std::vector<int>) {}
        Mantissa(const Mantissa& other) : data(other.data) {}
        // no need for a destructor since the smart pointer takes
        // care of deleting data when necessary

        // get the i'th element of the mantissa or 0 for digits we don't have
        int operator[](int i) const {
            return (i < data->size()) ? data->at(i) : 0;
        }

        // move from the end of the vector toward beginning and only keep
        // non-zero head
        void trim_zeros() {
            int i = data->size() - 1;
            for (; i >= 0; --i) {
                if (data->at(i) != 0) break;
            }
            data->resize(i+1);
        }
        int size() const { return data->size(); }
        void append(int i) { data->push_back(i); }

    private:
        // reference counting pointer wrapper mantissa vectors
        std::tr1::shared_ptr< std::vector<int> > data;
};

class BigFloat {
    public:
        // default constructor, initialize to 0
        BigFloat () : _sign(1), _exp(0) { }

        // initialize with preallocated mantissa
        BigFloat (char s, int e, const Mantissa& m) :_sign(s), _exp(e), _mantissa(m) {}

        // copy constructor
        BigFloat (const BigFloat& other) : _sign(other._sign), _exp(other._exp), _mantissa(other._mantissa) {}

        // create a BigFloat with value equivalent to given int
        BigFloat (int i) {
            _sign = (i < 0) ? -1 : 1;
            _exp = 0;
            i *= _sign;
            while (i != 0) {
                _mantissa.append(i % base);
                i /= base;
            }
        }

        friend std::ostream& operator<< (std::ostream &out, const BigFloat& bf);

        BigFloat abs() const {
            return BigFloat(1, _exp, _mantissa);
        }

        bool operator< (const BigFloat& other) const {
            // a negative is always less than a positive
            if (_sign < other._sign) { return true; }
            else if (_sign > other._sign) { return false; }


            aligned_mantissas a = align_with(other);

            int len1 = a.m1.size();
            int len2 = a.m2.size();

            // less-than if negative with longer mantissa
            // or positive with shorter mantissa
            if (len1 > len2) { return (_sign == -1); }
            else if (len2 > len1) { return (_sign == 1); }
            // same length mantissas, check element-by-element
            else {
                for (int i = len1-1; i >= 0; --i) {
                    int x = a.m1[i];
                    int y = a.m2[i];
                    if (x < y) { return true; }
                    else if (x > y) { return false; }
                }
                // if we pass the loop then two mantissas were equal
                return false;
            }
        }

        // two numbers are equal if x is not less than y and
        // y is not less than x
        bool operator==(const BigFloat& other) const {
            if (*this < other) { return false; }
            else { return !(other < *this); }
        }

        // 'x > y' is the same as 'y < x'
        bool operator>(const BigFloat& other) const {
            return other < *this;
        }

        // 'x <= y' is the same as 'not y < x'
        bool operator<=(const BigFloat& other) const {
            return !(other < *this);
        }
        // 'x >= y' is the same as 'not x < y'
        bool operator>=(const BigFloat& other) const {
            return !(*this < other);
        }

        // unary minus
        BigFloat operator-() const {
            return BigFloat(_sign * -1, _exp, _mantissa);
        }

        // todo: handle signs, don't shift your actual mantissa but make a copy
        BigFloat operator+ (const BigFloat& other) const {
            aligned_mantissas a = this->align_with(other);

            if (_sign * other._sign == 1) {
                // if we have the same sign, then add the mantissas as if
                // we're both positive and then tag the result with
                // whatever my sign is
                return BigFloat(_sign, a.exp, add_mantissas(a.m1, a.m2, 1));
            } else {
                // we know one of the two is negative, now figure out how to
                // compute the subtraction using add_mantissas, which always expects
                // its first argument to be positive
                bool abs_less = this->abs() < other.abs();
                // if |x| < |y| then (-|x| + |y|) == |y - x|
                if (abs_less && _sign == -1) return BigFloat(1, a.exp, add_mantissas(a.m2, a.m1, -1));
                // if |x| >= |y| then (|x| - |y|) == |x - y|
                else if (!abs_less && _sign == 1) return BigFloat(1, a.exp, add_mantissas(a.m1, a.m2, -1));
                // if |x| >= |y| then (-|x| + |y|) = -(|x| - |y|)
                else if (!abs_less && _sign == -1) return BigFloat(-1, a.exp, add_mantissas(a.m1, a.m2, -1));
                // if |x| < |y| then (|x| - |y|) = -(|y| - |x|)
                else return BigFloat(-1, a.exp, add_mantissas(a.m2, a.m1, -1));

            }
        }

        BigFloat operator-(const BigFloat& other) const {
            return (*this) + (-other);
        }

        // multiply by a small int
        BigFloat scale(int n) const {
            if (n == 0) {
                // fresh BigFloats have a value of 0
                return BigFloat();
            } else if (n == 1) {
                // multiplying by 1 leaves us unchanged
                return *this;
            } else if (n < 0) {
                // rather than worry about negative digits, just
                // always multiply by a positive n and flip the result
                // sign
                return -(this->scale(-n));
            }
            // multiplying by an int is similar to addition in that
            // you loop over all the digits, compute the result digit
            // (mod 10,000) and carry over whatever exceeds the base
            Mantissa result;
            int carry = 0;

            for (int i = 0; i < _mantissa.size(); ++i) {
                int x = _mantissa[i] * n + carry ;
                result.append(x % base);
                carry = x / base;
            }
            if (carry != 0) result.append(carry);
            return BigFloat(_sign, _exp, result);
        }

        // the naive O(n^2) multiplication routine
        BigFloat operator* (const BigFloat& other) const {
            BigFloat result;
            for (int i = 0; i < _mantissa.size(); ++i) {
                for (int j = 0; j < other._mantissa.size(); ++j) {
                    BigFloat temp = this->scale(other._mantissa[j]);
                    // every element of the second mantissa
                    // represents a move of 4 decimal digits
                    temp._exp += j*4;
                    result = result + temp;
                }
            }
            return result;
        }

        std::ostream& to_stream(std::ostream& out) const {
            if (_sign == -1) out << "-";
            int n = _mantissa.size();
            for (int i = n - 1; i >= 0; --i) {
                int x = _mantissa[i];
                // all positions except for the last one
                // need extra zeros when their digits are too small
                // to fill the field
                if (i < n -1) {
                    if (x < 10) out << "000" << x;
                    else if (x < 100) out << "00" << x;
                    else if (x < 1000) out << "0" << x;
                    else out << x;
                } else {
                    out << x;
                }
            }
            if (_exp != 0) out << " * 10^"  << _exp;
            return out;
        }

    private:
        char _sign;
        int _exp;
        Mantissa _mantissa;


        struct aligned_mantissas {
            int exp;
            Mantissa m1;
            Mantissa m2;
        };

        aligned_mantissas align_with(const BigFloat& other) const {
            int new_exp = 0;
            Mantissa m1 = _mantissa;
            Mantissa m2 = other._mantissa;
            // align two floats so their exponents are the same
            // by shifting the number with the larger exponent
            if (_exp < other._exp) {
                new_exp = _exp;
                m2 = shift_k_times(m2, other._exp - _exp);
            } else {
                new_exp = other._exp;
                m1 = shift_k_times(m1, _exp - other._exp);
            }
            aligned_mantissas result = {new_exp, m1, m2};
            return result;
        }

        // to multiply the mantissa by 10 we have to shift every digit over
        // by one position
        Mantissa shift(Mantissa old_mantissa) const {
            Mantissa new_mantissa;
            int carry = 0;
            int digit = 0;
            for (int i = 0; i < old_mantissa.size(); ++i) {
                digit = 10 * old_mantissa[i] + carry;
                new_mantissa.append(digit % base);
                carry = digit / base;
            }
            if (carry != 0) new_mantissa.append(carry);
            return new_mantissa;
        }

        // multiply a mantissa by 10^k by repeatedly calling shift
        Mantissa shift_k_times(const Mantissa& m, int k) const {
            if (k == 0) return m;
            else {
                Mantissa old_mantissa = m;
                Mantissa new_mantissa = shift(old_mantissa);
                for (int i = 1; i < k; ++i) {
                    old_mantissa = new_mantissa;
                    new_mantissa = shift(old_mantissa);
                }
                return new_mantissa;
            }
        }

        // assumes the sign of the first mantissa is always positive
        // and if the sign of the second is negative then its mantissa
        // should be shorter
        Mantissa add_mantissas(const Mantissa& m1, const Mantissa& m2, char sign2) const {
            Mantissa result;
            int carry = 0;
            int x, y, z;
            for (int i = 0; i < std::max(m1.size(), m2.size()); ++i) {
                x = m1[i];
                y = m2[i] * sign2;
                z = x + y + carry;
                if (z >= 0) {
                    result.append(z % base);
                    carry = z / base;
                } else {
                    // negative sums require us to borrow from the next digit
                    result.append(base + z);
                    carry = -1;
                }
            }
            // don't have to worry about negative carries at the end
            // since we're assuming that the positive m1 is longer than
            // a potentially negative m2
            if (carry > 0) {
                result.append(carry);
            }
            result.trim_zeros();
            return result;
        }

};

std::ostream& operator<< (std::ostream &out, const BigFloat& f) {
    return f.to_stream(out);
}

BigFloat fact(BigFloat n) {
    std::cout << n << std::endl;
    if (n <= 1) return 1;
    else {
        BigFloat res = n * fact(n - 1);
        std::cout <<  n << "==> " << res << std::endl;
        return res;
    }
}

int main() {
    std::cout << "fact(20.3) = " << fact(20.3) << std::endl;
    //std::cout << "fact(300) = " << fact(300) << std::endl;
   return 0;
}

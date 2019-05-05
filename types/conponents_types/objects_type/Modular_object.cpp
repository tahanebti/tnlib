#include <iostream>
using namespace std;

template<typename T>
class Number
{
public:
   using Type = typename decay<decltype(T::value)>::type;

  constexpr Number() : value() {}
  template <typename U>
  Number(const U& x) {
    value = normalize(x);
  }

  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }

const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }

  Number& operator+=(const Number& other) { 
    if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Number& operator-=(const Number& other) {
   if ((value -= other.value) < 0) value += mod(); 
   return *this; }

  template <typename U>
 Number& operator+=(const U& other) { return *this += Number(other); }

  template <typename U>
 Number& operator-=(const U& other) { return *this -= Number(other); }

  Number& operator++() { return *this += 1; }
  Number& operator--() { return *this -= 1; }
  Number operator++(int) { Number result(*this); *this += 1; return result; }
  Number operator--(int) { Number result(*this); *this -= 1; return result; }
  Number operator-() const { return Number(-value); }


private: 
  Type value;

};


template <typename T> bool operator==(const Number<T>& lhs, const Number<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Number<T>& lhs, U rhs) { return lhs == Number<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Number<T>& rhs) { return Number<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Number<T>& lhs, const Number<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Number<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Number<T>& rhs) { return !(lhs == rhs); }

template <typename T> Number<T> operator+(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) += rhs; }
template <typename T, typename U> Number<T> operator+(const Number<T>& lhs, U rhs) { return Number<T>(lhs) += rhs; }
template <typename T, typename U> Number<T> operator+(U lhs, const Number<T>& rhs) { return Number<T>(lhs) += rhs; }

template <typename T> Number<T> operator-(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) -= rhs; }
template <typename T, typename U> Number<T> operator-(const Number<T>& lhs, U rhs) { return Number<T>(lhs) -= rhs; }
template <typename T, typename U> Number<T> operator-(U lhs, const Number<T>& rhs) { return Number<T>(lhs) -= rhs; }

template <typename T> Number<T> operator*(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) *= rhs; }
template <typename T, typename U> Number<T> operator*(const Number<T>& lhs, U rhs) { return Number<T>(lhs) *= rhs; }
template <typename T, typename U> Number<T> operator*(U lhs, const Number<T>& rhs) { return Number<T>(lhs) *= rhs; }

template <typename T> Number<T> operator/(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) /= rhs; }
template <typename T, typename U> Number<T> operator/(const Number<T>& lhs, U rhs) { return Number<T>(lhs) /= rhs; }
template <typename T, typename U> Number<T> operator/(U lhs, const Number<T>& rhs) { return Number<T>(lhs) /= rhs; }


template<typename T, typename U>
Number<T> power(const Number<T>& a, const U& b) {
  assert(b >= 0);
  Number<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}

template <typename T>
string to_string(const Number<T>& number) {
  return to_string(number());
}


template <typename T>
std::ostream& operator<<(std::ostream& stream, const Number<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Number<T>& number) {
  stream >> number.value;
  number.value = Number<T>::normalize(number.value);
  return stream;
}

int main() {
    // your code goes here
    return 0;
}
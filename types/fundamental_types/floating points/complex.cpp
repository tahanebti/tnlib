//Complex.cpp

#include <bits/stdc++.h>
using namespace std;
class DivisionByZeroException : public exception
{
    virtual const char *what() const throw()
    {
        return "\nDivision by zero is not defined\n";
    }
};
class Complex
{
  private:
    long double real; //real part
    long double imag; //imaginary part
  public:
    Complex()
    {
        real = 0;
        imag = 0;
    }
    Complex(long double r, long double i)
    {
        real = r;
        imag = i;
    }
    long double getReal()
    {
        return real;
    }
    long double getImag()
    {
        return imag;
    }
    Complex conjugate()
    {
        return Complex(real, -imag);
    }
    long double modulus()
    {
        return sqrt((real * real) + (imag * imag));
    }
    Complex reciprocal()
    {
        long double deno = (real * real) + (imag * imag);
        if (deno == 0)
        {
            DivisionByZeroException e;
            throw e;
        }
        return Complex(real / deno, -imag / deno);
    }
    Complex root()
    {
        long double mod = this->modulus();
        return Complex(sqrt((mod + real) / 2), sqrt((mod - real) / 2));
    }
    //operators
    Complex operator+(Complex c2)
    {
        return Complex(real + c2.getReal(), imag + c2.getImag());
    }
    Complex operator-(Complex c2)
    {
        return Complex(real - c2.getReal(), imag - c2.getImag());
    }
    Complex operator*(Complex c2)
    {
        long double a = real, b = imag, c = c2.getReal(), d = c2.getImag();
        return Complex((a * c) - (b * d), (b * c) + (a * d));
    }
    Complex operator/(Complex c2)
    {
        long double a = real, b = imag, c = c2.getReal(), d = c2.getImag(), deno = (c * c) + (d * d);
        if (deno == 0)
        {
            DivisionByZeroException e;
            throw e;
        }
        return Complex(((a * c) + (b * d)) / deno, ((b * c) - (a * d)) / deno);
    }
    void operator+=(Complex c2)
    {
        real += c2.getReal();
        imag += c2.getImag();
    }
    void operator-=(Complex c2)
    {
        real -= c2.getReal();
        imag -= c2.getImag();
    }
    void operator*=(Complex c2)
    {
        Complex c = Complex(real, imag) * c2;
        real = c.getReal();
        imag = c.getImag();
    }
    void operator/=(Complex c2)
    {
        Complex c = Complex(real, imag) / c2;
        real = c.getReal();
        imag = c.getImag();
    }
    bool operator==(Complex c2)
    {
        return ((real == c2.getReal()) && (imag == c2.getImag()));
    }
    friend ostream &operator<<(ostream &output, Complex &c)
    {   
        output << c.toString();
        return output;
    }
    friend istream &operator>>(istream &input, Complex &c)
    {   
        input >> c.real >> c.imag;
        return input;
    }
    //utility functions
    string toString()
    {
        stringstream s;
        s << real << " ";
        if (imag >= 0)
            s << "+ " << imag << "i";
        else if (imag < 0)
            s << "- " << -imag << "i";
        return s.str();
    }
};
Complex power(Complex c1, int n)
{
    Complex C(1, 0);
    while (n--)
        C = C * c1;
    return C;
}
int main()
{
    Complex c1(3, 2), c2(1, 7), c3;
    c3 = c1 + c2;
    cout << c3.toString() << "\n";
    c3 = c1 - c2;
    cout << c3 << "\n";
    c3 = c1 * c2;
    cout << c3.toString() << "\n";
    c3 = c1 / c2;
    cout << c3 << "\n";
    c3 = c1.reciprocal();
    cout << c3.toString() << "\n";
    c3 = c1.root();
    cout << c3 << "\n";
    c3 = power(c1, 2);
    cout << c3 << "\n";
    c3 += c2;
    cout << c3.toString() << "\n";
    c3 -= c2;
    cout << c3 << "\n";
    c3 *= c2;
    cout << c3.toString() << "\n";
    c3 /= c2;
    cout << c3 << "\n";
    cin >> c3;
    cout << c3 << "\n";
    c3 /= Complex(0, 0);
    cout << c3;
    return 0;
}
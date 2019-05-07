//
//  all operator overloading implementation
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#ifndef OVERLOAD_H_ 
#define OVERLOAD_H_
#include <iostream>

//-------------------------------------------------------------------------------------------------
class Point
{
private:
    int x;
    int y;
    int z;
public:
    Point() { x = 0; y = 0; z = 0; }
    Point(int x, int y, int z) : x(x), y(y), z(z) {};
    
    // arithmetic operator.
    friend Point operator + (const Point & p);
    friend Point operator - (const Point & p);
    friend Point operator + (const Point & left, const Point & right);
    friend Point operator - (const Point & left, const Point & right);
    friend Point operator * (const Point & left, const Point & right);
    friend Point operator / (const Point & left, const Point & right);
    friend Point operator % (const Point & left, const Point & right);
    
    //inc / dec operator
    friend Point & operator ++ (Point & p);
    friend Point & operator -- (Point & p);
    friend Point operator ++ (Point & p, int);
    friend Point operator -- (Point & p, int);

    //compairson operator
    friend bool operator == (const Point & left, const Point & right);
    friend bool operator != (const Point & left, const Point & right);
    friend bool operator > (const Point & left, const Point & right);
    friend bool operator < (const Point & left, const Point & right);
    friend bool operator >= (const Point & left, const Point & right);
    friend bool operator <= (const Point & left, const Point & right);
    //friend bool operator <=> (const Point & left, const Point & right); C++ 20 Coming

    //logical operator
    friend bool operator ! (const Point & v);
    friend bool operator && (const Point & left, const Point & right);
    friend bool operator || (const Point & left, const Point & right);

    //bitwise operator
    friend Point operator ~ (const Point & v);
    friend Point operator & (const Point & left, const Point & right);
    friend Point operator | (const Point & left, const Point & right);
    friend Point operator ^ (const Point & left, const Point & right);
    friend std::istream & operator >> (std::istream & is, Point & p);
    friend std::ostream & operator << (std::ostream & os, Point & p);

    //compound assignments statments
    Point & operator = (const Point & p);
    friend Point & operator += (Point & left, const Point & right);
    friend Point & operator -= (Point & left, const Point & right);
    friend Point & operator *= (Point & left, const Point & right);
    friend Point & operator /= (Point & left, const Point & right);
    friend Point & operator %= (Point & left, const Point & right);
    friend Point & operator &= (Point & left, const Point & right);
    friend Point & operator |= (Point & left, const Point & right);
    friend Point & operator ^= (Point & left, const Point & right);
    friend std::istream & operator >>= (std::istream & is, Point & p);
    friend std::ostream & operator <<= (std::ostream & os, Point & p);
    
    //operator working with pointer and class members
    int operator [] (int p);
    //int & operator*();
    //int* operator&();
    //int* operator->();
    //int & operator->*(int p);

    //conversion to another type
    operator bool() const;
};
//-------------------------------------------------------------------------------------------------
#endif // OVERLOAD_H_


//***arithmetic operator***
//-------------------------------------------------------------------------------------------------
Point operator + (const Point & p)
{
    return Point(p.x, p.y, p.z);
}
//-------------------------------------------------------------------------------------------------
Point operator - (const Point & p)
{
    return Point(-p.x, -p.y, -p.z);
}
//-------------------------------------------------------------------------------------------------
Point operator + (const Point & left, const Point & right)
{
    return Point(left.x + right.x, left.y + right.y, left.z + right.z);
}
//-------------------------------------------------------------------------------------------------
Point operator - (const Point & left, const Point & right)
{
    return Point(left.x - right.x, left.y - right.y, left.z - right.z);
}
//-------------------------------------------------------------------------------------------------
Point operator * (const Point & left, const Point & right)
{
    return Point(left.x * right.x, left.y * right.y, left.z * right.z);
}
//-------------------------------------------------------------------------------------------------
Point operator / (const Point & left, const Point & right)
{
    return Point(left.x / right.x, left.y / right.y, left.z / right.z);
}
//-------------------------------------------------------------------------------------------------
Point operator % (const Point & left, const Point & right)
{
    return Point(left.x % right.x, left.y % right.y, left.z % right.z);
}
//-------------------------------------------------------------------------------------------------

//***inc / dec operator***
//-------------------------------------------------------------------------------------------------
Point & operator ++ (Point & p)
{
    p.x++;
    p.z++;
    p.y++;
    return p;
}
//-------------------------------------------------------------------------------------------------
Point operator ++ (Point & p, int)
{
    Point old_value(p.x, p.y, p.z);
    p.x++;
    p.y++;
    p.z++;
    return old_value;
}
//-------------------------------------------------------------------------------------------------
Point & operator -- (Point & p)
{
    p.x--;
    p.z--;
    p.y--;
    return p;
}
//-------------------------------------------------------------------------------------------------
Point operator -- (Point & p, int)
{
    Point old_value(p.x, p.y, p.z);
    p.x--;
    p.y--;
    p.z--;
    return old_value;
}
//-------------------------------------------------------------------------------------------------

//***logical operator***
//-------------------------------------------------------------------------------------------------
bool operator == (const Point & left, const Point & right)
{
    return (left.x == right.x) && (left.y == right.y) && (left.z == right.z);
}
//-------------------------------------------------------------------------------------------------
bool operator != (const Point & left, const Point & right)
{
    return !(left.x == right.x) && !(left.y == right.y) && !(left.z == right.z);
}
//-------------------------------------------------------------------------------------------------
bool operator > (const Point & left, const Point & right)
{
    return (left.x > right.x) && (left.y > right.y) && (left.z > right.z);
}
//-------------------------------------------------------------------------------------------------
bool operator < (const Point & left, const Point & right)
{
    return (left.x < right.x) && (left.y < right.y) && (left.z < right.z);
}
//-------------------------------------------------------------------------------------------------
bool operator >= (const Point & left, const Point & right)
{
    return !(left.x < right.x) && !(left.y < right.y) && !(left.z < right.z);
}
//-------------------------------------------------------------------------------------------------
bool operator <= (const Point & left, const Point & right)
{
    return !(left.x > right.x) && !(left.y > right.y) && !(left.z > right.z);
}
//-------------------------------------------------------------------------------------------------

//***boolean operator***
//-------------------------------------------------------------------------------------------------
bool operator ! (const Point & p)
{
    return !(bool)p;
}
//-------------------------------------------------------------------------------------------------
bool operator && (const Point & left, const Point & right)
{
    return (bool)left && (bool)right;
}
//-------------------------------------------------------------------------------------------------
bool operator || (const Point & left, const Point & right)
{
    return (bool)left || (bool)right;
}

//***bitwise operator***
//-------------------------------------------------------------------------------------------------
Point operator ~ (const Point & v)
{
    return Point(~(v.x), ~(v.y), ~(v.z));
}
//-------------------------------------------------------------------------------------------------
Point operator & (const Point & left, const Point & right)
{
    return Point(left.x & right.x, left.y & right.y, left.z & right.z);
}
//-------------------------------------------------------------------------------------------------
Point operator | (const Point & left, const Point & right)
{
    return Point(left.x | right.x, left.y | right.y, left.z | right.z);
}
//-------------------------------------------------------------------------------------------------
Point operator ^ (const Point & left, const Point & right)
{
    return Point(left.x ^ right.x, left.y ^ right.y, left.z ^ right.z);
}
//-------------------------------------------------------------------------------------------------
std::istream & operator >> (std::istream & is, Point & p)
{
    std::cout << "Enter Point.\nX:";
    std::cin >> p.x;
    std::cout << "\nY:";
    std::cin >> p.y;
    std::cout << "\nZ:";
    std::cin >> p.z;
    std::cout << std::endl;
    return is;
}
//-------------------------------------------------------------------------------------------------
std::ostream  & operator << (std::ostream & os, Point & p)
{
    os << '(' << p.x << ", " << p.y << ", " << p.z << ')';
    return os;
}
//-------------------------------------------------------------------------------------------------

//***assignments operator***
//-------------------------------------------------------------------------------------------------
Point & Point::operator = (const Point & p)
{
    this->x = p.x, this->y = p.y, this->z = p.z;
    return *this;
}
//-------------------------------------------------------------------------------------------------
Point & operator += (Point & left, const Point & right)
{
    left.x += right.x, left.y += right.y, left.z += right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
Point & operator -= (Point & left, const Point & right)
{
    left.x -= right.x, left.y -= right.y, left.z -= right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
Point & operator *= (Point & left, const Point & right)
{
    left.x *= right.x, left.y *= right.y, left.z *= right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
Point & operator /= (Point & left, const Point & right)
{
    left.x /= right.x, left.y /= right.y, left.z /= right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
Point & operator %= (Point & left, const Point & right)
{
    left.x %= right.x, left.y %= right.y, left.z %= right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
Point & operator &= (Point & left, const Point & right)
{
    left.x &= right.x, left.y &= right.y, left.z &= right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
Point & operator |= (Point & left, const Point & right)
{
    left.x |= right.x, left.y |= right.y, left.z |= right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
Point & operator ^= (Point & left, const Point & right)
{
    left.x ^= right.x, left.y ^= right.y, left.z ^= right.z;
    return left;
}
//-------------------------------------------------------------------------------------------------
std::istream & operator >>= (std::istream & is, Point & p)
{
    std::cout << "Point.\nX:";
    std::cin >> p.x;
    std::cout << "\nY:";
    std::cin >> p.y;
    std::cout << "\nZ:";
    std::cin >> p.z;
    std::cout << std::endl;
    return is;
}
//-------------------------------------------------------------------------------------------------
std::ostream & operator <<= (std::ostream & os, Point & p)
{
    os.clear();
    os << '(' << p.x << ", " << p.y << ", " << p.z << ')';
    return os;
}
//-------------------------------------------------------------------------------------------------
Point::operator bool() const
{
    if (*this != Point(0, 0, 0))
        return true;
    return false;
}
//-------------------------------------------------------------------------------------------------

//***operator working with pointer and data members***
//-------------------------------------------------------------------------------------------------
int Point::operator [] (int p)
{
    try
    {
        if (p < 3)
        {
            if (p == 0)
                return this->x;
            if (p == 1)
                return this->y;
            if (p == 2)
                return this->z;
        }
        else
            throw "Error: out of range vector";
    }
    catch (const char *str)
    {
        std::cerr << str << std::endl;
    }
    return NULL;
}
//-------------------------------------------------------------------------------------------------
int main()
{
    setlocale(LC_ALL, "Rus");

    Point v1(10,20,30);
    Point v2(5,10,15);
    Point v3;
    bool Result;

    //Арифметические операторы
    std::cout << "arithmetic operator" << std::endl;
    v3 = v1 + v2;
    std::cout << " (v1 + v2) " << v3 << std::endl;
    v3 = v1 - v2;
    std::cout << " (v1 - v2) " << v3 << std::endl;
    v3 = v1 * v2;
    std::cout << " (v1 * v2) " << v3 << std::endl;
    v3 = v1 / v2;
    std::cout << " / (v1 / v2) " << v3 << std::endl;
    v1 = Point(8, 7, 2);
    v2 = Point(4, 4, 4);
    v3 = v1 % v2;
    std::cout << " (v1 % v2) " << v3 << std::endl;
    v3 = -v1;
    std::cout << "unary operator - (v1) " << v3 << std::endl;
    v3 = +v1;
    std::cout << "unary operator + (v1) " << v3 << std::endl;

    //inc / dec operator
    v1 = Point(10, 20, 30);
    v2 = Point(5, 10, 15);
    std::cout << "\ninc / dec operator" << std::endl;
    v3 = ++v1;
    std::cout << "prefix operator increments ++v1 " << v3 << std::endl;
    v3 = v1++;
    std::cout << "postfix operator increments v1++ " << v3 << std::endl;
    v3 = --v1;
    std::cout << "prefix operator decrements --v1 " << v3 << std::endl;
    v3 = v1--;
    std::cout << "postfix operator decrements v1-- " << v3 << std::endl;

    //compairson operator
    v1 = Point(10, 20, 30);
    v2 = Point(5, 10, 15);
    std::cout << "\ncompairson operator" << std::endl;
    v3 = v2;
    std::cout << " = " << v3 << std::endl;
    Result = v1 == v2;
    std::cout << std::boolalpha << " (v1 == v2) " << Result << std::endl;
    Result = v1 != v2;
    std::cout << std::boolalpha << " (v1 != v2) " << Result << std::endl;
    Result = v1 > v2;
    std::cout << std::boolalpha << " (v1 > v2) " << Result << std::endl;
    Result = v1 < v2;
    std::cout << std::boolalpha << " (v1 < v2) " << Result << std::endl;
    Result = v1 >= v2;
    std::cout << std::boolalpha << " (v1 >= v2) " << Result << std::endl;
    Result = v1 <= v2;
    std::cout << std::boolalpha << " (v1 <= v2) " << Result << std::endl;

    //logical operator
    std::cout << "\nlogical operator" << std::endl;
    v1 = Point(10, 20, 30);
    v2 = Point(5, 10, 15);
    Result = !v1;
    std::cout << std::boolalpha << "not ! (!v1) " << Result << std::endl;
    Result = (v1 && v2);
    std::cout << std::boolalpha << "and && (v1 && v2) " << Result << std::endl;
    Result = (v1 || v2);
    std::cout << std::boolalpha << "or || (v1 || v2) " << Result << std::endl;
    
    //bitwise operator
    std::cout << "\nbitwise operator" << std::endl;
    v1 = Point(10, 20, 30);
    v2 = Point(5, 10, 15);
    v3 = Point(0, 0, 0);

    v3 = ~v1;
    std::cout << "  (~v1) " << v3 << std::endl;
    v3 = (v2 & v1);
    std::cout << " (v2 & v1) " << v3 << std::endl;
    v3 = (v2 | v1);
    std::cout << "  (v2 | v1) " << v3 << std::endl;
    v3 = (v2 ^ v1);
    std::cout << " (v2 ^ v1) " << v3 << std::endl;

    //assignments operator
    v1 = Point(10, 20, 30);
    v2 = Point(5, 10, 15);
    v3 = Point(100, 100, 100);
     
    std::cout << "\nassignments operator" << std::endl;
    v3 += v1;
    std::cout << " (v3 += v1) " << v3 << std::endl;
    v3 -= v1;
    std::cout << " (v3 -= v1) " << v3 << std::endl;
    v3 *= v1;
    std::cout << " (v3 *= v1) " << v3 << std::endl;
    v3 /= v1;
    std::cout << " (v3 /= v1) " << v3 << std::endl;
    v3 = Point(8, 7, 2);
    v1 = Point(4, 4, 4);
    v3 %= v1;
    std::cout << " (v3 %= v1) " << v3 << std::endl;
    v1 = Point(10, 20, 30);
    v2 = Point(5, 10, 15);
    v3 = Point(100, 100, 100);
    v3 &= v1;
    std::cout << " (v3 &= v1) " << v3 << std::endl;
    v3 |= v1;
    std::cout << " (v3 |= v1) " << v3 << std::endl;
    v3 ^= v1;
    std::cout << " (v3 ^= v1) " << v3 << std::endl;

    
    return 0;
}
//-------------------------------------------------------------------------------------------------
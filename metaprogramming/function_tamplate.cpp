#include <iostream>
using namesapce std;


//
//  function template
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  Notes : 

  A template is a mechanism for generic programming to provide a
  ”schema“ to represent the structure of an entity

  In C++, templates are a compile-time functionality to represent:
    • A family of functions
    • A family of classes
    • A family of variables C++14
  Templates are a way to make code more reusable and faster
  negative sides: hard to read, cryptic error messages, larger binary
  size, and higher compile time


  Function Templates
    - Template parameters   <typename T>, <int, enum, class ...>
    - Default parameters    <int a = 2, int b = a + 3> 
    - Template specialization <>
    - Template overloading 


**/

//The problem: We want to define a function to handle different types

int add(int a, int b) {
  return a + b;
}
float add(float a, float b) {
  return a + b;
}

//solution : Function templates are special functions that can operate with
//generic types (independent of any particular type)

template<typename T>
T add(T a, T b) {
return a + b;
}


/**
  Template Parameters
  template <typename T> is a template parameter
    non-type template parameters
    - integral type (int, char, etc) (not floating point)
    - enumerator, enumerator class

**/

//Examples 
//int parameter
template<int A, int B>
int addInt() {
  return A + B; // sum is computed at compile-time
} // e.g. addInt<3, 4>();

//enum parameter
enum class EnumT { X, Y };

template<EnumT Z>
int addEnum(int a, int b) {
  return (Z == EnumT::X) ? a + b : a;
} // e.g. addEnum<EnumT::X>(3, 4);

//Ceiling division
template<int DIV, typename T>
T ceil_div(T value) {
  return (value + DIV - 1) / DIV;
}
// e.g. ceil_div<5>(11); // returns 3

// Rounded division
template<int DIV, typename T>
T round_div(T value) {
  return (value + DIV / 2) / DIV;
}
// e.g. round_div<5>(11); // returns 2 (2.2)



/**
  Function Template - Specialization
**/

template<typename T>
T max_value(T a, T b) {
  return a > b ? a : b;
}

//max value() does not make sense for floating-point computation because of rounding errors
//Solution: Template (full) specialization

template<>
T max_value<float>(float a, float b) {
  return a > b ? a : b; // floating point relative error implementation
}


/**

  function template overloading

**/
//Template Functions can be overloaded
template<typename T>
T add(T a, T b) {
  return a + b;
} // e.g add(3, 4);

template<typename T>
T add(T a, T b, T c) {
  return a + b + c;
} // e.g add(3, 4, 5);

//Also templates themselves can be overloaded
template<int C, typename T>
T add(T a, T b) { // it is not in conflict with
  return a + b + C; // T add(T a, T b) thanks to int C
}


//C++17 introduces automatic deduction of non-type template
//parameters with the auto keyword

template<auto X, auto Y>
void g() {}
//g<2, 3>(); // X: int, Y: int
//g<2u, 2u>(); // X: unsigned, Y: unsigned
//g<2, 3u>(); // X: int, Y: unsigned


int main()
{
  int c1 = add(3, 4); // c1 = 7
  float c2 = add(3.0f, 4.0f); // c2 = 7.0f
  int c3 = add<int>(3.0f, 4.0f); // c3 = 7 (int forced)
}

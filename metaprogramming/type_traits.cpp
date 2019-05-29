#include <iostream>
using namesapce std;


//
//  type traits
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  - Type Traits
    - Type trait library
    - Type manipulation
    - Type Relation and Transformation


  Introspection : is the ability to inspect a type and retrieve its
  various qualities

  Reflection : is the ability of a computer program to examine,
  introspect, and modify its own structure and behavior at runtime

------------------------------------------------------------
  C++ provides compile-time reflection and introspection
  capabilities through type traits
-------------------------------------------------------------
**/

//Type traits (C++11) defines a compile-time interface to query or modify the properties of types

//The problem:
template<typename T>
T floor_div(T a, T b) {
  return a / b;
}

//If we what to prevent floating-point division at compile-time a
//first solution consists in specialize for all “integral” types
template<typename T>
T floor_div(T a, T b); // declaration (error for other types)
template<>
char floor_div<char>(char a, char b) { // specialization
  return a / b;
}

template<>
int floor_div<int>(int a, int b) { // specialization
  return a / b;
}


//The best solution is to use type traits
# include <type_traits> // <-- std type traits library
template<typename T>
T floor_div(T a, T b) {
  static_assert(std::is_integral<T>::value, "floor_div accepts only integral types");
  return a / b;
}

//std::is integral<T> is a struct with a boolean field value
//It is true if T is a bool, char, short, int, long, long long, false otherwise


/**
  Type Traits Library 

  (Basic Types) 
    • is_integral checks for an integral type (bool, char, unsigned char, short, unsigned short, int, long, etc.)
    • is_floating point checks for a floating-point type (float,double)
    • is_arithmetic checks for a integral or floating-point type
    • is_signed checks for a signed type (float, int, etc.)
    • is_unsigned checks for an unsigned type (unsigned T,  bool, etc.)
    • is_enum checks for an enumerator type (enum, enum class)

  (pointer, reference, etc.) 
    • is_void checks for (void)
    • is_pointer checks for a pointer (T*)
    • is_nullptr checks for a (nullptr) C++14
    • is_reference checks for a reference (T&)
    • is_array checks for an array (T (&)[N])
    • is_function checks for a function type
    • is_const checks if a type is const

  (Objects)
    • is_class checks for a class type (struct, class, not enum class)
    • is_empty checks for empty class types (struct A fg)
    • is_abstract checks for a class with at least one pure virtual function
    • is_polymorphic checks for a class with at least one virtual function
    • is_final checks for a class that cannot be extended

**/


template<typename T>
void f(T x) { std::cout << std::is_const<T>::value; }

template<typename T>
void g(T& x) { std::cout << std::is_const<T>::value; }

template<typename T>
void h(T& x) {
  std::cout << std::is_const<T>::value;
  x = nullptr; // ok, it compiles for T: (const int)*
}


/**

Type Manipulation 
Signed and Unsigned types:
  • make_signed makes a type signed
  • make_unsigned makes a type unsigned
Pointers and References:
  • remove_pointer remove pointer (T* -> T)
  • remove_lvalue_reference remove reference (T& -> T)
  • add_pointer add pointer (T -> T*)
  • add_lvalue_reference add reference (T -> T&)
Const-Volatile Specifiers:
  • remove_const remove const (const T -> T)
  • remove_volatile remove volatile (volatile T -> T)
  • remove_cv remove const and volatile
  • add_const add const

**/

template<typename T>
void f(T ptr) {
  using R = typename std::remove_pointer<T>::type;
  R x = ptr[0]; // char
}

template<typename T>
void g(T& x) {
  using R = typename std::remove_const<T>::type;
  const_cast<R>(x) = 0; // ok
}



/**
  Type Relation and Transformation

Type relation:
  • is_same<T, R> check if T and R are the same type
  • is_base_of<T, R> check if T is base of R
  • is_convertible<T, R> check if T can be converted to R
Type Transformation:
  • common_type<T, R> returns the common type between T and R
  • conditional<pred, T, R> returns T if pred is true, R otherwise
  • decay<T> returns the same type as function pass-by-value

**/

template<typename T, typename R>
T add(T a, R b) {
static_assert(std::is_same<T, R>::value,"T and R must be the samae");
  return a + b;
}
struct A {};
struct B : A {};


//std::common_type
template<typename T, typename R>
typename std::common_type<R, T>::type //<-- return type
add(T a, R b) { 
  return a + b;
}


//std::conditional
template<typename T, typename R>
void f(T a, R b) {
  const bool pred = sizeof(T) > sizeof(R);
  using S = typename std::conditional<pred, T, R>::type;
  S result = a + b;
}

int main() {
  floor_div(7, 2); // returns 3 (int)
  floor_div(7ull, 2); // returns 3 (unsigned long long)
  floor_div(7.0, 3.0); // ??? it compiles, but the result is

  const int a = 3;
  f(a); // print false
  g(a); // print true
  const int* b = nullptr;
  h(b); // print false!! T: (const int)*

  //Type traits allows also to manipulate types by using the type
  //field (can be used also in the return type of a function)

  //convert int to unsigned
  using T = int;
  T x = -3; // int

  using R = typename std::make unsigned<int>::type;
  R y = 5; // unsigned

  const char* a = "abc";
  const int b = 3;
  f(a); // T: const char*
  g(b); // T&: const int&


  add(1, 2); // ok
  // add(1, 2.0); // compile error!!
  std::is_base<A, B>::value; // true
  std::is_base<A, A>::value; // true
  std::is_convertible<int, float>::value; // true


  //std::common_type
  add(3, 4.0f); // .. but we don't know the type of the result
  // we can use decltype to derive the result type of
  // a generic expression
  using result_t = decltype(add(3, 4.0f));
  result_t x = add(3, 4.0f);

  //std::conditional
  f(2, 'a'); // S: int
  f(2, 2ull); // S: unsigned long long

} // not what we expect
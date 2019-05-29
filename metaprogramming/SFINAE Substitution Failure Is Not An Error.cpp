#include <iostream>
using namesapce std;


//
//  SFINAE Substitution Failure Is Not An Error
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  Notes : 
  
  Substitution failure is not an error (SFINAE) applies during
  overload resolution of function templates. When substituting the
  deduced type for the template parameter fails, the specialization
  is discarded from the overload set instead of causing a compile
  error
**/

//The problem
template<typename T>
T ceil_div(T value, T div);
unsigned ceil_div<unsigned>(unsigned value, unsigned div) {
  return (value + div - 1) / div;
}

int ceil_div<int>(int value, int div) {
  return (value > 0) ^ (div > 0) ? (value / div) : (value + div - 1) / div;
}

// what about "char", "unsigned char", "short", etc.?

/**
  //solution

  std::enable if Type Trait
  The most common way to adopt SFINAE is using the
  std::enable if/std::enable if t type traits
  std::enable if allows a function template or a class template
  specialization to include or exclude itself from a set of matching
  functions/classes
**/

template<bool B, class T = void>
struct enable_if {
// "type" is not defined of "B = false"
};
template<class T>
struct enable_if<true, T> {
  using type = T;
};
//helper alias: std::enable if t<T> instead of typename std::enable if<T>::type  

//Example : SFINAE as return type
template<typename T>
std::enable_if_t<std::is_signed_v<T>> f(T) {
  std::cout << "signed";
}
template<typename T>
std::enable_if_t<!std::is_signed_v<T>> f(T) {
  std::cout << "unsigned";
}


//Example : SFINAE as parameter
template<typename T>
void g(std::enable_if_t<std::is_signed_v<T>, T>) {
  std::cout << "signed";
}
template<typename T>
void g(std::enable_if_t<!std::is_signed_v<T>, T>) {
  std::cout << "unsigned";
}


//Example : Function SFINAE as hidden parameter
template<typename T>
void h(T, std::enable_if_t<std::is_signed_v<T>, T> = 0) {
  std::cout << "signed";
}

template<typename T>
void h(T, std::enable_if_t<!std::is_signed_v<T>, T> = 0) {
  std::cout << "unsigned";
}


//Example : Function SFINAE as decltype + return type
template<typename T, typename R>
decltype(std::declval<T>() + std::declval<R>()) add(T a, R b) {
    return a + b;
}

template<typename T>
std::enable_if_t<std::is_class_v<T>, T> add(T a, T b) {
    return a;
}


//Example : Function SFINAE as template parameter
template<typename T,std::enable_if_t<std::is_signed_v<T>, int> = 0> 
void f(T) {}

template<typename T, std::enable_if_t<!std::is_signed_v<T>, int> = 0>
void f(T) {}





//Class SFINAE
template <typename T, typename Enable = void>
class A;

template <typename T>
struct A<T, std::enable_if_t<std::is_signed_v<T>>>{};

template <typename T>
struct A<T, std::enable_if_t<!std::is_signed_v<T>>>{};


//check struct member
//SFINAE can be also used to check if a structure has a specific data member or type
//Let consider the following structures:
struct A {
  static int x;
  int y;
  using type = int;
};

struct B {};

//Check Struct Member - Variable
template<typename T, typename = void>
struct has_x : std::false_type {};

template<typename T>
struct has_x<T, decltype((void) T::x)> : std::true_type {};
//----------------------------------------------------------------------
template<typename T, typename = void>
struct has_y : std::false_type {};

template<typename T>
struct has_y<T,e
decltype((void) std::declval<T>().y)> : std::true_type {};
//----------------------------------------------------------------------


//Check Struct Member - Type
template<typename...>
using void_t = void; // included in C++17 <utility>

template<typename T, typename = void>
struct has_type : std::false_type {};

template<typename T>
struct has_type<T, std::void_t<typename T::R> > : std::true_type {};


//Support Trait for Stream Operator
template<typename T>
using EnableP = decltype( std::declval<std::ostream&>() << std::declval<T>() );

template<typename T, typename = void>
struct is_stream_supported : std::false_type {};

template<typename T>
struct is_stream_supported<T, EnableP<T>> : std::true_type {};
struct A {};

int main() {
  //Example : SFINAE as return type
  f(1); // print "signed"
  f(1u); // print "unsigned"

  //Example : SFINAE as parameter
  h<int>(1); // print "signed"
  h<unsigned>(1); // print "unsigned"

  //Example : Function SFINAE as hidden parameter
  h(1); // print "signed"
  h(1u); // print "unsigned"

  //Example : Function SFINAE as decltype + return type
  add(1, 2); // return 3
  add(A(), A()); // add() not supported

  //Example : Function SFINAE as template parameter
  f(4);
  f(4u);



  //Class SFINAE
  A<int>;
  A<unsigned>;

  //Check Struct Member - Variable
  has_x< A >::value; // returns true
  has_x< B >::value; // returns false
  has_y< A >::value; // returns true
  has_y< B >::value; // returns false

  //Check Struct Member - Type
  has_type< A >::value; // returns true
  has_type< B >::value; // returns false

  //Support Trait for Stream Operator
  is_stream_supported<int>::value; // returns true
  is_stream_supported<A>::value; // returns false

}
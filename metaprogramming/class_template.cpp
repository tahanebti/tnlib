#include <iostream>
using namesapce std;


//
//  class template
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  - Class Templates
      - Full/Partial specialization
      - Class + function template specialization
      - virtual
      - friend
      - Template dependent names
      - Template template arguments
      - Template variable

**/


//In a similar way to function templates, class templates are used to build a family of classes
template<typename T>
struct A { // templated class (typename template)
  T x = 0;
};

template<int N1>
struct B { // templated class (numeric template)
  const int N = N1;
};


//C++17 introduces automatic deduction of class template arguments for object constructor
template<typename T, typename R>
struct A {
A(T x, R y) {}
};

/**
Template Class Specialization 
  The main difference with template functions is that classes can be partially specialized
  Note: Every class specialization (both partial and full) is a completely
  new class and it does not share anything with the generic class
**/
template<typename T, typename R>
struct A { // generic template class
  T x;
};

template<typename T>
struct A<T, int> { // partial specialization
  T y;
};

template<>
struct A<float, int> { // full specialization
  T z;
};

//Example 1
template<typename T, typename R>
struct A { // generic template class
  void f() { std::cout << "A<T, R>"; }
};
template<typename T>
struct A<T, int> { // partial specialization
  void f() { std::cout << "A<T, int>"; }
};


//class + function template
template<typename T>
struct A {
  T x = 2;
};

template<typename T, int N>
struct B : A<T> {
  template<typename R>
  int f(T y, R z) {
    return x * N;
  }
};



//implement a simple type_traits
// std::true type, std::false type contain a field "value"
// set to true or false respectively
template<typename T>
struct is_const_pointer : std::false_type {};

template<typename R> // const R* specialization
struct is_const_pointer<const R*> : std::true_type {};


//compaire class template
template<typename T> struct A {};
template<typename T> struct B {};

template<typename T, typename R>
struct Compare : std::false_type {};

template<typename T, typename R>
struct Compare<A<T>, A<R>> : std::true_type {};



//class  + function template specialization
//Given a template class and a template member function
template<typename T, typename R>
struct A {
  template<typename X, typename Y>
  void f();
};

//There are three ways to specialize the class/function:
  //- Generic class, generic function
  //- Full class specialization, generic function or full function specialization
  //- Partial class specialization + declaration, generic function or full function specialization

template<typename T, typename R>
template<typename X, typename Y>
void A<T, R>::f() {}
// ok, A<T, R> and f<X, Y> are not specialized

template<>
template<typename X, typename Y>
void A<int, int>::f() {}
// ok, A<int, int> is full specialized
// ok, f<X, Y> is not specialized

template<>
template<>
void A<int, int>::f<int, int>() {}
// ok, A<int, int> and f<int, int> are full specialize



//Virtual functions cannot have template arguments
//• Templates are a compile-time feature
//• Virtual functions are a run-time feature


//Class Template Hierarchy
  //Member of class templates can be used internally in derived class
  //templates by specifying the particular type of the base class with
  //the keyword using
template<typename T>
struct A {
  T x;
  void f() {}
};

template<typename T>
struct B : A<T> {
  using A<T>::x; // needed (may be also a specialization)
  using A<T>::f; // needed
  void g() {
    x;
    f();
  }
};


//friend keyword
template<typename T> struct A {};
template<typename T, typename R> struct B {};
template<typename T> void f() {}
//--------------------------------------------------------------
class C {
friend class A<int>; // match only A<int>
template<typename> friend class A; // match all A templates
// template<typename T> friend class B<int, T>;
// partial specialization cannot be declared as a friend
friend void f<int>(); // match only f<int>
template<typename T> friend void f(); // match all templates
};


//Template Dependent Names (template keyword)
  //The template keyword tells the compiler that what follows is a
  //function template, and not a member data
  //This is important when there are two (or more) dependent names

template<typename T>
struct A {
  template<typename R>
  void g() {}
};

template<typename T> // (A<T> is a dependent name (from T)
  void f(A<T> a) { // (g<int> is a dependent name (from int)
// a.g<int>(); // compile error!!
// interpreted as: "(a.g < int) > ()"
  a.template g<int>(); // ok
}


//Template Template Arguments
//Template template parameters match templates instead of
//concrete types
template<typename T> struct A {};
template<typename T> struct B {};

template<template <typename> class R>
struct B {
  R<int> x;
  R<float> y;
};

template<template <typename> class R, typename S>
void f(R<S> x) {} // works with every class and type


//Template Variable
//C++14 allows the creation of variables that are templated
//Template variable can be considered a special case of template class
template<typename T>
constexpr T pi = T{3.1415926535897932385}; // variable template

template<typename T>
T circular_area(T r) {
  return pi<T> * r * r; // pi<T> is a variable template
}                       // instantiation


int main() {
  A<int> a1; // a1.x is int = 0
  A<float> a2; // a2.x is float = 0.0f
  A<double> a4; // a3.x is double = 0.0
  B<1> b1; // b1.N is 1
  B<2> b2; // b2.N is 2

  A<int, float> a1(3, 4.0f); // < C++17
  A a2(3, 4.0f); // C++17


  //template class specialization
  A<float, float> a1;
  a1.f(); // print "A<T, R>"
  
  A<float, int> a2;
  a2.f(); // print "A<T, int>"


  //class + function template
  B<int, 3> b;
  b.f(3, 3.3);


  //implement simple type_traits
  using namespace std;
  cout << std::is_const<int*>::value; // print false
  cout << std::is_const<const int*>::value; // print false
  cout << std::is_const<int* const>::value; // print true
  cout << is_const_pointer<int*>::value; // print false
  cout << is_const_pointer<const int*>::value; // print true
  cout << is_const_pointer<int* const>::value; // print false

  //compaire class template
  using namespace std;
  cout << Compare<int, float>::value; // false
  cout << Compare<int, int>::value; // false
  cout << Compare<B<int>, B<int>>::value; // false
  cout << Compare<A<int>, B<int>>::value; // false
  cout << Compare<A<int>, A<float>>::value; // true

  //Template Template Arguments
  f( A<int>() );
  f( B<float>() );
  B<A> y;


  //template variable
  circular_area(3.3f); // float
  circular_area(3.3); // double
  // circular_area(3); // error -> narrowing conversion on "pi"
}
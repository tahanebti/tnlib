#include <iostream>
using namesapce std;


//
//  Compile-time utilities
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  - Compile-Time Utilities
    - static assert : static assert (C++11) is used to tests a software assertion at compile-time
    - decltype : is a keyword used to get the type of an entity or an expression 
    - declval
    - using : A typedef-name can also be introduced by an alias-declaration
**/



//If the static assertion fails, the program does not compile

template<typename T, typename R>
void f(T, R) {
  static_assert(sizeof(T) == sizeof(R), "test4");
}


//decltype expression
bool f(int) { return true; }
struct A {
  int x;
};



//using keyword
  // using keyword allows also for templated aliases
  // using keyword is useful to simplify complex template expression
template<typename T>
struct A {
  T x;
};

template<typename T>

using Alias = A<T>; // called "Alias Template"

using IntAlias = A<int>;




int main() {
  static_assert(2 + 2 == 4, "test1"); // ok, it compiles
  static_assert(2 + 2 == 5, "test2"); // compile error!!
  static_assert(sizeof(void*) * 8 == 64, "test3");

  f<int, unsigned>(); // ok, it compiles
// f<int, char>(); // compile error!!


  //decltype
  int x = 3;
  int& y = x;
  const int z = 4;
  int array[2];
  decltype(x); // int
  decltype(2 + 3.0); // double
  decltype(y); // int&
  decltype(z); // const int
  decltype(array); // int[2]

  //decltype expression
  int x = 3;
  const A a;
  decltype(x); // int
  decltype((x)); // int&
  decltype(f); // bool
  decltype((f)); // bool (*)(int)
  decltype(a.x); // int
  decltype((a.x)); // const int

  //using keyword
  Alias<int> a;
  IntAlias b; // the same


} // depends on the OS (32/64-bit)
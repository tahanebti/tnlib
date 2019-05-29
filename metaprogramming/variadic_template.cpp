#include <iostream>
using namesapce std;


//
//  Variadic Template
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  Notes : 
  
  Variadic templates (C++11), also called template parameter
  pack, are templates that take a variable number of arguments of
  any type 
**/


template<typename... TArgs> // variadic typename
void f(TArgs... args) { // typename expansion
  args...; // arguments expansion
}

//Note: Variadic parameter must be the last one in the declaration
//The number of variadic arguments can be retrieved with the sizeof... operator
sizeof...(args);

//variadic template
template<typename T, typename R>
auto add(T a, R b) { // base case
  return a + b;
}

// recursive case
template<typename T, typename... TArgs> // variadic typename
auto add(T a, TArgs... args) { // typename expansion
  return a + add(args...); // parameters expansion
}

template<typename... TArgs>
void f(TArgs... args) {}


//Variadic Template Parameters
template<typename... TArgs>
void f(TArgs... args) {} // generic

template<typename... TArgs>
void g(const TArgs&... args) {} // force "const references"

template<typename... TArgs>
void h(TArgs*... args) {} // force "pointer"

// list of "pointers" followed by a list of "const references"
template<typename... TArgs1, typename... TArgs2>
void f2(const TArgs1*... args, const TArgs2& ...va) {}



//Variadic Template Parameters Recursion
template<typename T>
T square(T value) {
  return value * value;
}

template<typename T, typename... TArgs>
auto add(TArgs... args) {
  return (... + args);
}

template<typename... TArgs>
int add_square(TArgs... args) {
  return add(square(args)...); // square is applied to
} // variadic arguments




//Folding Expression
//C++17 Folding expressions perform a fold of a template parameter pack over a binary operator

//Unary folding
template<typename... Args>
auto add(Args... args) {
  return (... + args); // unfold: 1 + 2.0f + 3ull
}

//Binary folding
template<typename... Args>
auto add(Args... args) {
  return (1 + ... + args); // unfold: 1 + 1 + 2.0f + 3ull
}


//Variadic Template sizeof and sizeof...
template<typename... TArgs>
int count(TArgs... args) { // count number of arguments
  return sizeof...(args);
}

template<typename T, typename R>
auto add(T a, R b) { return a + b; }

template<typename T, typename... TArgs>
auto add(T a, TArgs... args) {
  return a + add(args...);
}

template<typename... TArgs>
int f(TArgs... args) { // get the sum of argument sizes
  return add(sizeof(args)...);
}




//Class Variadic Template
//Variadic Template can be used to build recursive data structures
template<typename... TArgs>
struct Tuple; // data structure declaration

template<typename T>
struct Tuple<T> { // base case
  T value; // specialization with one parameter
};

template<typename T, typename... TArgs>
struct Tuple<T, TArgs...> { // recursive case
  T value; // specialization with more
  Tuple<TArgs...> tail; // than one parameter
};


//Variadic Template and Meta-Programming
template<int... NArgs>
struct Add; // data structure declaration

template<int N1, int N2>
struct Add<N1, N2> { // base case
  static const int value = N1 + N2;
};

template<int N1, int... NArgs>
struct Add<N1, NArgs...> { // recursive case
  static const int value = N1 + Add<NArgs...>::value;
};





//Variadic Template and Class Specialization
template <typename T>
struct GetArity;

// generic function pointer
template<typename R, typename... Args>
struct GetArity<R(*)(Args...)> {
  static const int value = sizeof...(Args);
};

// generic function reference
template<typename R, typename... Args>
struct GetArity<R(&)(Args...)> {
  static const int value = sizeof...(Args);
};

// generic function object
template<typename R, typename... Args>
struct GetArity<R(Args...)> {
  static const int value = sizeof...(Args);
};

void f(int, char, double) {}





//Variadic Template and Class Specialization 
//Get operator() (and lambda) arity at compile-time:
template <typename T>
struct GetArity;

template<typename R, typename C, typename... Args>
struct GetArity<R(C::*)(Args...)> { // class member
  static const int value = sizeof...(Args);
};

template<typename R, typename C, typename... Args>
struct GetArity<R(C::*)(Args...) const> { // "const" class member
  static const int value = sizeof...(Args);
};

struct A {
  void operator()(char, char) {}
  void operator()(char, char) const {}
};





int main() {
  add(2, 3.0); // 5
  add(2, 3.0, 4); // 9
  add(2, 3.0, 4, 5); // 14
  // add(2); // compile error!!
  f(2); // ok, all parameters are variadic
  f(); // ok, all parameters are variadic

  //variadic template parameters
  f(1, 2.0);
  g(1, 2.0);
  int* a, *b;
  h(a, b);
  f2(a, b, 3);

  //Variadic Template Parameters Recursion
  add_square(2, 2, 3); // returns 17

  //folding expression : unary folding
  add(1, 2.0f, 3ll); // returns 6.0f (float)

  //folding expression : binary folding
  add(1, 2.0f, 3ll); // returns 7.0f (float)


  //Variadic Template sizeof and sizeof...
  count(2, 2.0, 'a'); // returns 3
  f(2, 2.0, 'a'); // returns 4 + 8 + 1 = 13 (int + double + char)


  //class variadic template
  Tuple<int, float, char> t1 { 2, 2.0, 'a' };
  t1.value; // 2
  t1.tail.value; // 2.0
  t1.tail.tail.value; // 'a'


  //Variadic Template and Meta-Programming
  Add<2, 3, 4>::value; // returns 9
// Add<2>::value; // compile error Add<> "empty"


  //Variadic Template and Class Specialization
  // function object
  GetArity<decltype(f)>::value;
  auto& g = f;
  // function reference
  GetArity<decltype(g)>::value;
  // function reference
  GetArity<decltype((f))>::value;
  auto* h = f;
  // function pointer
  GetArity<decltype(h)>::value;



  //Variadic Template and Class Specialization 
  //Get operator() (and lambda) arity at compile-time:
  GetArity<A>::value; // call GetArity<R(C::*)(Args...)>
  GetArity<const A>::value; // call GetArity<R(C::*)(Args...) const>


}
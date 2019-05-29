#include <iostream>
using namesapce std;


//
//  template metaprogramming
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  Notes : 

  • Template Meta-Programming is fast Template Metaprogramming is computed at compile-time
  (nothing is computed at run-time)
  
  • Template Meta-Programming is Turing Complete Template Metaprogramming is capable of expressing all tasks that
  standard programming language can accomplish
  
  • Template Meta-Programming requires longer compile time Template recursion heavily slows down the compile time, and
  requires much more memory than compiling standard code
  
  • Template Meta-Programming is complex Everything is expressed recursively. Hard to read, hard to write,
  and also very hard to debug  
**/



//Example 1: Factorial
template <int N>
struct Factorial { // specialization: recursive step
  static const int value = N * Factorial<N - 1>::value;
};

template <>
struct Factorial<0> { // specialization: base case
  static const int value = 1;
};

//The previous example can be easily written as a constexpr in C++14
template <typename T>
constexpr int factorial(T value) {
  T tmp = 1;
  for (int i = 2; i <= value; i++)
      tmp *= i;
  return tmp;
};

//Advantages:
//• Easy to read and write (easy to debug)
//• Faster compile time (no recursion)
//• Works with different types (typename T)





//Example 2: Log2
template <int N>
struct Log2 {
  static_assert(N > 0, "N must be greater than zero");
  static const int value = 1 + Log2<N / 2>::value;
};

template <>
struct Log2<1> { // partial specialization: base case
  static const int value = 0;
};



//Example 3: Log
template <int A, int B>
struct Max {
  static const int value = A > B ? A : B;
};

template <int N, int BASE>
struct Log { // specialization: recursive step
  static_assert(N > 0, "N must be greater than zero");
  static_assert(BASE > 0, "BASE must be greater than zero");
  static const int TMP = Max<1, N / BASE>::value;
  static const int value = 1 + Log<TMP, BASE>::value;
};

template <int BASE>
struct Log<1, BASE> { // partial specialization: base case
  static const int value = 0;
};








//Example 4: Unroll (Compile-time/Run-time Mix)
template<int MAX_VALUE, int STEP = 0>
struct Unroll { // recursive step
  template<typename Op>
  static void run(Op op) {
    op(STEP);
    Unroll<MAX_VALUE, STEP + 1>::run(op);
  }
};

template<int MAX_VALUE>
struct Unroll<MAX_VALUE, MAX_VALUE> { // base case (specialization)
  template<typename Op>
  static void run(Op) {}
};

struct MyOp {
void operator()(int step) { // Function call operator
  std::cout << step << ", ";
  }
};


int main() {
  int x = Factorial<5>::value; // 120
  // int y = Factorial<-1>::value; // Infinite recursion :)

  //Log2
  int x = Log2<20>::value; // 4


  //log
  int x = Log<20, 2>::value; // 4


  //unroll
  Unroll<5>::run( MyOp() ); // print 0, 1, 2, 3, 4
}






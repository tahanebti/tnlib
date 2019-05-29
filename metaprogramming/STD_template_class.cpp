#include <iostream>
using namesapce std;


//
//  STD Template Classes
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
  Notes :  - STD Template Utility  #include <utility>
    
    - std::pair : class couples together a pair of values, which may be of different types
    
    - std::tuple : is a fixed-size collection of heterogeneous values. 
                  It is a generalization of std::pair. It allows any number of values
    
    - std::variant : C++17 represents a type-safe union as the corresponding objects know which type is currently being held 
    
    - std::optional : C++17 provides std::optional facilities to represent potential ”no value“ states
    
    - std::any  : C++17 introduces std::any to hold arbitrary values and provides type-safety
**/


/*
  std::pair
  
  Construct a std::pair
    • std::pair<T1, T2> pair(value1, value2)
    • std::pair<T1, T2> pair = fvalue1, value2g
    • auto pair = std::make pair(value1, value2)
  Data members:
    • first access first field
    • second access second field
  Methods:
    • comparison ==, <, >, =<, >=
    • swap std::swap

*/

/*

  std::tuple

  Construct a std::tuple (of size 3)
    • std::tuple<T1, T2, T3> tuple(value1, value2, value3)
    • std::tuple<T1, T2, T3> tuple = fvalue1, value2, value3g
    • auto tuple = std::make tuple(value1, value2, value3)
  Data members:
    std:get<I>(tuple) returns the i-th value of the tuple
  Methods:
    • comparison ==, <, >, =<, >=
    • swap std::swap

  Utility methods:
  • auto t3 = std::tuple cat(t1, t2) 
    concatenate two tuples
  
  • const int size = std::tuple size<TupleT>::value
  returns the number of elements in a tuple at compile-time
  
  • using T = typename std::tuple element<TupleT>::type
  obtains the type of the specified element
  
  • std::tie(value1, value2, value3) = tuple
  creates a tuple of references to its arguments
  
  • std::ignore
  an object of unspecified type such that any value can be assigned
  to it with no effect

*/

std::tuple<int, float, char> f() { return {7, 0.1f, 'a'}; }



/*
  std::variant

  std::variant can be indexed by:
  • std::get<index>(variant) an integer
  • std::get<type>(variant) a type

*/

//std::variant + Visitor
//It is also possible to query the index at run-time depending on the
//type currently being held by providing a visitor  
struct Visitor {
void operator()(int& value) { value *= 2; }
void operator()(float& value) { value += 3.0f; } // <--
void operator()(bool& value) { value = true; }
};


/*
  std::optional 
  As an example, it can be used for representing the state when an
element is not found in a set
*/

std::optional<std::string> find(const char* set, char value) {
  for (int i = 0; i < 10; i++) {
    if (set[i] == value)
      return i;
  }
  return {}; // std::nullopt;
}

int main() {
  //std::pair
  using namespace std;
  std::pair<int, std::string> pair1(3, "abc");
  std::pair<int, std::string> pair2 = { 4, "zzz" };
  auto pair3 = std::make_pair(3, "hgt");
  cout << pair1.first; // print 3
  cout << pair1.second; // print "abc"
  swap(pair1, pair2);
  cout << pair2.first; // print "zzz"
  cout << pair2.second; // print 4
  cout << (pair1 > pair2); // print 1

  //std::tuple
  std::tuple<int, char, float> tuple1(3, 'c', 2.2f);
  std::tuple<int, char, float> tuple2 = {2, 'd', 1.5f};
  auto tuple3 = std::make_tuple(3, 'c', 2.2f);
  std::cout << std::get<0>(tuple1); // print 3
  std::cout << std::get<1>(tuple1); // print 'c'
  std::cout << std::get<2>(tuple1); // print 2.2f
  std::cout << (tuple1 > tuple2); // print 1
  auto concat = std::tuple_cat(tuple1, tuple2);
  std::cout << std::tuple_size<decltype(concat)>::value; // print 6
  using T = std::tuple_element<4, decltype(concat)>::type; // T is int
  int value1; float value2;
  std::tie(value1, value2, std::ignore) = f();


  //std::variant
  std::variant<int, float, bool> v(3.3f);
  int x = std::get<0>(v); // return integer value
  bool y = std::get<bool>(v); // return bool value
  // std::get<0>(v) = 2.0f; // run-time exception!!
  //Another useful method is index() which returns position of the type currently held by the variant
  cout << v.index(); // return 1
  std::get<bool>(v) = true
  cout << v.index(); // return 2

  //std::variant + Visitor
  std::visit(v, Visitor{});
  std::cout << std::get<float>(v); // 6.3f

  //std::optional
  char set[] = "sdfslgfsdg";
  auto x = find(set, 'a');
  
  if (!x)
    cout << "not found";
  
  if (x.has_value())
    cout << "not found";
  
  auto y = find(set, 'd');
  cout << *y << " " << y.value(); // print '1' '1'
  x.value_or(-1); // print '-1'
  x.value_or(-1); // print '1'


  //std::any
  std::any var = 1; // int
  cout << var.type().name(); // print 'i'
  cout << std::any_cast<int>(var);
  // cout << std::any_cast<float>(var); // exception!!
  var = 3.14; // double
  cout << std::any_cast<double>(var);
  var.reset();
  cout << var.has_value(); // print 'false'


}
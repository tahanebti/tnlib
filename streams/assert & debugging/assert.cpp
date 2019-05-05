//
//  assert
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>

using namespace std;

void foo(const char* msg)
{
  assert(msg != nullptr);  // or: assert(msg);
}

bool isZero(int number){
     //  assert (number == 0);
       return (number == 0)? true : false;
 }
bool isPositve(int number){
     //  assert(number >= 0);
  return (number >= 0)? true : false;
}

bool isNatural(int number){
    return (number >=1)? true : false;
}

bool isWhole(int number){
  return (number >= 0)? true : false;
}

bool isEven(int number){
  return (number % 2 == 0)? true : false;
}

bool isOdd(int number){
  return (number % 2 != 0)? true : false;
}


bool isNumberHex(const std::string& str){
   if(str == "") return false;
   return std::all_of(
              str.begin(),
              str.end(),
              [](char x){
                return std::isxdigit(x);
              });
 }





int main()
{
  foo("Test");  // OK
  foo(nullptr); // Triggers the assertion.


    cout<<"is zero : "<<isZero(10)<<endl;
  cout<<"is positive : "<<isPositve(-10)<<endl;
  
  static_assert(numeric_limits<int>::is_integer, " invalid_argument ");
  
  cout<<"is natural: "<<isNatural(0)<<endl;
  cout<<"is whole: "<<isWhole(1)<<endl;
  cout<<"is even : "<<isEven(1)<<endl;
  cout<<"is odd: "<<isOdd(3)<<endl;
  
}

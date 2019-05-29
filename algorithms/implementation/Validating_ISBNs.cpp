//
//  Validating ISBNs
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


//Write a program that validates that 10-digit values entered by the user, as a
//string, represent valid ISBN-10 numbers.

#include <bits/stdc++.h>
using namespace std;

bool validate_isbn_10(string isbn)
{
   auto valid = false;

   if (isbn.size() == 10 && std::count_if(std::begin(isbn), std::end(isbn), isdigit) == 10)
   {
      auto w = 10;
      auto sum = std::accumulate(
         std::begin(isbn), std::end(isbn), 0,
         [&w](int const total, char const c) {
            return total + w-- * (c - '0'); });

      valid = !(sum % 11);
   }

   return valid;
}

int main()
{
   assert(validate_isbn_10("0306406152"));
   assert(!validate_isbn_10("0306406151"));

   std::string isbn;
   std::cout << "isbn:";
   std::cin >> isbn;

   std::cout << "valid: " << validate_isbn_10(isbn) << std::endl;
}

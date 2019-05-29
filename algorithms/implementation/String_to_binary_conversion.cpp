//
//  String to binary conversion
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//



/**
    Write a function that, given a string containing hexadecimal digits as the
input argument, returns a vector of 8-bit integers that represent the
numerical deserialization of the string content. The following are
examples:

Input: "BAADF00D" or "baadF00D", output: {0xBA, 0xAD, 0xF0, 0x0D}
Input "010203040506", output: {1, 2, 3, 4, 5, 6}
**/

#include <bits/stdc++.h>
using namespace std;

unsigned char hexchar_to_int(char const ch)
{
   if (ch >= '0' && ch <= '9') return ch - '0';
   if (ch >= 'A' && ch <= 'F') return ch - 'A' + 10;
   if (ch >= 'a' && ch <= 'f') return ch - 'a' + 10;
   throw std::invalid_argument("Invalid hexadecimal character");
}

std::vector<unsigned char> hexstr_to_bytes(std::string str)
{
   std::vector<unsigned char> result;

   for (size_t i = 0; i < str.size(); i += 2)
   {
      result.push_back(
         (hexchar_to_int(str[i]) << 4) | hexchar_to_int(str[i+1]));
   }

   return result;
}

int main()
{
   std::vector<unsigned char> expected{ 0xBA, 0xAD, 0xF0, 0x0D, 0x42 };
   assert(hexstr_to_bytes("BAADF00D42") == expected);
   assert(hexstr_to_bytes("BaaDf00d42") == expected);
}

//
//  License plate validation
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//



/**
    Considering license plates with the format LLL-LL DDD or LLL-LL DDDD (where L
is an uppercase letter from A to Z and D is a digit), write:
  One function that validates that a license plate number is of the correct format
  
  One function that, given an input text, extracts and returns all the
license plate numbers found in the text

**/

#include <string>
#include <regex>
#include <assert.h>

bool validate_license_plate_format(std::string str)
{
   std::regex rx(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");
   return std::regex_match(str.data(), rx);
}

std::vector<std::string> extract_license_plate_numbers(std::string const & str)
{
   std::regex rx(R"(([A-Z]{3}-[A-Z]{2} \d{3,4})*)");
   std::smatch match;
   std::vector<std::string> results;

   for(auto i = std::sregex_iterator(std::begin(str), std::end(str), rx);
       i != std::sregex_iterator(); ++i)
   {
      if((*i)[1].matched)
         results.push_back(i->str());
   }

   return results;
}

int main()
{
   assert(validate_license_plate_format("ABC-DE 123"));
   assert(validate_license_plate_format("ABC-DE 1234"));
   assert(!validate_license_plate_format("ABC-DE 12345"));
   assert(!validate_license_plate_format("abc-de 1234"));

   std::vector<std::string> expected{"AAA-AA 123", "ABC-DE 1234", "XYZ-WW 0001"};
   std::string text("AAA-AA 123qwe-ty 1234  ABC-DE 123456..XYZ-WW 0001");
   assert(expected == extract_license_plate_numbers(text));
}

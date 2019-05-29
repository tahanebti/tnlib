//
//  Capitalizing an article title
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//



/**
    Write a function that transforms an input text into a capitalized version,
where every word starts with an uppercase letter and has all the other
letters in lowercase. For instance, the text "the c++ challenger" should be
transformed to "The C++ Challenger".

**/
#include <string>
#include <sstream>
#include <cctype>
#include <assert.h>

template <class Elem>
using tstring = std::basic_string<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
using tstringstream = std::basic_stringstream<Elem, std::char_traits<Elem>, std::allocator<Elem>>;

template <class Elem>
tstring<Elem> capitalize(tstring<Elem> const & text)
{
   tstringstream<Elem> result;

   bool newWord = true;
   for (auto const ch : text)
   {
      newWord = newWord || std::ispunct(ch) || std::isspace(ch);
      if (std::isalpha(ch))
      {
         if (newWord)
         {
            result << static_cast<Elem>(std::toupper(ch));
            newWord = false;
         }
         else
            result << static_cast<Elem>(std::tolower(ch));
      }
      else result << ch;
   }

   return result.str();
}

int main()
{
   using namespace std::string_literals;

   std::string text = "THIS IS an ExamplE, should wORk!";
   std::string expected = "This Is An Example, Should Work!";
   assert(expected == capitalize(text));

   assert(
          L"The C++ Challenger"s ==
          capitalize(L"the c++ challenger"s));

   assert(
      L"This Is An Example, Should Work!"s ==
      capitalize(L"THIS IS an ExamplE, should wORk!"s));
}

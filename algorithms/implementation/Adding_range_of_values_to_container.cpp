//
//  Adding a range of values to a container
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
    Write a general-purpose function that can add any number of elements to
the end of a container that has a method push_back(T&& value).
**/

#include <iostream>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <list>

template<typename C, typename... Args>
void push_back(C& c, Args&&... args)
{
   (c.push_back(args), ...);
}

int main()
{
   std::vector<int> v;
   push_back(v, 1, 2, 3, 4);
   std::copy(std::begin(v), std::end(v), 
             std::ostream_iterator<int>(std::cout, " "));

   std::list<int> l;
   push_back(l, 1, 2, 3, 4);   
   std::copy(std::begin(l), std::end(l), 
             std::ostream_iterator<int>(std::cout, " "));
}

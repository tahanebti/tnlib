//
//  std::adjasent_find 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


#include <iostream>
#include <algorithm>
#include <list>

/// adjacent_find
///
/// Returns: The first iterator i such that both i and i + 1 are in the range
/// [first, last) for which the following corresponding conditions hold: *i == *(i + 1).
/// Returns last if no such iterator is found.
///
/// Complexity: Exactly 'find(first, last, value) - first' applications of the corresponding predicate.
///

	namespace __tn
	{
        template <typename ForwardIterator>
        inline ForwardIterator adjacent_find(ForwardIterator first, ForwardIterator last)
        {
            if(first != last)
            {
                ForwardIterator i = first;

                for(++i; i != last; ++i)
                {
                    if(*first == *i)
                        return first;
                    first = i;
                }
            }
            return last;
        }
	}

int main()
{
    std::list<int> numbers = {10, 20, 30, 40, 40, 40, 50, 60, 60};
    //auto iter  = std::adjacent_find(numbers.begin(), numbers.end());
    auto iter  = __tn::adjacent_find(numbers.begin(), numbers.end());

    if(iter != numbers.end())
    {
        std::cout << "First item to occur twice: " << *iter << "\n";
    }

    iter = std::adjacent_find(iter, numbers.end());

    if(iter != numbers.end())
    {
        std::cout << "Second item to occur twice: " << *iter << "\n";
    }




    return 0;
}


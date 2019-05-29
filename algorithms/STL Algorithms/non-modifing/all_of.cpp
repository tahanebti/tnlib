//
//  std::all_of
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


#include <algorithm>
#include <iostream>
#include <set>
#include <list>

/// all_of
///
/// Returns: true if the unary predicate p returns true for all elements in the range [first, last)
///

namespace __tn
{
    template <typename InputIterator, typename Predicate>
	inline bool all_of(InputIterator first, InputIterator last, Predicate p)
	{
		for(; first != last; ++first)
		{
			if(!p(*first))
				return false;
		}
		return true;
	}
}



int main(int argc, char const *argv[])
{
    /* Returns 'true' if all of the elements passes truth test */
    std::set<unsigned> numbers = {3, 5, 7, 9, 1, 11};

    bool result = __tn::all_of(numbers.begin(), numbers.end(), [](const unsigned& number){
        return (number % 2 != 0);
    });

    std::cout <<  "All are primes ....? "  << std::boolalpha << result << "\n";

    numbers.emplace(2);
    result = __tn::all_of(numbers.begin(), numbers.end(), [](const unsigned& number){
        return (number % 2 == 0);
    });

    std::cout <<  "All are non-primes ....? "  << std::boolalpha << result << "\n";



    return 0;
}

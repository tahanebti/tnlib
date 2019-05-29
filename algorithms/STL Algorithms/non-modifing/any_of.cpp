//
//  std::any_of
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <set>
#include <map>

    /// any_of
	///
	/// Returns: true if the unary predicate p returns true for any of the elements in the range [first, last)
	///

namespace __tn
{
	template <typename InputIterator, typename Predicate>
	inline bool any_of(InputIterator first, InputIterator last, Predicate p)
	{
		for(; first != last; ++first)
		{
			if(p(*first))
				return true;
		}
		return false;
	}

}

int main(int argc, char const *argv[])
{
    std::set<std::string> languages = {"C", "C++", "Java", "JavaScript", "Python"};

    bool result = __tn::any_of(languages.begin(), languages.end(), [](const std::string& language){
        return (language.at(0) == 'O');
    });

    std::cout << "Any of the langauge begins with P ? " << std::boolalpha << result << "\n";



    return 0;
}


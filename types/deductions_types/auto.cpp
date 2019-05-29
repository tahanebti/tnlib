//
//  auto : the type of the variable
//		will be automatically deduced by the compiler 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


auto main() -> int
{
	auto a = 1 + 2; // 1 is int, 2 is int, 1 + 2 is int!
// -> 'a' must be int
auto b = 1 + 2.0; // 1 is int, 2.0 is double. 1 + 2.0 is double
// -> 'b' must be double
//auto keyword may be very useful for maintainability.
	for (auto i = k; i < size; i++)
		//...
//On the other hand, it may make the code less readable if
//excessively used because of type hiding
//Note: auto x = 0; in general makes no sense ( x is int)    
	return 0;
}

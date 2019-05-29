//
//  using and decltype 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


//In C++11, the using keyword has the same semantics of typedef
//specifier (alias-declaration), but with better syntax

typedef int distance_t; // equal to:
using distance_t = int;

auto main() -> int
{
	//In C++11, decltype captures the type of an object or an expression
	int a = 3;
	decltype(a) b = 5; // 'b' is int
	decltype(2.0f) c = 3.0f; // 'c' is float
	decltype(a + 2.0f) d = 3.0f; // 'd' is float
	decltype(f(a)) e = ...; // 'e' depends on f(a)
    
	using T = decltype(a); // T is int
	T value = 3;

	return 0;
}

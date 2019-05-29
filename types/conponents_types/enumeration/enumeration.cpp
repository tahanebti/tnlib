//
//  enumerator (enum) is a data type that groups a set of
//		named integral constants
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

enum color_t { BLACK, BLUE, GREEN = 2 };
/*
The problem:
	enum color_t { BLACK, BLUE, GREEN };
	enum fruit_t { APPLE, CHERRY };

	color_t color = BLACK; // int: 0
	fruit_t fruit = APPLE; // int: 0
	cout << (color == fruit); // print 'true'!!
	// and, most importantly, does the match between a color and
	// a fruit makes any sense?
*/

//C++11 introduces a type safe enumerator enum class (scoped enum)
// data type that are not implicitly convertible to int

enum class color_t { BLACK, BLUE, GREEN = 2 };
enum class fruit_t { APPLE, CHERRY };
color_t color = color_t::BLUE;
fruit_t fruit = fruit_t::APPLE;
// cout << (color == fruit); // compile error!!


//Strongly typed enumerators can be compared
enum class Colors { RED = 1, GREEN = 2, BLUE = 3 };
cout << (Colors::RED < Colors::GREEN); // print true

//The size of enum class can be set
#include <cstdint>
enum class Colors : int8_t { RED = 1, GREEN = 2, BLUE = 3 };

auto main() -> int
{
	color_t color = BLUE;
	cout << (color == BLACK);

	return 0;
}

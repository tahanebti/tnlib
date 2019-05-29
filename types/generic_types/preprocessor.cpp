//
//  Preprocessing and Macro 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


/*
	Preprocessor directives are lines preceded by a hash sign (#)
	which tell the compiler how to interprets the source code before
	compiling

	Macro are preprocessor directives which replace any occurrence of
	an identifier in the rest of the code by replacement
*/

# define MIN(a, b) ((a) < (b) ? (a) : (b))

# define SIZE 3 // replaced with
const int SIZE = 3; // only C++11 at global scope

# define SUB(a, b) ((a) - (b)) // replaced with
constexpr int sub(int a, int b) {
return a - b;
}	

//macro trics 

//Convert a number literal to a string literal
# define TO_LITERAL_AUX(x) #x
# define TO_LITERAL(x) TO_LITERAL_AUX(x)


//Find the size offset of a field inside a structure:
# define FIELD_OFFSET(structure, field) \
			reinterpret_cast<size_t>(   \
 	&((reinterpret_cast<structure*>(0))->field) )

//Get the size of an arbitrary type without using sizeof
# define MY_SIZE(type, ret) \
{ type x; ret = reinterpret_cast<char*>(&x + 1) - \
reinterpret_cast<char*>(&x); }

auto main() -> int
{

	//Commun used macro
	/*
	Commonly used macros:
	__LINE__ Integer value representing the current line in the source
	code file being compiled
	
	__FILE__ A string literal containing the presumed name of the source
	file being compiled
	
	__DATE__ A string literal in the form ”MMM DD YYYY” containing
	the date in which the compilation process began
	
	__TIME__ A string literal in the form ”hh:mm:ss” containing the time
	at which the compilation process began
	*/

//Motivation: avoid integer to string conversion (performance)
	int x1 = 3 * 10;
	int y1 = __LINE__ + 4;
	char x2[] = TO_LITERAL(3);
	char y2[] = TO_LITERAL(__LINE__);


struct A {
	int a;
	float b;
};
std::cout << FIELD_OFFSET(A, b); // print 4
int size;
MY_SIZE(A, size); // size = 8

	return 0;
}

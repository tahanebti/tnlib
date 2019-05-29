//
//  floating points 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**

In general, C/C++ adopt IEEE754 floating-point standard
• Single precision (32-bit) (float)
	Sign 		Exponent (or base) 		Mantissa (or significant)
	1-bit 		8-bit 					23-bit



• Double precision (64-bit) (double)
	Sign 		Exponent (or base) 		Mantissa (or significant)
	1-bit 		11-bit 					52-bit



In IEEE 754 floating point numbers, the exponent value is offset
from the actual value by the exponent bias
	• The exponent is stored as an unsigned value suitable for comparison
	• Floating point values are lexicographic ordered
	• For a single-precision number, the exponent is stored in the range [1, 254] 
		(0 and 255 have special meanings), and is biased by subtracting 127 to get an 
		exponent value in the range [−126, +127]
	• Example
		0 	10000111 				11000000000000000000000
		+ 	2^(135−127) = 28 		1/2^1 + 1/2^2 = 0.5+0.25 = 0.75 normal 1.75
											+1.75 * 28 = 448.0 31
**/

#include <bits/stdc++.h>
#include <limits>

using namespace std;


bool areFloatNearlyEqual(float a, float b) {
	if (std::abs(a - b) < epsilon); // epsilon is fixed by the user
		return true
	return false;
}

/*
Problems:
	• Fixed epsilon “looks small” but, it could be too large when the numbers
		being compared are very small
	• If the compared numbers are very large, the epsilon could end up being
	smaller than the smallest rounding error, so that the comparison always
	returns false
*/


//Solution: Use relative error |a−b| / b < EPS"
bool areFloatNearlyEqual(float a, float b) {
	if (std::abs(a - b) / b < epsilon); // epsilon is Fixed
		return true
	return false;
}

/*
Problems:
	• a=0, b=0 The division is evaluated as 0.0/0.0 and the whole if
	statement is (nan < espilon) which always returns false
	• b=0 The division is evaluated as abs(a)/0.0 and the whole if statement
	is (+inf < espilon) which always returns false
	• a and b very small. The result should be true but the division
	by b may produces wrong results
	• It is not commutative. We always divide by b

*/


//Possible solution: |a−b| / max(|a|,|b|) < EPS"
bool areFloatNearlyEqual(float a, float b) {
	const float epsilon = <user_defined>
	if (a == b) // a=0,b=0 and a = ±1, b = ±1
		return true;
	
	if (std::isnan(a) || std::isnan(b)) // optional
		return false;
	float abs_a = std::abs(a);
	float abs_b = std::abs(b);
	float diff = std::abs(a - b);
	return (diff / std::max(abs_a, abs_b)) < epsilon; // relative error
}

//Machine epsilon " (or machine accuracy) is defined to be the
//smallest number that can be added to 1.0 to give a number other
//than one
//IEEE 754 Single precision : " = 1.17549435 * 10^−38

T std::numeric_limits<T>:: epsilon() // returns the machine epsilon


int main()
{
	//The floating point precision is finite!
	cout << setprecision(20);
	cout << 3.33333333f; // print 3.333333254!!
	cout << 3.33333333; // print 3.333333333
	cout << (0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
	// print 0.59999999999999998

	//Floating point arithmetic is commutative, but not associative and not reflexive (see NaN) !!
	cout<< 0.1 + (0.2 + 0.3) == (0.1 + 0.2) + 0.3; // print false


	//Floating point type has special values (C++11):
	std::numeric_limits<float>::infinity; // float infinity
	std::numeric_limits<float>::quiet_NaN; // float NaN
	
	// Check if the actual C++ implementation adopts the IEEE754 standard:
	std::numeric_limits<float>::is_iec559; // should return true
	std::numeric_limits<double>::is_iec559; // should return true

	INFINITY // float infinity
	NAN // float NaN

	cout << 0 / 0; // undefined behavior
	cout << 0.0 / 0.0; // print "nan"
	cout << (-0.0 == 0.0); // true
	cout << 5.0 / 0.0; // print "inf"
	cout << -5.0 / 0.0; // print "-inf"
	cout << ((5.0 / 0.0) == ((5.0 / 0.0) + 9999999.0); // true
	cout << ((5.0f / INFINITY) == ((-5.0f / INFINITY)); // true


	// std::ceil((float) 101 / 2.0f) -> 50.5f -> 51
	float x = std::ceil((float) 20000001 / 2.0f);	

	return 0
}

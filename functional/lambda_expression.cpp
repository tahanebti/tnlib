//
//  lambda expression
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

/**
	Notes : 

	Lambda expression syntax:
	[capture clause] (parameters) f body g
	• The brackets [] mark the declaration of the lambda and
	how the local scope arguments are captured (by-value,
	by-reference, etc.)
	• The parameters of the lambda are normal function
	parameters (optional)
	• The body of the lambda is a normal function body


	Capture Lists
	Lambda expressions capture external references/variables in two ways:
		• Capture by copy
		• Capture by reference (can modify external variable values) Capture list can be passed as follows
		• [] captures nothing
		• [=] captures all variables used in the body of the lambda by copy
		• [&] captures all variables used in the body of the lambda by reference
		• [var1] captured only var1 by copy
		• [&var2] captured only var2 by reference
	Capture List Other Cases : 
		• [var1, &var2] captured var1 by copy and var2 by reference
		• [=, &var1] captures all variables used in the body of the lambda by copy, except var1 that is captured by reference
		• [&, var1] captures all variables used in the body of the lambda by reference, except var1 that is captured by value
		• A lambda expression can read a variable without capturing it if the variable is a constexpr

	Capture List and Classes: 
		• [this] capture the current object (*this) by reference
		• [var = var] capture the current object member var by copy C++14
		• [&var = var] capture the current object member var by reference C++14	
**/

//functor
struct Unary { // equivalent to lambda2, lambda4
	int _limit;
	Unary(int limit) : _limit(limit) {}
	bool operator()(int value) const { // lambda expr. are const
		return value > _limit;
	};
};


//Capture list and class
class A {
	int data = 1; // <--
	void f() {
		int var = 2; // <--
		// return 3 (nearest scope)
		auto lambda1 = [=]() { int var = 3; return var; };
		// return 2 (nearest scope)
		auto lambda2 = [=]() { return var; };
		auto lambda3 = [this]() { return data; }; // copy by reference
		auto lambda3 = [*this]() { return data; }; // copy by value (only C++17)
		// auto lambda4 = [data]() { return data; }; // compile error (not visible)
		auto lambda5 = [data = data]() { return data; }; // return 1
	}
};


//C++17 Lambda expression supports constexpr
constexpr int f() {
	auto lambda = [](int value) { return value * 2 };
	return lambda(3); // 6
}

int main() {
	std::vector<int> vector { 7, 2, 9, 4 };
	int limit = 5;
	// auto lambda1 = [](int value) { return value > limit; }; // error
	auto lambda2 = [=](int value) { return value > limit; }; // by value
	auto lambda3 = [&](int value) { return value > limit; }; // by ref
	auto lambda4 = [limit](int value) { return value > limit; }; // by value
	auto lambda5 = [&limit](int value) { return value > limit; }; // by ref
	
	std::remove_if(vector.begin(), vector.end(), lambda5);

	//list other cases
	constexpr int limit = 5;
	int var1 = 3, var2 = 4;
	auto lambda1 = [](int value) { return value > limit; };
	auto lambda2 = [=, &var3](int value) {
	return var1 + value > var2 + var3;

	//Lambda expression parameters
	auto lambda1 = [](int value) { return value + 4; };
	auto lambda2 = [](int value) { return value * 2; };
	auto lambda3 = [&](int value) { return lambda2(lambda1(value)); };
	// returns (value + 4) * 2

	//lambda + constexpr
	constexpr auto lambda = [](int value) constexpr {
		return value + 4;
	};

	constexpr int v1 = lambda(1); // '4'
	constexpr int v2 = f(); // '6'


	//mutable specifier allows the lambda to modify the parameters captured by copy
	int var1 = 1;
	auto lambda1 = [&]() { var1 = 4; };
	std::cout << lambda1() << ", " << var1; // print 4, 4
	int var2 = 1;
	// auto lambda2 = [=]() { var2 = 4; }; // compile error
	// lambda operator() is const
	auto lambda3 = [=]() mutable { var2 = 4; };
	lambda3();
	std::cout << var2; // print 4

}		
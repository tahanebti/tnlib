//
//  functional_callback_using_std::map
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
	#include <iostream>
	#include <functional>
	#include <string>
	#include <map>

	//A normal function
	int add(int lhs, int rhs)
	{
		return lhs + rhs;
	}

	//Function Object or Functor
	struct substractor
	{
		int operator()(int lhs, int rhs)
		{
			return (lhs < rhs) ? (rhs - lhs) : (lhs - rhs);
		}
	};

	//A named lambda
	auto divide = [](int lhs, int rhs)-> int {
		return lhs/rhs;
	};

	int modulus(int numerator, int denominator)
	{
		return numerator % denominator;
	}

	int main()
	{
		substractor sub;
		int (*functionPointerToModulus)(int, int) = modulus;

	    std::map<std::string, std::function<int(int,int)>> functionTable;

	    functionTable.insert({"+", add}); //Inserting normal function
	    functionTable.insert({"-", sub}); //Inserting function-object 
	    functionTable.insert({"*", [](int lhs, int rhs)-> int { return lhs * rhs; } }); //Inserting unnamed lambda
	    functionTable.insert({"/", divide}); //Insertig named lambda
	 	functionTable.insert({"%", functionPointerToModulus}); //Inserting function pointer

	    std::cout << "Addition:       " << functionTable["+"](10,20) << std::endl;
	    std::cout << "Substraction:   " << functionTable["-"](40,30) << std::endl;
	    std::cout << "Multiplication: " << functionTable["*"](50,60) << std::endl;
	    std::cout << "Division:       " << functionTable["/"](80,20) << std::endl;
	    std::cout << "Modulus:        " << functionTable["%"](14,10) << std::endl;

		return 0;
	}
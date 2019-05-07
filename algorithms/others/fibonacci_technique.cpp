//
//	fibonacci technique
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

//-------------------------------------------------------------------------------------------------
//Method №1 - Use recursion
size_t fibonacci_1(size_t numb);

//Method №2 - Use Dynamic Programming
size_t fibonacci_2(size_t numb);

//Method №3 - Use the mathematical method
size_t fibonacci_3(size_t numb);

//Method №4 - Use result memory
size_t fibonacci_4(size_t numb);

//Method №5 - Use matrix algebra
size_t fibonacci_5(size_t numb);

//-------------------------------------------------------------------------------------------------
int main()
{
	std::cout << fibonacci_1(8) << std::endl;
	std::cout << fibonacci_2(8) << std::endl;
	std::cout << fibonacci_3(8) << std::endl;
	std::cout << fibonacci_4(50) << std::endl;

	std::cin.get();
    return 0;
}
//-------------------------------------------------------------------------------------------------
size_t fibonacci_1(size_t numb)
{
	return numb > 3 ? fibonacci_1(numb - 1) + fibonacci_1(numb - 2) : 1;
}
//-------------------------------------------------------------------------------------------------
size_t fibonacci_2(size_t numb)
{
	std::vector<size_t> fib = { 0, 1 };

	for (size_t i = 2; i < numb; ++i)
	{
		fib.push_back(fib[i - 1] + fib[i - 2]);
	}
	return fib.back();
}
//-------------------------------------------------------------------------------------------------
size_t fibonacci_3(size_t numb)
{
	const double sqrt5 = std::sqrt(5);
	const double phi = (sqrt5 + 1) / 2;
	return static_cast<int>(std::pow(phi, numb - 1) / sqrt5 + 0.5);
}
//-------------------------------------------------------------------------------------------------
size_t fibonacci_4(size_t numb)
{
	static std::vector<size_t> fib = { 0, 1 };
	
	if (numb <= 3)
	{
		fib.push_back(1);
	}
	else
	{
		fib.push_back(fibonacci_4(numb - 1) + fibonacci_4(numb - 2));
	}
	return fib.back();
}
//-------------------------------------------------------------------------------------------------
size_t fibonacci_5(size_t numb)
{
	return 0;
}
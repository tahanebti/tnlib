//
//  Wild and Dangling Pointers
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

auto main() -> int
{
//wild pointer
{
	int* ptr; // wild pointer: Where will this pointer points?
	//... // solution: always initialize a pointer
}

//dangling pointer
{
	int* array = new int[10];
	delete[] array; // ok -> "array" now is a dangling pointer
	delete[] array; // double free or corruption!!
	// program aborted, the value of "array" is not null


	//solution
	array = nullptr; // no more dagling pointer
	delete[] array; // ok, no side effect

}    


	return 0;
}

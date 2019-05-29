//
//  range loop
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


auto main() -> int
{

//C++11 introduces the range loop to simplifies the verbosity of
//traditional for loop constructs. They are equivalent to the for
//loop operating over a range of values

	for (int v : { 3, 2, 1 }) // INITIALIZER LIST
		cout << v << " "; // print: 3 2 1
	
	for (auto c : "abcd") // RAW STRING
		cout << c << " "; // print: a b c d
	
	int values[] = { 3, 2, 1 };
	for (int v : values) // ARRAY OF VALUES
		cout << v << " "; // print: 3 2 1
	
	char letters[] = "abcd";
	for (auto c : letters) // ARRAY OF CHARS
		cout << c << " "; // print: a b c d


//C++17 extends the concepts of range loop for structure binding
struct A {
	int x;
	int y;
};
A array[10] = { {1,2}, {5,6}, {7,1} };
for (auto [x, y] : array)
	cout << x << "," << y << " "; // print: 1,2 5,6 7,1  

	return 0;
}

//
//  switch
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

//C++ switch can be defined over int, char, enum class, enum, etc.
int f(char x) {
	int y;
	swicth (x) {
		case 'a': y = 1; break;
		default: return -1;
	}
return y;
}

int f(MyEnum x) {
	int y = 0;
	swicth (x) {
		case MyEnum::A: // fallthrough
		case MyEnum::B: // fallthrough
		case MyEnum::C: return 0;
	default: return -1;
}
}

auto main() -> int
{


	return 0;
}

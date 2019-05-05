/*
*	Mathematics, Algorithms & Data structures
*   Author : Taha Nebti
*   Github : github.com/tahanebti

	elementary Math function <math.h>:
			abs(x)  : compute the absolut value of number x
			fabs(x) : compute the absolut value of floating point x

			signbit(x) : check if the given number is negative
*/
#include <bits/stdc++.h>
using namespace std;
int absolut_val(int number){
	if(number == 0) return 0;
	return (number>0)? number : -number;
}
//using bitwise operator
int abs_bitwise(int number){
	return (number>>30 | 1) * number;
}
int main()
{
	cout<<signbit(+0.0)<<endl;  //0
	cout<<signbit(-0.0)<<endl;  //128
	cout<<abs(+3.0)<<endl;  			//3
	cout<<abs(-3.0)<<endl;  			//3

	cout<<absolut_val(+3.0)<<endl;  	//3
	cout<<absolut_val(-3.0)<<endl;  	//3

	cout<<abs_bitwise(3.0)<<endl;  		//3
	cout<<abs_bitwise(-3.0)<<endl;  	//3
	return 0;
}

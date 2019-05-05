/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti

*		Smallest & Greatest digit
*/
#include <bits/stdc++.h>
using namespace std;

int smallest_digit(int number){
	int min_digit = number % 10; //asume that last digit is the small
	while(number){
		min_digit = (min_digit > number%10) ? number%10 : min_digit;
		number /=10;
	}
	return min_digit;
}

int greatest_digit(int number){
	int max_digit = number % 10; //asume that last digit is the bigger
	while(number){
		max_digit = (max_digit < number%10) ? number%10 : max_digit;
		number /=10;
	}
	return max_digit;
}

int main()
{
    int number = 723456;
    cout<<smallest_digit(number)<<endl;
    cout<<greatest_digit(number)<<endl;
    return 0;
}

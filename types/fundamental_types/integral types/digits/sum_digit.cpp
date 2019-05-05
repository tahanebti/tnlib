/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*/

/*
	sum digit of a given number
*/

#include <bits/stdc++.h>
using namespace std;

int sum_digit(int number){
	int sum = 0;
	while(number != 0){
		sum += number % 10;
		number /=10;
	}
	return sum;
}

//sum of digit using recursion
int sum_digit2(int number){
	if(number == 0) return 0;
	return (number%10) + sum_digit2(number/10);
}

int main()
{
    int number = 123456;
    cout<<sum_digit(number)<<endl;
    return 0;
}

/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*/

#include <bits/stdc++.h>
using namespace std;
/*

Ex : count digit og a given number

N.B
	 number % 10 -> get the last digit
 	 number / 10 -> remove the last digit
*/
int count_digit1(int number){
	int count = 0;
	while(number != 0){
		int rem = number % 10;
		count++;
		number /=10;
	}
	return count;
}

//count digit using recursion
int count_digit2(int number){
	//base cases
	if(number == 0) return 0;
	return 1 + count_digit2(number/10);
}


int count_digit3(int number){
	return ceil(log(number) / log(10));
}

int main()
{

    int number = 123456;
    cout<<count_digit3(number)<<endl;

    return 0;
}

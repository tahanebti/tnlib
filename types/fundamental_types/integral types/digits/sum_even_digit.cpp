/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*/


/*
		Sum of even digit of a given number
*/
#include <bits/stdc++.h>
using namespace std;

int sum_even_digit(int number){
	if(number == 0) return 0;
    int sum_even_digit = 0;
	while(number !=0){
	    int digit = number % 10;
        if(digit % 2 == 0)
            sum_even_digit += number % 10 ;
            number /=10;
	}
	return sum_even_digit;
}

int main()
{
    int number = 123456;
    cout<<sum_even_digit(number)<<endl;
    
    return 0;
}

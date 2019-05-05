/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*/

/*
*
/*
*
* 		Digital root (iterated digit sum, repeated digital sum)
* 		The single digit value obtained by an iterative process of summing digits,
* 		on each iteration using the result from the previous iteration to compute a digit sum.
* 		The process continues until a single-digit number is reached.
* 		https://en.wikipedia.org/wiki/Digital_root
*
* 		Example: 65,536 is 7, because 6 + 5 + 5 + 3 + 6 = 25 and 2 + 5 = 7
*
*
*/

#include <bits/stdc++.h>
using namespace std;

int sum_digit(int number){
	if(number == 0) return 0;
    int sum = 0;
	while(number !=0){
		sum += number % 10;
		number /=10;
	}
	return sum;
}

int digitalRoot(int number){
    while (number >= 10) {
        number = sum_digit(number);
    }
 	return number;
}


int main()
{
    unsigned long number = 123456;
    printf("Sum of digit is-----> %d\n", sum_digit(number));
    printf("digitalRoot of digit is-----> %d", digitalRoot(number));
    return 0;
}

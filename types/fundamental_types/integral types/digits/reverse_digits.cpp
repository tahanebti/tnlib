/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*/


/*
*
*		Reverse digit of number
*
*
*/

#include <bits/stdc++.h>
using namespace std;

int count_digit(int number){
    int count_digit = 0;
    while(number !=0){
        count_digit++;
		number /=10;
    }
    return count_digit;
}

int main()
{   int number = 103406;
    int size_a = count_digit(number);
    int a[size_a] , i=0;
    while(number !=0){
        a[i] = number % 10;
        number/=10;
        i++;
    }

    for(int i=0; i<size_a; ++i){
        cout<<a[i]<<" ";
    }
    return 0;
}

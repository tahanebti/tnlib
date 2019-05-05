/*
*
*       Lib Mathematics, Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*
*/
#define _CRT_SECURE_NO_WARNINGS
/*
*
*       Check number is_divisible_by_3 if sum of all digit is divible by 3
*
*/


#include <bits/stdc++.h>
using namespace std;

bool is_divisible_by_3(int number){
    int sum = 0;
    while(number !=0){
        int rem = number % 10;
        sum += rem;
        number/=10
    }
    return (sum % 3 == 0) ? true : false;
}

int main()
{
    int a = 32151;
    cout<<is_divisible_by_2(a)<<endl;
    cout<<is_divisible_by_2(b)<<endl;

return 0;
}

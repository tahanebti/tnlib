/*
*       Lib Mathematics, Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti

       push digit of a given number into an array in a reverse order 
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
{
    int number = 123456;
    int len = count_digit(number);
    int a[len]= {0};
    int i=0;
    for (int i = 0; i < len; ++i)
    {
        //a[i] = number % 10;           //6 5 4 3 2 1
        a[len-i-1] = number % 10;       //1 2 3 4 5 6 
        number/=10;
    }
    for(int i=0; i<len; ++i){
        cout<<a[i]<<" ";
    }
    return 0;
}

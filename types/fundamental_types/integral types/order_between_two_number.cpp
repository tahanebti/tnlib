/*
*	Mathematics, Algorithms & Data structures
*   Author : Taha Nebti
*   Github : github.com/tahanebti
*/


#include <iostream>

using namespace std;

void order(int a, int b){
    if(a - b > 0) cout<<a<<" is greater then "<<b<<endl;
    if(a - b == 0) cout<<a<<" is equal to "<<b<<endl;
    if(a - b < 0) cout<<a<<" is less then "<<b<<endl;
}

int max_two_value(int a, int b){
    return (a > b) ? a : b;
}


int main()
{
   int a = 15, b = 5;
   order(a,b);
   cout<<"Max is : "<<max_two_value(a,b)<<endl;
    return 0;
}

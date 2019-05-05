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
*       Even or odd 
*           check if number is divisible by 2 is even  
*           else is odd
*
*       The time and date Sat Feb 10 11:54:14 2018
*       Runtime : 4.175
*
*       -> Mod operator is slow and it very bad when using for a bignumber-> sometimes problem solution depends on the equation
*        a % b = a - b * [a/b]  
*        7 % 3 = 3 - 3 * 2 = 1
*
*/


#include <bits/stdc++.h>
using namespace std;

void fast()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
//  freopen("input.txt", stdin);
//  freopen("output.text", stdout);
#endif

    time_t now = time(NULL);
    cout<<"The time and date "<<asctime(gmtime(&now))<<endl;
}

int modulo(int a, int b){
    return a - b * (a/b);
}

int main()
{
    fast();
    int n;
    cin>>n;

    if(n%2== 0)
        cout<<"even"<<endl;
    else
        cout<<"odd"<<endl;
    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;

    //without using mod operator
    if(modulo(n,2) == 0)
        cout<<"even"<<endl;
    else
        cout<<"odd"<<endl;
    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;


return 0;
}

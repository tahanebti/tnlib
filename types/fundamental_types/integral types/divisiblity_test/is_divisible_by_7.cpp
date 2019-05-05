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
*       Check number is_divisible_by_7 if substruct 2 time the last digit from
*       the rest give multiple of 7
*       Ex : 483 = 48 - (3*2) = 48 - 6 = 42 = 7 * 6
*
*           n = a*b         -> a is a multiple of b
*           a = n / b       -> n is divisible by b is r = 0 (even)
*           set of 7 = {1,2,3,4,5,6}
*
*           42 = 7*6        -> 6 is a multiple of 7
*           6 = 42 / 7      -> 42 is divisible by 7 (n % 7 == 0)
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

int main()
{
    fast();
    int n;
    cin>>n;

    int last_digit = n % 10;
    int rest_of_number = n / 10;
    int ans = rest_of_number - (last_digit * 2);

    if(ans % 7 == 0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;

return 0;
}

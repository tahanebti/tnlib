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
*       Check number is_divisible_by_6 if sum all digit is divisible by 3
*       and last digit is even
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


int sum_digit(int n){
    int sum=0;
    for (int i = 0; i < n; ++i)
    {
        sum+=i%10;
        n/=10;
    }
    return sum;
}

int main()
{
    fast();
    int n;
    cin>>n;
    int sum = sum_digit(n);

    //if(is_divisible_by_3(n) && is_divisible_by_2(n) )
    if( sum%3 == 0 && (n%10) % 2 == 0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;

return 0;
}

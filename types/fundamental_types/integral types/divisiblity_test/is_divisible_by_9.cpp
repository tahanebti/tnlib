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
*       Check number is_divisible_by_9 if sum of all digit is divisible by 9
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

int sum_digit(int n){
    int sum = 0;
    for (int i = 0; i < n; ++i)
    {
        sum += i%10;
        n/=10;
    }
    return sum;
}


int main()
{
    fast();
    int n;
    cin>>n;
    int sum = sum_digit(n)
    if((sum % 9 == 0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;

return 0;
}

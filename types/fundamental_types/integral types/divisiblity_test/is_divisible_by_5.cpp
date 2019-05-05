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
*       Check number is_divisible_by_5 if last digit is 0 or 5
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

    if( n%10 == 0 || n%10==5)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;

return 0;
}

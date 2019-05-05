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
*       Check number is_divisible_by_11 if numbers of digit is even 
*       add the first digit and substruct the last from the rest
*       result must bz divisible by 11
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
    
    //first_digit = n / pow(10, sum)
    while(n>=10){
        int firs_digit/=10;
    }
    cout<<firs_digit<<endl;
    cout<<last_digit<<endl;
    int rest_of_number = n / 10;
    cout<<rest_of_number<<endl;
    int ans = rest_of_number + firs_digit - last_digit;
        if(ans % 11 == 0)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;

    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;

return 0;
}

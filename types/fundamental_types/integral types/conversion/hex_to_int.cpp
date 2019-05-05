/*
*
*       Lib Mathematics, Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*
*/
#define _CRT_SECURE_NO_WARNINGS
/*
*       Convert hex to int
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

int hex_to_int(char c){
    if(c >= '0' && c <= '9')
        return c - '0';         //convert char to digit
    if(c >= 'A' && c <= 'Z')
        return (10 + c - 'A');   //convert upper Char to int
    if(c >= 'a' && c <= 'z')
        return (10 + c - 'z');   //convert lower Char to int
   return -1;
}

int main()
{
    fast();

    char c = 'A';
    cout<<hex_to_int(c);

    cerr<<"Runtime : "<<double(clock()-1) / CLOCKS_PER_SEC <<endl;

return 0;
}

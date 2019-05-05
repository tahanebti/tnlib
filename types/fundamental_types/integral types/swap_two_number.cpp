/*
*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*
*/
#define _CRT_SECURE_NO_WARNINGS
/*
*
*       swap two number
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
//	freopen("input.txt", stdin);
//	freopen("output.text", stdout);
#endif

    time_t now = time(NULL);
	cout<<"The time and date "<<asctime(gmtime(&now))<<endl;
}



int main()
{
    fast();
    int a, b;
    cin>>a>>b;
    cout<<"First Value : "<<a<<" "<<"Second Value : "<<b<<endl;
    int temp = a;
    a = b;
    b = temp;
    cout<<"First Value : "<<a<<" "<<"Second Value : "<<b<<endl;

    cerr<<"Time Complexity : "<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

return 0;
}

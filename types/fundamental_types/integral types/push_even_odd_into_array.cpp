/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*
*
*/

#include <bits/stdc++.h>
using namespace std;

const int n = 10;
/*
Ex : push all number into array in range[0 .. n]
*/
int push_number(int *a, const int n){
	for (int i = 0; i < n; ++i)
	{
		a[i] = i;
	}
}
/*
Ex : push even number into array in range[0 .. n]
*/
int push_even(int *a, const int n){
	for (int i = 0; i < n; ++i)
	{
		a[i] = 2*i;
	}
}
/*
Ex : push odd number into array in range[0 .. n]
*/
int push_odd(int *a, const int n){
	for (int i = 0; i < n; ++i)
	{
		a[i] = 2*i + 1;
	}
}


int main()
{
	int a[n] = {0};

	push_odd(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout<<a[i]<<" ";
	}
    cout<<endl;

    return 0;
}

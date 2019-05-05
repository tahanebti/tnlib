/*
*       Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*/



#include <bits/stdc++.h>
using namespace std;


void srand_seed(){
	srand((unsigned)time(0));
}

int rand_int(int a, int b){
	return rand()  % (b-a) + 1;
}

const int n = 10;
int a[n];

int main()
{

    srand_seed();

    for(int i=0; i<n; ++i){
        a[i] = rand_int(1, 10);
    }
    
    for(int i= 0;i<n;++i){
        cout<<a[i]<<" ";
    }
    cout<<endl;


return 0;
}

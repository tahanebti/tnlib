//
//  stack vs heap
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#define _CRT_SECURE_NO_WARNINGS

/*
*
*		Stack (Static allocation)  vs heap (dynamic allocation ) 
*          Runtime using Stack  : 0.013   
*          Runtime using heap   : 0.389   
*    Stack is contiguous area of memory : constant time O(1) to access to any elements            
*    heap is not contiguous and it access to elements by using pointer 
*
*       The time and date Fri Feb 09 14:40:50 2018
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

    void on_stack(){
    int i;
    }

    void on_heap(){
        int* i = new int;
        delete i;
    }

int main()
{
    fast();
   
   for(int i = 0; i<1000000; ++i){
    on_stack();
   }
   cerr<<"Runtime using Stack: "<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;


   for(int i = 0; i<1000000; ++i){
    on_heap();
   }
   cerr<<"Runtime using heap: "<<double(clock()-1)/ CLOCKS_PER_SEC<<endl;

    return 0;
}

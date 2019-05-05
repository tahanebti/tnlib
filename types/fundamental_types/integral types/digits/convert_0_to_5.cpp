/*
* 		Lib Mathematics, Algorithms & Data structures
*		Author : Taha Nebti
*		github : github.com/tahanebti
*/


/*
		Convert digit 0 to 5 
*/

#include <bits/stdc++.h>
using namespace std;

int convert_0_to_5(int number){
	if(number == 0) return 0;
    int digit = number % 10;
	
	while(number !=0){
        if(digit == 0)
            digit = 5;
        return convert_0_to_5(number/10)*10 + digit;
	}

}

int main()
{
    int number = 103400;
    cout<<convert_0_to_5(number)<<endl;

    return 0;
}

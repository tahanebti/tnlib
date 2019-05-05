/*
*	Mathematics, Algorithms & Data structures
*   Author : Taha Nebti
*   Github : github.com/tahanebti

		Branching logic

		Relation Operator:
		== check 2 value are equal
		!= check 2 value equal or not
		> check is value grater than
		< check is value less than

		Logical Operator : 
		&& // true && false = false
		|| // true or false = true
		! // not true = false

*/

#include <iostream>
using namespace std;
int main()
{
	int x = 5;
    //true && false || true
    //false || true
    //true -> print 1
	if(x<1 && x <= 4 || x == 5)
		cout<<true;
	else
        cout<<false;
    return 0;
}

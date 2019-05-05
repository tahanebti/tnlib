
/*
*	     		  Lib Mathematics, Algorithms & Data structures
*   	   		  Author : Taha Nebti
*      			  github : github.com/tahanebti
*/

#include <bits/stdc++.h>
using namespace std;		

//.isZero -> return 1 if number == 0 else return 0
bool isZero(int number){
	return (number == 0)? true : false;
}

// 0 -> is a reflection between negative & positive values
// print number in range[-10..0 ..10 ]
for (int i = -10; i < 10; ++i) cout <<i<<" ";

//.isPositive -> if number > 0 return 1, else return 0
bool isPositive(int number){
    return (number>0)? true : false;
}

//isNatural -> return 1 if number in range[1 .. n) else return 0
bool isNatural(int number ){
	return (number>=1) ? true : false;
}

//isWhole -> return 1 if number in range[0 .. n) else return 0
bool isWhole(int number){
	return (number>=0)? true : false
}


int int main(int argc, char const *argv[])
{
	int number;
	cin>>number;

	cout<<isZero(number)<<endl;
	cout<<isPositive(number)<<endl;
	cout<<isNatural(number)<<endl;
	cout<<isWhole(number)<<endl;
	return 0;
}

//C++

#include <iostream>

using namespace std;

class Number
{
public:
    Number(){};
	Number(int number){
        number = number;
	};

	int getNumber() {
		return number;
	}

	void setNumber(int number) {
		number = number;
	}

	// check given number is positive or negative
	bool isPositive(Number& number) {
		return (this->number > 0)? true : false;
	}


private :
	int number;
};

int main()
{
    Number n;
    n.setNumber(-12);
    cout<<n.isPositive(n);
    return 0;
}

/*
*	 Mathematics, Algorithms & Data structures
*    Author : Taha Nebti
*    github : github.com/tahanebti
*/
#include <bits/stdc++.h>
using namespace std;

//.is_octal -> return 1 if number in range[0..7] else return 0;
bool is_octal(int number){
	return (number>= 0 && number<= 7) ? true : false;
}
//.is_digit -> return 1 if number in range[0..9] else return 0;
bool is_digit(int number){
	return (number>= 0 && number<= 9) ? true : false;
}
//.is_xdigit -> hex digit return 1 if number is digit[0 .. to],
//or isAlpha[LowerCase[a .. f] or UpperCase[A .. F]]
bool is_xdigit(char c){
	return (isdigit(c)||isalpha(c))? true: false;
}
// N.B : Compiler classifier token bay ASCII code

int main()
{
	int n = 10;
	cout<<"set of octal digit  = {";
	for (int i = 0; i < n; ++i)
	{	//print set of octal digit from given range
		if(is_octal(i)) cout<<i<<" ";
	}
	cout<<" } "<<endl;
	return 0;
}




int n = 10 // Set of integer number in range[0..10]
for (int i = 0; i < n; ++i) cout<<i<<" ";

/*
	Also n is a set of binary string in memory 
	this is a presentation for sizeof(int) 32 bits : 

		<------------------int---------------->

	32  |31	    24|23    1|15	  8|7       0|
	    +--------+--------+--------+---------+					
	[0] |000 0000|000 0000|000 0000|000 101[0] 
		+--------+--------+--------+---------+
	hex:0x	 FF      FF       FF       FF	

*/
#include <bitset>
int n = 10	
cout<<bitset<8>(n); //00001010

//ios format
cout.setf(ios::showbase);
cout.setf(ios::hex, ios::basefield);
cout<<n<<endl; 	//0x22	hexadecimal




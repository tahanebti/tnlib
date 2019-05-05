/*
*	Mathematics, Algorithms & Data structures
*   Author : Taha Nebti
*   Github : github.com/tahanebti
*/

#include <bits/stdc++.h>
using namespace std;

int decimal_to_binary(int number){
	int r, i=1, binary = 0;
	while(number !=0){
		r = number % 2;
		number /= 2;
		binary += r*i;
		i*=10;
	}
	return binary;
}

//using bitwise operator 
void decimal_to_binary2(int number, int len)
{
	if(!len)return ;
	decimal_to_binary2(number>>1, len-1);	
	cout<<(number & 1);		
}

int main()
{
    int n = 5;
    cout<<decimal_to_binary2(n);
return 0;
}







#include <stdio.h> 

int main(int argc, char *argv[])
{	
	
	printf("hello world! from tunisia :D\n");

	return 0;
}

























/*
	Ex : push lowerCase English letter into array
*/

#include <bits/stdc++.h>
using namespace std;


int main()
{
    char letters[26];

    //'a' = 97 + 0 ... 'z' = 122
    for(int i =0; i<26; ++i) letters[i] = 'a' + i;  //'A' + i for UpperCase char
    for(int i =0; i<26; ++i) cout<<letters[i]<<" ";
    cout<<endl;
    return 0;
}

</*


	char is an integer : sizeof(char) = 8 byte = 255 bits (10^3 -> up to 3 decimal digit)

							byte 			bits
	unsigned char: 		 -> 1            -> : 0 to 255  
	char:          		 -> 1            -> : Signage Dependent on compiler						
	signed char : 		 -> 1 			 -> : –128 ~ 127		
	char16_t             -> 2            -> : 0 to 65535 (UTF-16 character representation)

	N.B : Compiler clasifier token bay ASCII code

	
E x : 

	the digit from 0 to 9 as character is represented in ASCII code 
	starting from 48 for '0' to 57 for '9'
	Exemple : to convert '1' to 1 substruct '1' - '0' 
	=> 49 - 48 = 1 ans so one till '9' - '0' = 57 - '48' = 9


	All function is in <cctype>
			.charpos 
			.isalnum	=>is alphanumirique charactre, a letter or a digit
	 		.isspace	=>is whitespace ' ', '\t', '\r','\n','\f' or vertical tab
	 		.isalpha
	 		.ispunct	=>is punctuation charcater
			.isascii	=>is an ASCII code less than 0200
			.isprint	=>is printing character
			.isgraph	=>is a visible graphic character
			.iscntrl	=>is controle charcater or '\b'
			.isupper 	=>uppercase letter [A to Z]
			.islower	=>lowercase letter [a to z]
			.isdigit	=> is digit [0 to 9]
			.isxdigit	=> hexa digit [0 to 9], [a to f], or [A - F]
		conversion
			.toascii
			.toupper
			.tolower 	 
		getchar
		setchar

OPERATORS / ESCAPED CHARACTERS
		"::"   //Scope resolution operator
		"\n"   //Newline
		"\t"   //Horizontal tab
		"\b"   //Backspace
		"\\"   //Backslash
		"\'"   //Single quote
		"\""   //Double quote
		"\r"   //Return
		"\0"   //Null character

*/

#include <bits/stdc++.h>
using namespace std;		

// N.B : Compiler clasifier token bay ASCII code

//.isDigit -> return 1 if number in range[0..9] else return 0;
bool isDigit(char c){
	return ((c-'0'>= '0') && (c-'0'<= 9)) ? true : false;
}

//.isxDigit -> hexa_digit return 1 if number isDigit[0 .. to], 
//or isAlpha[isLowerCase[a .. f], or isApperCase[A .. F]] 
bool isxdigit(char c){
	return (isdigit(c)||islower(c)||isupper(c))? true: false;
}

bool isLowerCase(char c){
	return ((c>='a')&&(c<='z'))? true : false;
}

bool isUpperCase(char c){
	return ((c>='A')&&(c<='Z'))? true : false;
}

bool isAlpha(char c){
	return (isLowerCase(c) || isApperCase(c))? true : false;
}

bool isPunct(char c){
	return (c>='!' && c<='/') || 
		   (c>=';' && c<='@') || 
	       (c>='[' && c<='`') || 
	       (c>='{' && c<='~') ? true : false;
}

bool isGraph(char c){
	return (c =='!' || c =='~') ? true : false;
}
bool isBlank(char c){
	return (c =='\t' || c == ' ') ? true : false;
}

bool isSpace(char c){
	return (c == ' ' || (c>='\t' && c<='\r')) ? true : false;
}
bool isPrint(char c){
	return (c>=' ' && c<='~') ? true : false;
}

bool isCntrl(char c){
	return (c == '0x7F' || (c>='0' && c<='0x0F')) ? true : false;
}



 int main()
{
	return 0;
}



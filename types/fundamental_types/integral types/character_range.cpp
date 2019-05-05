
/*
*	     		  Lib Mathematics, Algorithms & Data structures
*   	   		  Author : Taha Nebti
*      			  github : github.com/tahanebti

	char is an integer : sizeof(char) = 8 byte = 255 bits (10^3 -> up to 3 decimal digit)

							byte 			bits
	unsigned char: 		 -> 1            -> : 0 to 255  
	char:          		 -> 1            -> : Signage Dependent on compiler						
	signed char : 		 -> 1 			 -> : –128 ~ 127		
	char16_t             -> 2            -> : 0 to 65535 (UTF-16 character representation)

	N.B : Compiler clasifier token bay ASCII code

	CHARACTER ENCODING
		• ASCII Represents English characters as numbers from 0 to 127 in 1 byte
		• UTF-8 (Unicode) backward compatibly with ASCII and use 1 byte
			- other characters require 2-4 bytes
		• UTF-16 (Unicode) better when not using ASCII
			- can represent some characters with less memory than UTF-8

	the digit from 0 to 9 as character is represented in ASCII code 
	starting from 48 for '0' to 57 for '9'
	Exemple : to convert '1' to 1 substruct '1' - '0' 
	=> 49 - 48 = 1 ans so one till '9' - '0' = 57 - '48' = 9
*/	

    //char in C;
    printf("Enter a character : ");
    scanf(" %c", &c);//important dont forget add space before %c//
    printf("You Entered : %c\n\n", c);
    
    //or
    char c = getchar(); 
    putchar(c);  

    //Or
    char ch = getchar();
    printf("%c\n", ch);

 	//char in C++    
    char ch = cin.get();
    cout<<ch;
    //or
    cin>>ch;
/*

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



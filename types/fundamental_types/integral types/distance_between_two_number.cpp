/*

									
bit 	half_nibble 	nible	     byte = char 		half_word = short  		word = int  		double_word = long
2^0=1 	  2^1=2 		 2^2=4        2^3=8 			    2^4=16 		           2^5=32   		  2^=6 64

1 - introduction
	CPU read everything in bianry 
	it is low-level optimization, so better time order
	it drop memory by factor of 8! so better memory order
	it make code shorter

this is a presentation for 64 bits : 

		
	  				  64|63	 56|55     48|47    40|39    32| |31	24|23    16|15	   8|7       0|
					   +--------+--------+--------+--------+-+--------+--------+--------+---------+					
 MSB : {+ or -}---> [0]|000 0000|000 0000|000 0000|000 0000| |000 0000|000 0000|000 0000|000 000[0] <---MSB : {Even or ODD}
					   +--------+--------+--------+--------+-+--------+--------+--------+---------+
hex : 				 0x	  FF       FF       FF        FF		 FF        FF       FF        FF



*/

/*

Encoding Byte values

Base 2 : Binaray : 0000 0000 -- 1111 1111
	8 bits (binary digits)
	Ex : 00101011 : 32 + 8 + 2 + 1 = 34 base 10

Base 10 : Dicimal : 0 -- 255 

Base 16 : hexadecimal : 00 -- FF	
	group 4 binary digit
	byte = 2 hex or base 16
	use '0' to '9' and 'A' to 'F' tor represent
	Ex : 0xFA A1 D3 7B


	Conceptualy Memory is a single large array of byets.
	Each byte with unique address(index).
	
	Data of size n only stored at addresses a where a Mod n = 0
		n is usully a power of 2 


	Operating system provide an adress space private to each process
		process = program begin execute
		Program can modify it own data
	
	Compiler + Runtim system control memory alloction
		where different program object should be stored
		all allocation with a sigle @ space

	Machine hase a 'word size' : 
	most old machine used 4 byte = 32 bits 
	most curent machine use 8 byte = 64 bits
	
Adresses and pointer 	
	adress is location in memory
	pointer is a data object that holds an address
	Ex : the value 351 is stord at adress 0x04
		351 (in base 10) = 0x00 00 01 5F (in base 16)


Byte ordring
say we want to store 4 byte 0xaabbccdd
	what order will the byte b stored?
we have two way to do that big endian vs little endian
	big endian : big en first : most signification byte has lowset adress
	Little endian : Little end first : least signification byte has lowest adress
	Ex : 0x1234567
	Big endian    :  01 23 45 67		
	Little endina :  67 45 23 01

"Hary potter" can be stroed as 13 byte array terminted ny NULL zero
why do we put a \0 a the end of string ? to endicate finsh and count the string length

code to print byte reprenstation of data
	any data type can be treted as a byte array casting it to char
*/


#include <bits/stdc++.h>
using namespace std;

void print_bits(int n, int len)
{
	if(!len)return ;
	print_bits(n>>1, len-1);	// remove last bit
	cout<<(n&1);			    // print last bit
}

int main()
{
    short n = 5;
    //int presentation
    print_bits(n, sizeof(short)*8);
return 0;
}




void show_byte(char* start, int len){
	for (int i = 0; i < len; ++i)
		printf("%p\t0x%.2x\n", start+i, *(start+i));
	printf("\n");
		//%p : print pointer
		//\t : tab
		//%.2x : print 2 digits as hex
		//\n : newline

}

void show_int(char *str){
	show_byte((char*)&n, sizeof(int));
	/*
	output : 
	0022FEF0        0x39
    0022FEF1        0x30
    0022FEF2        0x00
    0022FEF3        0x00
	*/
}

int main()
{
    char name[] = "harry potter";
    show_int(a);   
    return 0;
}

/*

Bit Manipulation

	AND : A&B = 1 when both A is 1 and B is 1
	OR  : A|B = 1 when either A is 1 or B is 1
	XOR : A^B = 1 when either A is 1 or B is 1, but not both
	NOT : ~A = 1 when A is 0 and vise versa
	DeMorgan's Law = ~(A|B) = ~A & ~B

Boolean Logic
	&&(and) ||(or) !(not)
	true = 1, false = 0
	Any anything nonzero is true
	Ex : 0x00 && 0x55 = 0x01
		 false && true = true = 1
	
	>= equivalent to <
	<= equivalent to >
	== equal

Representaion & manipulation of Set
	Bit vector can be used to represent a set with {0, ....n-1} subset
	each bit in vector represent the absence(0) or presence(1) of an element int the set

	Ex : {0,3,5,6}				{0,2,4,6}
		  01101001				 01010101
		  76543210				 76543210

	operation : 
	& : intersection : {0,6} : 01000001 
	| : union : {0,2,3,4,5,6}: 01111101 
	^ : symetric diference : {2,3,4,5} : 00111100
	~ : complement : {1,3,5,7} : 10101010 


Integer & Floating Point Numbers

	unsigned integer : 
			1+2+4+8....+2^(n-1) = (2^N) - 1
		you add/sub ising normal carry rules just in binary
			carry      1 
			63 		00111111
		   + 8 		00001000		 
		  = 71	    01000111

	Signed integer
		to get a negative represtantion of any intger
		take bitise complement and then add one
		~x + 1 = -x
	Tow's complement arithmetic the same addition procedure work 
	just drop the carry
		carry          1 
			63 		00111111
		   - 8 		00001000		 
		  = 55	    00110111	
Formulas

The formulas for a signed number with N bits (using two's complement) are
min = -1 * 2^(N - 1)
max = 2^(N - 1) - 1
The formulas for an unsigned number with N bits are
min = 0
max = (2^N) - 1
Example: 8-bit char
The char has N = 8 bits. Let's verify these formulas with signed char and unsigned char.

signed char
min = -1 * 2^N - 1 = -1 * 2^7 = -128
max = 2^N - 1 - 1 = 2^7 - 1 = 127
unsigned char
min = 0
max = 2^N - 1 = 2^8 - 1 = 255	

Shift operation for unsigned integer
	Left shift  x << y : equivalent to multiple 2^N
		shift bit vector x left by y position
		throw away extra bits on left
		fill with 0 on right
		Ex : 		x        00000110
					<< 3  	 00110000	
					>> 2     00000001

	left shift : x >> y : equivalent to divide by 2^N
		shift bit vector x rigth by y postion
		throw away extra bit rigth
		fill 0 on left
		Ex : 		x        11110010
					<< 3  	 10010000	
					>> 2     00111100	

Sift operation signed integer
	Logical shift(for unsigned value)
		fill 0 on left
	Arithmetics shift(for signed value)
		Replicate most signification bit on left
		Maintainsign of x
	Ex : x 		01100010   98
		<< 3    00010000 
	Ligical >>2 00011000
	arith >> 2  00011000

	Ex : x 		10100010 
		<< 3    00010000
	Ligical >>2 00101000
	arith >> 2  11101000
undefined behavior when y < 0 or y >= MAX_SIZE	

Logical shift by 0 
arithmetics shift by 0 and copy the signed bit to the left 

using Shift and Masks
	(x >> 16) & 0xFF   
	Extract the sign bit of singed integer 
	(x >> 31) & 1 : - need the '&' to clear out all  other bit expect LSB
	condition as boolean expression
	if(x) a = b else a = c wich the same a = x ? b : c;
	can be writhen using arithmetics rigth shift :
		a = ((x << 31) >> 31) & b + (!(x << 31) >> 31) & c 


conditional and control flow
impicite methode : addition t = a + b 
	if(t == 0)
	if(t < 0)

explictie methode : compare : a-b
	if(a==b)  c.a.d a - b = 0
	i(a-b < 0)  c.a.d a < b 

Expliste : test a & b
	if(a&b == 0)
	if(a&b < 0)

Codition code
	set a signe byte 0 or 1 base to the combination of condition
	x 	equal or zero
	~x  not equal or not sero
	 

array allocation 
	type name[size] : array of data type an length n 
	contiguously allocation with n*sizeof(type)

grow   : yekber
shrink : yetkamech 
chunk  : 9at3a
-> 	   : arrow
[] 	   : bracket


first comprehensive from mostafa saad



structures is containre complexe data dtype
//C
struct rectangle{
	int i;
	int a[6];
	struct rectangle *ptr;
} 
//java
class rectangle{
	int i;
	int[] a = new int[3] ;
	rectangle ptr;
} 
void set_i(struct rectangle *r, int val){
	r->i = val 
}	

generate pointer to array elements
int *find(struct rectangle *r, int i){
	return &r->a[i]
}


why cache work
Locality : Program tend to use data and instruction
with adress near or equal to those they have use recently

sum = 0
for (int i = 0; i < n; ++i)
{
	sum += a[i];
}
return sum ;
sequence memory able to access using the locality  

is we have an 3d array
sum += a[k][i][j] //very bad and slow because k have random locality
so we fixe by read first j nex i next k




C++ style programming
# alwayse read elements 						//1
	vector <double> v;
	double n;
	while(cin>>n)
		v.push_back(n)
# next check if input faild						//2
	if(!cin.eof()){
		cin.clear();							//3 clear error stat				
		stirng s;
		cin>>s;
		if(s !=end){
			cree<< "format error \n";
			return 1;  //return error
		}
			
	}		
	cout<<"read "<<v.size()<<" elements"




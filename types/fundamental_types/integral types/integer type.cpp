//
//  character_representations
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

int main()
{
  x%y = x(mod y) = x reduce modulo y to the interval [0, abs(y)-1]
  return 0;
}
/*
Types:

I. Integers
   1) char (character data type, 1 byte)
   2) short int (less than int and long int)
   3) int (in most cases 4 bytes)
   4) long int ()
   Can be unsigned: 

   a) -2 ^ (n -1) ... (2 ^ (n-1) -1), where
   n is the number of bits (for example: char -128..127 or the anssend 0..255, int 2 ^ -31 ... 2 ^ -31 - 1)
   b) 0..2 ^ n - 1 for unsigned

Ii. Floating point numbers:
    1. float - 4 bytes, 7 significant digits (used to save memory)
    2. double - 8 bytes, 15 significant digits (reasonably used in practice, less error)

Iii. Boolean type bool

Iv. Empty void type (for example, the function does not return a value)

============================= Step 3 ================== ============
Literals

I. Integers
   1) 'a' - the code of the letter 'a', type char
   2) 42 - all integers by default of type int
   3) 123456789L - suffix L means type long
   4) 1703U - unsigned int
   5) 2128506UL - unsigned long int

Ii. Floating point numbers:
    1) 3.14 - all numbers with a double point of default
    2) 2.71F - float
    3) 3.0E8 - 3.0 * 10 ^ 8

Iii. Boolean type bool
     true and false

Strings are set in double quotes: "Text string"

============================= Step 4 ================== ============
Variables

first type, then name, initial value or initialization (optional)
int i = 10;
short j = 20; # converting from int to short will occur, it is better to avoid such
bool b = false;
unsigned long l = 123123; # will also be converted from int to unsigned int

double x = 13.5, y = 3.1415; # not very convenient for real projects
float z; # correctly, but badly in practice - it is unclear what is written there, you must always initialize

You cannot leave variables uninitialized.
It is impossible to create a variable of the empty type void

============================== Step 5 ================== ============
Operations

1) Assignment = 
int i = 10;
2) Arithmetic
   a) binary: + - * /%
   i = (20 * 3)% 7; # remainder of division 60 by 7 = 4
   b) unary (only for integers): ++ - 
   int k = i ++; # i value before increment: 4 (after i = 5 is given)
   int l = --i; # i value after decrement: 4 (because we take 1 from 5)

3) Logical
   a) binary && ||
   bool b =! (k == 1) # 
   b = (a == 0) || (1 / a <1); #
   b) unary! (negation)

4) Compare ==! => <> = <=
5) Type Reduction
   double d = 3.1415;
   float f = (int) d; # lead double to int with rounding - 3
6) Abbreviated versions of binary operators + = = - =. =% =
// d = d * (i + k)
   d * = i + k;

============================= Step 6 ================== ============
Instructions

The order of calculations inside the instructions is not defined
/ * undefined behavior * /
int i = 10;
i = (i + = 5) + (i * 4); // because if the first bracket is the first, then we will be 15 + 60 = 75, if the second is 55
   
Such expressions are prohibited!

You can use expression blocks with a nested scope.
int k = 10;
{
   int k = 5 * i; // not visible outside the block
   i = (k + = 5) + 5;
}
k = k + 1; # will be equal to 10 as to the block

============================== Step 7 ================== ============
Conditional statements

1) if

int d = b * b - 4 * a * c;
if (d> 0) {
   roots = 2;
} else if (d == 0) {
  roots = 1;
} else {
  roots = 0;
}

2) Ternary conditional operator
int roots = 0;
if (d> = 0)
   roots = (d> 0)? 2: 1;

============================== Step 8 ================== ============
Cycles

1) while loop

int squares = 0;
int k = 10;
while (k <10) {
      squares + = k * k;
      k = k + 1;
}
2) for loop
for (int k = 0; k <10; k = k + 1) {
    squares + = k * k;
}

For infinite loop while (true) {...}
or for (;;;) {...}

The break statement is used to exit the loop.

If the loop is inside a function, then you can also exit through
return statement

============================== Step 9 ================== ============
Functions

1) The function signature specifies the return type and types
parameters

2) The return keyword returns a value.

double square (double x) {
       return x * x;
}

3) The variables inside the function are local.

4) The function can return void

5) Parameters are passed by value (copied)

// the function does not modify anything outside
void strange (double x, double y) {
     x = y;
}

============================== Ste [10 ================= =============
Macros

1) Macros in C ++ are preprocessor instructions

2) C ++ preprocessor is a separate language that works with
arbitrary strings

3) Macros can be used to define "functions":
int max1 (int x, int y) {
    return x> y? x: y;
}

#define max2 (x, y) x> y? x: y

a = b + max2 (c, d); // b + c> d? c: d;

4) The preprocessor does not know the C ++ syntax.

How to avoid problems?

1) Macro parameters need to be wrapped in brackets
#define max3 (x, y) ((x)> (y)? (x): (y))
2) This does not eliminate all problems.
int a = 1;
int b = 1;
inc c = max3 (++ a, b); // expect a response from = 2, BUT
// c = ((++ a)> (b)? (++ a): (b)) - will be 3 instead of 2

3) Defining functions through macros is a bad idea.
4) Macros can be used for conditional compilation.
#ifdef DEBUG
 // additional checks
#endif

============================= Step 12 ================== ============
Input Output

1) We will use the library <iostream>
#include <iostream>
using namespace std; // so as not to specify the prefix of the function names std.

2) Enter
int a = 0;
int b = 0;
cin >> a >> b;

3) Conclusion
cout << "a + b =" << (a + b) << endl; // endl - line feed

============================== Step 14 ================== ============
Integer types in C ++.

All integer types (except char) are signed. Unsigned
type versions are defined with the unsigned keyword, for example:
unsigned short int, unsigned int or unsigned long int. For symmetry
the language provides an explicit indication that the type is signed
- keyword signed (rarely used).

Moreover, C ++ allows the use of the following abbreviations:

    unsigned instead unsigned int short instead of short int long instead
    long int

The type of char in the C ++ language is special: the standard does not stipulate
whether char is signed or unsigned and does not rely on it
worth it. If you need an unsigned version, use unsigned
char explicitly, if you need a signed use signed char. With
Thereby all three types (char, unsigned char, signed char) are three.
different types.

Do while loop

In addition to the for and while loops, in C ++ there is also a do ... while loop:

do {// body of the loop} while (condition);

It is similar to a while loop, however the condition is checked after the body of the loop, and
not before.

Increment and decrement operations. int a = 10; // a = 10 int b = ++ a;
// prefix increment returns the new value => b = 11 and a = 11
int c = a ++; // postfix increment returns old value => s
= 11 and a = 12

============================= Step 15 ================== ============
    Input and output streams.

To successfully complete the tasks, you need to familiarize yourself with the threads.
input / output. We will use the standard library.
iostream. To connect the library iostream need to enable
iostream header:

#include <iostream>
using namespace std;

To output something to the output stream, use the following syntax:

cout << "Some string"; cout << 3.14 << "" << 0;

As a result of this code, the text "Some string 3.14" will be displayed.
0 ". Please note that iostream does not insert
no spaces automatically, so we explicitly use the string ""
for separation. Also note that you can "link"
several output operations in one.

Entering values ​​is largely symmetrical, but cin and
operator >>:

int a, b; cin >> a >> b;

But unlike the output, when inputting, spaces are discarded. So the code
Above reads two numbers and if the input is the string "10
20 ", and if the input is the string" 10 20 ".
 Desktop version Sign out
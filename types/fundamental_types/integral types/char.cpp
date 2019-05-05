//
//  character_representations
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;



/**
    Notes :

    The ASCII character set contains all characters on a typewriter.
    0x00 to 0x1F - control characters
    0x20 to 0x2F - symbols - SPACE ! " # $ % & ' ( ) * + , - . /
    0x30 to 0x39 - digits - 0 1 2 3 4 5 6 7 8 9 0x3A to 0x40 - symbols - : ; < = > ? @
    0x41 to 0x5A - uppercase letters - A to Z 0x5B to 0x60 - symbols – [ \ ] ^ _ `
    0x61 to 0x7A - lowercase letters - a to z 0x7B to 0x7E - symbols - { | } ~
    0x7F - "delete" control character - DEL

    CHARACTER ENCODING
    • ASCII Represents English characters as numbers from 0 to 127 in 1 byte
    • UTF-8 (Unicode) backward compatibly with ASCII and use 1 byte- other characters require 2-4 bytes
    • UTF-16 (Unicode) better when not using ASCII- can represent some characters with less memory than UTF-8
**/


int main()
{

    signed char c; //-128 ...127
    unsing char c; //0 ... 255

    //when we use getchar or getc -> this return the special value EOF (end of file)
    //but 255 it will map to -1 in unicode 
    //so we should store the output as int

    int c;
    while((c = getchar())!= EOF){
        putchar(c);
    }

//digits are all in order from 48 (for '0') to 57 (for '9').

char x = '1';

char *y = (char*)&x;

cout<<typeid(x).name()<<endl; // char
cout<<typeid(*y).name()<<endl; //char

//to convert char to integer
cout<<typeid(*y+48).name()<<endl; //integer
//the same using c - '0'
cout<<typeid(*y - '0').name();


return 0;
}

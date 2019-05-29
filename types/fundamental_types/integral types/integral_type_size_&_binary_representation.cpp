//
//  integral_type size & binary representation
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#include <iostream>
#include <bitset>

int main(int argc, char* argv[])
{
    bool boolean = true;
    char charType = 'G';
    int intType = 123;
    float floatType = 1.3;
    double doubleType = 232.2323;
    wchar_t wideCharType = L'G';
    void* voidPtr = 0;

    std::cout << "Size of bool: " << sizeof(bool) <<": " << std::bitset<sizeof(bool)*8>(boolean) << std::endl;
    std::cout << "Size of char: " << sizeof(char) <<": " << std::bitset<sizeof(char)*8>(charType) << std::endl;
    std::cout << "Size of int: "  << sizeof(int)   <<": " << std::bitset<sizeof(int)*8>(intType) << std::endl;
    std::cout << "Size of float: "  << sizeof(float)  <<": " << std::bitset<sizeof(float)*8>(floatType) << std::endl;
    std::cout << "Size of double: " << sizeof(double) <<": " << std::bitset<sizeof(double)*8>(doubleType) << std::endl;
    std::cout << "Size of wideCharType: " << sizeof(wchar_t) << ": " << std::bitset<sizeof(wchar_t)*8>(wideCharType) << std::endl;
    std::cout << "Size of *voidPtr: " << sizeof(void*) << ": " << voidPtr << std::endl;

    return 0;
}

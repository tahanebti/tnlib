//
//  reference
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>

int main(int argc, char* argv[])
{
    unsigned base = 4;
    unsigned *ptrToBase = &base;
    unsigned &refToBase = base;

    std::cout << "base :     " << base       << " Address: " << &base     << std::endl;
    std::cout << "ptrToBase: " << *ptrToBase << " Address: " << ptrToBase << std::endl;
    std::cout << "refToBase: " << refToBase  << " Address: " << &refToBase << std::endl;

    int nonConstVar = 10;
    const int &refToNonConstVar = nonConstVar;
    std::cout << "nonConstVar: " << nonConstVar << std::endl;
    std::cout << "refToNonConstVar: " << refToNonConstVar << std::endl;
    //refToNonConstVar = 30;
    nonConstVar = 0;
    std::cout << "nonConstVar: " << nonConstVar << std::endl;
    std::cout << "refToNonConstVar: " << refToNonConstVar << std::endl;

    const int constVar = 20;
    const int &refToConstVar = constVar;
    std::cout << "constVar: " << constVar << std::endl;
    std::cout << "refToConstVar: " << refToConstVar << std::endl;
    /* constVar = 0;
    refToConstVar = 0; */

    int someOtherVar = 0;
    const int someOtherConstVar = 0;
    int someNonConstVar  = 2;
    const int constantVar = 50;
    const int *ptrToSomeNonConstVar = &someNonConstVar;
    std::cout << "someNonConstVar: " << someNonConstVar << " *ptrToSomeNonConstVar: " << *ptrToSomeNonConstVar << std::endl;
    ptrToSomeNonConstVar = &someOtherVar;
    //*ptrToSomeNonConstVar = 4;
    std::cout << "someNonConstVar: " << someNonConstVar << " *ptrToSomeNonConstVar: " << *ptrToSomeNonConstVar << std::endl;

    const int *ptrToConstInt = &constantVar;
    //*ptrToConstInt  = 45;
    ptrToConstInt = &someOtherVar;

    const int *const constPtrToConstVar = &constantVar;
    //*constPtrToConstVar = &someOtherConstVar;
    //*constPtrToConstVar = 0;

    /* REFERENCES TO POINTERS */
    int variable = 20;
    int *ptr = &variable;
    int* &refToPtr = ptr;

    std::cout << "refToPtr: " << *refToPtr << ", *ptr: " << *ptr << std::endl;

    return 0;
}

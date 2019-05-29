//
//  passing arguments function
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>

/*
    Call-by-value : The object is copied and assigned to input arguments of the method
        disadvantge : Performance penalty if the copied arguments are large (e.g. a structure with a large array)
    
    Call-by-pointer : The address of a variable is copied and assigned to input arguments of the method
        disadvantages : The argument may be nullptr or Dereferencing a pointer is slower than accessing a value directly
        When to use:  When passing raw arrays (use const * if read-only)
        When not to use: Small objects 8 
    
    Call-by-reference : The reference of a variable is copied and assigned to input arguments of the method
        When to use: Structs or Classes (use const & if read-only)
*/

void someFunction(int passByValue, int *passByPointer, int* &passByReference)
{
    std::cout << "Value of passByValue:      " << passByValue << std::endl;
    std::cout << "Address of passByValue:    " << &passByValue << std::endl;
    std::cout << std::endl;

    std::cout << "Value of passByPointer:    " << *passByPointer << std::endl;
    std::cout << "Address of variable:       " << passByPointer << std::endl;
    std::cout << "Address of &passByPointer: " << &passByPointer << std::endl;
    std::cout << std::endl;

    std::cout << "Value of passByReference:  " << *passByReference << std::endl;
    std::cout << "Address of variable:       " << passByReference << std::endl;
    std::cout << "Address of pointer is :    " << &passByReference << std::endl;
    std::cout << std::endl;
}

int main()
{
    int variable = 4;
    int *ptrToVariable = &variable;

    /* Reference to the Pointer itself */
    int* &refToPtrToVariable = ptrToVariable;


    std::cout << "Value of variable:         " << variable << std::endl;
    std::cout << "Address of variable:       " << ptrToVariable << std::endl;
    std::cout << "Address of the Pointer:    " << &ptrToVariable << std::endl;
    std::cout << "Address of refToPtr:       " << &refToPtrToVariable << std::endl;
    std::cout << std::endl;

    someFunction(variable, ptrToVariable, refToPtrToVariable);

    return 0;
}

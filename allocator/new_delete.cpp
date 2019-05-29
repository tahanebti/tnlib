//
//  new & delete
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#include <iostream>
#include <string>
#include <memory>
/*
    new and delete are C++ keywords that perform dynamic
    memory allocation/deallocation, and object construction/
    destruction (at runtime)
    malloc and free are C functions and they allocate and free
    memory blocks
    new , delete advantages:
        • Return type: new returns exact data type, while malloc()
        returns void*
        • Failure: new throws an exception, while malloc() returns a
        NULL pointer
        • Allocated bytes: The size of the allocated memory is calculated by
        compiler for new , while the user must take care of manually
        calculate the size for malloc()
*/
int main()
{
    //Allocate a single element
    int* value = (int*) malloc(sizeof(int)); // C
    //Deallocate a single element
    free(value)
    
    int* value = new int; // C++
    delete value;

    //Allocate N elements
    int* array = (int*) malloc(N * sizeof(int)); // C

    //Deallocate N elements
    int* array = new int[N]; // C++
    delete[] value;

    //Allocate and zero-initialize N elements
    int* array = (int*) calloc(N * sizeof(int)); // C
    int* array = new int[N](); // C++
    
    //Allocate N structures
    MyStruct* array = (int*) malloc(N * sizeof(MyStruct)); // C
    MyStruct* array = new MyStruct[N]; // C++
    

    
    

    return 0;
}

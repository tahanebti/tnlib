//
//  reference as function arguments
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>

struct MyStruct {
    int number;
    float fraction;
    char *msg;
};

void testFunction(int value, int *ptr, int &ref)
{
    std::cout << "value: " << value <<  " address: " << &value << std::endl;
    std::cout << "ptr:   " << *ptr  <<  " address: " << ptr    << std::endl;
    std::cout << "ref:   " <<  ref  <<  " address: " << &ref   << std::endl;
}

void testFunction(MyStruct value, const MyStruct *ptr, const MyStruct &ref)
{
    std::cout << "number: " << value.number << " fraction: " << value.fraction << " msg: " << value.msg << std::endl;
    std::cout << "number: " << ptr->number  << " fraction: " << ptr->fraction  << " msg: " << ptr->msg  << std::endl;
    std::cout << "number: " << ref.number   << " fraction: " << ref.fraction   << " msg: " << ref.msg  << std::endl;
    //ref.number = 3;
    //ptr->number = 4;
 }

int main(int argc, char* argv[])
{
    int variable = 40;
    testFunction(variable, &variable, variable);

    MyStruct mystruct;
    mystruct.number = 1;
    mystruct.fraction = 4.5;
    mystruct.msg = "hello";

    testFunction(mystruct, &mystruct, mystruct);

    return 0;
}

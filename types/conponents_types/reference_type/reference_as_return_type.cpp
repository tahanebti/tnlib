//
//  reference as return type
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#include <iostream>

int globalArray[5] = {0,1,2,3,4};

int& getElement(int index)
{
    return globalArray[index];
}

int main(int argc, char *argv[])
{
    for(std::size_t index = 0; index < sizeof(globalArray)/sizeof(int); index++)
    {
        std::cout << globalArray[index] << " ";
    }
    std::cout << "\n";

    int firstValue = getElement(0);
    getElement(4) = 99;
    getElement(2) = 100;

    for(std::size_t index = 0; index < sizeof(globalArray)/sizeof(int); index++)
    {
        std::cout << globalArray[index] << " ";
    }
    std::cout << "\n";

    return 0;
}

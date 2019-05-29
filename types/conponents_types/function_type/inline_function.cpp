//
//  inline function
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>


/*
    inline specifier is a hint for the compiler. The code of the
    function can be copied where it is called (inlining)
*/

#define SQUARE(x) (x * x)

inline int square(int x)
{
    return (x * x);
}

inline void someOtherFunction()
{
    std::cout << "this is inline function " << std::endl;
}

int main(int argc, char* argv[])
{
    int x = 5;
    std::cout << "Evaluating macro: " << SQUARE(x) << std::endl;
    std::cout << "Evaluating inline function: " << square(x) << std::endl;

    x = 7;
    std::cout << "Evaluating macro: " << SQUARE(x++) << std::endl;
    std::cout << "Value of x: " << x << std::endl;
    std::cout << "Evaluating inline function: " << square(x++) << std::endl;
    std::cout << "Value of x: " << x << std::endl;

    float y = 2.3F;
    std::cout << "Evaluating macro with float value: " << SQUARE(y) << std::endl;
    std::cout << "Evaluating inline function with float value: " << square(y) << std::endl;


    return 0;
}

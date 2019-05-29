//
//  function overloading
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>

/*
    An overloaded declaration is a declaration with the same name
    as a previously declared identifier (in the same scope), which
    have different number of arguments and types
*/

void f(int a);
void f(float value);
void g(int a);
void h(int a);
void h(int a, int b = 0);

int main(int argc, char* argv[])
{
    f(0); // ok
    
    // f('a'); // ambiguous matches, compile error
    f(2.3f); // ok
    
    // f(2.3); // ambiguous matches, compile error
    
    g(2.3); // ok, standard type conversion
    // h(3); // ambiguous matches, compile error

    return 0;
}

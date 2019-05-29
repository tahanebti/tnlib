//
//  functor as function pointer
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>

/*
  Functors, or function pointer, are objects that can be treated as
    parameters*
*/

int eval(int a, int b, int (*f)(int, int)) 
{
    return f(a, b);
}

int add(int a, int b) 
{ // type: int (*)(int, int)
    return a + b;
}

int sub(int a, int b) 
{
    return a - b;
}

int main()
{
    cout << eval(4, 3, add); // print 7
    cout << eval(4, 3, sub); // print 1

    //C++11 provides a more efficient and convenience way to pass “procedure” to
    //other function called lambda expression

    return 0;
}

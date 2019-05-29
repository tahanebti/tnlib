//
//  Function Attributes 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>

/*
C++ allows marking functions with standard properties to better
express their intent:
    • C++11 [[noreturn]] indicates that the function does not
    return
    
    • C++14 [[deprecated]] , [[deprecated("reason")]]
    indicates the use of a function is discouraged (for some
    reason). It issues a warning if used
    
    • C++17 [[nodiscard]] issues a warning if the return value
    is discarded
    
    • C++17 [[maybe unused]] suppresses compiler warnings on
    unused functions, if any (it applies also to other entities)
*/

[[noreturn]] void f() {
    std::exit(0);
}

[[deprecated]] void my_rand() {
    rand();
}

[[nodiscard]] int g() { 
    return 3;
}

[[maybe_unused]] void h() {}

int main()
{
    my_rand(); // warning "deprecated"
    g(); // warning "discard return value"
    int x = g(); // no warning

    return 0;
}

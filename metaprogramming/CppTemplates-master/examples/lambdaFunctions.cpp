
#include <functional>
#include <iostream>

// https://en.cppreference.com/w/cpp/language/lambda

int main()
{
    // Implicit return type
    auto funcA = [](int a, int b) -> int {return a + b;};
    std::cout << funcA(4,5) << std::endl;

    // Explicit return type
    auto funcB = [](int a, int b) -> int {return a + b;};
    std::cout << funcB(4,5) << std::endl;

    // Conversion to explicit function type
    // Note: lambda expressions do not have a "given" type (specified type)
    // (See https://stackoverflow.com/questions/7951377/what-is-the-type-of-lambda-when-deduced-with-auto-in-c11)
    std::function<int(int,int)> funcD = [](int a, int b) -> int {return a + b;};
    std::cout << funcD(4,5) << std::endl;

    // With capture (See https://en.cppreference.com/w/cpp/language/lambda#Lambda_capture)
    int c = 9;
    auto funcC = [&](int a) -> int {return a + c;};
    std::cout << funcC(4) << std::endl;

    return 0;
}

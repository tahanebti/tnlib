
#include <iostream>

bool funcA(int a)
    { return a > 1; }

bool funcB(int a)
    { return a < 5; }

int main()
{
    bool (*ptr)(int) = nullptr;

    ptr = funcA;
    std::cout << ptr(0) << ", " << ptr(6) << std::endl;

    ptr = funcB;
    std::cout << ptr(0) << ", " << ptr(6) << std::endl;

    return 0;
}


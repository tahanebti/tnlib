
#include <iostream>

template<int... parameters>
void printParameters()
{
    for(int parameter : {parameters...})
        { std::cout << parameter << ", "; }
    std::cout << std::endl;
}

template<>
void printParameters()
{
    std::cout << "(Empty list)" << std::endl;
}

int main()
{
    printParameters<>();
    printParameters<1>();
    printParameters<1,2,3>();
    return 0;
}


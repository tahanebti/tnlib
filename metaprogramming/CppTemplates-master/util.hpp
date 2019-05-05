
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


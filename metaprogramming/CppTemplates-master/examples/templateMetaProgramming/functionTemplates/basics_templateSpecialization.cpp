

#include <iostream>

template<int param>
void readNumber()
    { std::cout << param << std::endl; }

template<>
void readNumber<1>()
    { std::cout << "One" << std::endl; }

int main()
{
    readNumber<1>();
    readNumber<3>();
    readNumber<4>();
    return 0;
}


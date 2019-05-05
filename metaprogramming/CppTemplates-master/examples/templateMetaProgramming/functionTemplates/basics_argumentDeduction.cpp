
#include <iostream>

template<typename T>
T max(T a, T b)
    { return a > b ? a : b; }

int main()
{
    double ansA = max(3.4, 6.3);
    std::cout << "ansA = " << ansA << std::endl;

    int ansB = max(3, 7);
    std::cout << "ansB = " << ansB << std::endl;

    auto ansC = max(3.4, 6.3);
    std::cout << "ansC = " << ansC << std::endl;

    return 0;
}


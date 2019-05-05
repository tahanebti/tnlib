
#include <algorithm>
#include <vector>
#include "util.hpp"

// Access a given parameter in parameter pack
template <int...params>
void getSecond()
{
    constexpr int arr[] = {params...};
    printParameters<arr[1]>();
}

template <int...params>
void getLast()
{
    constexpr int arr[] = {params...};
    printParameters<arr[sizeof...(params)-1]>();
}

template <int index, int...params>
void getAny()
{
    constexpr int arr[] = {params...};
    printParameters<arr[index]>();
}



int main()
{
    getSecond<7,8,9,10,11>();
    getLast<7,8,9,10,11>();
    getAny<3, 7,8,9,10,11>();
}


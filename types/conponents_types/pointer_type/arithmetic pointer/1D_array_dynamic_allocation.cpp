//
//  1D array dynamic allocation
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/*
    Two arrays are set - A (5) and B (5). In each of the arrays, 
    find the largest value and multiply all elements of the arrays by it.
     Print the original and converted arrays.
*/

#include <iostream>
#include <algorithm>
#include <ctime>
 
//-------------------------------------------------------------------------------------------------
int main()
{
    size_t size_a = 0;
    std::cin >> size_a;
 
    size_t size_b = 0;
    std::cin >> size_b;
 
    std::srand(std::time(nullptr));
 
    int* a = new int[size_a];
 
    for (size_t i = 0; i < size_a; i++)
    {
        a[i] = rand() % 10 + 4;
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
 
    int* b = new int[size_b];
 
    for (size_t i = 0; i < size_b; i++)
    {
        b[i] = rand() % 10 + 4;
        std::cout << b[i] << ' ';
    }
    std::cout << std::endl;
 
    int max_a = *std::max_element(a, a + size_a);
    int max_b = *std::max_element(b, b + size_b);
 
    std::cout << "max_a = " << max_a << std::endl;
    std::cout << "max_b = " << max_b << std::endl;
 
    for (size_t i = 0; i < size_a; i++)
    {
        a[i] *= max_a;
        std::cout << a[i] << ' ';
    }
    std::cout << std::endl;
 
    for (size_t i = 0; i < size_b; i++)
    {
        b[i] *= max_b;
        std::cout << b[i] << ' ';
    }
    std::cout << std::endl;
 
    delete[] a;
    delete[] b;
 
    return 0;

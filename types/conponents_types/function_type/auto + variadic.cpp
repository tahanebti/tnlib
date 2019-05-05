//
//  summation 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

template <typename A, typename B>
auto sum(A a, B b) -> typename common_type<A, B>::type {
    return static_cast<typename common_type<A, B>::type>(a) + static_cast<typename common_type<A, B>::type>(b);
}

template <typename A, typename B, typename... Args>
auto sum(A a, B b, Args... args) -> typename common_type <A, B, Args...>::type {
    return sum(sum(a, b), args...);
}

int main() {
    cout << sum(5, 7, 2, 2) + sum(3.14, 4.89) << endl;
    cout << sum (complex <double>(1, 2), 1.3, 2) << endl;
return 0;
}

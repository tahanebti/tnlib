
#include <iostream>

// Variadic template function: remove last template parameter

// NOTE: the order of the functions is important!
// Swap them and it no longer works!

template <int firstTerm>
int sum()
    { return firstTerm; }

template <int firstTerm, int secondTerm, int... otherTerms>
int sum()
    { return sum<firstTerm + secondTerm, otherTerms...>(); }

int main() {
    std::cout << sum<1,2,3,4,5>() << std::endl;
}


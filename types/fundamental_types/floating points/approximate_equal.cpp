
#include <iostream>
#include <cmath>
#include <limits>
using namespace std;

template <typename T>
bool ApproximatelyEqual(const T dX, const T dY)
{
    return std::abs(dX - dY) <= std::max(std::abs(dX), std::abs(dY))
    * std::numeric_limits<T>::epsilon();
}

int main() {
    double a=0.0132;
    double b=0.9581;
    double c=0.0287;

    //Evaluates to true and does not print error.
    if (!ApproximatelyEqual(a+b+c,1.0)) cout << "error" << endl;
}

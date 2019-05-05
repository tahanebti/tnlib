

#include <iostream>

// Dummy parameter-pack expander
template <class T>
void expand(std::initializer_list<T>) {}

// Fun
template <class Fun, class... Args>
typename std::result_of<Fun&&(Args&&...)>::type
call(Fun&& f, Args&&... args) {

    // Print all parameters
    std::cout << "Params : ";
    expand({(std::cout << args << ' ', 0)...});
    std::cout << '\n';

    // Forward the call
    return std::forward<Fun>(f)(std::forward<Args>(args)...);
}

// Random test function
int myFunc(std::string const &s, double d, int i) {
    std::cout << s << ' ' << d << ' ' << i << '\n';
    return 57;
}

int main()
{
    // Painless call
    std::cout << call(myFunc, "hello", 3.14, 42) << '\n';

    return 0;
}

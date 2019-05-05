
#include <iostream>

class MyClass
{
public:
    MyClass() = default;

private:
    bool funcA(int a)
        { return a > 1; }

    bool funcB(int a)
        { return a < 5; }

public:
    void runIt()
    {
        bool (MyClass::*ptr)(int) = nullptr;

        ptr = &MyClass::funcA;
        std::cout << (this->*ptr)(0) << ", " << (this->*ptr)(6) << std::endl;

        ptr = &MyClass::funcB;
        std::cout << (this->*ptr)(0) << ", " << (this->*ptr)(6) << std::endl;
    }

};

int main()
{
    MyClass myObj;
    myObj.runIt();
    return 0;
}


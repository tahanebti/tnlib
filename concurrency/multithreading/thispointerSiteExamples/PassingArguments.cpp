#include <iostream>
#include <vector>
#include <thread>

void threadCallback(int x, std::string name)
{
    std::cout << "Passed number: " << x << "\n";
    x= 30;
    std::cout << "Passed text: " << name << "\n";
}

int main(int argc, char const *argv[])
{
    int sample = 10;
    std::thread threadObj(threadCallback, sample, "C++");

    threadObj.join();
    std::cout << "Sample value: " << sample << "\n";

    return 0;
}

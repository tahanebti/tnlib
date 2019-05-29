#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

std::timed_mutex t_mutex_;
        
void printCharacters(char ch)
{
    for(unsigned index = 0; index < 50; ++index)
    {
        std::lock_guard<std::timed_mutex> guard(t_mutex_);
        std::cout << ch;
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
    std::cout <<"\n";
}

int main(int argc, char const *argv[])
{
    std::thread thread_1(printCharacters, '*');
    std::thread thread_2(printCharacters, '#');
    std::thread thread_3(printCharacters, '$');
    std::thread thread_4(printCharacters, '%');

    thread_4.join();
    thread_3.join();
    thread_2.join();
    thread_1.join();

    return 0;
}

#include <thread>
#include <iostream>
#include <mutex>
#include <chrono>

std::timed_mutex t_mutex_;

void printCharacters(char ch)
{
    for(unsigned index = 0; index < 50; ++index)
    {
        t_mutex_.lock();
        std::cout << ch;
        t_mutex_.unlock();
        //std::this_thread::sleep_for(std::chrono::microseconds(1000));
    }
    std::cout <<"\n";
}

int main(int argc, char const *argv[])
{
    std::thread thread_1(printCharacters, '*');
    std::thread thread_2(printCharacters, '#');

    thread_1.join();
    thread_2.join();

    return 0;
}

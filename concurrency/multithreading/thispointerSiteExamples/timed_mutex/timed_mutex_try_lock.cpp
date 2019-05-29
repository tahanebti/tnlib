#include <mutex>
#include <thread>
#include <iostream>
#include <chrono>
#include <string>
#include <vector>

std::timed_mutex t_mutex_;
unsigned int treasure_ = 0;
std::chrono::microseconds interval(100);

void getPrize(std::string threadName)
{
    std::cout << "Thread " << threadName << "\n";
    std::this_thread::sleep_for(interval);
    std::lock_guard<std::timed_mutex> treasureGuard(t_mutex_);
    ++treasure_;

    if(treasure_ == 4)
    {
        std::cout << "Found treasure by thread:  " << threadName << "\n";
        return;
    }
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threadList;

    for(unsigned index = 0; index < 10; ++index)
    {
        std::string name = "ID:";
        threadList.push_back(std::thread(getPrize, name.append(std::to_string(index))));
    }

    for(auto iter = threadList.begin(); iter != threadList.end(); ++iter)
    {
        iter->join();
    }

    return 0;
}

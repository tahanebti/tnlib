#include <thread>
#include <iostream>
#include <mutex>
#include <vector>
#include <chrono>

std::timed_mutex t_mutex_;
std::chrono::microseconds interval(200);

void fireworks(const std::string& name)
{
    while(!t_mutex_.try_lock_for(interval)){
        std::cout << name << "-";
        //std::cout << name << " executing....";
    }
    std::this_thread::sleep_for(5 * interval);
    std::cout <<"*\n";
    t_mutex_.unlock();
    std::cout << name << " goes out" << "\n";
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threadList;

    for(unsigned index = 0; index < 10; ++index)
    {
        std::string name = ""; 
        std::string n = name.append(std::to_string(index));
        threadList.push_back(std::thread(fireworks, n));
    }

    for(auto iter = threadList.begin(); iter!= threadList.end(); ++iter)
    {
        iter->join();
    }
    return 0;
}

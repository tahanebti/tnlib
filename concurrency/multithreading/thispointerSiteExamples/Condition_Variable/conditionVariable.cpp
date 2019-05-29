#include <mutex>
#include <thread>
#include <condition_variable>
#include <iostream>
#include <vector>

std::mutex mutex_;
std::condition_variable conditionVar_;
bool ready = false;

void race(int id)
{
    std::unique_lock<std::mutex> guard(mutex_);

    while(!ready)
    {
        conditionVar_.wait(guard);
        //std::cout << "executing thread id: " << id << "\n";
    } 
    //conditionVar_.wait(guard);

    std::cout << "Thread id : "<< id << "\n";
}

void go()
{
    std::unique_lock<std::mutex> guard(mutex_);
    ready = true;
    conditionVar_.notify_all();
}

int main(int argc, char const *argv[])
{
    std::vector<std::thread>  threadList;

    for(int index = 0; index < 10; ++index)
    {
        threadList.push_back(std::thread(race, index));
    }

    go();

    for(auto iter = threadList.begin(); iter != threadList.end(); ++iter)
    {
        iter->join();
    }

    return 0;
}

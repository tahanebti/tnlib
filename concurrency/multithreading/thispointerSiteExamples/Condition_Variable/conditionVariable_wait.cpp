#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

std::mutex mutex_;
std::condition_variable conditionVar_;

int cargo = 0;

bool isShipmentAvailable()
{
    return (cargo != 0);
}

void consume(int n)
{
    for(int index = 0; index < n; ++index)
    {
        std::unique_lock<std::mutex> guard(mutex_);
        conditionVar_.wait(guard, isShipmentAvailable);
        std::cout << cargo << "\n";
        cargo = 0;
    }
}

int main(int argc, char const *argv[])
{
    std::thread consumer_thread(consume, 10);

    for(int index = 0; index < 10; ++index)
    {
        while(isShipmentAvailable())
        {
            std::this_thread::yield();
        }

        std::unique_lock<std::mutex> guard(mutex_);
        cargo = index + 1;
        conditionVar_.notify_one();
    }

    consumer_thread.join();

    return 0;
}


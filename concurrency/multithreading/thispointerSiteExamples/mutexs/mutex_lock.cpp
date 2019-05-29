#include <thread>
#include <mutex>
#include <iostream>
#include <chrono>

unsigned counter = 0;
std::mutex counterMutex_;

void incrementCounter(int threadId)
{
    for(unsigned index =  0; index < 3; ++index)
    {
        /* Acquire the lock */
        counterMutex_.lock();

        /* Increment the counter */
        ++counter;
        std::cout << threadId << " --> " << counter << " with index: " << index << "\n";

        /* Release the lock */
        counterMutex_.unlock();

        /* Sleep for 1 second */
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main(int argc, char const *argv[])
{
    std::thread thread_1(incrementCounter, 111);
    std::thread thread_2(incrementCounter, 222);
    std::thread thread_3(incrementCounter, 333);
    std::thread thread_4(incrementCounter, 444);
    std::thread thread_5(incrementCounter, 555);
    std::thread thread_6(incrementCounter, 666);

    thread_1.join();
    thread_2.join();
    thread_3.join();
    thread_4.join();
    thread_5.join();
    thread_6.join();

    return 0;
}


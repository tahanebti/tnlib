#include <thread>
#include <chrono>
#include <iostream>
#include <mutex>

std::chrono::microseconds interval(100);
unsigned int job_shared = 0;
unsigned int job_exclusive = 0;
std::mutex mutex_;

void job_1()
{
    std::this_thread::sleep_for(interval);

    while(true)
    {
        /* try_lock returns 'true' if lock is successful else returs 'false' */
        if(mutex_.try_lock())
        {
            std::cout << "Job_shared: " << job_shared << "\n";
            mutex_.unlock();
            return;
        }
        else
        {
            ++job_exclusive;
            std::cout <<"Job_exclusive: " << job_exclusive << "\n";
            std::this_thread::sleep_for(interval);
        }
    }
}

void job_2()
{
    mutex_.lock();
    std::this_thread::sleep_for(5 * interval);
    ++job_shared;
    mutex_.unlock();
}

int main(int argc, char const *argv[])
{
    std::thread thread_1(job_1);
    std::thread thread_2(job_2);

    thread_2.join();
    thread_1.join();

    return 0;
}

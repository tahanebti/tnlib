#include <iostream>
#include <thread>

void threadCallback(int *sample)
{
    std::cout << "Inside new thread: sample: " << *sample << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    *sample = 19;
}

void startNewThread()
{
    int var = 10;
    std::cout << "Value of var in MainThread: " << var << "\n";
    std::thread newThread(threadCallback, &var);
    newThread.detach();
    std::cout << "Value of var in MainThread after: " << var << "\n";
}

int main(int argc, char const *argv[])
{
    startNewThread();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    
    return 0;
}

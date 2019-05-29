#include <iostream>
#include <thread>

void threadCallBack(int *param)
{
    std::cout << "In newThread value of param: " << *param << "\n";
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    *param = 20;
}

void startNewThread()
{
    int *ptr = new int();
    *ptr = 10;
    std::thread threadObj(threadCallBack, ptr);
    threadObj.detach();
    delete ptr;
    ptr = nullptr;
}

int main(int argc, char const *argv[])
{
    startNewThread();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));

    return 0;
}

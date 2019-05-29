#include <thread>
#include <iostream>

class ThreadWrapper
{
    public:
        ThreadWrapper(){};
        ~ThreadWrapper(){};
    
        void threadCallback(int x)
        {
            std::cout << "New thread running: " << "\n";
        }
};

int main(int argc, char const *argv[])
{
    ThreadWrapper threadWrapper_;
    std::thread newThread(&ThreadWrapper::threadCallback, &threadWrapper_, 49);
    newThread.join();

    return 0;
}

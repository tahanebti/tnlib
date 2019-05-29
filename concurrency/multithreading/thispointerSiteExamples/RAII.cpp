#include <iostream>
#include <thread>


/* Resource aquisition is Initialization */
class ThreadRAII
{
    public:
        ThreadRAII(std::thread & threadInstance) : threadInstance_(threadInstance)
        {
            std::cout << "thread constructor " << "\n";
        }

        ~ThreadRAII()
        {
            std::cout << "thread destructor " << "\n";
            if(threadInstance_.joinable())
            {
                threadInstance_.detach();
            }
        }

    private:
        std::thread & threadInstance_;
};

void threadFunction()
{
    for(int index = 0; index < 100; ++index)
    {
        std::cout << "TheadFunction executing....." << index << "\n";
    }
}

int main(int argc, char const *argv[])
{
    std::thread threadObj(threadFunction);

    ThreadRAII threadWrapper(threadObj);

    std::this_thread::sleep_for(std::chrono::milliseconds(1000));

    return 0;
}

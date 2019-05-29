#include <iostream>
#include <thread>

void startThreadFunction()
{
    std::cout << "startThreadFunc: " << std::this_thread::get_id() << "\n";
    for(auto index = 0; index < 10; index++)
    {
        std::cout << "[New Thread] Running....." << "\n";
    }
}

class FunctionObject
{
    public:
        void operator()()
        {
            for(auto index = 0; index < 30; ++index)
            {
                std::cout << "[Thread Two] Running....." << "\n";
            }
        }
};

int main(int argc, char const *argv[])
{
    /* Using Function pointer */
    std::thread threadOne(startThreadFunction);

    /* Using Function object */
    std::thread threadTwo(FunctionObject{});

    /* Using Lambda */
    std::thread threadThree([](){
        for(auto index = 0; index < 60; ++index)
        {
            std::cout << "[Thread Three]: Running....." << "\n";
        }
    });

    for(auto index = 0; index < 10; ++index)
    {
        std::cout << "[Main Thread] Running....." << "\n";
    }

    std::cout << "Thread id(threadOne): " << threadOne.get_id() << "\n";
    std::cout << "Thread id(threadTwo): " << threadTwo.get_id() << "\n";
    std::cout << "Thread id(threadThree): " << threadThree.get_id() << "\n";

    threadOne.join();
    threadTwo.join();
    threadThree.join();

    return 0;
}

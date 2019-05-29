#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <functional>

class WorkerThread
{
    public:
        void operator()()
        {
            for(int index = 0; index < 5; ++index){
                std::cout << "Worker thread with Id: " << std::this_thread::get_id() << " is Executing...." << "\n";
            }
        }
};

int main(int argc, char const *argv[])
{
    std::vector<std::thread> threadList;

    for(unsigned index = 0; index < 10; ++index)
    {
        threadList.push_back(std::thread(WorkerThread{}));
    }

    std::cout << "Wait for all the worker thread to finish...." << "\n";
    std::for_each(threadList.begin(), threadList.end(), std::mem_fn(&std::thread::join));
    std::cout << "Exiting main thread...." << "\n";

    return 0;
}

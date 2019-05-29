#include <iostream>
#include <thread>
#include <mutex>  //lock_guard, mutex

class Application
{
    public:
        explicit Application() : isDataLoaded_(false) {}
        ~Application() {};

        /* Thread-1 Task */
        void mainTask() 
        {
            std::cout << "Initiating handshake with server....." << "\n";

            mutex_.lock();
            while(!isDataLoaded_){
                mutex_.unlock();

                std::this_thread::sleep_for(std::chrono::microseconds(1000));
                mutex_.lock();
            }
            mutex_.unlock();

            std::cout << "Do processing on loaded data...." << "\n";            
        }

        /* Thread-2 Task */
        void LoadData()
        {
            std::this_thread::sleep_for(std::chrono::microseconds(1000));
            std::cout << "Load the data from XML...." << "\n";

            /* lock guard is a RAII class which takes mutex_ in its construtor and calls 'locks' and in destructor it
            calls  'unlock' on mutex_ */
            std::lock_guard<std::mutex> guard(mutex_);

            isDataLoaded_ = true;
        }

    private:
        bool isDataLoaded_;
        std::mutex mutex_;
};

int main(int argc, char const *argv[])
{
    Application app{};
    std::thread thread_1(&Application::mainTask, &app);
    std::thread thread_2(&Application::LoadData, &app);

    thread_2.join();
    thread_1.join();

    return 0;
}

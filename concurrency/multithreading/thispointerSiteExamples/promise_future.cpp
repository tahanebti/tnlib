#include <thread>
#include <future>
#include <iostream>
#include <chrono>

void initializer(std::promise<int> *promiseObj, std::promise<std::string> *strPromise)
{
    std::cout << "Executing initializer function...." << "\n";

    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    promiseObj->set_value(40);
    strPromise->set_value("C++");
}

int main(int argc, char const *argv[])
{
    std::promise<int> promiseObj;
    std::promise<std::string> strPromise;

    std::future<int> futureObj = promiseObj.get_future();
    std::future<std::string> futureStr =  strPromise.get_future();

    std::thread threadObj(initializer, &promiseObj, &strPromise);

    std::cout << "Got Value: " << futureObj.get() << "\n";
    std::cout << "Got Value: " << futureStr.get() << "\n";

    threadObj.join();

    return 0;
}

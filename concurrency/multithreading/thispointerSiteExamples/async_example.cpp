#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <string>

std::string fetchDataFromDB(const std::string& data)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Thread Id: " << std::this_thread::get_id() << "\n";

    return "DB_" + data;
}

std::string fetchDataFromFile(const std::string& data)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "Thread Id: " << std::this_thread::get_id() << "\n";

    return "FILE_" + data;
}

int main(int argc, char const *argv[])
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    std::future<std::string> dbResult = std::async(std::launch::async, fetchDataFromDB, "Data");
    std::future<std::string> fileResult = std::async(std::launch::async, fetchDataFromFile, "Data");

    std::string dbData_ = dbResult.get();
    std::string fileData_ = fileResult.get();

    auto end = std::chrono::system_clock::now();

    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::seconds> (end - start).count() << "\n";
    std::cout << "Result: " << dbData_ << "::" << fileData_ << "\n";

    return 0;
}

#include <thread>
#include <iostream>
#include <chrono>
#include <future>
#include <string>

std::string getDBData(const std::string& data)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "Thread Id: " << std::this_thread::get_id() << "\n";
    return "DB_" + data;
}

std::string getFileData(const std::string& data)
{
    std::this_thread::sleep_for(std::chrono::seconds(5));
    
    std::cout << "Thread Id: " << std::this_thread::get_id() << "\n";
    return "File_" + data;
}

int main(int argc, char const *argv[])
{
    std::chrono::system_clock::time_point start = std::chrono::system_clock::now();

    std::string db_ = getDBData("data");
    std::string file_ = getFileData("data");

    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    auto diff = std::chrono::duration_cast<std::chrono::seconds> (end - start).count();

    std::cout <<"Total time taken: " << diff << " seconds" << "\n";
    std::cout <<" Result: " << db_ << "::" << file_ << "\n";

    return 0;
}


#include <thread>
#include <iostream>
#include <mutex>
#include <map>
#include <string>

std::map<std::string, std::string> pages;
std::mutex page_mutex_;

void savePages(const std::string& url)
{
    std::this_thread::sleep_for(std::chrono::microseconds(2000));
    std::string result = "FakePage";

    /* mutex lock will be called here */
    std::lock_guard<std::mutex> pageGuard(page_mutex_);
    pages[url] = result;

    /* mutex unlock will be called when pageGuard goes out of stack */
}

int main(int argc, char const *argv[])
{
    std::thread thread_1(savePages, "https://foo");
    std::thread thread_2(savePages, "https://bar");

    thread_1.join();
    thread_2.join();

    for(auto page: pages)
    {
        std::cout << page.first << " => " << page.second << "\n";
    }
    return 0;
}

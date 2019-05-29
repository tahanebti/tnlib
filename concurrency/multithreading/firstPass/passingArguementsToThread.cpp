#include <iostream>
#include <thread>
#include <string>

void threadCallback(int count, std::string text)
{
	std::cout << "Parameter 1: " << count << std::endl;
	std::cout << "Parameter 2: " << text << std::endl;
}

int main()
{
	std::thread newThread(threadCallback, 4, "Hello");
	newThread.join();

	std::cout << "Thread ended...." << std::endl;
	return 0;
}
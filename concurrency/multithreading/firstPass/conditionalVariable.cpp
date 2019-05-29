#include <iostream>
#include <thread>
#include <mutex>
#include <functional>
#include <condition_variable>

class Application
{
public:
	Application(): isDataReadingDone_(false){};
	~Application() = default;

	void loadDataFile()
	{
		std::cout << "Loading the file: " << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));

		std::lock_guard<std::mutex> guard(mutex_);

		isDataReadingDone_ = true;
		conditionVariable_.notify_one();
	}

	void mainTask()
	{
		std::cout << "Doing some handshaking...." << std::endl;

		std::unique_lock<std::mutex> mlock(mutex_); // mutex with RAII

		conditionVariable_.wait(mlock, std::bind(&Application::isDoneWithDataReading, this));
		std::cout << "Do processing On Loaded data ...." << std::endl;
	}

	bool isDoneWithDataReading()
	{
		return isDataReadingDone_;
	}

private:
	std::mutex mutex_;
	std::condition_variable conditionVariable_;
	bool isDataReadingDone_;
};

int main()
{
	Application app;
	std::thread thread_two(&Application::loadDataFile, &app);
	std::thread thread_one(&Application::mainTask, &app);

	thread_two.join();
	thread_one.join();

	return 0;
}



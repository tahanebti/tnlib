#include <iostream>
#include <thread>
#include <mutex>

class Application
{
public:
	Application(): isDoneWithLoading_(false){};
	~Application(){};

	void loadData()
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
		std::cout << "Loading data from XML...." << std::endl;

		std::lock_guard<std::mutex> lockGuard(mutex_);
		isDoneWithLoading_ = true;
	}

	void mainTask()
	{
		std::cout << "Do some handshaking " << std::endl;

		mutex_.lock();
		while(isDoneWithLoading_ != true)
		{
			mutex_.unlock();

			std::this_thread::sleep_for(std::chrono::milliseconds(1000));

			mutex_.lock();
		}
		mutex_.unlock();

		std::cout << "Do Processing on loaded data: " << std::endl;
	}

private:
	std::mutex mutex_;
	bool isDoneWithLoading_;
};


int main()
{
	Application app;

	std::thread thread_1(&Application::loadData, &app);
	std::thread thread_2(&Application::mainTask, &app);

	thread_2.join();
	thread_1.join();

	return 0;
}
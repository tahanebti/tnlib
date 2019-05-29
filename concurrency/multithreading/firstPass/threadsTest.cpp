#include <iostream>
#include <thread>

void logFunction(int count)
{
	for(int index = 0; index < count; index++)
	{
		std::cout << "logFunction: count = " << index << std::endl;
	}
}

class Log
{
public:
	void operator()(int count)
	{
		for(int index = 0 ; index < count; index++)
		{
		    std::cout << "Log class operator(): " << index << std::endl;
		}
	}

	void operator()()
	{
		std::cout << "Overloaded operator(): " << std::endl;
	}
};

auto lambdaLog = [](int count){
	for(int index = 0; index < count; index++)
	{
		std::cout << "Lambda expression: " << index << std::endl;
	}
};

int main()
{
	std::thread threadOne(logFunction, 4);
	std::thread threadTwo(Log(), 5); 
	std::thread threadThree(lambdaLog, 6);
	std::thread threadFour((Log()));
	/*Braces is needed as Log() is tmp obj & treated as func declation otherwise*/
	std::thread threadFive{Log()};

	threadOne.join();
	threadTwo.join();
	threadThree.join();
	threadFour.join();
	threadFive.join();

	return 0;
}
#include <thread>
#include <iostream>

void threadFunction()
{
	const int count = 90;
	for(;;)
	{
		for(int index = 0; index < count; index++)
			std::cout << "Executing \"threadFunction\" : " << index << std::endl;
	}
}

void threadFunctionTakingParameters(int count)
{
	for(;;)
	{
		for(int index = 0; index < count; index++)
			std::cout << "Executing \"threadFunctionTakingParameters\" : " << index << std::endl;
	}
}

void threadFunctionTwo(int count)
{
	for(;;) 
	{
		for(int index = 0; index < count; index++)
			std::cout << "Executing \"threadFunctionTwo\" : " << index << std::endl;
	}
}

int main()
{
	std::cout << "Starting new thread 1 ...." << std::endl;
	std::thread threadOne(threadFunction); //Passing function pointer to the thread as callback

	std::cout << "Starting new thread 2 ...." << std::endl;
	std::thread threadTwo(threadFunctionTakingParameters, 1000);

	void (*functionPointer)(int) = threadFunctionTwo;
	std::cout << "Starting new thread 3 ...." << std::endl;
	std::thread threadThree(functionPointer, 8000);

	std::cout << "Thread id [MainThread]: " <<std::this_thread::get_id() << std::endl;
	std::cout << "Thread id [threadOne]: " <<threadOne.get_id() << std::endl;
	std::cout << "Thread id [threadTwo]: " <<threadTwo.get_id() << std::endl;
	std::cout << "Thread id [threadThree]: " <<threadThree.get_id() << std::endl;


	threadOne.join(); //Wait for new thread to exit before exiting the main thread
	threadTwo.join();
	threadThree.join();

	std::cout << "Exiting main thread now: " << std::endl;

	return 0;
}
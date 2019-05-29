#include <thread>
#include <iostream>

class DataClass
{
public:
	DataClass(int count = 0): count_(count){};
	~DataClass() = default;

	void callBackFunction(int count)
	{
		count_ = count;
		for(int iter = 0; iter < count; iter++)
			std::cout << "Logging from callBackFunction...." << std::endl;
	}

	int count_;
};

int main()
{
	DataClass dataClass;
	DataClass dataClass_1(10);
	int DataClass::*pointerToCount = &DataClass::count_;
	void (DataClass::*pointerToCallback)(int) = &DataClass::callBackFunction;

	(dataClass.*pointerToCallback)(2);
	std::cout << "Count is : " << dataClass.*pointerToCount << std::endl;
	std::cout << "Count is : " << dataClass_1.*pointerToCount << std::endl;

	std::thread newThread(&DataClass::callBackFunction, &dataClass, 4);

	if (newThread.joinable())
		newThread.join();

	std::cout << "Reached end of the execution...." << std::endl;

	return 0;
}

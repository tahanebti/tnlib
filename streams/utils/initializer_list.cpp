#include <iostream>
#include <initializer_list>


template<typename Type>
auto average_list(std::initializer_list<Type> list) -> Type
{
	Type sum = 0;
	for (auto it = list.begin(); it != list.end(); it++)
	{
		sum += *it;
	}
	Type average = sum / list.size();
	return average;
}

//with object
class ExampleClass {
public:
	ExampleClass(int, int) { std::cout << "(int, int) ctor" << '\n'; }
	ExampleClass(std::initializer_list<int>) { std::cout << "initializer_list<int> ctor" << '\n'; }
};


int main()
{

	auto q = average_list({ 15.4, 10.7, 9.0 });
	cout << q << endl;

	cout << average_list({ 20,30,19,17,45,38 }) << endl;

	auto ad = average_list<double>({ 'A', 70, 65.33 });
	cout << ad << endl;

	//with object

	auto list = { 1, 2, 3 };    // list has type std::initializer_list<int>

	ExampleClass a(1, 2);	// (int, int) constructor is used
	ExampleClass b{ 1, 2 };	// initializer_list<int> constructor is used
	
	std::cout << std::endl;
}

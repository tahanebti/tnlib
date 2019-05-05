#include <iostream>

template<typename T, typename... Args>
long double sum_values(const T& t, const Args&... args);

template<typename T>
long double sum_values(const T& t);

long double sum_values();

int main()
{
	using namespace std;
	cout << sum_values(2, 5, 10, 25, 10.5, 'C') << endl;
	system("pause");
	return 0;
}

template<typename T, typename ...Args>
long double sum_values(const T & t, const Args & ...args)
{

	return sum_values(args...) + t;
}

template<typename T>
long double sum_values(const T & t)
{
	return t;
}

long double sum_values()
{
	return 0;
}
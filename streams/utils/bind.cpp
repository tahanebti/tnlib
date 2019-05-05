#include <iostream>
#include <functional>

class Test
{
public:

	int add(int a, int b, int c){
		return a + b + c;
	}
};

int run(std::function<int(int, int)> op){
	return op(5, 3);
}

int main()
{
	Test t;
	auto cal = bind(&Test::add, t, _2, 100, _1);
	cout<<run(cal)<<endl;
	std::cout << std::endl;
}

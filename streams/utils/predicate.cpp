/*
*       Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*/

#include <iostream>
using namespace std;

//predicate using function pointer
int add(int a, int b){return a + b;}

//predicate using function pointer
{
	int (*predicate)(int, int);
	
	int add(int a, int b){return a + b;}

	int do_op(predicate op, int a, int b){
		return op(a, b);
	}
}

//predicate using pair operation 
{
	pair<int, int> op(int a, int b){
    return make_pair(a, b);
	}

	int add(pair<int, int> p){
		return p.first + p.second;
	}
	int mul(pair<int, int> p){
		return p.first * p.second;
	}

	cout<<add(op(5, 3));
	cout<<mul(op(5, 3));

}

//predicate using functor wrapper 
{
	template <typename T>
	struct add
	{
		T operator() (const T& x, const T& y) const { return x + y; }
	};

	void testing()
	{
	  	add<int> functor;
		std::cout << functor(11, 22) << std::endl;		    // 33
	}
}

//predicate using std:: functor
{
	//std::plus
	std::plus<> functor;                         // defaults to std::plus<void> 
	std::cout << functor(234, 432) << ' ' << functor(1.101, 2.0405) << std::endl;
	std::cout << std::endl;
}


//predicate using std::function
{
	int do_oper(int a, int b, std::function<int(int, int)> filter){
    return filter(a, b);
	}

	auto add = [](int a, int b){ return a + b;};

	cout<<do_oper(5, 3, add));
	cout<<do_oper(5, 3, mul));
}
//predicate using std::bind

//predicate using std::mem_fm


//predicate using lambda

int main() {

	return 0;
}

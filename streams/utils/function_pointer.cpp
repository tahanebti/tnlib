//
//  function 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


/**
    Notes :

    constexpr inline return_type function(argument) noexcept{
    
    }
    
    static : Makes static storage, can be used on local, global or class member variable
    extern : References (in .h) or declares (in .cpp) an externally linked global variable
    register : May store variable in register, not on stack, no address and can't be global
    volatile : Don't cache or optimize value, can prevent cache race conditions
    mutable : Value changes ignored for bitwise const checking; used to show internal synchronization
    const : Can store variable in read-only memory or value repaced at compile time
    constexpr : Evaluates at compile time, will store in read-only memory
    ::myInt : Allows access to global variables when shadowed by local variables
**/


#include <bits/stdc++.h>
using namespace std;


/********************************* pass one argument ***************************************/

int f(int);
int f(int*);
int f(int&);
int f(int&&);

//function pointer as predicate
void (*predicate)(void);
/**
	//function pointer array
		p 			data 
		*p 			pointer
		(*p)[4]		pointer to first elements array
		*(*p)[4]	pointer of pointer
		*(*p)[4]()	pointer to function

**/
/********************************* pass two argument ***************************************/

//pass two argument
int f(int, int);

int add(int a, int b){return a + b;}

//function pointer as predicate
int (*predicate)(int, int);
int do_oper(predicate op, int a, int b){
	return op(a, b);
}

//using pair operation as filter operation
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

//using std::function<> as filter operation
int do_oper(std::function<int(int, int)> filter, int a, int b){
    return filter(a, b);
}

auto add = [](int a, int b){ return a + b;};

cout<<do_oper(add, 5, 3));
cout<<do_oper(mul, 5, 3));


//functor wrapper as a predication
template<typename T>
class Functor {
  T f;
public:
  Functor(T t){
      f = t;
  }
  T& operator()(){
    return f;
  }
};


void testing()
{
  Functor<int (*)(int, int)> f(add);
  cout << f()(2,3);
}

/********************************* pass three arguments ***************************************/
//pass three argument
int f(int, int, int);

int three_add(int a, int b, int c){
	return add(add(a,b),c);
}

//using function pointer as perdicate
int (*predicate)(int, int);
int do_oper(predicate op, int a, int b, int c){
	return op(op(a, b),c);
}

//using tuple wrapper as predicate
int do_oper(std::function<int(int, int)> filter, int a, int b, int c){
    return filter(filter(a, b),c);
}

//using a functor wrapper as predicate
template<typename T>
class Functor {
  T f;
public:
  Functor(T t){
      f = t;
  }
  T& operator()(){
    return f;
  }
};


void testing()
{
  Functor<int (*)(int, int, int)> f(add);
  cout << f()(2,3,6);
}
/********************************* pass n arguments ***************************************/
void print(std::initializer_list<int> const l){
	for (const auto& e : l)
		cout << e << std::endl;
}

const int n = 10;
int arr[n] = {0};
memset(arr, 0, sizeof(arr));

int arr[] = {}
int length = sizeof(arr)/sizeof(arr[0]);

auto length = std::extent(decltype(arr));

int f(int arr[], size_t n);
int f(int* arr, size_t n);
int f(int* arr, int begin ,int end);

//function pointer as a predicate
int (*predicate)[4](int , int);
int (predicate)[4] = {&add, &sub, &mul, &division};

int f(vector<int>& v);
int f(deque<int>& d);

int f(list<int>& l);
int f(stack<int>& s);
int f(queue<int>& q);
int f(priorty_queue<int>& pq);
int f(set<int>& sv);
int f(multiset<int>& v);
int f(map<int>& v);
int f(multimap<int>& v);
/********************************* return two arguments ***************************************/
int pair<int, int> f(int);
//array of pair
int pair<int, int> ap[1000]
//vector of pair
int vector<pair<int, int>> vp;

/********************************* return tuple arguments ***************************************/
int tuple<int, int, int> f(int);
/********************************* return n arguments ***************************************/
int* f(int)
unique_ptr<int> f(int);
shared_ptr<int> f(int);

vector<int> f(int);
set<int> f(int);
map<int, int> f(int);

auto main() -> int
{
	//the following line at the beginning of the code
	// make input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


    for (int i=0; i < argc; i++) {
        cout<<"Argument : "<<i<<endl;
        cout<<argv[i]<<endl;
    }
    
	return 0;
}

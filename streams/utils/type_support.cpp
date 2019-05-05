/*
*       Algorithms & Data structures
*       Author : Taha Nebti
*       github : github.com/tahanebti
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	//basic built-in type
		//intergral type
		{
			char c = 'a';
			bool flag = true;        	//1 byte = 8 bites = (1 << 7) - 1
        	short s = 42;				//4 byte = 16 bites = (1 << 15) - 1
        	int d = 42;      			//4 byte = 32 bites = (1 << 31) - 1
        	long l = 42l;        	    //8 byte = 64 bites = (1 << 63) - 1

        	unsigned ud = 42;

			//template<typename T> T n = 42; //template declaration cannot appear at block scope

			typedef long long ll;
			using ll = long long;

			auto number {42};
			// with prefixes
            auto t1{ L"text" };
            auto hx{ 0xBAD };

            // with suffixes
            auto a{ 42u };     	// unsigned int
            auto ld = 42ll ;     // long long
            auto f{ 42.5f };   // float
		}
		//floating point type
		{
			float fi = 42.5f;
        	double fd = 42.5f;
		}
		//additional types
		{
			size_t ul = 42; 		//unsigned long
			//ptrdiff_t         //used for an arithmetic pointer or array index
			//nullptr_t         //is the type of null pointer
			//byte
		}
		//reference type
		{
			int number = 42;

			int* ptr = &number; 			//pointer to the @number

			int& ref = number;
			int&& rri = std::move(number); // binds directly to number


            auto uintptr{0};
            auto p{nullptr};

            auto pp = std::make_shared<int>(number);
		}
		//string
		{
			const char* str;
			string str;
		}
		//numeric library
		{
			//array of number
			valarray<int> varr; //array class of number
			complex<int> c; 	//ax + i
		}
		//class pair & tuple of non homogenous type
		{
			pair<int, string> p;
			tuple<int, double, string> t;
		}
		//type of function type
		{
			auto a = f();
		}
		//user defined type
		{
			int array[] = {};
			enum{};
			union{};
			struct A{};	//public by default
			class B{};	//private by default
			class C : B{};

			//stl container
			vector<int> v; 					//dynamic array
			vector<vector<int>> vv;			//matrix
			vector<pair<int, string>> vp 
			list<int> l;
			set<int, int> s;
			map<int , int> m;
		}
		//type_info
		{
		    auto a = 42;
		    size_t b = 42;
		    auto c = 42ll;

            cout<<"size int : "<<sizeof(a)<<" bytes"<<endl;
            cout<<"size size_t : "<<sizeof(b)<<" bytes"<<endl;
            cout<<"auto long long: "<<sizeof(c)<<" bytes"<<endl;

            cout<<"typeid int : "<<typeid(a).name()<<endl;
            cout<<"typeid size_t : "<<typeid(b).name()<<endl;
            cout<<"typeid auto : "<<typeid(c).name()<<endl;

            cout<<"max int : "<<numeric_limits<int>::min()<<endl;
            cout<<"max int : "<<numeric_limits<int>::max()<<endl;
            cout<<"max unsigned int : "<<numeric_limits<unsigned int>::max()<<endl;
            cout<<"max size_t : "<<numeric_limits<size_t>::max()<<endl;

			//cout<<std::alignof(int)<<endl; //return value of max size_t


		}
		//type_traits
		{
			cout << std::boolalpha;            // Print true/false instead of 1/0
			cout << std::is_void<void>::value << '\n';	                   // true
			cout << std::is_void<int>::value << '\n';					   // false

			cout << std::is_integral<int>::value << '\n';                	 // true
			cout << std::is_floating_point<float>::value << '\n';       	  // true
			cout << std::is_arithmetic<int>::value << '\n';          	   	 //integral or deciaml
			//type relationship
			cout << std::is_same<int, signed int>::value << '\n';			//true
			cout << std::is_same<int, unsigned int>::value << '\n';			//false

			cout << std::is_array<int>::value << '\n';
			cout << std::is_array<int[3]>::value << '\n';
			cout << std::rank<int[3]>::value << '\n';					//1 number of dimenssion
			cout << std::rank<int[3][3]>::value << '\n';					//2
			cout << std::extent<int[4][5]>::value << '\n';				//3 number of elements of dimension
			int arr[] = {1,3,4,5};
			cout << std::extent<decltype(arr)>::value << '\n';		//array size

			class A{};
			cout << std::is_class<A>::value << '\n';    // true
			cout << std::is_object<A>::value << '\n';
			//type relationship
			class B : A{};
			cout << std::is_base_of<A, B>::value << '\n';				//a2b: true base 2 derived
			cout << std::is_base_of<B, A>::value << '\n';				//b2a: false

			cout << std::is_function<int(void)>::value << '\n';           // true
			cout << std::is_function<decltype(main)>::value << '\n';      // true

			cout << std::is_pointer<decltype(&main)>::value << '\n';      // true
			cout << std::is_pointer<int*>::value << '\n';
			cout << std::is_null_pointer<decltype(nullptr)>::value << '\n';//true					   // false

			cout << std::is_reference<int>::value << '\n';   		      // true
			cout << std::is_reference<int&>::value << '\n';               // true
			cout << std::is_lvalue_reference<int&>::value << '\n';        // true
			cout << std::is_reference<int&&>::value << '\n';              // true
			cout << std::is_rvalue_reference<int&&>::value << '\n';       // true

			struct AA { void f() {}; };

			void(AA::* p)() = &AA::f;
			std::cout << std::is_member_function_pointer<decltype(p)>() << '\n';// true

			std::cout << std::endl;
		}
	return 0;
}

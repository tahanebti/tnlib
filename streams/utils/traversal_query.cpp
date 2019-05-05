//
//  traversal query
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

void print(int number){
    cout << setw(2) << setfill('0')
         << number << "  ";
}



/********************************* sequence ***************************************/

int print_sequence_forward(int end){
	for (int i = 0; i < end; ++i){
		cout<<i<<" ";
	}
	cout<<'\n';
}

int print_sequence_forward2(int end){
	int i = 0;
	while(i < end){
		cout<<i<<" ";
		++i;
	}
	cout<<'\n';
}

int print_sequence_forward3(int end){
	int i = 0;
	do{
        cout<<i<<" ";
        ++i;
	}while(i < end);
	cout<<'\n';
}

int print_sequence_backward(int end){
	for(int i = 0; i < end; ++i){
		cout<<end-i-1<<" ";
	}
	cout<<'\n';
}

int print_sequence_backward2(int end){
	for(int i = end-1; i >= 0; --i){
		cout<<i<<" ";
	}
	cout<<'\n';
}


int print_sequence_backward3(int end){
	while(end > 0){
        --end;
		cout<<end<<" ";
	}
	cout<<'\n';
}

int print_sequence_backward4(int end){
	do{
        --end;
		cout<<end<<" ";
	}while(end > 0);
	cout<<'\n';
}




//1 -1 1 -1 1 -1 1 -1 1 -1 1
int print_sequence_pow(int end){
	for (int i = 0; i <= end; ++i){
		cout<<pow(-1,i)<<" ";
	}
	cout<<'\n';
}

//0 -1 2 -3 4 -5 6 -7 8 -9 10
int print_sequence_pow2(int end){
	for (int i = 0; i < end; ++i){
		cout<<pow(-1,i)*i<<" ";
	}
	cout<<'\n';
}

//-0 1 -2 3 -4 5 -6 7 -8 9 -10
int print_sequence_pow3(int end){
	for (int i = 0; i < end; ++i){
		cout<<pow(-1,i+1)*i<<" ";
	}
	cout<<'\n';
}

// X 0 1 2  X 3 4 5  X 6 7 8  X 9 10
int print_sequence_cyle_rotation(int end){
	for (int i = 0; i < end; ++i){
		if(i % 3 == 0) cout<<" X ";
        cout<<i<<" ";
	}
	cout<<'\n';
}

//(0) 1 (2) 3 (4) 5 (6) 7 (8) 9
int print_sequence_cyle_rotation2(int n){
	bool open = false;
    for(int i = 0; i<n; ++i){
        if(i % 2 == 0 && !open){
            cout<<"("; open = true;
        }
        cout<<i;
        if(open){
          cout<<")"; open = false;
        }
        cout<<" ";
    }
	cout<<'\n';
}




/********************************* segments ***************************************/

int print_segment_forward(int begin, int end){
	for (int i = begin; i < end; ++i){
		cout<<i<<" ";
	}
	cout<<'\n';
}



int print_segment_forward2(unsigned begin, int end){
	for (; begin < end; ++begin){
		cout<<begin<<" ";
	}
	cout<<'\n';
}

int print_segment_forward3(int begin, int end){
	while(begin < end){
		cout<<begin<<" ";
		++begin;
	}
	cout<<'\n';
}

int print_segment_forward4(int begin, int end){
	do{
        cout<<begin<<" ";
        ++begin;
	}while(begin != end); //begin <= end || begin>= 0 || end <= 0 || begin != end
	cout<<'\n';
}

int print_segment_backward(int begin, int end){
	for(begin = end-1;  begin>= 0; --begin){
		cout<<begin<<" ";
	}
	cout<<'\n';
}

int print_segment_backward2(unsigned begin, int end){
	for (; begin < end; ++begin){
		cout<<end-begin-1<<" ";
	}
	cout<<'\n';
}

int print_segment_backward3(int begin, int end){
	begin = end;
	while(begin >= 0){
		cout<<begin<<" ";
		--begin;
	}
	cout<<'\n';
}

int print_segment_backward4(int begin, int end){
	while(end >= 0){
		cout<<end<<" ";
		--end;
	}
	cout<<'\n';
}

int print_segment_pow(int begin, int end){
	for (int i = begin; i < end; ++i){
		cout<<pow(-1,i)*i<<" ";
	}
	cout<<'\n';
}

int print_segment_pow2(int begin, int end){
	for (int i = begin; i < end; ++i){
		cout<<pow(-1,i+1)*i<<" ";
	}
	cout<<'\n';
}

int print_segment_cyle_rotation(int begin, int end){
	bool open = false;
    for(int i = begin; i <end; ++i){
        if(i % 2 == 0 && !open){
            cout<<"{"; open = true;
        }
        cout<<i;
        if(open){
          cout<<"}"; open = false;
        }
        cout<<" ";
    }
	cout<<'\n';
}

/********************************* array iterative forward ***************************************/
void array_create(int arr[], size_t n){
	for (int i = 0; i < n; ++i){
		arr[i] = i;
	}
	cout<<'\n';
}
//forward iterative for, while, do{}while
void print_array_forworad(int arr[], size_t n){
	for (int i = 0; i < n; ++i){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
}

void print_array_forworad2(int* arr, size_t n){
	int i = 0;
	while(i<n){
		cout<<arr[i]<<" ";
		++i;
	}
	cout<<'\n';
}

void print_array_forworad3(int* arr, size_t n){
	int i = 0;
	do{
		cout<<arr[i]<<" ";
		++i;
	}while(i < n);
	cout<<'\n';
}



int print_array_pow(int* arr, size_t n){
	for (ptrdiff_t i = 0; i < n; ++i){
		cout<<pow(-1,i+1)*i<<" ";
	}
	cout<<'\n';
}

int print_array_cyle_rotation(int*arr, size_t n){
	bool open = false;
    for(int i = 0; i < n; ++i){
        if(arr[i] % 2 == 0 && !open){
            cout<<"{"; open = true;
        }
        cout<<arr[i];
        if(open){
          cout<<"}"; open = false;
        }
        cout<<" ";
    }
	cout<<'\n';
}


int print_array_cyle_rotation2(int*arr, size_t n){
	bool open = false;
    int top = 0;
    while(top < n){
        if(arr[top] % 2 == 0 && !open){
            cout<<"{"; open = true;
        }
        cout<<arr[top];
        if(open){
          cout<<"}"; open = false;
        }
        cout<<" ";
        ++top;
    }
	cout<<'\n';
}




/********************************* array iterative backward ***************************************/

//backward iterative
void print_array_backward(int arr[], size_t n){
	for (int i = 0; i < n; ++i){
		cout<<arr[n-i-1]<<" ";
	}
	cout<<'\n';
}

void print_array_backward2(int arr[], size_t n){
	for (int i = n-1; i >=0 ; --i){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
}

void print_array_backward3(int* arr, size_t n){
	int i = n;
	while(i<n){
		cout<<arr[i]<<" ";
		--i;
	}
	cout<<'\n';
}

int print_array_backward4(int* arr, size_t n){
	//int i = n;
	do{
		--n;
		cout<<arr[n]<<" ";
	}while(n != 0); //begin <= end || begin>= 0 || end <= 0 || begin != end
	cout<<'\n';
}

void Swap(int* arr,  int begin, int end ){
    int temp = arr[begin];
    arr[begin] = arr[end];
    arr[end] = temp;
}



void print_array_backward5( int * arr, size_t n){
	for(int i = 0; i<n/2; ++i ){
		Swap(arr, i, n-i-1);
	}
	for(int i = 0; i<n; ++i ){
		cout<<arr[i]<<" ";
	}
	cout<<'\n';
}

/********************************* array forward pointer arithmetic ***************************************/

//pointer arithmetic
void print_array_forward_ptr(int * arr, size_t n ){
	for ( ptrdiff_t i = 0; i < n; i++ ){
		if ( i > 0 )
			cout<<' ';
		cout<<*(arr+i);
	}
	cout<<'\n';
}

//c style
void print_array_forward_ptr(int * arr, size_t n ){
	for ( const int* p = &arr[0]; p != &arr[0]+n; ++p ){
		cout<<*p<<" ";
	}
	cout<<'\n';
}

void print_array_forward_ptr2(int * arr, int begin, int end){
	for ( ptrdiff_t i = begin; i < end; i++ ){
		if ( i > 0 )
			cout<<' ';
		cout<<*(arr+i);
	}
	cout<<'\n';
}



void print_array_forward_ptr3(int* begin, int* end){
	for ( ; begin != end; ++begin ){
		if ( begin > 0 )
			cout<<' ';
		cout<<*begin;
	}
	cout<<'\n';
}

void print_array_forward_ptr4(int* begin, int* end){
	while(begin != end){
		cout<<*begin<<" ";
		++begin ;
	}
	cout<<'\n';
}

void print_array_forward_ptr5(int* begin, int* end){
	do{
        ++begin ;
        cout<<*begin<<" ";
	}while(begin != end);
	cout<<'\n';
}



template<class Iterator>
void print_array_forward_generic(Iterator begin, Iterator end){
	while(begin != end){
		cout<<*begin<<" ";
		++begin ;
	}
	cout<<'\n';
}

//return iterator
int* print_array_forward_ptr6(int* begin, int* end){
	while(begin != end){
		cout<<*begin<<" ";
		++begin ;
	}
	cout<<'\n';
}

vector<int> print_array_forward_ptr7(int* begin, int* end){
	while(begin != end){
		cout<<*begin<<" ";
		++begin ;
	}
	cout<<'\n';
}


template<class Iterator>
Iterator print_array_forward_generic2(Iterator begin, Iterator end){
	while(begin != end){
		cout<<*begin<<" ";
		++begin ;
	}
	cout<<'\n';
}




/********************************* array backward pointer ***************************************/

void print_array_backward_ptr( int * arr, size_t n){
	for ( int i = 0; i < n; i++)
		cout<<*(arr+n-i-1)<<" ";
	cout<<'\n';
}

void print_array_backward_ptr2( int * arr, size_t n){
	for ( int i = n-1;  i >= 0; --i)
		cout<<*(arr+i)<<" ";
	cout<<'\n';
}




/********************************* random access forward iterator ***************************************/

int print_vector_random_access_forward_iterator(vector<int>& v){
    for(size_t i = 0; i< v.size(); ++i){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

//C++ correct forward iterator
int print_vector_random_access_forward_iterator2(vector<int>& v){
    for(vector<int>::iterator it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<'\n';
}

//correct forward iterator and tiny
int print_vector_random_access_forward_iterator3(vector<int>& v){
    for(auto it = v.begin(); it != v.end(); ++it){
        cout<<*it<<" ";
    }
    cout<<'\n';
}

int print_vector_random_access_forward_iterator4(vector<int>& v){
    for(auto& i : v){
        cout<<i<<" ";
    }
    cout<<'\n';
}

//c++11 functional programming
int print_vector_random_access_forward_functional(vector<int>& v){
  std::for_each(begin(v), end(v), [](int n){ std::cout << n <<" "; });
  cout<<'\n';
}

template <class Iterator, class Function>
Function For_each(Iterator begin, Iterator end, Function f) {
    while (begin != end) f(*begin++);
    return f;
}

int print_vector_random_access_my_for_each(vector<int>& v){
  For_each(begin(v), end(v), [](int n){ std::cout << n <<" "; });
  cout<<'\n';
}

/********************************* random access backward iterator ***************************************/
//naive backward
int print_vector_random_access_backward_iterator(vector<int>& v){
    for(size_t i = v.size()-1; i> 0; --i){
        cout<<v[i]<<" ";
    }
    cout<<'\n';
}

//correct backward
int print_vector_random_access_backward_iterator2(vector<int>& v){
    for(vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); ++it){
        cout<<*it<<" ";
    }
    cout<<'\n';
}

//correct backward and tiny
int print_vector_random_access_backward_iterator3(vector<int>& v){
    for(auto it = v.rbegin(); it != v.rend(); ++it){
        cout<<*it<<" ";
    }
    cout<<'\n';
}

//c++11 functional programming
int print_vector_random_access_backward_functional(vector<int>& v){
  std::for_each(v.rbegin(),v.rend(), [](int n){ std::cout << n <<" "; });
  cout<<'\n';
}



int print_vector_random_access_my_for_each_backward(vector<int>& v){
  For_each(v.rbegin(),v.rend(), [](int n){ std::cout << n <<" "; });
  cout<<'\n';
}


/********************************* backward for_each ***************************************/
void print_init(std::initializer_list<int> const l){
  for (const auto& e : l)
    cout << e << std::endl;
}

//template args
//auto sum(){return 0;}
//template<typename T, typename... Args>
//auto sum(T a, Args...args){return a + sum(args...);}
//cout<<sum(1,2,4);

/********************************* recursion ***************************************/
/*
Recursion
A function (or method) that invokes itself again


	//arithmetic  sequence  => f(n) = a + f(n-1)*d
	//geomethri sequence 	  => f(n) = a*r^n-1


*/

//Time limit exceeded
void func(){
  func();
}

void print_sequence_recursive2(int end){
   //base case
   if(end == 0) return;
   //recursive case
   cout<<end<<" ";
   return print_sequence_recursive2(end-1);
}

// this is exactly like the fibonacci sequence, where the answer for n is equal to the sum of the answers for n-1 and n-2
// Fib is very easy to compute with a recursive function:

int recursive(int n){
    if (n == 0 || n == 1) return 1;
    return recursive(n-1) + recursive(n-2);
}

// but this has O(n^2) as we have to compute two recursive calls for every call with n greater than 1
// If we store previous answers in an array we can reduce the time complexity to O(n)
// this is called memoization

int storage[9] = {0};
int recursive2(int n){
    if (storage[n] != 0) return storage[n];
    if (n == 0 || n == 1) return 1;
    return storage[n] = recursive2(n - 1) + recursive2(n - 2);
}

// We can still be more memory efficient, we don't need a full array with all the answers, we only need to lookup the last two
// and keep updating them.
int small[1] = {-1};
int recursive3(int n){
    if (small[0] <= 0 && small[1] <= 0){
        if (small[0] > small[1]) return small[0];
        else return small[1];
    }
    if (n == 0 || n == 1) return 1;
   
    if (small[1] < small[0]) return small[0] = recursive3(n - 1) + recursive3(n - 2);
    else return small[1] = recursive3(n - 1) + recursive3(n - 2);
}
//One value f(end)
	//traverse             	-> return f(end-1)
	//accumulate by one 	-> return 1 + f(end-1)
	//accumulate by number 	-> return end + f(end-1)
	//product by number    	-> return end * f(end-1)
	//fibbonaci				-> return f(end-1) + f(end+2)

//two value f(begin, end)
	//traverse  			-> return f(begin+1, end-1)
	//addition 				-> return f(begin+1, end-1)
	//difference 			-> return f(begin-1, end-1)
	//product    			-> return begin + f(begin, end-1)
	//division    			-> return  1 + f(begin-end, end) ;

// n value f(container, begin, end)
	//traverse				-> return f(container, begin+1, end)
	//min 					-> arr[begin] < arr[0] ? arr[begin] : f(arr, begin+1, end);

//backtracking
//dp
  //buttom-up : memoization
  //buttom-down : tabulation
//divide and conque
	//partition + merging
//greedy


//traverse object oriented class range
template <class T> class range {
private:
    class iter {
    private:
        T at;
    public:
        iter(T at) : at(at) {}
        bool operator!=(iter const& other) const { return at != other.at; }
        T const& operator*() const { return at; }
        iter& operator++() { ++at; return *this; }
    };

    T begin_val;
    T end_val;
public:
    range(T begin_val, T end_val) :
        begin_val(begin_val), end_val(end_val) { }
    iter begin() { return iter(begin_val); }
    iter end() { return iter(end_val); }
};


template<long FROM, long TO>
class Range {
public:
    // member typedefs provided through inheriting from std::iterator
    class iterator: public std::iterator<
                        std::input_iterator_tag,   // iterator_category
                        long,                      // value_type
                        long,                      // difference_type
                        const long*,               // pointer
                        long                       // reference
                                      >{
        long num = FROM;
    public:
        explicit iterator(long _num = 0) : num(_num) {}
        iterator& operator++() {num = TO >= FROM ? num + 1: num - 1; return *this;}
        iterator operator++(int) {iterator retval = *this; ++(*this); return retval;}
        bool operator==(iterator other) const {return num == other.num;}
        bool operator!=(iterator other) const {return !(*this == other);}
        reference operator*() const {return num;}
    };
    iterator begin() {return iterator(FROM);}
    iterator end() {return iterator(TO >= FROM? TO+1 : TO-1);}
};



template<class BidirIt>
void my_reverse(BidirIt first, BidirIt last)
{
    typename std::iterator_traits<BidirIt>::difference_type n = std::distance(first, last);
    --n;
    while(n > 0) {
        typename std::iterator_traits<BidirIt>::value_type tmp = *first;
        *first++ = *--last;
        *last = tmp;
        n -= 2;
    }
}

/**
	iterator type :

    Random access iterator :
      array, vector, deque
    Bidirectional iterator :
      list, map, set
    forward iterator :
      forward_list, unordred_map, unordred_set
**/

template <class RAIter>
void alg(RAIter, RAIter, std::random_access_iterator_tag)
{
    std::cout << "alg() called for random-access iterator\n";
}


template< class BDIter >
void alg(BDIter, BDIter, std::bidirectional_iterator_tag)
{
    std::cout << "alg() called for bidirectional iterator\n";
}

template< class BDIter >
void alg(BDIter, BDIter, std::forward_iterator_tag)
{
    std::cout << "alg() called for forward iterator\n";
}


template< class Iter >
void alg(Iter first, Iter last)
{
    alg(first, last,
        typename std::iterator_traits<Iter>::iterator_category());
}


auto main() -> int
{
	//the following line at the beginning of the code
	// make input and output more efficient
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    cout<<"--number--"<<endl;
    print(10);
    cout<<'\n';
    cout<<"--sequence forward--"<<endl;
    print_sequence_forward(10);
    print_sequence_forward2(10);
    print_sequence_forward3(10);
    cout<<"--sequence backward--"<<endl;
    print_sequence_backward(10);
    print_sequence_backward2(10);
    print_sequence_backward3(10);
    print_sequence_backward4(10);
    cout<<"--sequence recursive--"<<endl;
    print_sequence_recursive(10);
    cout<<'\n';
    print_sequence_recursive2(10);
    cout<<'\n';
    //print_sequence_pow(10);
    cout<<"--sequence tricks--"<<endl;
    print_sequence_pow2(10);
    print_sequence_pow3(10);
    print_sequence_cyle_rotation(10);
    print_sequence_cyle_rotation2(10);

    cout<<"--segment forward--"<<endl;
    print_segment_forward(0, 10);
    print_segment_forward2(0, 10);
    print_segment_forward3(0, 10);
    print_segment_forward4(0, 10);
    cout<<"--segment backward--"<<endl;
    print_segment_backward(0, 10);
    print_segment_backward2(0, 10);
    print_segment_backward3(0, 10);
    print_segment_backward4(0, 10);
    cout<<"--segment tricks--"<<endl;
    print_segment_pow(0,10);
    print_segment_pow2(0,10);
    print_segment_cyle_rotation(0, 10);

    cout<<"--array iterative forward--"<<endl;
    const int n = 10;
    int arr[n] = {0};
    memset(arr, 0, sizeof(arr));

    array_create(arr, n);


    //int arr[] = {6,4,8,4,6,8,3,7,9};

    cout <<"is array?: "<< std::is_array<decltype(arr)>::value << '\n';
    cout <<"number of dimension :"<< std::rank<decltype(arr)>::value << '\n';

    int len = sizeof(arr) / sizeof(arr[0]);
    cout<<" array size using sizeof: " <<len<<endl;
    cout <<"array size using extent: "<< std::extent<decltype(arr)>::value << '\n';

    print_array_forworad(arr, n);
    print_array_forworad2(arr, n);
    print_array_forworad3(arr, n);
    print_array_pow(arr, n);
    print_array_cyle_rotation2(arr, n);

    cout<<"--array iterative backward--"<<endl;
    print_array_backward(arr, n);
    print_array_backward2(arr, n);
    print_array_backward3(arr, n);
    print_array_backward4(arr, n);
    print_array_backward5(arr, n);

    cout<<"--array pointer forward--"<<endl;

    print_array_forward_ptr(arr, n);
    print_array_forward_ptr2(arr, 0, n);

    int* begin = &arr[0];
    int* end = &arr[n];

    print_array_forward_ptr3(begin, end);

    auto first = std::begin(arr);
    auto last = std::begin(arr);

    print_array_forward_ptr4(first, last);

    cout <<"--pass generic iterator--: "<<endl;
    print_array_forward_generic(std::begin(arr), std::end(arr));

    //return iterator
    *print_array_forward_ptr6(std::begin(arr), std::end(arr));
    int* ptr = print_array_forward_ptr6(std::begin(arr), std::end(arr));

    cout <<"is pointer?: "<< std::is_pointer<decltype(ptr)>::value << '\n';

    cout <<"--pass & return generic iterator--: "<<endl;
    *print_array_forward_generic2(std::begin(arr), std::end(arr));

    cout<<"--array pointer backward--"<<endl;
    print_array_backward_ptr(arr, n);
    print_array_backward_ptr2(arr, n);


    cout<<"--random access forward iterator --"<<endl;
    //array copy
    //method 1 :
    {
        //vector<int> v(arr, arr+n);
    }
    //method 2 : vector + vector
    {
        //v.assign(arr, arr+n);
    }
    //Method 3 : copy using back_inserter
    {
        //copy(&arr[0], &arr[n], back_inserter(v));
    }
    //Method 4 : same as 1 but extend the vector by the size of the array
    {
        //v.reserve(v.size()+n);
        //copy(&arr[0], &arr[n], back_inserter(v));
    }
    //method 5 : using old memcpy
    {
        //v.reserve(v.size()+n);
        //memcpy(&v[v.size()-n], &arr[0], n*sizeof(int));
    }
    //method 6 : vector::insert
    {
        v.insert(v.end(), &arr[0], &arr[n]);
    }
    vector<int> v;


    reverse(v.begin(), v.end());

    print_vector_random_access_forward_iterator(v);
    print_vector_random_access_forward_iterator2(v);
    print_vector_random_access_forward_iterator3(v);
    print_vector_random_access_forward_functional(v);
    print_vector_random_access_my_for_each(v);


    auto it = v.begin();
    auto nx = std::next(it, 2);
    auto pv = std::prev(it, 2);

    std::cout << *it <<" "<<*nx<<" "<<*pv
              << "\ndistance(first, last) = "
              << std::distance(v.begin(), v.end()) << '\n'
              << "\ndistance(last, first) = "
              << std::distance(v.end(), v.begin()) << '\n';

    std::advance(it, 2); //increment by n
    std::cout << *it <<" "<<*nx<<" "<<*pv<<endl;

    cout<<"--random access backward iterator --"<<endl;
    print_vector_random_access_backward_iterator(v);
    print_vector_random_access_backward_iterator2(v);
    print_vector_random_access_backward_iterator3(v);
    print_vector_random_access_backward_functional(v);
    print_vector_random_access_my_for_each_backward(v);

    cout<<"--bidirectional forward iterator--"<<endl;
    cout<<"--bidirectional backward iterator--"<<endl;

    cout<<"--forward iterator--"<<endl;
    cout<<"--backward iterator--"<<endl;
    //vector<int> vv(arr, arr+n);
    //print_forward_iterator(vv);







//stream iterator
std::istringstream str("0.1 0.2 0.3 0.4");
    std::partial_sum(std::istream_iterator<double>(str),
                     std::istream_iterator<double>(),
                     std::ostream_iterator<double>(std::cout, " "));

    std::istringstream str2("1 3 5 7 8 9 10");
    std::cout << "\nThe first even number is " <<
        *std::find_if(std::istream_iterator<int>(str2),
                      std::istream_iterator<int>(),
                      [](int i){return i%2 == 0;})
        << ".\n";



//iterator adapter

// std::find requires an input iterator
    auto range = Range<15, 25>();
    auto itr = std::find(range.begin(), range.end(), 18);
    std::cout << *itr << '\n'; // 18

    // Range::iterator also satisfies range-based for requirements
    for(long l : Range<3, 5>()) {
        std::cout << l << ' '; // 3 4 5
    }
    std::cout << '\n';


std::string s = "Hello, world";
    std::reverse_iterator<std::string::iterator> r = s.rbegin();
    r[7] = 'O'; // replaces 'o' with 'O'
    r += 7; // iterator now points at 'O'
    std::string rev(r, s.rend());
    std::cout << rev << '\n';



//std::vector<int> v{1, 2, 3, 4, 5};
    my_reverse(v.begin(), v.end());
    for (int n : v) {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::list<int> l{1, 2, 3, 4, 5};
    my_reverse(l.begin(), l.end());
    for (auto n : l) {
        std::cout << n << ' ';
    }
    std::cout << '\n';



//std::vector<int> v;
    alg(v.begin(), v.end());

  //  std::list<int> l;
    alg(l.begin(), l.end());

    std::unordered_map<int, int> um;
    alg(um.begin(),um.end());

	return 0;
}

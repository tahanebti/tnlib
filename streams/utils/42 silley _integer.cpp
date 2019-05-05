#include <bits/stdc++.h>

using namespace std;

void print(int* arr, size_t n){
    for(int i =0; i<n; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

void print2(int* arr, int begin, int end){
    for(int i =begin; i<end; ++i){
        cout<<arr[i]<<" ";
    }
    cout<<'\n';
}

void print3(int* begin, int* end){
    for(; begin != end; ++begin){
        cout<<*begin<<" ";
    }
    cout<<'\n';
}

void print4(int * begin, int * end)
{
    for (int* it = begin; it != end; ++it)
        cout<<*it<<" ";
    cout<<'\n';
}

void print5(int * begin, int * end)
{
    for (auto it = begin; it != end; ++it)
        cout<<*it<<" ";
    cout<<'\n';
}

namespace my
{
    int print(int number)
    {
        cout<<setw(2)<<setfill('0')<<number<<" ";
    }
}

/** std::for_each & namespace **/
void print6(int * begin, int * end)
{
    std::for_each(begin, end, my::print);
}

/** user-defined container **/
template <size_t N>
struct myArr
{
    int* begin()  { return &data_[0]; }
    int* end()  { return &data_[N]; }
    int data_[N];
};


void print7(myArr<10>& arr)
{
    std::for_each(begin(arr), end(arr), my::print);
}

/** std::array **/
void print8(array<int, 10>& arr)
{
    std::for_each(std::begin(arr), std::end(arr), my::print);
}

/** std::vector **/
void print9(vector<int>& arr)
{
    std::for_each(std::begin(arr), std::end(arr), my::print);
}
/**
    Perhaps we need to rearrange the elements before printing out.
    Then we might want to pass by value so that we get a copy of the container.
    and sort the elements
**/
/** std::sort and pass by value (copy) **/
void print10(vector<int> arr)
{
    std::sort(std::begin(arr), std::end(arr));
    std::for_each(std::begin(arr), std::end(arr), my::print);
}


//remove duplicate
/** erase-remove idiom **/
void print11(vector<int> arr)
{
    std::sort(std::begin(arr), std::end(arr));
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), std::end(arr), my::print);
}

/** algorithms and high level optimization **/
namespace my
{
    template<typename T>
    T is_unique(vector<int> v){
        std::sort(v.begin(), v.end());
        return std::unique(v.begin(), v.end()) == v.end();
    }

    int is_even(int number){
        return number % 2 == 0 ? true : false;
    }
}


void print12(vector<int> arr)
{
    auto newend = std::remove_if(std::begin(arr), std::end(arr), my::is_even);
    std::sort(std::begin(arr), newend);
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), vector<int>::iterator(newend), my::print);
}


/** std::function & function object (functor) **/
template <typename T>
    struct myfilter
    {
        T operator() (T& n) const { return n % 2 == 0; }
    };


void print13(vector<int> arr, std::function<bool(int)> filter)
{
    auto newend = std::remove_if(std::begin(arr), std::end(arr), filter);
    std::sort(std::begin(arr), newend);
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), vector<int>::iterator(newend), my::print);
}

/** function template and dependent names **/
template<typename  Container, typename Filter>
void print14(Container arr, Filter filter)
{
    auto newend = std::remove_if(std::begin(arr), std::end(arr), filter);
    std::sort(std::begin(arr), newend);
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), vector<int>::iterator(newend), my::print);
}

/**
    Generic code is nice, but often you will
    need to specify certain requirements for
    the template arguments. Types are
    known at compile time, so we can use
    type traits and static assert to reason
    about template arguments.
**/
/** type traits and static assert **/
template<typename  Container, typename Filter>
void print15(Container arr, Filter filter)
{
    assert(std::is_integral<typename Container::value_type>::value);
    auto newend = std::remove_if(std::begin(arr), std::end(arr), filter);
    std::sort(std::begin(arr), newend);
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), vector<int>::iterator(newend), my::print);
}
/**
With enable_if we can take this idea
further and tell the compiler that if certain
requirements are not met, then a particular
template should not even be considered for
instantiation.
**/
/** enable_if **/
template<typename  Container, typename Filter,
    typename = std::enable_if<std::is_integral<typename Container::value_type>::value>>
void print16(Container arr, Filter filter)
{
    auto newend = std::remove_if(std::begin(arr), std::end(arr), filter);
    std::sort(std::begin(arr), newend);
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), vector<int>::iterator(newend), my::print);
}

/**
Enough templates and concepts for now. Let's simplify the code.

For efficiency, we might want to pass by reference
The key thing here is the & to avoid a copy
operation. We pass the sequence by a so
called lvalue reference. Since we are not
using the sequence after the call to print, this
might be an acceptable solution.

**/
/** pass by lvalue reference & lambda expression and generalized lambda capture **/
void print17(vector<int>& arr)
{
    auto newend = std::remove_if(std::begin(arr), std::end(arr), [](int number){return number % 2 == 0 ? true : false;});
    std::sort(std::begin(arr), newend);
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), vector<int>::iterator(newend), my::print);
}
/**
It would be nice to express ownership when
passing references like this. Who owns the
content of the object? With rvalue references
and move semantics you can in our example
express transfer of ownership with && and a
std::move.

It is important to realize that std::move is
just a cast from lvalue to rvalue.

**/
/** pass by rvalue reference and std::move **/
void print18(vector<int>&& arr)
{
    auto newend = std::remove_if(std::begin(arr), std::end(arr), [](int number){return number % 2 == 0 ? true : false;});
    std::sort(std::begin(arr), newend);
    arr.erase(std::unique(std::begin(arr), std::end(arr)),std::end(arr));
    std::for_each(std::begin(arr), vector<int>::iterator(newend), my::print);
}

namespace my
{
    int println(int number)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << setw(2)<<setfill('#')<<number << std::flush;
    }

    void putchar(char ch)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << ch << std::flush;
    }
}

std::size_t print20(std::vector<int> seq)
{
    std::reverse(seq.begin(), seq.end());
    std::for_each(std::begin(seq), std::end(seq), my::println);
    return seq.size();
}

template <typename Func>
void operator*(int n, Func f)
{
    while (n--)
        f();
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int len = std::extent<decltype(arr)>::value;

    //int* first = &arr[0];
    //int* last = &arr[0] + sizeof(arr)/sizeof(arr[0]);

    //int* first = std::begin(arr);
    //int* last = std::end(arr);

    auto first = std::begin(arr);
    auto last = std::end(arr);

    int distance = last - first;

    //length of array
    cout<<n<<endl;
    cout<<len<<endl;
    cout<<distance<<endl;

    //method 1
    print(arr, n);
    print2(arr, 0, n);
    print3(first, last);
    print4(first, last);
    print5(std::begin(arr), std::end(arr));
    print6(std::begin(arr), std::end(arr));
    cout<<'\n';

    myArr<10> arr2 = {1,2,3,4,5,6,7,8,9};
    print7(arr2);
    cout<<'\n';

    array<int, 10> arr3 = {1,2,3,4,5,6,7,8,9};
    print8(arr3);
    cout<<'\n';

    vector<int> v;

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
    print9(v);
    cout<<'\n';


    vector<int> seq = {1,2,4,6,2,3,2,1,8,5,5,6};
    print10(seq);
    cout<<'\n';

    print11(seq);
    cout<<'\n';

    print12(seq);
    cout<<'\n';

    print13(seq, my::is_even);
    cout<<'\n';

    print14(seq, my::is_even);
    cout<<'\n';

    print15(seq, my::is_even);
    cout<<'\n';

    print16(seq, my::is_even);
    cout<<'\n';

    print17(seq);
    cout<<'\n';

    print18(std::move(seq));
    cout<<'\n';

    /**
        We will soon show how to run code
        asynchronously. But first we show an
        alternative way to invoke a function.
    **/
    print20(std::move(seq));
    cout<<'\n';

    /**
        std::async returns a future that holds a
        value that we can retrieve later. Notice how
        invoking and getting the result is now two
        separate statements, this allow us to
        something while it is executing.

    **/
   //auto f = std::async(print20, seq);
   //auto k = f.get();
   //for (int i = 10; i; --i)
   //     my::putchar('.');
   // std::cout << k;
    /**
        Ok, I just can not resist... let's have some fun
        with overloading the multiplication operator
        and create a repeat function. (Don't do this in
        your codebase...)
    **/
    auto f = std::async(print20, seq);
    auto k = f.get();
    10 * []{ my::putchar('.'); };
        std::cout << k;


    return 0;
}

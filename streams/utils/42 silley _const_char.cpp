#include <bits/stdc++.h>

using namespace std;

template <size_t N>
struct MyCharArr
{
    const char * begin() const { return &data_[0]; }
    const char * end() const { return &data_[N]; }
    char data_[N];
};

void print(const char * begin, const char * end)
{
    for (auto it = begin; it != end; ++it)
        std::putchar(*it);
}

void print2(const char * begin, const char * end)
{
    std::for_each(begin, end, std::putchar);
}

void print3(const MyCharArr<5> & arr)
{
    std::for_each(std::begin(arr), std::end(arr), std::putchar);
}

void print4(const std::array<char, 5> & seq)
{
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
}

void print5(const std::vector<char> & seq)
{
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
}

void print6(std::vector<char> seq)
{
    std::sort(std::begin(seq), std::end(seq));
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
}

void print7(std::vector<char> seq)
{
    std::sort(std::begin(seq), std::end(seq));
    seq.erase(std::remove_if(std::begin(seq), std::end(seq), ::ispunct), std::end(seq));
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
}

void print8(std::vector<char> seq, std::function<bool(int)> filter)
{
    std::sort(std::begin(seq), std::end(seq));
    seq.erase(std::remove_if(std::begin(seq), std::end(seq), filter), std::end(seq));
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
}


template <typename Seq, typename Filter>
void print9(Seq seq, Filter filter)
{
    std::sort(std::begin(seq), std::end(seq));
    seq.erase(std::remove_if(std::begin(seq), std::end(seq), filter), std::end(seq));
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
}

/**
    Generic code is nice, but often you will
    need to specify certain requirements for
    the template arguments. Types are
    known at compile time, so we can use
    type traits and static assert to reason
    about template arguments.
**/

template <typename Seq, typename Filter>
void print10(Seq seq, Filter filter)
{
    assert(std::is_integral<typename Seq::value_type>::value);
    //static_assert(std::is_invocable<Filter, int>::value);
    std::sort(std::begin(seq), std::end(seq));
    seq.erase(std::remove_if(std::begin(seq), std::end(seq), filter), std::end(seq));
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
}
/**
With enable_if we can take this idea
further and tell the compiler that if certain
requirements are not met, then a particular
template should not even be considered for
instantiation.
**/
template <typename Seq, typename Filter,
            typename = std::enable_if<std::is_integral<typename Seq::value_type>::value>>
void print11(Seq seq, Filter filter)
{
    std::sort(std::begin(seq), std::end(seq));
    seq.erase(std::remove_if(std::begin(seq), std::end(seq), filter), std::end(seq));
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
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

void print12(std::vector<char> & seq)
{
    auto newend = std::remove_if(std::begin(seq), std::end(seq), [](char ch) { return !std::isalpha(ch); });
    std::sort(std::begin(seq), newend);
    std::for_each(std::begin(seq), std::vector<char>::iterator(newend), std::putchar);
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

void print13(std::vector<char>&& seq)
{
    auto newend = std::remove_if(std::begin(seq), std::end(seq), [](char ch) { return !std::isalpha(ch); });
    std::sort(std::begin(seq), newend);
    std::for_each(std::begin(seq), std::vector<char>::iterator(newend), std::putchar);
}
/**
Now we will show how rvalue references can
bind to objects without a name, eg a return
value from a function.
**/

std::vector<char> greeting()
{
    return std::vector<char>{'e', '&', '.', 'l', 'l', '{', 'H', 'o'};
}

/**
Due to return value optimization, copy
elision, rvalues and move semantics,
nothing will be copied here. All the elements
(and the ownership) are just moved into the
print function.
**/
/*
auto greeting2()
{
    return std::tuple<std::vector<char>,int>({'e', '&', '.', 'l', 'l', '{', 'H', 'o'}, 42);
}
*/

std::size_t print14(std::vector<char> seq)
{
    std::for_each(std::begin(seq), std::end(seq), std::putchar);
    return seq.size();
}

/**
Let's write our very own putchar and put it in
our very own namespace.
**/

/**
Let's introduce a type writer effect by adding
a small pause before printing each character.
**/
namespace my {
    void putchar(char ch)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << ch << std::flush;
    }
}

std::size_t print15(std::vector<char> seq)
{
    std::reverse(seq.begin(), seq.end());
    std::for_each(std::begin(seq), std::end(seq), my::putchar);
    return seq.size();
}


template <typename Func>
void operator*(int n, Func f)
{
    while (n--)
        f();
}



int length(const char* str){
    int i = 0, count = 0;
    while(str[count] != '\0'){
        count++;
    }
    return count;
}

int main()
{
    //const char arr[] = {'H', 'e', 'l', 'l', 'o'};


    //int n = sizeof(arr)/sizeof(arr[0]);
    //int N = length(arr);

    //int len = std::extent<decltype(arr)>::value;


    //const char * begin = &arr[0];
    //const char * end = &arr[len];

    //const char * begin = std::begin(arr);
    //const char * end = std::end(arr);


    //auto begin = std::begin(arr);
    //auto end = std::end(arr);

    //print(std::begin(arr), std::end(arr));

    //MyCharArr<5> seq[] {'H', 'e', 'l', 'l', 'o'};
    //std::array<char, 5> seq{'H', 'e', 'l', 'l', 'o'};
    //std::vector<char> seq{'H', 'e', 'l', 'l', 'o'};
    //print2(std::begin(arr), std::end(arr));

    //Perhaps we need to rearrange the elements before printing out.
    //Then we might want to pass by value so that we get a copy of the container.
    //and sort the elements
    //std::vector<char> seq{'e', 'l', 'l', 'H', 'o'};


    //Here we have some superfluous punctuation characters that needs to be filtered out.
    //We apply the erase-remove idiom with std::ispunct as a predicate.
    //std::vector<char> seq{'e', '&', '.', 'l', 'l', '{', 'H', 'o'};
    //Now we can pass in quite advanced filters.
    //Let us create an old-school function object
    //(aka functor).
    //struct MyFilter {
    //    MyFilter(std::set<char> validchars) : validchars_(validchars) {}
    //    bool operator()(char ch) const { return validchars_.find(std::tolower(ch)) == validchars_.end(); }
    //    std::set<char> validchars_;
    //} myfilter({'h','e','l','o'});

    //We can also use lambda expressions to create function objects.
    //auto myfilter = [vc=std::set<char>{'h','e','l','o'}](char ch) { return vc.find(std::tolower(ch)) == vc.end(); };
    //print8(seq, myfilter);
    //Lambdas are often used as simple wrappers for existing functions.

	//print11(seq, [](char ch) { return !std::isalpha(ch); });

	//print12(seq);
    //print13(std::move(seq));

    //print(greeting());
/*
    auto [str, answer] = greeting2();
    if (answer == 42)
        print(str);


    if (auto [str, answer] = greeting(); answer == 42)
        print(str);
*/

    std::vector<char> seq{'o', 'l', 'l', 'e', 'H'};
    //print15(seq);

    /**
        We will soon show how to run code
asynchronously. But first we show an
alternative way to invoke a function.
    **/


/**
std::async returns a future that holds a
value that we can retrieve later. Notice how
invoking and getting the result is now two
separate statements, this allow us to
something while it is executing.

**/
   // auto f = std::async(print15, seq);
   // auto n = f.get();
   // for (int i = 10; i; --i)
   //     my::putchar('.');
   // std::cout << n;
/**
Ok, I just can not resist... let's have some fun
with overloading the multiplication operator
and create a repeat function. (Don't do this in
your codebase...)
**/
auto f = std::async(print15, seq);
    auto n = f.get();
    10 * []{ my::putchar('.'); };
    std::cout << n;
	return 0;
}

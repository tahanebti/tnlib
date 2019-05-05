#include <iostream>
using namesapce std;

/**
  Notes : Function Template parametre
    – Allows writing function families
    ● polymorphism: compile time  
  
  template<typename T>  
  template<class T>
  template<size_t n = 10>

**/


//using type alias
    typedef long long ll;
    using ll = long long;
    
    typedef void(*func)(int, int) // function pointer
    using func = void(*)(int, int)
    
//function<>::value : getting value out of type
    template<size_t n>
    struct int_type
    {
        static constexpr int value {n};
    };
//function<>::type : function calling
    template<typename T>
    struct to_pointer
    {
        using type = T*;
    };
    using int_ptr = typename to_pointer<int>::type;
    
//mix    
    <typename T>
    class Object
    {
        using Type = typename decay<decltype(T::value)>::type;
    private:
        Type value;
    };
    
//meta-function
    constexpr size_t recursive_factorial(size_t number){
        return (number == 0 || number == 1)? 1 : number * recursive_factorial(number - 1);
    }

    //meta-function
    template<size_t number>
    struct factorial
    {
       constexpr static auto value = factorial<number - 1>::value * number;     
    };
    
//length
        

/**
It is possible to use the following kinds of template parameters.

class or typename
Integers
Function pointer
Member function pointer
**/

// n => Numeric template argument with default value
template<size_t n = 3, typename Action>
void repeat(Action fn){
    for(size_t i = n; i > 0; i--)
       fn();
}


//function pointer
template<double (*mfunction) (size_t)>
void tabulateFunPTR(size_t n)
{
    std::cout << std::fixed << std::setprecision(3);
    for(size_t i = 0; i < n; i++)
        std::cout << std::setw(5) << i
                  << std::setw(10) << mfunction(i)
                  << std::endl;
}

// It is also possible the following syntax with auto keyword.
template<auto mfunction (size_t) -> double>
void tabulateFunPTRC(size_t n)
{
    std::cout << std::fixed << std::setprecision(3);
    for(size_t i = 0; i < n; i++)
        std::cout << std::setw(5) << i
                  << std::setw(10) << mfunction(i)
                  << std::endl;
}


//template with d
template<class T, size_t n>
class array{};
/**
A class template is not a class, it is factory of classes and has zero cost until it is used or instantiated.
**/
template<class A, class B, class C>
class tuple{};

//template with range
template<class Range, class Function>
void forEachRange(const Range& range, Function func){
    for(const auto& x: range) func(x);
}

//template specialization
// Check whether type is float point
template<class T>
auto isFPNumber() -> bool {
     return false;
}
// Template specialization of isFPNumber for type float
template<> auto isFPNumber<float>() -> bool {
     return true;
}
// Template specialization of isFPNumber for type double
template<> auto isFPNumber<double>() -> bool {
     return true;
}

//template type alias
template<class T>
using Action = std::function<T (int)>;

template<class T>
void doTimes(int n, Action<T> action){
     for(int i = 0; i < n; i++)
        std::cout << " i = 0; x = " << action(i) << "\n";
}

//template with default argument
template <typename Element, size_t Size = 10>
class Array{};

//template type function
template<class T>
struct isPointer{
    static constexpr bool value = false;
    constexpr bool operator()() const { return false; }
};

template<class T>
struct isPointer<T*>{
    static constexpr bool value = true;
    constexpr bool operator()() const { return true; }
};


// Variadic template arguments
template<typename T>
void printTypes(const T& x){
     std::cout << std::left << std::setw(15) << x
               << std::setw(10) << std::right << " size = "
               << std::setw(2) << sizeof(x) << "\n";
     std::clog << " [TRACE] Base case => x = " << x << "\n";
}

template<typename T, typename ... Types>
void printTypes(const T& x, const Types ... args){
     std::cout << std::left << std::setw(15) << x
               << std::setw(10) << std::right << " size = "
               << std::setw(2) << sizeof(x) << "\n";
     printTypes(args ...);
}


int main()
{
  //template arguments
        repeat<5>([]{ std::cout << "integer as template arguments " << std::endl; });

        std::cout << "function pointer as template parameter  " << std::endl;
        tabulateFunPTR<exp>(4);



        std::cout << "metafunction or type traits   " << std::endl;

        std::cout << "isPointer<short*>::value  = " << isPointer<short*>::value << "\n";
        std::cout << "isPointer<short>::value   = " << isPointer<short>::value << "\n";
        std::cout << "isPointer<double>::value  = " << isPointer<double>::value << "\n";
        std::cout << "isPointer<double*>::value = " << isPointer<double*>::value << "\n";


        std::cout << "predefined type traits <type_traits>   " << std::endl;

        cout<<std::is_void<void>::value<<endl;
         std::is_void<int>::value;
        std::is_void<void*>::value;
        std::is_void<bool>::value;

        cout<<std::is_floating_point<float>::value<<endl;

        cout<<std::is_integral<int>::value<<endl;
        cout<<std::is_const<int>::value<<endl;

        cout<<std::is_same<int, float>::value;

        //coit<<std::is_base_of<A, B>::value;
        /*returns true if A is a base type (superclass) of B or B is derived class of A.*/

        //Variadic template to print a sequence of heterogenous arguments.
        printTypes("hello world", 10, 'x', 20.23f, true, NAN);
}

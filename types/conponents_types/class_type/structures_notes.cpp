#include <iostream>

//
//  structures notes
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


using namesapce std;

/**
    Notes : 

    A structure (struct) is a collection of variables of different data
    types under a single name

    A class extends the concept of structure to hold data members
    and also functions as members
    
    Structure and classes are semantically equivalent. In general,
    struct represents passive objects(public by default), while class active objects(private by default)
**/

/**
    Notes :

    DEEP COPY: Underlying memory the reference/pointer points to is copied
    SHALLOW COPY: Reference/pointer is copied and points to original data
**/


/**
    Notes :

    STATIC BINDING: Uses pointer/ref type to determine function to call at compilation
    DYNAMIC BINDING: Uses internal held object type to determine function to call at runtime
**/

/**
    Notes :

    OBJECT ORIENTED
    POLYMORPHISM: Implementing the same methods in different ways
    ABSTRACTION: Providing an interface for commonly used actions (eg. IMyClass, =0)
    INHERITANCE: Using previously written classes as a base for new classes
    RE-USABILITY: Preventing code duplication (eg. templates, shared functions/classes)
    DATA HIDING: Type of encapsulation- hiding members from view (eg. Pimpl)
    ENCAPSULATION: Hiding private implementation details behind a public interface/class (eg. private/public)


    INHERITANCE
    COVARIANCE: Allows assignment MyClass or derived from it to MyClass object [polymorphism basis]
    CONTRAVARIANCE: Allows assigning MyClass or what MyClass derived from to MyClass object
    INVARIANCE: Allows neither

**/


/** 
    Notes : rule of five

    implicit constructor T :: T();
    ● destructor T :: ~T();
    ● copy constructor T :: T( const T& );
    ● move constructor T :: T( T&& );
    ● copy assignment operator
    ● T& T :: operator=( const T& );
    ● move assignment operator
    ● T& T :: operator=( T&& rhs );
**/

/*
  Notes : 

  Copy constructor vs. move constructor
    ● Copy constructor: deep copy
    ● Move constructor: shallow copy + ownership transfer

  Ex : 
      // constructor
      string s=”apple”;
      // copy constructor: s is an lvalue
      string s1 = s;
      // move constructor: right side is an rvalue
      string s2 = s + s1;

*/

//noCopy
struct noCopy{
    //defualte C++11 Explicitly forcing the automatic generation of a default constructor by the compiler.
    noCopy() = default; //use the synthesized default constructor
    noCopy(const noCopy&) = delete; //no copy constructor
    noCopy& operator=(const noCopy&) = delete; //no assignment
    ~noCopy() = default;  //use the synthesized default destructor
};

struct noDtro{
    noDtro() = default; //use the synthesized default constructor
    ~noDtro() = delete;  //we can't destroy a object
};

class PrivateCopy
{
private:
    PrivateCopy(const PrivateCopy&);
    PrivateCopy& operator=(const PrivateCopy&);
public:
    PrivateCopy() = default;
    ~PrivateCopy() = default;
};

class smartPtr
{
public:
    int& operator*() const {return *data;}
    int* operator->() const {return data;}
    int* get() const {return data;}
private:
    int* data;
};


class Integer
{
    int number;
public:
    Integer(){}
    Integer(int number):number(number){}
    //copy constructor shallow copy
    // to make sure that ref vars not modified, make the params constant
    Integer(const Integer& other):number(other.number){}
    //copy assignment operator
    Integer& operator=(const Integer& other){
        if(this != &other){
            number = other.number;
        }
        return *this;
    }

    //rvalue move constructor
    //declare 
    Integer(const Integer&& other)noexcept{
        number = std::move(other.number);
    }

    //move assignment operator
    //we need noexcept to inform that your move constructor & destructor does no throw 
    //then the constructor will called when will grow 
    const Integer& operator =( const Integer&& other)noexcept{
        if(this != &other){
            number = std::move(other.number);
        }
        return *this;
    }

    //A const member function cannot change the object's
    //state, can be invoked on const objects
    int get()const{return number;}
    Integer& setNumber(const int& number){this->number = number;}

    //convert implicit object to int
    operator int() const {return number;}

    //Compare operator
	bool operator==(const Integer&);
	bool operator!=(const Integer&);
	bool operator>(const Integer&);
	bool operator<(const Integer&);
	bool operator>=(const Integer&);
	bool operator<=(const Integer&);

//Member
    //modifiers
    Integer& operator=(int other)  {number = other; return *this;}
    Integer& operator+=(int other) {number += other; return *this;}
    Integer& operator-=(int other) {number -= other; return *this;}
    Integer& operator*=(int other) {number *= other; return *this;}
    Integer& operator/=(int other) {number /= other; return *this;}
    Integer& operator%=(int other) {number %= other; return *this;}

    Integer& operator++() {++number; return *this;}
    Integer& operator--() {--number; return *this;}
    Integer operator++(int) {return Integer(number++);}
    Integer operator--(int) {return Integer(number--);}

    Integer& operator&=(int other) {number &= other; return *this;}
    Integer& operator|=(int other) {number |= other; return *this;}
    Integer& operator^=(int other) {number ^= other; return *this;}
    Integer& operator<<=(int other) {number <<= other; return *this;}
    Integer& operator>>=(int other) {number >>= other; return *this;}

    //accessors
    Integer operator+() const {return Integer(+number);}
    Integer operator-() const {return Integer(-number);}
    Integer operator!() const {return Integer(!number);}
    Integer operator~() const {return Integer(~number);}


};

//standalone
//compare operator overloading
bool Integer::operator==(const Integer& other){return this->number == other.number;}
bool Integer::operator!=(const Integer& other){return this->number != other.number;}
bool Integer::operator>(const Integer& other){return this->number > other.number;}
bool Integer::operator>=(const Integer& other){return *this >= other || *this == other;}
bool Integer::operator<(const Integer& other){return !(*this >= other);}
bool Integer::operator<=(const Integer& other){return !(*this > other);}

//
Integer& Integer::operator++(){ //prefix
  (this->number)++;
return *this;
}

Integer Integer::operator++( int ){ //postfix
  Integer temp(*this);
  (this->number)++;
return temp;
}

class Number{
  explicit Number(const int& x):value(new int(x)){cout << "ctor" << endl; }
  ~Number() { delete value; }

  //• Do your own memory management - 
  //don't create garbage for your client to clean-up.
  Number(const Number& x):value(new int(*x.value))
  { cout << "copy" << endl; }
  
  /*
  • The semantics of copy are to create a new object which is equal to, and logically disjoint from, the original.
  • Copy constructor must copy your object.The compiler is free to elide copies so if your copy constructor does something else you code is incorrect.
  • When a type manages remote parts it is necessary to supply your own copy constructor.
  • If you can, use an existing class (such as a vector) to manage remote parts.
  */
  Number& operator=(const Number& x){ Number tmp(x); swap(*this, tmp); return *this; }

  //Pass sink arguments by value and swap or move into place
  //A sink argument is any argument consumed or returned by the function.
  //• The argument to assignment is a sink argument
  Number& operator=(Number x){ 
  //value = new int_value(*x.value); 
  /*
    • If new throws an exception, the object will be left in an invalid state.
    • If we assign an object to itself this will crash.
  */ 
    swap(*this, x); 
  return *this; 
  }

  friend void print(const Number& x);
  friend void swap(Number& x, Number& y);

  private : 
    int* value; //built-in type pointer
};

void print(const Number& x){ x.value->print_(); }

void swap(Number& x, Number& y){
  swap(x.value, y.value);
  cout << "swap" << endl;
}

/**
  The Private Implementation (Pimpl), or Handle-Body, idom is good for separating the
implementation and reducing compile times.
**/

class Number{
  explicit Number(const int& x):value(new int(x)){cout << "ctor" << endl; }
  ~Number() { delete value; }

  Number(const Number& x):value(new int(*x.value)){ cout << "copy" << endl; }
  
  Number& operator=(const Number& x){ Number tmp(x); swap(*this, tmp); return *this; }
  Number& operator=(Number x){  swap(*this, x); return *this; }

  friend void print(const Number& x);
  friend void swap(Number& x, Number& y);

  private : 
    struct int_value {
      explicit int_value(const int& x) : data_m(x) { }
      void print_() const { print(data_m); }
      int data_m;
    };
  
  int_value* value;
};


//Don't allow polymorphism to complicate the client code.
//• Polymorphism is an implementation detail.

//Polymorphism : is divide as 2 type :
//  -Compile time Polymorphism : achived from function and operator overloading
//  -Runtime Polymorphism : achived from function overriding

//Encapsulation : from using access modifer to encapsulate data and methods



class Number {
public:
  explicit Number(const string& x) : value(new string_value(x)){ }
  explicit Number(const int& x) : value(new int_value(x)){ }
  ~Number() { delete value; }
  
  Number(const Number& x) : value(x.value->copy_()){ }
  Number& operator=(Number x){ swap(*this, x); return *this; }
  
  friend void print(const Number& x);
  friend void swap(Number& x, Number& y);
private:
  struct Data {
    virtual ~Data() { }
    virtual Data* copy_() const = 0;
    virtual void print_() const = 0;
  };
  struct string_value : Data {
    explicit string_value(const string& x) : data_m(x) { }
    Data* copy_() const { return new string_value(data_m); }
    void print_() const { print(data_m); }
    string data_m;
  };
  struct int_value : Data {
    explicit int_value(const int& x) : data_m(x) { }
    Data* copy_() const { return new int_value(data_m); }
    void print_() const { print(data_m); }
  int data_m;
  };

  Data* value;
};


//using template to avoid polymorphic impl

template <typename T>
void print(const T& x) { cout << x << endl; }

class Number {
public:
  template <typename T>
  explicit Number(const T& x) : value(new model<T>(x)){ }
  ~Number() { delete value; }
  
  Number(const Number& x) : value(x.value->copy_()){ }
  Number& operator=(Number x){ swap(*this, x); return *this; }

  friend void print(const Number& x);
  friend void swap(Number& x, Number& y);
private:
  struct Data {
    virtual ~Data() { }
    virtual Data* copy_() const = 0;
    virtual void print_() const = 0;
  };
  
  template <typename T>
  struct model : Data {
    explicit model(const T& x) : data_m(x) { }
    Data* copy_() const { return new model(data_m); }
    void print_() const { print(data_m); }
    T data_m;
  };
  
  Data* value;
};

void swap(Number& x, Number& y){
  swap(x.value, y.value);
}

//modern c++ implementation

const int md = 490019;

template<typename T>
class Number
{
public:
    using Type = typename decay<decltype(T::value)>::type;
    constexpr Number():value(){}
    template<typename U>
    Number(const U& x):value(x){}


    Number& operator+=(const Number& other) {
        value += other.value;
        return *this;
    }
    Number& operator-=(const Number& other) {
        value -= other.value;
        return *this;
    }

    template <typename U>
    Number& operator+=(const U& other) { return *this += Number(other); }

    template <typename U>
    Number& operator-=(const U& other) { return *this -= Number(other); }

    Number& operator++() { return *this += 1; }
    Number& operator--() { return *this -= 1; }
    Number operator++(int) { Number result(*this); *this += 1; return result; }
    Number operator--(int) { Number result(*this); *this -= 1; return result; }
    Number operator-() const { return Number(-value); }

    template<typename U = T>
    typename enable_if<is_same<typename Number<U>::Type , int>::value, Number>::type& operator*=(const Number& rhs){
        value = static_cast<int64_t>(value)*static_cast<int64_t>(rhs.value);
    }

    const Type& operator()() const { return value; }
    template <typename U>
    explicit operator U() const { return static_cast<U>(value); }

    template<typename U>
    friend bool operator==(const Number<U>& lhs, const Number<U>& rhs);

    template<typename U>
    friend istream& operator>>(std::istream& stream, Number<U>& number);
private:
    Type value;
};


template <typename T>
string to_string(const Number<T>& number) {
  return to_string(number());
}


template <typename T>
std::ostream& operator<<(std::ostream& stream, const Number<T>& number) {
  return stream << number();
}

template <typename T>
std::istream& operator>>(std::istream& stream, Number<T>& number) {
  stream >> number.value;
  number.value = Number<T>::normalize(number.value);
  return stream;
}

//operator overloading
//equality
template <typename T> bool operator==(const Number<T>& lhs, const Number<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Number<T>& lhs, U rhs) { return lhs == Number<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Number<T>& rhs) { return Number<T>(lhs) == rhs; }

template <typename T> bool operator!=(const Number<T>& lhs, const Number<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Number<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Number<T>& rhs) { return !(lhs == rhs); }

template <typename T> Number<T> operator+(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) += rhs; }
template <typename T, typename U> Number<T> operator+(const Number<T>& lhs, U rhs) { return Number<T>(lhs) += rhs; }
template <typename T, typename U> Number<T> operator+(U lhs, const Number<T>& rhs) { return Number<T>(lhs) += rhs; }

template <typename T> Number<T> operator-(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) -= rhs; }
template <typename T, typename U> Number<T> operator-(const Number<T>& lhs, U rhs) { return Number<T>(lhs) -= rhs; }
template <typename T, typename U> Number<T> operator-(U lhs, const Number<T>& rhs) { return Number<T>(lhs) -= rhs; }

template <typename T> Number<T> operator*(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) *= rhs; }
template <typename T, typename U> Number<T> operator*(const Number<T>& lhs, U rhs) { return Number<T>(lhs) *= rhs; }
template <typename T, typename U> Number<T> operator*(U lhs, const Number<T>& rhs) { return Number<T>(lhs) *= rhs; }

template <typename T> Number<T> operator/(const Number<T>& lhs, const Number<T>& rhs) { return Number<T>(lhs) /= rhs; }
template <typename T, typename U> Number<T> operator/(const Number<T>& lhs, U rhs) { return Number<T>(lhs) /= rhs; }
template <typename T, typename U> Number<T> operator/(U lhs, const Number<T>& rhs) { return Number<T>(lhs) /= rhs; }



int main()
{

  /**
      Notes : 
      
      OOP: Types of Classes
      Types of classes:
      – Polymorphic Classes – designed for extension
        ● Shape, exception, ...
      – Value Classes – designed for storing values
        ● int, complex<double>, ...
      – RAII (Resource Acquisition Is Initialization) Classes –
      (encapsulate a resource into a class → resource lifetime
      object lifetime)
        ● thread, unique_ptr, ...
    **/  
    
    Integer i(42);
    //if you don't define a copy-constructor explicitly, the compiler creates one for you
    //● this performs a bitwise copy
    Integer ci(i);
    Integer ci = i;
    cout<<((ci == i)?"Equal" : "not Equal")<<endl;
    ci+=2;
    cout<<((ci == i)?"Equal" : "not Equal")<<endl;
    
    Integer a1 = 1;      // OK: copy-initialization selects Integer::Integer(int)
    Integer a2(2);       // OK: direct-initialization selects Integer::Integer(int)
    Integer a3 {4, 5};   // OK: direct-list-initialization selects Integer::Integer(int, int)
    Integer a4 = {4, 5}; // OK: copy-list-initialization selects Integer::Integer(int, int)
    Integer a5 = (A)1;   // OK: explicit cast performs static_cast
    if (a1) cout << "true" << endl; // OK: A::operator bool()
    bool na1 = a1; // OK: copy-initialization selects Integer::operator bool()
    bool na2 = static_cast<bool>(a1); // OK: static_cast performs direct-initialization

}

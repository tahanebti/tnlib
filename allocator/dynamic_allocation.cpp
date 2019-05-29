//
//  dynamic memory allocation of string vector Implementation 
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#include <iostream>
#include <string>
#include <memory>

class str_vector
{
  public:
    str_vector(): element_(nullptr), ptrToFirstFree_(nullptr), cap_(nullptr){};
    str_vector(const str_vector&);
    str_vector& operator=(const str_vector&);
    ~str_vector();

    //returns how many locations are occupied
    std::size_t size() const
    {
        //std::cout <<"ptrToFirstFree_: " << ptrToFirstFree_ << std::endl;
        //std::cout <<"element_: " << element_ << std::endl;
        return (ptrToFirstFree_ - element_);
    }

    //returns the total capacity of allocated memory
    std::size_t capacity() const
    {
        return (cap_ - element_);
    }

    //returns the pointer to the start of the memory allocated
    std::string* begin() const
    {
        return element_;
    }

    //returns the pointer to the end of the memory allocated
    std::string* end() const
    {
        return cap_;
    }
    void push_back(const std::string& str);

  private:
    static std::allocator<std::string> customAllocator_;
    std::string *element_;
    std::string *ptrToFirstFree_;
    std::string *cap_;

    void checkAndAllocate();
    void free();
    void reallocate();
    std::pair<std::string*, std::string*> allocateAndCopy(const std::string* begin, const std::string* end);
};

std::allocator<std::string> str_vector::customAllocator_;



void str_vector::checkAndAllocate()
{
    std::cout << "checkAndAllocate: size: = " << size() << " capacity: = " << capacity() << std::endl;
    if(size() == capacity())
    {
        reallocate();
    }
}

void str_vector::free()
{
    std::cout << "free(): " << std::endl;
    if(element_)
    {
        for (auto ptr = ptrToFirstFree_; ptr != element_;)
        {
            customAllocator_.destroy(--ptr);
        }
        customAllocator_.deallocate(element_, (cap_ - element_));
    }
}

void str_vector::reallocate()
{
    std::cout << "reallocating locations.... " << std::endl;
    std::size_t  newCapacity = size() ? size() * 2 : 4;
    auto newData = customAllocator_.allocate(newCapacity);

    auto dest = newData;
    auto ele = element_;

    //std::cout <<"Size is : " << size() << std::endl;
    for(std::size_t index = 0; index < size(); index++)
    {
        customAllocator_.construct(dest++, std::move(*ele++));
    }

    free();

    ptrToFirstFree_ = dest;
    element_ = newData;
    cap_ = element_ + newCapacity;
}

std::pair<std::string*, std::string*> str_vector::allocateAndCopy(const std::string *b, const std::string *e)
{
    std::cout << "allocateAndCopy: " << std::endl;
    auto data = customAllocator_.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void str_vector::push_back(const std::string& str)
{
    std::cout << "Pushing element ..." << str << std::endl;
    checkAndAllocate();
    customAllocator_.construct(ptrToFirstFree_++, str);
}

//copy-constructor
str_vector::str_vector(const str_vector& vect)
{
    std::cout << "copy-constructor.... "<< std::endl;
    auto newSpace = allocateAndCopy(vect.begin(), vect.end());
    element_ = newSpace.first;
    ptrToFirstFree_ = newSpace.second;
    cap_ = newSpace.second;
}

//copy-assignment operator
str_vector &str_vector::operator=(const str_vector &rhs)
{
    std::cout << "copy-assignment.... "<< std::endl;
    auto newSpace = allocateAndCopy(rhs.begin(), rhs.end());
    free();

    element_ =  newSpace.first;
    ptrToFirstFree_ = newSpace.second;
    cap_ = newSpace.second;
    return *this;
}

//destructor
str_vector::~str_vector()
{
    std::cout << "destructor.... "<< std::endl;
    free();
}

int main()
{
    str_vector str_v;
    std::string str = "Hello";
    str_v.push_back(str);
    str_v.push_back("C++");
    str_v.push_back("Java");
    str_v.push_back("Python");
    str_v.push_back("C");

    str_vector str_v_1;
    str_vector str_v_2 = str_v;
    str_v_1 = str_v_2;
    std::cout <<"capacity: " << str_v.size() << std::endl;

    return 0;
}

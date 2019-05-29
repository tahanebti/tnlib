//
//  access specifiers
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>

class Base
{
    private:
        int privateMember_ = 10;
    public:
        int publicMember_ = 20;
    protected:
        int protectedMember_ = 40;
};

class Derived : Base
{
    public:
        void accessPrivateMember()
        {
            //std::cout << "Accessing private member: " << privateMember_;
        }

        void accessPublicMember()
        {
            publicMember_ = 1000;
            std::cout << "Accessing public member: " << publicMember_ << std::endl;
        }

        void accessProtectedMember()
        {
            std::cout << "Accessing protected member: " << protectedMember_ << std::endl;
        }
};

int main(int argc, char const *argv[])
{
    Base base;
    Derived  derived;
    derived.accessPublicMember();
    derived.accessProtectedMember();

    //std::cout << "Base class private member: " << base.privateMember_ << std::endl;
    std::cout << "Base class public member: " << base.publicMember_ << std::endl;
    //std::cout << "Base class protected member: " << base.protectedMember_ << std::endl;
    //std::cout << "Derived class protected member: " << derived.protectedMember_ << std::endl;


    return 0;
}

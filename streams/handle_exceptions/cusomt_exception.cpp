//
//  custom exception
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>
#include <exception>

class myException : public std::exception
{
    virtual const char* what() const throw()
    {
        return "MyException";
    }
};

int intThrow() throw(int)
{
    throw 22;
    return 22;
}

int throwSomethingElse()
{
    myException myEx;
    throw myEx;
    return 0;
}


int main(int argc, char* argv[])
{
    int sizeRequired  = 0;
    int* freeStore = nullptr;

    do{
        std::cout << "enter the size to be allocated: " << "\n";
        std::cin >> sizeRequired;

        try
        {
            freeStore = new int[sizeRequired];
            delete [] freeStore;
            std::cout << "Allocated " << sizeRequired << " bytes ...." << std::endl;

            if(sizeRequired == 5)
            {
                try{
                    intThrow();
                }catch(int number)
                {
                    std::cout << "Init throw exception: " << number << std::endl;
                }
            }else if( sizeRequired == 10)
            {
                throwSomethingElse();
            }
        }
        catch(const std::bad_alloc& ba)
        {
            std::cout << "Exception: caught bad_allocation expn " << ba.what() << std::endl;
            break;
        }
        catch (const std::exception& ex)
        {
            std::cout << "Exception: caught c++ exception " << ex.what() << std::endl;
            break;
        }
    }while(sizeRequired != 100);

    return 0;
}


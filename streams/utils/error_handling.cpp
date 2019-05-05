//
//  error_handling
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//


#include <iostream>
#include <fstream>

  /**
            Notes :

            1) THROW BY VALUE
            • When exception is thrown, copy of thrown variable is made as it needs it after function out of scope

            2) STACK UNWINDS
            • Stack releases memory until reaching the corresponding try-catch block
            • Any destructors are called on way as objects go out of scope
            • Local pointers are destroyed without calling delete

            3) CATCH BY CONST REFERENCE
            • Const is used to prevent the exception from being modified and giving incorrect crash information
            • Reference is used so the exception can be resolved polymorphically and so slicing does not happen
            • Reference is used instead of pointer to reduce the need to manage any memory at the catch position
            • Allocating memory for an exception through a pointer may not work if the exception is out of memory

            EXCEPTION SAFETY
            • Use RAII to auto cleanup resources if exception is thrown
            • Only change state once any possible errors have been resolved
            • Destructor/deallocation/swap functions should never throw as impossible to safely cleanup

            EXCEPTION NEUTRAL
            • Exceptions thrown should be propagated unchanged to the objects's caller

            ABRAHAMS GUARANTEE: BASIC
            • Failures/exceptions might alter program state
            • No leaks occur and affected objects are still usable but not in predictable state

            ABRAHAMS GUARANTEE: STRONG
            • Failures/exceptions guarantee program state is unchanged
            • No leaks occur and objects and iterators not affected

            ABRAHAMS GUARANTEE: NOTHROW
            • Failure and exceptions do not happen
        **/






//nested exception
void execute_helper() {
    throw std::range_error("Out-of-range error in execute_helper()");
}

void execute() {
    try { execute_helper(); }
    catch (...) {
        std::throw_with_nested(std::runtime_error("Caught in execute()"));
    }
}

void print(const std::exception& exc) {
    std::cout << "Exception: " << exc.what() << std::endl;
    try { std::rethrow_if_nested(exc); }
    catch (const std::exception& e) {
        std::cout << "   Nested ";
        print(e);
    }
}

void invalidArgument(int number){
  if (cin.fail())
    throw invalid_argument(" Enter a valid argument .");
}


void domainError(int number){
  if (number<0)
    throw domain_error (" Error negative value.");
}

/*
void lengthError(int  number){
  if(to_string(number).length() >= 10)
      throw length_error("max 10 digits allowed  ");
}
*/

int main()
{
    {
        /**
      Notes : 

      Exceptions
      – Exception = unexpected situation
      – Exception handling = a mechanism for dealing with problems
        ● throwing an exception – detecting an unexpected situation
        ● catching an exception – taking appropriate action
      
      Handle error throw exception
       domain : set of the input value
       range : set of the output value
       logic error
          invalid_argument : cin.fail()
          domain_error : error of the input value
          length_error : > str.length()
          out_of_range : > arr.size()

      runtime_error
          range_error
          overflow_error : > max_size
          underflow_error < 0
    ios_base::failure

    */
    try {
         bool is_error = true ;
         if(is_error) { // some error occurred
          throw  std :: runtime_error ( " error! " );
        }
      }
      catch (std :: exception & e) {
        // Print error reason
         cout << e.what() <<endl;
        cout << "Type " << typeid( e ).name( ) << endl;
      }


    //invalid_argument
    try{
        invalidArgument(10);
    }catch(invalid_argument& e){
        cout<<e.what()<<endl;
    cout << "Type " << typeid( e ).name( ) << endl;
    }
    //domain error work with mathematics

    try{
       domainError(-5);
    }catch(domain_error& e){
        cout<<e.what()<<endl;
        cout << "Type " << typeid( e ).name( ) << endl;
    }


    try{
//      lengthError(1234567891);
    }catch(length_error& e){
    cout<<e.what()<<endl;
    cout << "Type " << typeid( e ).name( ) << endl;

    }

    // out_of_range
       try {
          string str( "Micro" );
          string rstr( "soft" );
          str.append( rstr, 5, 3 );
          cout << str << endl;
       }
       catch ( exception &e ) {
          cout<< "Caught: " << e.what( ) << endl;
         cout << "Type " << typeid( e ).name( ) << endl;
       }


    //stack overflow
    try
       {
          bitset< 33 > bitset;
          bitset[32] = 1;
          bitset[0] = 1;
          unsigned long x = bitset.to_ulong( );
       }
       catch ( exception &e ) {
          cout << "Caught " << e.what( ) << endl;
          cout << "Type " << typeid( e ).name( ) << endl;
       }
    }
    }


    {
        std::ifstream ofs("non_existing_file.ext");
        std::cout << ofs.fail() << std::endl;        // 1
    }


    {
        std::ifstream ofs("non_existing_file.ext");
        try {
            ofs.exceptions(ofs.failbit);      // Enable exceptions for failures.
        }
        catch (const std::ios_base::failure& exception) {
            std::cout << exception.what() << std::endl;
        }
    }

    //exception pointer
    {

    std::exception_ptr threadException;
    std::thread t([&threadException] {                  // Needs <thread>
        try {
            throw std::invalid_argument("Test");        // In worker thread
        }
        catch (...) {
            threadException = std::current_exception(); // Store exception
        }
    });

    t.join();               // Wait for thread to finish.

    if (threadException) {  // In main thread: handle exception if there is one.
        try {
            std::rethrow_exception(threadException);
        }
        catch (const std::exception& caughtException) {
            std::cout << "Caught from thread: " << caughtException.what() << '\n';
        }
    }
    }


    //nested exception
    {
        try { execute(); }
    catch (const std::exception& e) { print(e); }
    }


    //system_error
    {
            try {
        throw std::system_error(std::make_error_code(std::errc::invalid_argument),
            "Now what am I to do with that argument?");  // optional what() message
    } catch (const std::exception& caughtException) {
        std::cout << caughtException.what();
    }

    }

    //cerrno
    {
            errno = 0;                         // Reset errno to 0!
    std::exp(100000);                  // Causes an overflow error.
    // Convert the errno error code to an error_code instance.
    std::error_code errorCode(errno, std::generic_category());
    std::error_condition okCondition;  // Default constructor creates
                                       // a no-error condition.
    if (errorCode != okCondition)      // Check for an error.
        std::cerr << "Error: " << errorCode.message() << std::endl;


    std::cerr << "Error: " << std::strerror(errno) << std::endl;
    std::perror("Error");     // Prefix string is non-optional 
    }

    std::cout << std::endl;
}

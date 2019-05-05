//
//  casting_type
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
/**
        Notes :

        converting an expression of a given type into another type

        TYPE-CAST / EXPLICIT CONVERSION
            • Data may be lost, done by user with cast operator
            • base -> derived
            • double -> float -> long -> int -> short
            • unsigned -> signed
**/
using namespace std;


class A { public: virtual ~A() {}; };
class B : public A {};
class C {};

int main()
{
	//static cast
	{
		/*

        X x;
        Y y(x) //explicit conversion

          and

        X x;
        Y y = x; //implicit conversion

     	*/

        int dv = 9;
        cout<<fixed<<setprecision(3)<<dv<<endl;

        double iv  = (double) dv;
        cout<<"implicit cast : "<<iv<<endl;

        double ev(dv);
        cout<<"explicit cast : "<<ev<<endl;


        //c++11
        /**
           Notes :

          static_cast<>() gives you a compile time checking ability,
          C-Style cast doesn't.
        **/

		int i = 9;
		float f = static_cast<float>(i);  // convert object from one type to another
		A d1 = static_cast<A>(string("Bob"));  // Type conversion needs to be defined.
		A* pd = static_cast<A*>(new B()); // convert pointer/reference from one type
		                                              // to a related type (down/up cast)
	}
	
	//const cast
	{
		 //   - A compile time constraint that an object can not be modified
        const int i = 1;
        const int* modifier = &i;  // data is const, pointer is not
        modifier++;
        cout<<"const modifier : "<<*modifier<<endl; //ERROR

        //c++11
        const int num = 42;
        // Only works on same type
        auto modifiable = const_cast<const int&>(num);
        // cast away constness of the object
        cout<<"const_cast modifier : "<<++modifiable<<endl;
	}

	//dynamic_cast
	{
		/*
            * dynamic_cast : only works on classes with virtual member functions. To cast raw pointer types
            between each other, you need reinterpret_cast.
        */

        A* a = new B();
		B py = dynamic_cast<B*>(a);
		// a. It convert pointer/reference from one type to a related type (down cast)
		// b. run-time type check.  If succeed, py==pd; if fail, py==0;
		// c. It requires the 2 types to be polymorphic (have virtual function).



        class A { public: virtual ~A() {}; };
		class B : public A {};
		class C {};

		std::shared_ptr<A> a = std::make_shared<B>();    // a points to a new B()
		std::shared_ptr<B> b = std::dynamic_pointer_cast<B>(a);
		std::shared_ptr<C> c = std::dynamic_pointer_cast<C>(a);
		// (c == nullptr) && (a.use_count() == b.use_count() == 2)

	}
	//reinterpted_cast
	{
		long p = 51110980;
		A* dd = reinterpret_cast<A*>(p);  // re-interpret the bits of the object pointed to
		// The ultimate cast that can cast one pointer to any other type of pointer.
	}
	return 0;
}

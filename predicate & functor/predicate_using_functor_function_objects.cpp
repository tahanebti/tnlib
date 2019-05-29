//
//  predicate using function object
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>
#include <functional>

struct funObj
{
	void operator()(int count) const
	{
		std::cout <<"Function Object called ...." << count << std::endl;
	}

	void operator()() const
	{
		std::cout <<"Overloaded: " << std::endl;
	}
};

void print(funObj f)
{
	f(3);
}

int main(int argc, char const *argv[])
{
    funObj()(4);
    //(funObj());
    funObj f;
    f(5);

    funObj g;
    g();
    print(g);

    print(funObj()); //if you are passing tmp object then syntax is same is function declartion
    print(f); //passing a named object

	return 0;
}

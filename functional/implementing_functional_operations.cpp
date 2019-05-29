//
//  Implementing Functional Operations
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;

/**
	function idioms :
		filter 	: remove unwanted items
		map 	: applay a transformation
		reduce 	: reduce sequence to a single value


		auto total = tn::reduce(tn::map(price, add_tax), 0.0, sum);
**/

namespace __tn
{

//version that take a lambda
template<typename Seq, typename Predicate>
Seq filter(Seq s, Predicate p)
{
    //use an alias
    //we need the value_type trait for the argument type
    using f = std::function<bool(typename Seq::value_type)>;
    Seq result;

    std::remove_copy_if(std::begin(s), std::end(s), std::back_inserter(result), std::not1(f(p)));

    return result;
}


template<typename Seq, typename Op>
Seq map(Seq s, Op p)
{
    using value = typename Seq::value_type;
    using f = std::function<value(value)>;

    Seq result;

    std::transform(std::begin(s), std::end(s), std::back_inserter(result), f(p));

    return result;
}





//reduce the values in a sequence by applying the operation sequentially.
//the second argument provide the start value
template<typename Seq, typename Result, typename Op>
Result reduce(Seq s, Result r, Op p)
{
    return std::accumulate(std::begin(s), std::end(s), r, p);
}

}





int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8};
	std::vector<int> result;

	//define a predicate that we whant to filter
	std::function<bool(int)> is_even = [](int n){ return n % 2 == 0; };
    std::function<bool(int)> is_large = [](int n){ return n >= 5; };


	//this remove elements that is don't match the predicate
	std::remove_copy_if(v.begin(), v.end(), std::back_inserter(result), std::not1(is_even));


	for(auto i : result)
		cout<<i<<" ";
	cout<<endl;


	//filter would be easy
	auto res = __tn::filter(v, is_even);
	for(auto i : res)
		cout<<i<<" ";
	cout<<endl;


	//composing filter
	auto r = __tn::filter(__tn::filter(v, is_large), is_even);
	for(auto i : r)
		cout<<i<<" ";
	cout<<endl;

    //define map function
    std::function<int(int)> twice = [](int n){return n * 2;};

    //try map
    auto map_result = __tn::map(v, twice);
    for(auto i : map_result)
		cout<<i<<" ";
	cout<<endl;



	//composing map and filter
	auto map_filter_result = __tn::map(__tn::filter(v, is_large), twice);
	for(auto i : map_filter_result)
		cout<<i<<" ";
	cout<<endl;



	//reduce
	auto reduce_result = __tn::reduce(v, 0, [](int a, int b){return a + b;});
	cout<<reduce_result<<endl;

	std::vector<string> str = {"ab", "cd", "ef"};
	auto str_reduce_result = __tn::reduce(str, std::string(), [](string a, string b){return a + b;});
	cout<<str_reduce_result<<endl;



	//put them together
	std::vector<double> prices = {10.0, 12.0, 22.2, 15.6};
	auto add_tax = [](double d){return d + d * 0.22;};

	auto sum =  [](double a, double b){ return a + b;};

	auto total = __tn::reduce(__tn::map(prices, add_tax), 0.0, sum);
	cout<<total<<endl;

	return 0;
}

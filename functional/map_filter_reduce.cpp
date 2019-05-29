//
//  std::transform
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;


namespace __tn
{
	/// transform
	///
	/// Iterates the input range of [first, last) and the output iterator result
	/// and assigns the result of unaryOperation(input) to result.
	///
	/// Effects: Assigns through every iterator i in the range [result, result + (last1 - first1))
	/// a new corresponding value equal to unaryOperation(*(first1 + (i - result)).
	///
	/// Requires: op shall not have any side effects.
	///
	/// Returns: result + (last1 - first1). That is, returns the end of the output range.
	///
	/// Complexity: Exactly 'last1 - first1' applications of unaryOperation.
	///
	/// Note: result may be equal to first.
	///
	template <typename InputIterator, typename OutputIterator, typename UnaryOperation>
	inline OutputIterator transform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation unaryOperation)
	{
		for(; first != last; ++first, ++result)
			*result = unaryOperation(*first);
		return result;
	}


	/// transform
	///
	/// Iterates the input range of [first, last) and the output iterator result
	/// and assigns the result of binaryOperation(input1, input2) to result.
	///
	/// Effects: Assigns through every iterator i in the range [result, result + (last1 - first1))
	/// a new corresponding value equal to binaryOperation(*(first1 + (i - result), *(first2 + (i - result))).
	///
	/// Requires: binaryOperation shall not have any side effects.
	///
	/// Returns: result + (last1 - first1). That is, returns the end of the output range.
	///
	/// Complexity: Exactly 'last1 - first1' applications of binaryOperation.
	///
	/// Note: result may be equal to first1 or first2.
	///
	template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryOperation>
	inline OutputIterator transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperation binaryOperation)
	{
		for(; first1 != last1; ++first1, ++first2, ++result)
			*result = binaryOperation(*first1, *first2);
		return result;
	}
}
int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9};
    vector<int> v2;

    //transform == map functional
    //recive a function return an transform item
    __tn::transform(v.begin(), v.end(),std::back_inserter(v2), [](int& n){return n * 2;});

    for(auto& i : v2)
        cout<<i<<" ";
    cout<<endl;

    //filter : recive a function 
    vector<int>::iterator filter = std::remove_if(v2.begin(), v2.end(), [](int& n){
            if(n % 2 == 0) return true;
            return false;
    });

    for(auto it = v2.begin(); it != filter; ++it)
        cout<<*it<<" ";


    //reduce
    int sum = std::accumulate(v2.begin(), filter, 0, [](int a, int b){return a + b;});
    cout<<"sum : "<<sum<<endl;

    return 0;
}


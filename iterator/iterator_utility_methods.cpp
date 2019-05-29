//
//  iterator utility methods
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
	Notes : 

	- std::advance(InputIt& it, Distance n) : Increments a given iterator it by n elements
		- InputIt must support input iterator requirements
		- Modifies the iterator
		- Returns void
		- More general than adding a value it + 4
		- No performance loss if it satisfies random access iterator requirements
	
	- std::next(ForwardIt it, Distance n) C++11 : Returns the n-th successor of the iterator
		- ForwardIt must support forward iterator requirements
		- Does not modify the iterator
		- More general than adding a value it + 4
		- The compiler should optimize the computation if it satisfies random
		access iterator requirements
		- Supports negative values if it satisfies bidirectional iterator requirements

	- std::prev(BidirectionalIt it, Distance n) C++11 : Returns the n-th predecessor of the iterator
		- InputIt must support bidirectional iterator requirements
		- Does not modify the iterator
		- More general than adding a value it + 4
		- The compiler should optimize the computation if it satisfies random
		access iterator requirements
	
	- std::distance(InputIt start, InputIt end) : Returns the number of elements from start to last
		- InputIt must support input iterator requirements
		- Does not modify the iterator
		- More general than adding iterator difference it2 - it1
		- The compiler should optimize the computation if it satisfies random
		access iterator requirements
		- C++11 Supports negative values if it satisfies random iterator requirements
**/




//Range Access Methods
//C++11 / C++14 provide a generic interface for containers, plain arrays,
//and std::initializer list to access to the corresponding iterator.
//Standard method .begin() , .end() etc., are not supported by plain
//array and initializer list

// std::begin begin iterator  				 std::cbegin begin const iterator
// std::rbegin begin reverse iterator		 std::crbegin begin const reverse iterator
// std::end end iterator					 std::cend end const iterator
// std::rend end reverse iterator			 std::crend end const reverse iterator





/**
Iterator Traits
std::iterator traits allows retrieving iterator properties
• difference type a type that can be used to identify
distance between iterators
• value type the type of the values that can be obtained by
dereferencing the iterator. This type is void for output
iterators
• pointer defines a pointer to the type iterated over
value type
• reference defines a reference to the type iterated over
value type
• iterator category the category of the iterator. Must be
one of iterator category tags
**/

template<typename T>
void f(const T& list) {
	using D = std::iterator_traits<T>::difference_type; // D is std::ptrdiff_t
	// (pointer difference)
	// (signed size_t)
	using V = std::iterator_traits<T>::value_type; // V is double
	using P = std::iterator_traits<T>::pointer; // P is double*
	using R = std::iterator_traits<T>::reference; // R is double&
	// C is BidirectionalIterator
	using C = std::iterator_traits<T>::iterator_category;
}


int main() {
	std::vector<int> vector { 1, 2, 3 }; // random access iterator
	auto it1 = std::next(vector.begin(), 2);
	auto it2 = std::prev(vector.end(), 2);
	std::cout << *it1; // 3
	std::cout << *it2; // 2
	std::cout << std::distance(it2, it1); // 1
	std::advance(it2, 1);
	std::cout << *it2; // 3
	//--------------------------------------
	std::forward_list<int> list { 1, 2, 3 }; // forward iterator
	// std::prev(list.end(), 1); // compile error



	//range access iterator
	int array[] = { 1, 2, 3 };
	for (auto it = std::crbegin(array); it != std::crend(array); it++)
		std::cout << *it << ", "; // 3, 2, 1


	//iterator traits
	std::list<double> list;
	f(list);
}		
//
//  iterator
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

/**
	Notes : 


	Iterator
		• CopyConstructible It(const It&)
		• CopyAssignable It operator=(const It&)
		• Destructible ~X()
		• Dereferenceable It value& operator*()
		• Pre-incrementable It& operator++()
	Input/Output Iterator
		• Satisfy Iterator
		• Equality bool operator==(const It&)
		• Inequality bool operator!=(const It&)
		• Post-incrementable It operator++(int)
	Forward Iterator
		• Satisfy Input/Output Iterator
		• Default constructible It()
		• Immutable (const iterator), i.e. underlying data cannot be changed
	Bidirectional Iterator
		• Satisfy Forward Iterator
		• Pre/post-decrementable It& operator--(), It operator--(int)
	Random Access Iterator
		• Satisfy Bidirectional Iterator
		• Addition/Subtraction
			void operator+(const It& it) , void operator+=(const It& it) ,
			void operator-(const It& it) , void operator-=(const It& it)
		• Comparison
			bool operator<(const It& it) , bool operator>(const It& it) ,
			bool operator<=(const It& it) , bool operator>=(const It& it)
		• Subscripting It value& operator[](int index)

**/


#include <bits/stdc++.h>
using namespace std;


//Goal: implement a simple iterator to iterate over List elements and
//achieve the following result

struct List {
	struct Node { // Internal Node Structure
		int _value; // node value
		Node* _next; // pointer to next node
	};
	
	Node* head { nullptr }; // head of the list
	Node* tail { nullptr }; // tail of the list
	void push_back(int value); // insert integer value at the end
	
	// !! here we have to define the List iterator "It"
	It begin(); // returns an Iterator pointing to the begin of the list
	It end(); // returns an Iterator pointing to the end of the list
};

struct It : public std::iterator<std::input_iterator_tag,int> { // int dereferencing type
	Node* _ptr; // internal pointer
	// it is useful to extend
	It(Node* ptr); // std::iterator to inherit
	// common iterator fields
	int& operator*(); // deferencing
	bool operator!=(const It& it);
	It& operator++(); // pre-increment
	//--------------------------
	// no needed for std::find()
	bool operator==(const It& it); // comparison
	// no needed for std::find()
	It operator++(int); // post-increment
};

void List::push_back(int value) {
	if (head == nullptr) { // empty list
		head = new Node(); // head is updated
		tail = head;
	}
	else {
		tail->_next = new Node();
		tail = tail->_next; // tail is updated
	}
		tail->_data = data;
		tail->_next = nullptr; // very important to match end() method!!
}

It List::begin() {
	return It { head };
}

It List::end() {
	return It { nullptr }; // after the last element
}

void It::It(Node* ptr) : _ptr(ptr) {}
int& It::operator*() {
	return _ptr->_data;
}
bool It::operator!=(const It& it) {
	return _ptr != it._ptr;
}
It& It::operator++() {
	_ptr = _ptr->_next;
	return *this;
}

int main()
{
	List list;
	list.push_back(2);
	list.push_back(4);
	list.push_back(7);
	std::cout << *std::find(list.begin(), list.end(), 4); // print 4
	for (const auto& it : list) // range-based loop
	std::cout << it << " "; // 2, 3, 4
	return 0;
}
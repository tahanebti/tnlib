	/// find_first_of
	///
	/// find_first_of is similar to find in that it performs linear search through 
	/// a range of ForwardIterators. The difference is that while find searches 
	/// for one particular value, find_first_of searches for any of several values. 
	/// Specifically, find_first_of searches for the first occurrance in the 
	/// range [first1, last1) of any of the elements in [first2, last2). 
	/// This function is thus similar to the strpbrk standard C string function.
	/// If the sequence of elements to search for (i.e. first2-last2) is empty,
	/// the find always fails and last1 will be returned.
	///
	/// Effects: Finds an element that matches one of a set of values.
	///
	/// Returns: The first iterator i in the range [first1, last1) such that for some 
	/// integer j in the range [first2, last2) the following conditions hold: *i == *j.
	/// Returns last1 if no such iterator is found.
	///
	/// Complexity: At most '(last1 - first1) * (last2 - first2)' applications of the 
	/// corresponding predicate.
	///
	template <typename ForwardIterator1, typename ForwardIterator2>
	ForwardIterator1
	find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, 
				  ForwardIterator2 first2, ForwardIterator2 last2)
	{
		for(; first1 != last1; ++first1)
		{
			for(ForwardIterator2 i = first2; i != last2; ++i)
			{
				if(*first1 == *i)
					return first1;
			}
		}
		return last1;
	}


	/// find_first_of
	///
	/// find_first_of is similar to find in that it performs linear search through 
	/// a range of ForwardIterators. The difference is that while find searches 
	/// for one particular value, find_first_of searches for any of several values. 
	/// Specifically, find_first_of searches for the first occurrance in the 
	/// range [first1, last1) of any of the elements in [first2, last2). 
	/// This function is thus similar to the strpbrk standard C string function.
	///
	/// Effects: Finds an element that matches one of a set of values.
	///
	/// Returns: The first iterator i in the range [first1, last1) such that for some 
	/// integer j in the range [first2, last2) the following conditions hold: pred(*i, *j) != false.
	/// Returns last1 if no such iterator is found.
	///
	/// Complexity: At most '(last1 - first1) * (last2 - first2)' applications of the 
	/// corresponding predicate.
	///
	template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
	ForwardIterator1
	find_first_of(ForwardIterator1 first1, ForwardIterator1 last1, 
				  ForwardIterator2 first2, ForwardIterator2 last2,
				  BinaryPredicate predicate)
	{
		for(; first1 != last1; ++first1)
		{
			for(ForwardIterator2 i = first2; i != last2; ++i)
			{
				if(predicate(*first1, *i))
					return first1;
			}
		}
		return last1;
	}
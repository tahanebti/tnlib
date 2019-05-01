	/// find_first_not_of
	///
	/// Searches through first range for the first element that does not belong the second input range.
	/// This is very much like the C++ string find_first_not_of function.
	///
	/// Returns: The first iterator i in the range [first1, last1) such that for some 
	/// integer j in the range [first2, last2) the following conditions hold: !(*i == *j).
	/// Returns last1 if no such iterator is found.
	///
	/// Complexity: At most '(last1 - first1) * (last2 - first2)' applications of the 
	/// corresponding predicate.
	///
	template <class ForwardIterator1, class ForwardIterator2>
	ForwardIterator1
	find_first_not_of(ForwardIterator1 first1, ForwardIterator1 last1, 
					  ForwardIterator2 first2, ForwardIterator2 last2)
	{
		for(; first1 != last1; ++first1)
		{
			if(eastl::find(first2, last2, *first1) == last2)
				break;
		}

		return first1;
	}



	/// find_first_not_of
	///
	/// Searches through first range for the first element that does not belong the second input range.
	/// This is very much like the C++ string find_first_not_of function.
	///
	/// Returns: The first iterator i in the range [first1, last1) such that for some 
	/// integer j in the range [first2, last2) the following conditions hold: pred(*i, *j) == false.
	/// Returns last1 if no such iterator is found.
	///
	/// Complexity: At most '(last1 - first1) * (last2 - first2)' applications of the 
	/// corresponding predicate.
	///
	template <class ForwardIterator1, class ForwardIterator2, class BinaryPredicate>
	inline ForwardIterator1
	find_first_not_of(ForwardIterator1 first1, ForwardIterator1 last1, 
					  ForwardIterator2 first2, ForwardIterator2 last2, 
					  BinaryPredicate predicate)
	{
		typedef typename eastl::iterator_traits<ForwardIterator1>::value_type value_type;

		for(; first1 != last1; ++first1)
		{
			if(eastl::find_if(first2, last2, eastl::bind1st<BinaryPredicate, value_type>(predicate, *first1)) == last2)
				break;
		}

		return first1;
	}

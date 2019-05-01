	/// mismatch
	///
	/// Finds the first position where the two ranges [first1, last1) and 
	/// [first2, first2 + (last1 - first1)) differ. The two versions of  
	/// mismatch use different tests for whether elements differ.
	///
	/// Returns: A pair of iterators i and j such that j == first2 + (i - first1)
	/// and i is the first iterator in the range [first1, last1) for which the 
	/// following corresponding condition holds: !(*i == *(first2 + (i - first1))).
	/// Returns the pair last1 and first2 + (last1 - first1) if such an iterator 
	/// i is not found.
	///
	/// Complexity: At most last1 first1 applications of the corresponding predicate.
	///
	template <class InputIterator1, class InputIterator2>
	inline eastl::pair<InputIterator1, InputIterator2>
	mismatch(InputIterator1 first1, InputIterator1 last1,
			 InputIterator2 first2) // , InputIterator2 last2)
	{
		while((first1 != last1) && (*first1 == *first2)) // && (first2 != last2) <- C++ standard mismatch function doesn't check first2/last2.
		{
			++first1;
			++first2;
		}

		return eastl::pair<InputIterator1, InputIterator2>(first1, first2);
	}


	/// mismatch
	///
	/// Finds the first position where the two ranges [first1, last1) and 
	/// [first2, first2 + (last1 - first1)) differ. The two versions of  
	/// mismatch use different tests for whether elements differ.
	///
	/// Returns: A pair of iterators i and j such that j == first2 + (i - first1)
	/// and i is the first iterator in the range [first1, last1) for which the 
	/// following corresponding condition holds: pred(*i, *(first2 + (i - first1))) == false.
	/// Returns the pair last1 and first2 + (last1 - first1) if such an iterator 
	/// i is not found.
	///
	/// Complexity: At most last1 first1 applications of the corresponding predicate.
	///
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	inline eastl::pair<InputIterator1, InputIterator2>
	mismatch(InputIterator1 first1, InputIterator1 last1,
			 InputIterator2 first2, // InputIterator2 last2,
			 BinaryPredicate predicate)
	{
		while((first1 != last1) && predicate(*first1, *first2)) // && (first2 != last2) <- C++ standard mismatch function doesn't check first2/last2.
		{
			++first1;
			++first2;
		}

		return eastl::pair<InputIterator1, InputIterator2>(first1, first2);
	}
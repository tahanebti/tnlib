	/// lower_bound
	///
	/// Finds the position of the first element in a sorted range that has a value 
	/// greater than or equivalent to a specified value.
	///
	/// Effects: Finds the first position into which value can be inserted without 
	/// violating the ordering.
	/// 
	/// Returns: The furthermost iterator i in the range [first, last) such that 
	/// for any iterator j in the range [first, i) the following corresponding 
	/// condition holds: *j < value.
	///
	/// Complexity: At most 'log(last - first) + 1' comparisons.
	///
	/// Optimizations: We have no need to specialize this implementation for random 
	/// access iterators (e.g. contiguous array), as the code below will already 
	/// take advantage of them.
	///
	template <typename ForwardIterator, typename T>
	ForwardIterator
	lower_bound(ForwardIterator first, ForwardIterator last, const T& value)
	{
		typedef typename eastl::iterator_traits<ForwardIterator>::difference_type DifferenceType;

		DifferenceType d = eastl::distance(first, last); // This will be efficient for a random access iterator such as an array.

		while(d > 0)
		{
			ForwardIterator i  = first;
			DifferenceType  d2 = d >> 1; // We use '>>1' here instead of '/2' because MSVC++ for some reason generates significantly worse code for '/2'. Go figure.

			eastl::advance(i, d2); // This will be efficient for a random access iterator such as an array.

			if(*i < value)
			{
				// Disabled because std::lower_bound doesn't specify (23.3.3.3, p3) this can be done: EASTL_VALIDATE_COMPARE(!(value < *i)); // Validate that the compare function is sane.
				first = ++i;
				d    -= d2 + 1;
			}
			else
				d = d2;
		}
		return first;
	}


	/// lower_bound
	///
	/// Finds the position of the first element in a sorted range that has a value 
	/// greater than or equivalent to a specified value. The input Compare function
	/// takes two arguments and returns true if the first argument is less than
	/// the second argument.
	///
	/// Effects: Finds the first position into which value can be inserted without 
	/// violating the ordering.
	/// 
	/// Returns: The furthermost iterator i in the range [first, last) such that 
	/// for any iterator j in the range [first, i) the following corresponding 
	/// condition holds: compare(*j, value) != false.
	///
	/// Complexity: At most 'log(last - first) + 1' comparisons.
	///
	/// Optimizations: We have no need to specialize this implementation for random 
	/// access iterators (e.g. contiguous array), as the code below will already 
	/// take advantage of them.
	///
	template <typename ForwardIterator, typename T, typename Compare>
	ForwardIterator
	lower_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare compare)
	{
		typedef typename eastl::iterator_traits<ForwardIterator>::difference_type DifferenceType;

		DifferenceType d = eastl::distance(first, last); // This will be efficient for a random access iterator such as an array.

		while(d > 0)
		{
			ForwardIterator i  = first;
			DifferenceType  d2 = d >> 1; // We use '>>1' here instead of '/2' because MSVC++ for some reason generates significantly worse code for '/2'. Go figure.

			eastl::advance(i, d2); // This will be efficient for a random access iterator such as an array.

			if(compare(*i, value))
			{
				// Disabled because std::lower_bound doesn't specify (23.3.3.1, p3) this can be done: EASTL_VALIDATE_COMPARE(!compare(value, *i)); // Validate that the compare function is sane.
				first = ++i;
				d    -= d2 + 1;
			}
			else
				d = d2;
		}
		return first;
	}
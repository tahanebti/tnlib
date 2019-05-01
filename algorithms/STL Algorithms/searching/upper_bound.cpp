	/// upper_bound
	///
	/// Finds the position of the first element in a sorted range that has a 
	/// value that is greater than a specified value.
	///
	/// Effects: Finds the furthermost position into which value can be inserted 
	/// without violating the ordering.
	///
	/// Returns: The furthermost iterator i in the range [first, last) such that 
	/// for any iterator j in the range [first, i) the following corresponding 
	/// condition holds: !(value < *j).
	///
	/// Complexity: At most 'log(last - first) + 1' comparisons.
	///
	template <typename ForwardIterator, typename T>
	ForwardIterator
	upper_bound(ForwardIterator first, ForwardIterator last, const T& value)
	{
		typedef typename eastl::iterator_traits<ForwardIterator>::difference_type DifferenceType;

		DifferenceType len = eastl::distance(first, last);

		while(len > 0)
		{
			ForwardIterator i    = first;
			DifferenceType  len2 = len >> 1; // We use '>>1' here instead of '/2' because MSVC++ for some reason generates significantly worse code for '/2'. Go figure.

			eastl::advance(i, len2);

			if(!(value < *i)) // Note that we always express value comparisons in terms of < or ==.
			{
				first = ++i;
				len -= len2 + 1;
			}
			else
			{
				// Disabled because std::upper_bound doesn't specify (23.3.3.2, p3) this can be done: EASTL_VALIDATE_COMPARE(!(*i < value)); // Validate that the compare function is sane.
				len = len2;
			}
		}
		return first;
	}


	/// upper_bound
	///
	/// Finds the position of the first element in a sorted range that has a 
	/// value that is greater than a specified value. The input Compare function
	/// takes two arguments and returns true if the first argument is less than
	/// the second argument.
	///
	/// Effects: Finds the furthermost position into which value can be inserted 
	/// without violating the ordering.
	///
	/// Returns: The furthermost iterator i in the range [first, last) such that 
	/// for any iterator j in the range [first, i) the following corresponding 
	/// condition holds: compare(value, *j) == false.
	///
	/// Complexity: At most 'log(last - first) + 1' comparisons.
	///
	template <typename ForwardIterator, typename T, typename Compare>
	ForwardIterator
	upper_bound(ForwardIterator first, ForwardIterator last, const T& value, Compare compare)
	{
		typedef typename eastl::iterator_traits<ForwardIterator>::difference_type DifferenceType;

		DifferenceType len = eastl::distance(first, last);

		while(len > 0)
		{
			ForwardIterator i    = first;
			DifferenceType  len2 = len >> 1; // We use '>>1' here instead of '/2' because MSVC++ for some reason generates significantly worse code for '/2'. Go figure.

			eastl::advance(i, len2);

			if(!compare(value, *i))
			{
				first = ++i;
				len -= len2 + 1;
			}
			else
			{
				// Disabled because std::upper_bound doesn't specify (23.3.3.2, p3) this can be done: EASTL_VALIDATE_COMPARE(!compare(*i, value)); // Validate that the compare function is sane.
				len = len2;
			}
		}
		return first;
	}
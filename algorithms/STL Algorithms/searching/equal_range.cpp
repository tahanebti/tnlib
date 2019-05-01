	/// equal_range
	///
	/// Effects: Finds the largest subrange [i, j) such that the value can be inserted 
	/// at any iterator k in it without violating the ordering. k satisfies the 
	/// corresponding conditions: !(*k < value) && !(value < *k).
	/// 
	/// Complexity: At most '2 * log(last - first) + 1' comparisons.
	///
	template <typename ForwardIterator, typename T>
	pair<ForwardIterator, ForwardIterator>
	equal_range(ForwardIterator first, ForwardIterator last, const T& value)
	{
		typedef pair<ForwardIterator, ForwardIterator> ResultType;
		typedef typename eastl::iterator_traits<ForwardIterator>::difference_type DifferenceType;

		DifferenceType d = eastl::distance(first, last);

		while(d > 0)
		{
			ForwardIterator i(first);
			DifferenceType  d2 = d >> 1; // We use '>>1' here instead of '/2' because MSVC++ for some reason generates significantly worse code for '/2'. Go figure.

			eastl::advance(i, d2);

			if(*i < value)
			{
				EASTL_VALIDATE_COMPARE(!(value < *i)); // Validate that the compare function is sane.
				first = ++i;
				d    -= d2 + 1;
			}
			else if(value < *i)
			{
				EASTL_VALIDATE_COMPARE(!(*i < value)); // Validate that the compare function is sane.
				d    = d2;
				last = i;
			}
			else
			{
				ForwardIterator j(i);

				return ResultType(eastl::lower_bound(first, i, value), 
								  eastl::upper_bound(++j, last, value));
			}
		}
		return ResultType(first, first);
	}


	/// equal_range
	///
	/// Effects: Finds the largest subrange [i, j) such that the value can be inserted 
	/// at any iterator k in it without violating the ordering. k satisfies the 
	/// corresponding conditions: compare(*k, value) == false && compare(value, *k) == false.
	/// 
	/// Complexity: At most '2 * log(last - first) + 1' comparisons.
	///
	template <typename ForwardIterator, typename T, typename Compare>
	pair<ForwardIterator, ForwardIterator>
	equal_range(ForwardIterator first, ForwardIterator last, const T& value, Compare compare)
	{
		typedef pair<ForwardIterator, ForwardIterator> ResultType;
		typedef typename eastl::iterator_traits<ForwardIterator>::difference_type DifferenceType;

		DifferenceType d = eastl::distance(first, last);

		while(d > 0)
		{
			ForwardIterator i(first);
			DifferenceType  d2 = d >> 1; // We use '>>1' here instead of '/2' because MSVC++ for some reason generates significantly worse code for '/2'. Go figure.

			eastl::advance(i, d2);

			if(compare(*i, value))
			{
				EASTL_VALIDATE_COMPARE(!compare(value, *i)); // Validate that the compare function is sane.
				first = ++i;
				d    -= d2 + 1;
			}
			else if(compare(value, *i))
			{
				EASTL_VALIDATE_COMPARE(!compare(*i, value)); // Validate that the compare function is sane.
				d    = d2;
				last = i;
			}
			else
			{
				ForwardIterator j(i);

				return ResultType(eastl::lower_bound(first, i, value, compare), 
								  eastl::upper_bound(++j, last, value, compare));
			}
		}
		return ResultType(first, first);
	}
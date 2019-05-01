	/// binary_search
	///
	/// Returns: true if there is an iterator i in the range [first last) that 
	/// satisfies the corresponding conditions: !(*i < value) && !(value < *i).
	///
	/// Complexity: At most 'log(last - first) + 2' comparisons.
	///
	/// Note: The reason binary_search returns bool instead of an iterator is
	/// that search_n, lower_bound, or equal_range already return an iterator. 
	/// However, there are arguments that binary_search should return an iterator.
	/// Note that we provide binary_search_i (STL extension) to return an iterator.
	///
	/// To use search_n to find an item, do this:
	///     iterator i = search_n(begin, end, 1, value);
	/// To use lower_bound to find an item, do this:
	///     iterator i = lower_bound(begin, end, value);
	///     if((i != last) && !(value < *i))
	///         <use the iterator>
	/// It turns out that the above lower_bound method is as fast as binary_search
	/// would be if it returned an iterator.
	///
	template <typename ForwardIterator, typename T>
	inline bool
	binary_search(ForwardIterator first, ForwardIterator last, const T& value)
	{
		// To do: This can be made slightly faster by not using lower_bound.
		ForwardIterator i(eastl::lower_bound<ForwardIterator, T>(first, last, value));
		return ((i != last) && !(value < *i)); // Note that we always express value comparisons in terms of < or ==.
	}


	/// binary_search
	///
	/// Returns: true if there is an iterator i in the range [first last) that 
	/// satisfies the corresponding conditions: compare(*i, value) == false && 
	/// compare(value, *i) == false.
	///
	/// Complexity: At most 'log(last - first) + 2' comparisons.
	///
	/// Note: See comments above regarding the bool return value of binary_search.
	///
	template <typename ForwardIterator, typename T, typename Compare>
	inline bool
	binary_search(ForwardIterator first, ForwardIterator last, const T& value, Compare compare)
	{
		// To do: This can be made slightly faster by not using lower_bound.
		ForwardIterator i(eastl::lower_bound<ForwardIterator, T, Compare>(first, last, value, compare));
		return ((i != last) && !compare(value, *i));
	}


	/// binary_search_i
	///
	/// Returns: iterator if there is an iterator i in the range [first last) that 
	/// satisfies the corresponding conditions: !(*i < value) && !(value < *i).
	/// Returns last if the value is not found.
	///
	/// Complexity: At most 'log(last - first) + 2' comparisons.
	///
	template <typename ForwardIterator, typename T>
	inline ForwardIterator
	binary_search_i(ForwardIterator first, ForwardIterator last, const T& value)
	{
		// To do: This can be made slightly faster by not using lower_bound.
		ForwardIterator i(eastl::lower_bound<ForwardIterator, T>(first, last, value));
		if((i != last) && !(value < *i)) // Note that we always express value comparisons in terms of < or ==.
			return i;
		return last;
	}


	/// binary_search_i
	///
	/// Returns: iterator if there is an iterator i in the range [first last) that 
	/// satisfies the corresponding conditions: !(*i < value) && !(value < *i).
	/// Returns last if the value is not found.
	///
	/// Complexity: At most 'log(last - first) + 2' comparisons.
	///
	template <typename ForwardIterator, typename T, typename Compare>
	inline ForwardIterator
	binary_search_i(ForwardIterator first, ForwardIterator last, const T& value, Compare compare)
	{
		// To do: This can be made slightly faster by not using lower_bound.
		ForwardIterator i(eastl::lower_bound<ForwardIterator, T, Compare>(first, last, value, compare));
		if((i != last) && !compare(value, *i))
			return i;
		return last;
	}
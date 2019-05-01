	/// count
	///
	/// Counts the number of items in the range of [first, last) which equal the input value.
	///
	/// Effects: Returns the number of iterators i in the range [first, last) for which the 
	/// following corresponding conditions hold: *i == value.
	///
	/// Complexity: At most 'last - first' applications of the corresponding predicate.
	///
	/// Note: The predicate version of count is count_if and not another variation of count.
	/// This is because both versions would have three parameters and there could be ambiguity.
	///
	template <typename InputIterator, typename T>
	inline typename eastl::iterator_traits<InputIterator>::difference_type
	count(InputIterator first, InputIterator last, const T& value)
	{
		typename eastl::iterator_traits<InputIterator>::difference_type result = 0;

		for(; first != last; ++first)
		{
			if(*first == value)
				++result;
		}
		return result;
	}



	// C++ doesn't define a count with predicate, as it can effectively be synthesized via count_if
	// with an appropriate predicate. However, it's often simpler to just have count with a predicate.
	template <typename InputIterator, typename T, typename Predicate>
	inline typename eastl::iterator_traits<InputIterator>::difference_type
	count(InputIterator first, InputIterator last, const T& value, Predicate predicate)
	{
		typename eastl::iterator_traits<InputIterator>::difference_type result = 0;

		for(; first != last; ++first)
		{
			if(predicate(*first, value))
				++result;
		}
		return result;
	}
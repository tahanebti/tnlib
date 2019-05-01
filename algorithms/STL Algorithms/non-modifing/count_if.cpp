	/// count_if
	///
	/// Counts the number of items in the range of [first, last) which match 
	/// the input value as defined by the input predicate function.
	///
	/// Effects: Returns the number of iterators i in the range [first, last) for which the 
	/// following corresponding conditions hold: predicate(*i) != false.
	///
	/// Complexity: At most 'last - first' applications of the corresponding predicate.
	///
	/// Note: The non-predicate version of count_if is count and not another variation of count_if.
	/// This is because both versions would have three parameters and there could be ambiguity.
	///
	template <typename InputIterator, typename Predicate>
	inline typename eastl::iterator_traits<InputIterator>::difference_type
	count_if(InputIterator first, InputIterator last, Predicate predicate)
	{
		typename eastl::iterator_traits<InputIterator>::difference_type result = 0;

		for(; first != last; ++first)
		{
			if(predicate(*first))
				++result;
		}
		return result;
	}
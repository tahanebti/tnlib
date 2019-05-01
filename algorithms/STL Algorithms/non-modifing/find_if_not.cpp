	/// find_if_not
	///
	/// find_if_not works the same as find_if except it tests for if the predicate
	/// returns false for the elements instead of true.
	///
	template <typename InputIterator, typename Predicate>
	inline InputIterator 
	find_if_not(InputIterator first, InputIterator last, Predicate predicate)
	{
		for(; first != last; ++first)
		{
			if(!predicate(*first))
				return first;
		}
		return last;
	}

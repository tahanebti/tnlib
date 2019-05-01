/// none_of
	///
	/// Returns: true if the unary predicate p returns true for none of the elements in the range [first, last)
	///
	template <typename InputIterator, typename Predicate>
	inline bool none_of(InputIterator first, InputIterator last, Predicate p)
	{
		for(; first != last; ++first)
		{
			if(p(*first)) 
				return false;
		}
		return true;
	}

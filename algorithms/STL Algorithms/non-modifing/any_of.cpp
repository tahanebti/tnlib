/// any_of
	///
	/// Returns: true if the unary predicate p returns true for any of the elements in the range [first, last)
	///
	template <typename InputIterator, typename Predicate>
	inline bool any_of(InputIterator first, InputIterator last, Predicate p)
	{
		for(; first != last; ++first)
		{
			if(p(*first))
				return true;
		}
		return false;
	}


	/// copy_if
	///
	/// Effects: Assigns to the result iterator only if the predicate is true.
	/// 
	template <typename InputIterator, typename OutputIterator, typename Predicate>
	inline OutputIterator
	copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate predicate)
	{
		// This implementation's performance could be improved by taking a more complicated approach like with the copy algorithm.
		for(; first != last; ++first)
		{
			if(predicate(*first))
				*result++ = *first;
		}

		return result;
	}

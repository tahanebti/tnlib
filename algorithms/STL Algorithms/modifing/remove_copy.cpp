	/// remove_copy
	///
	/// Effects: Copies all the elements referred to by the iterator i in the range 
	/// [first, last) for which the following corresponding condition does not hold: 
	/// *i == value.
	///
	/// Requires: The ranges [first, last) and [result, result + (last - first)) shall not overlap.
	///
	/// Returns: The end of the resulting range.
	///
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	template <typename InputIterator, typename OutputIterator, typename T>
	inline OutputIterator
	remove_copy(InputIterator first, InputIterator last, OutputIterator result, const T& value)
	{
		for(; first != last; ++first)
		{
			if(!(*first == value)) // Note that we always express value comparisons in terms of < or ==.
			{
				*result = move(*first);
				++result;
			}
		}
		return result;
	}
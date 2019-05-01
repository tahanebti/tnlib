	/// remove_copy_if
	///
	/// Effects: Copies all the elements referred to by the iterator i in the range 
	/// [first, last) for which the following corresponding condition does not hold: 
	/// predicate(*i) != false.
	///
	/// Requires: The ranges [first, last) and [result, result + (last - first)) shall not overlap.
	///
	/// Returns: The end of the resulting range.
	///
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	template <typename InputIterator, typename OutputIterator, typename Predicate>
	inline OutputIterator
	remove_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate predicate)
	{
		for(; first != last; ++first)
		{
			if(!predicate(*first))
			{
				*result = eastl::move(*first);
				++result;
			}
		}
		return result;
	}

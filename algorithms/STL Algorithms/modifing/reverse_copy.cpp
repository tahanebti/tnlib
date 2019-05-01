	/// reverse_copy
	///
	/// Copies the range [first, last) in reverse order to the result.
	///
	/// Effects: Copies the range [first, last) to the range 
	/// [result, result + (last - first)) such that for any nonnegative
	/// integer i < (last - first) the following assignment takes place:
	/// *(result + (last - first) - i) = *(first + i)
	///
	/// Requires: The ranges [first, last) and [result, result + (last - first))
	/// shall not overlap.
	///
	/// Returns: result + (last - first). That is, returns the end of the output range.
	///
	/// Complexity: Exactly 'last - first' assignments.
	///
	template <typename BidirectionalIterator, typename OutputIterator>
	inline OutputIterator
	reverse_copy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result)
	{
		for(; first != last; ++result)
			*result = *--last;
		return result;
	}
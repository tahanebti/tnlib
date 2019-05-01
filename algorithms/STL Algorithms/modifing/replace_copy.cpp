	/// replace_copy
	///
	/// Effects: Assigns to every iterator i in the range [result, result + (last - first))
	/// either new_value or *(first + (i - result)) depending on whether the following 
	/// corresponding conditions hold: *(first + (i - result)) == old_value.
	///
	/// Requires: The ranges [first, last) and [result, result + (last - first)) shall not overlap.
	///
	/// Returns: result + (last - first).
	///
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	/// Note: The predicate version of replace_copy is replace_copy_if and not another variation of replace_copy.
	/// This is because both versions would have the same parameter count and there could be ambiguity.
	///
	template <typename InputIterator, typename OutputIterator, typename T>
	inline OutputIterator
	replace_copy(InputIterator first, InputIterator last, OutputIterator result, const T& old_value, const T& new_value)
	{
		for(; first != last; ++first, ++result)
			*result = (*first == old_value) ? new_value : *first;
		return result;
	}
	/// replace_copy_if
	///
	/// Effects: Assigns to every iterator i in the range [result, result + (last - first))
	/// either new_value or *(first + (i - result)) depending on whether the following 
	/// corresponding conditions hold: predicate(*(first + (i - result))) != false.
	///
	/// Requires: The ranges [first, last) and [result, result+(lastfirst)) shall not overlap.
	///
	/// Returns: result + (last - first).
	///
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	/// Note: The predicate version of replace_copy_if is replace_copy and not another variation of replace_copy_if.
	/// This is because both versions would have the same parameter count and there could be ambiguity.
	///
	template <typename InputIterator, typename OutputIterator, typename Predicate, typename T>
	inline OutputIterator
	replace_copy_if(InputIterator first, InputIterator last, OutputIterator result, Predicate predicate, const T& new_value)
	{
		for(; first != last; ++first, ++result)
			*result = predicate(*first) ? new_value : *first;
		return result;
	}
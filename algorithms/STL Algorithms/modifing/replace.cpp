	/// replace
	///
	/// Effects: Substitutes elements referred by the iterator i in the range [first, last) 
	/// with new_value, when the following corresponding conditions hold: *i == old_value.
	/// 
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	/// Note: The predicate version of replace is replace_if and not another variation of replace.
	/// This is because both versions would have the same parameter count and there could be ambiguity.
	///
	template <typename ForwardIterator, typename T>
	inline void
	replace(ForwardIterator first, ForwardIterator last, const T& old_value, const T& new_value)
	{
		for(; first != last; ++first)
		{
			if(*first == old_value)
				*first = new_value;
		}
	}
	/// replace_if
	///
	/// Effects: Substitutes elements referred by the iterator i in the range [first, last) 
	/// with new_value, when the following corresponding conditions hold: predicate(*i) != false.
	/// 
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	/// Note: The predicate version of replace_if is replace and not another variation of replace_if.
	/// This is because both versions would have the same parameter count and there could be ambiguity.
	///
	template <typename ForwardIterator, typename Predicate, typename T>
	inline void
	replace_if(ForwardIterator first, ForwardIterator last, Predicate predicate, const T& new_value)
	{
		for(; first != last; ++first)
		{
			if(predicate(*first))
				*first = new_value;
		}
	}
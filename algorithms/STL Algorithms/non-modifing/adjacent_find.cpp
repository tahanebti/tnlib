/// adjacent_find
	///
	/// Returns: The first iterator i such that both i and i + 1 are in the range 
	/// [first, last) for which the following corresponding conditions hold: *i == *(i + 1). 
	/// Returns last if no such iterator is found.
	///
	/// Complexity: Exactly 'find(first, last, value) - first' applications of the corresponding predicate.
	///
	template <typename ForwardIterator>
	inline ForwardIterator 
	adjacent_find(ForwardIterator first, ForwardIterator last)
	{
		if(first != last)
		{
			ForwardIterator i = first;

			for(++i; i != last; ++i)
			{
				if(*first == *i)
					return first;
				first = i;
			}
		}
		return last;
	}

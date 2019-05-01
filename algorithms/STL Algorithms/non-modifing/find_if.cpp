	/// find_if
	///
	/// finds the value within the unsorted range of [first, last). 
	///
	/// Returns: The first iterator i in the range [first, last) for which 
	/// the following corresponding conditions hold: pred(*i) != false. 
	/// Returns last if no such iterator is found.
	/// If the sequence of elements to search for (i.e. first2 - last2) is empty,
	/// the find always fails and last1 will be returned.
	///
	/// Complexity: At most 'last - first' applications of the corresponding predicate.
	///
	/// Note: The non-predicate version of find_if is find and not another variation of find_if.
	/// This is because both versions would have three parameters and there could be ambiguity.
	///
	template <typename InputIterator, typename Predicate>
	inline InputIterator
	find_if(InputIterator first, InputIterator last, Predicate predicate)
	{
		while((first != last) && !predicate(*first))
			++first;
		return first;
	}
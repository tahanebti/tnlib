	/// find
	///
	/// finds the value within the unsorted range of [first, last). 
	///
	/// Returns: The first iterator i in the range [first, last) for which 
	/// the following corresponding conditions hold: *i == value. 
	/// Returns last if no such iterator is found.
	///
	/// Complexity: At most 'last - first' applications of the corresponding predicate.
	/// This is a linear search and not a binary one. 
	///
	/// Note: The predicate version of find is find_if and not another variation of find.
	/// This is because both versions would have three parameters and there could be ambiguity.
	///
	template <typename InputIterator, typename T>
	inline InputIterator
	find(InputIterator first, InputIterator last, const T& value)
	{
		while((first != last) && !(*first == value)) // Note that we always express value comparisons in terms of < or ==.
			++first;
		return first;
	}


	// C++ doesn't define a find with predicate, as it can effectively be synthesized via find_if
	// with an appropriate predicate. However, it's often simpler to just have find with a predicate.
	template <typename InputIterator, typename T, typename Predicate>
	inline InputIterator
	find(InputIterator first, InputIterator last, const T& value, Predicate predicate)
	{
		while((first != last) && !predicate(*first, value))
			++first;
		return first;
	}

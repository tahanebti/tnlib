	/// for_each
	///
	/// Calls the Function function for each value in the range [first, last).
	/// Function takes a single parameter: the current value.
	/// 
	/// Effects: Applies function to the result of dereferencing every iterator in 
	/// the range [first, last), starting from first and proceeding to last 1.
	///
	/// Returns: function.
	///
	/// Complexity: Applies function exactly 'last - first' times.
	///
	/// Note: If function returns a result, the result is ignored.
	/// 
	template <typename InputIterator, typename Function>
	inline Function
	for_each(InputIterator first, InputIterator last, Function function)
	{
		for(; first != last; ++first)
			function(*first);
		return function;
	}
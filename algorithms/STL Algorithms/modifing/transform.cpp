	/// transform
	///
	/// Iterates the input range of [first, last) and the output iterator result
	/// and assigns the result of unaryOperation(input) to result.
	/// 
	/// Effects: Assigns through every iterator i in the range [result, result + (last1 - first1))
	/// a new corresponding value equal to unaryOperation(*(first1 + (i - result)).
	///
	/// Requires: op shall not have any side effects.
	///
	/// Returns: result + (last1 - first1). That is, returns the end of the output range.
	///
	/// Complexity: Exactly 'last1 - first1' applications of unaryOperation.
	///
	/// Note: result may be equal to first.
	///
	template <typename InputIterator, typename OutputIterator, typename UnaryOperation>
	inline OutputIterator
	transform(InputIterator first, InputIterator last, OutputIterator result, UnaryOperation unaryOperation)
	{
		for(; first != last; ++first, ++result)
			*result = unaryOperation(*first);
		return result;
	}


	/// transform
	///
	/// Iterates the input range of [first, last) and the output iterator result
	/// and assigns the result of binaryOperation(input1, input2) to result.
	/// 
	/// Effects: Assigns through every iterator i in the range [result, result + (last1 - first1))
	/// a new corresponding value equal to binaryOperation(*(first1 + (i - result), *(first2 + (i - result))).
	///
	/// Requires: binaryOperation shall not have any side effects.
	///
	/// Returns: result + (last1 - first1). That is, returns the end of the output range.
	///
	/// Complexity: Exactly 'last1 - first1' applications of binaryOperation.
	///
	/// Note: result may be equal to first1 or first2.
	///
	template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename BinaryOperation>
	inline OutputIterator
	transform(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, OutputIterator result, BinaryOperation binaryOperation)
	{
		for(; first1 != last1; ++first1, ++first2, ++result)
			*result = binaryOperation(*first1, *first2);
		return result;
	}
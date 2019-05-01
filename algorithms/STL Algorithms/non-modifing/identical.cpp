	/// identical
	///
	/// Returns true if the two input ranges are equivalent.
	/// There is a subtle difference between this algorithm and 
	/// the 'equal' algorithm. The equal algorithm assumes the 
	/// two ranges are of equal length. This algorithm efficiently
	/// compares two ranges for both length equality and for 
	/// element equality. There is no other standard algorithm
	/// that can do this.
	///
	/// Returns: true if the sequence of elements defined by the range 
	/// [first1, last1) is of the same length as the sequence of
	/// elements defined by the range of [first2, last2) and if
	/// the elements in these ranges are equal as per the 
	/// equal algorithm.
	///
	/// Complexity: At most 'min((last1 - first1), (last2 - first2))' applications 
	/// of the corresponding comparison.
	///
	template <typename InputIterator1, typename InputIterator2>
	bool identical(InputIterator1 first1, InputIterator1 last1,
				   InputIterator2 first2, InputIterator2 last2)
	{
		while((first1 != last1) && (first2 != last2) && (*first1 == *first2))
		{
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 == last2);
	}


	/// identical
	///
	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	bool identical(InputIterator1 first1, InputIterator1 last1,
				   InputIterator2 first2, InputIterator2 last2, BinaryPredicate predicate)
	{
		while((first1 != last1) && (first2 != last2) && predicate(*first1, *first2))
		{
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 == last2);
	}
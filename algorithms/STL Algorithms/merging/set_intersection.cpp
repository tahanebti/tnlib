	/// set_intersection
	///
	/// set_intersection over both ranges and copies elements present in
	/// both ranges to the output range. 
	///
	/// Effects: Constructs a sorted intersection of the elements from the 
	/// two ranges; that is, the set of elements that are present in both of the ranges.
	///
	/// Requires: The input ranges must be sorted.
	/// Requires: The resulting range shall not overlap with either of the original ranges.
	///  
	/// Returns: The end of the constructed range.
	/// 
	/// Complexity: At most 2 * ((last1 - first1) + (last2 - first2)) - 1)  comparisons.
	/// 
	/// Note: The copying operation is stable; if an element is present in both ranges, 
	/// the one from the first range is copied.
	/// 
	template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
	OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									OutputIterator result)
	{
		while((first1 != last1) && (first2 != last2))
		{
			if(*first1 < *first2)
				++first1;
			else if(*first2 < *first1)
				++first2;
			else
			{
				*result = *first1;
				++first1;
				++first2;
				++result;
			}
		}

		return result;
	}


	template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename Compare>
	OutputIterator set_intersection(InputIterator1 first1, InputIterator1 last1,
									InputIterator2 first2, InputIterator2 last2,
									OutputIterator result, Compare compare)
	{
		while((first1 != last1) && (first2 != last2))
		{
			if(compare(*first1, *first2))
			{
				EASTL_VALIDATE_COMPARE(!compare(*first2, *first1)); // Validate that the compare function is sane.
				++first1;
			}
			else if(compare(*first2, *first1))
			{
				EASTL_VALIDATE_COMPARE(!compare(*first1, *first2)); // Validate that the compare function is sane.
				++first2;
			}
			else
			{
				*result = *first1;
				++first1;
				++first2;
				++result;
			}
		}

		return result;
	}

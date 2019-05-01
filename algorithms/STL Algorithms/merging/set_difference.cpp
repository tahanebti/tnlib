	/// set_difference
	///
	/// set_difference iterates over both input ranges and copies elements present 
	/// in the first range but not the second to the output range.
	///
	/// Effects: Copies the elements of the range [first1, last1) which are not 
	/// present in the range [first2, last2) to the range beginning at result. 
	/// The elements in the constructed range are sorted.
	/// 
	/// Requires: The input ranges must be sorted.
	/// Requires: The output range shall not overlap with either of the original ranges.
	/// 
	/// Returns: The end of the output range.
	/// 
	/// Complexity: At most (2 * ((last1 - first1) + (last2 - first2)) - 1) comparisons.
	///
	template <typename InputIterator1, typename InputIterator2, typename OutputIterator>
	OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2, 
								  OutputIterator result) 
	{
		while((first1 != last1) && (first2 != last2))
		{
			if(*first1 < *first2) 
			{
				*result = *first1;
				++first1;
				++result;
			}
			else if(*first2 < *first1)
				++first2;
			else 
			{
				++first1;
				++first2;
			}
		}

		return eastl::copy(first1, last1, result);
	}


	template <typename InputIterator1, typename InputIterator2, typename OutputIterator, typename Compare>
	OutputIterator set_difference(InputIterator1 first1, InputIterator1 last1,
								  InputIterator2 first2, InputIterator2 last2, 
								  OutputIterator result, Compare compare) 
	{
		while((first1 != last1) && (first2 != last2))
		{
			if(compare(*first1, *first2)) 
			{
				EASTL_VALIDATE_COMPARE(!compare(*first2, *first1)); // Validate that the compare function is sane.
				*result = *first1;
				++first1;
				++result;
			}
			else if(compare(*first2, *first1))
			{
				EASTL_VALIDATE_COMPARE(!compare(*first1, *first2)); // Validate that the compare function is sane.
				++first2;
			}
			else 
			{
				++first1;
				++first2;
			}
		}

		return eastl::copy(first1, last1, result);
	}

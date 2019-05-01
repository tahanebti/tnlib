	/// next_permutation
	///
	/// mutates the range [first, last) to the next permutation. Returns true if the 
	/// new range is not the final permutation (sorted like the starting permutation).
	/// Permutations start with a sorted range, and false is returned when next_permutation
	/// results in the initial sorted range, or if the range has <= 1 element.
	/// Note that elements are compared by operator < (as usual) and that elements deemed
	/// equal via this are not rearranged.
	///
	/// http://marknelson.us/2002/03/01/next-permutation/
	/// Basically we start with an ordered range and reverse it's order one specifically
	/// chosen swap and reverse at a time. It happens that this require going through every 
	/// permutation of the range. We use the same variable names as the document above.
	///
	/// To consider: Significantly improved permutation/combination functionality: 
	///    http://home.roadrunner.com/~hinnant/combinations.html
	///
	/// Example usage:
	///     vector<int> intArray;
	///     // <populate intArray>
	///     sort(intArray.begin(), intArray.end());
	///     do {
	///         // <do something with intArray>
	///     } while(next_permutation(intArray.begin(), intArray.end()));
	///

	template<typename BidirectionalIterator, typename Compare>
	bool next_permutation(BidirectionalIterator first, BidirectionalIterator last, Compare compare)
	{
		if(first != last) // If there is anything in the range...
		{
			BidirectionalIterator i = last;

			if(first != --i) // If the range has more than one item...
			{
				for(;;)
				{
					BidirectionalIterator ii(i), j;
 
					if(compare(*--i, *ii)) // Find two consecutive values where the first is less than the second.
					{
						j = last;
						while(!compare(*i, *--j)) // Find the final value that's greater than the first (it may be equal to the second).
							{}
						eastl::iter_swap(i, j);     // Swap the first and the final.
						eastl::reverse(ii, last);   // Reverse the ranget from second to last. 
						return true;
					}

					if(i == first) // There are no two consecutive values where the first is less than the second, meaning the range is in reverse order. The reverse ordered range is always the last permutation.
					{
						eastl::reverse(first, last);
						break; // We are done.
					}
				}
			}
		}

		return false;
	}

	template<typename BidirectionalIterator>
	bool next_permutation(BidirectionalIterator first, BidirectionalIterator last)
	{
		typedef typename eastl::iterator_traits<BidirectionalIterator>::value_type value_type;

		return next_permutation(first, last, eastl::less<value_type>());
	}
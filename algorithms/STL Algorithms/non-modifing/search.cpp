	/// search
	///
	/// Search finds a subsequence within the range [first1, last1) that is identical to [first2, last2) 
	/// when compared element-by-element. It returns an iterator pointing to the beginning of that 
	/// subsequence, or else last1 if no such subsequence exists. As such, it is very much like 
	/// the C strstr function, with the primary difference being that strstr uses 0-terminated strings
	/// whereas search uses an end iterator to specify the end of a string.
	///
	/// Returns: The first iterator i in the range [first1, last1 - (last2 - first2)) such that for
	/// any nonnegative integer n less than 'last2 - first2' the following corresponding condition holds:
	/// *(i + n) == *(first2 + n). Returns last1 if no such iterator is found.
	///
	/// Complexity: At most (last1 first1) * (last2 first2) applications of the corresponding predicate.
	///
	template <typename ForwardIterator1, typename ForwardIterator2>
	ForwardIterator1
	search(ForwardIterator1 first1, ForwardIterator1 last1, 
		   ForwardIterator2 first2, ForwardIterator2 last2)
	{
		if(first2 != last2) // If there is anything to search for...
		{
			// We need to make a special case for a pattern of one element,
			// as the logic below prevents one element patterns from working.
			ForwardIterator2 temp2(first2);
			++temp2;

			if(temp2 != last2) // If what we are searching for has a length > 1...
			{
				ForwardIterator1 cur1(first1);
				ForwardIterator2 p2;

				while(first1 != last1)
				{
					// The following loop is the equivalent of eastl::find(first1, last1, *first2)
					while((first1 != last1) && !(*first1 == *first2))
						++first1;

					if(first1 != last1)
					{
						p2   = temp2;
						cur1 = first1;

						if(++cur1 != last1)
						{
							while(*cur1 == *p2)
							{
								if(++p2 == last2)
									return first1;

								if(++cur1 == last1)
									return last1;
							}

							++first1;
							continue;
						}
					}
					return last1;
				}

				// Fall through to the end.
			}
			else
				return eastl::find(first1, last1, *first2);
		}

		return first1;


		#if 0
		/*  Another implementation which is a little more simpler but executes a little slower on average.
			typedef typename eastl::iterator_traits<ForwardIterator1>::difference_type difference_type_1;
			typedef typename eastl::iterator_traits<ForwardIterator2>::difference_type difference_type_2;

			const difference_type_2 d2 = eastl::distance(first2, last2);

			for(difference_type_1 d1 = eastl::distance(first1, last1); d1 >= d2; ++first1, --d1)
			{
				ForwardIterator1 temp1 = first1;

				for(ForwardIterator2 temp2 = first2; ; ++temp1, ++temp2)
				{
					if(temp2 == last2)
						return first1;
					if(!(*temp1 == *temp2))
						break;
				}
			}

			return last1;
		*/
		#endif
	}


	/// search
	///
	/// Search finds a subsequence within the range [first1, last1) that is identical to [first2, last2) 
	/// when compared element-by-element. It returns an iterator pointing to the beginning of that 
	/// subsequence, or else last1 if no such subsequence exists. As such, it is very much like 
	/// the C strstr function, with the only difference being that strstr uses 0-terminated strings
	/// whereas search uses an end iterator to specify the end of a string.
	///
	/// Returns: The first iterator i in the range [first1, last1 - (last2 - first2)) such that for
	/// any nonnegative integer n less than 'last2 - first2' the following corresponding condition holds:
	/// predicate(*(i + n), *(first2 + n)) != false. Returns last1 if no such iterator is found.
	///
	/// Complexity: At most (last1 first1) * (last2 first2) applications of the corresponding predicate.
	///
	template <typename ForwardIterator1, typename ForwardIterator2, typename BinaryPredicate>
	ForwardIterator1
	search(ForwardIterator1 first1, ForwardIterator1 last1, 
		   ForwardIterator2 first2, ForwardIterator2 last2,
		   BinaryPredicate predicate)
	{
		typedef typename eastl::iterator_traits<ForwardIterator1>::difference_type difference_type_1;
		typedef typename eastl::iterator_traits<ForwardIterator2>::difference_type difference_type_2;

		difference_type_2 d2 = eastl::distance(first2, last2);

		if(d2 != 0)
		{
			ForwardIterator1 i(first1);
			eastl::advance(i, d2);

			for(difference_type_1 d1 = eastl::distance(first1, last1); d1 >= d2; --d1)
			{
				if(eastl::equal<ForwardIterator1, ForwardIterator2, BinaryPredicate>(first1, i, first2, predicate))
					return first1;
				if(d1 > d2) // To do: Find a way to make the algorithm more elegant.
				{
					++first1;
					++i;
				}
			}
			return last1;
		}
		return first1; // Just like with strstr, we return first1 if the match string is empty.
	}


	// search_n helper functions
	//
	template <typename ForwardIterator, typename Size, typename T>
	ForwardIterator     // Generic implementation.
	search_n_impl(ForwardIterator first, ForwardIterator last, Size count, const T& value, EASTL_ITC_NS::forward_iterator_tag)
	{
		if(count <= 0)
			return first;

		Size d1 = (Size)eastl::distance(first, last); // Should d1 be of type Size, ptrdiff_t, or iterator_traits<ForwardIterator>::difference_type?
													  // The problem with using iterator_traits<ForwardIterator>::difference_type is that 
		if(count > d1)                                // ForwardIterator may not be a true iterator but instead something like a pointer.
			return last;

		for(; d1 >= count; ++first, --d1)
		{
			ForwardIterator i(first);

			for(Size n = 0; n < count; ++n, ++i, --d1)
			{
				if(!(*i == value)) // Note that we always express value comparisons in terms of < or ==.
					goto not_found;
			}
			return first;

			not_found:
			first = i;
		}
		return last;
	}

	template <typename RandomAccessIterator, typename Size, typename T> inline
	RandomAccessIterator    // Random access iterator implementation. Much faster than generic implementation.
	search_n_impl(RandomAccessIterator first, RandomAccessIterator last, Size count, const T& value, EASTL_ITC_NS::random_access_iterator_tag)
	{
		if(count <= 0)
			return first;
		else if(count == 1)
			return find(first, last, value);
		else if(last > first)
		{
			RandomAccessIterator lookAhead;
			RandomAccessIterator backTrack;

			Size skipOffset = (count - 1);
			Size tailSize = (Size)(last - first);
			Size remainder;
			Size prevRemainder;

			for(lookAhead = first + skipOffset; tailSize >= count; lookAhead += count)
			{
				tailSize -= count;

				if(*lookAhead == value)
				{
					remainder = skipOffset;

					for(backTrack = lookAhead - 1; *backTrack == value; --backTrack)
					{
						if(--remainder == 0)
							return (lookAhead - skipOffset); // success
					}

					if(remainder <= tailSize)
					{
						prevRemainder = remainder;

						while(*(++lookAhead) == value)
						{
							if(--remainder == 0)
								return (backTrack + 1); // success
						}
						tailSize -= (prevRemainder - remainder);
					}
					else
						return last; // failure
				}

				// lookAhead here is always pointing to the element of the last mismatch.
			}
		}

		return last; // failure
	}

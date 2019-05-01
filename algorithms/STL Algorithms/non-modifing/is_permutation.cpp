	/// is_permutation
	///
	template<typename ForwardIterator1, typename ForwardIterator2>
	bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2)
	{
		typedef typename eastl::iterator_traits<ForwardIterator1>::difference_type difference_type;

		// Skip past any equivalent initial elements.
		while((first1 != last1) && (*first1 == *first2))
		{
			++first1;
			++first2;
		}

		if(first1 != last1)
		{
			const difference_type first1Size = eastl::distance(first1, last1);
			ForwardIterator2 last2 = first2;
			eastl::advance(last2, first1Size);

			for(ForwardIterator1 i = first1; i != last1; ++i)
			{
				if(i == eastl::find(first1, i, *i)) 
				{
					const difference_type c = eastl::count(first2, last2, *i);

					if((c == 0) || (c != eastl::count(i, last1, *i)))
						return false;
				}
			}
		}

		return true;
	}

	/// is_permutation
	///
	template<typename ForwardIterator1, typename ForwardIterator2, class BinaryPredicate>
	bool is_permutation(ForwardIterator1 first1, ForwardIterator1 last1, ForwardIterator2 first2, BinaryPredicate predicate)
	{
		typedef typename eastl::iterator_traits<ForwardIterator1>::difference_type difference_type;

		// Skip past any equivalent initial elements.
		while((first1 != last1) && predicate(*first1, *first2))
		{
			++first1;
			++first2;
		}

		if(first1 != last1)
		{
			const difference_type first1Size = eastl::distance(first1, last1);
			ForwardIterator2 last2 = first2;
			eastl::advance(last2, first1Size);

			for(ForwardIterator1 i = first1; i != last1; ++i)
			{
				if(i == eastl::find(first1, i, *i, predicate)) 
				{
					const difference_type c = eastl::count(first2, last2, *i, predicate);

					if((c == 0) || (c != eastl::count(i, last1, *i, predicate)))
						return false;
				}
			}
		}

		return true;
	}
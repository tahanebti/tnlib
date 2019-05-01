	template <class BidirectionalIterator1, class ForwardIterator2>
	inline BidirectionalIterator1
	find_last_not_of(BidirectionalIterator1 first1, BidirectionalIterator1 last1, 
					 ForwardIterator2 first2, ForwardIterator2 last2)
	{
		if((first1 != last1) && (first2 != last2))
		{
			BidirectionalIterator1 it1(last1);

			while((--it1 != first1) && (eastl::find(first2, last2, *it1) != last2))
				; // Do nothing

			if((it1 != first1) || (eastl::find( first2, last2, *it1) == last2))
				return it1;
		}

		return last1;
	}


	template <class BidirectionalIterator1, class ForwardIterator2, class BinaryPredicate>
	inline BidirectionalIterator1
	find_last_not_of(BidirectionalIterator1 first1, BidirectionalIterator1 last1, 
					 ForwardIterator2 first2, ForwardIterator2 last2, 
					 BinaryPredicate predicate)
	{
		typedef typename eastl::iterator_traits<BidirectionalIterator1>::value_type value_type;

		if((first1 != last1) && (first2 != last2))
		{
			BidirectionalIterator1 it1(last1);

			while((--it1 != first1) && (eastl::find_if(first2, last2, eastl::bind1st<BinaryPredicate, value_type>(predicate, *it1)) != last2))
				; // Do nothing

			if((it1 != first1) || (eastl::find_if(first2, last2, eastl::bind1st<BinaryPredicate, value_type>(predicate, *it1))) != last2)
				return it1;
		}

		return last1;
	}
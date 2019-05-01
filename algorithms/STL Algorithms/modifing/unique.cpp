	/// unique
	///
	/// Given a sorted range, this function removes duplicated items.
	/// Note that if you have a container then you will probably want 
	/// to call erase on the container with the return value if your 
	/// goal is to remove the duplicated items from the container.
	///
	/// Effects: Eliminates all but the first element from every consecutive 
	/// group of equal elements referred to by the iterator i in the range 
	/// [first, last) for which the following corresponding condition holds:
	/// *i == *(i - 1).
	///
	/// Returns: The end of the resulting range.
	///
	/// Complexity: If the range (last - first) is not empty, exactly (last - first)
	/// applications of the corresponding predicate, otherwise no applications of the predicate.
	///
	/// Example usage:
	///    vector<int> intArray;
	///    ...
	///    intArray.erase(unique(intArray.begin(), intArray.end()), intArray.end());
	///
	template <typename ForwardIterator>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last)
	{
		first = eastl::adjacent_find<ForwardIterator>(first, last);

		if(first != last) // We expect that there are duplicated items, else the user wouldn't be calling this function.
		{
			ForwardIterator dest(first);
			
			for(++first; first != last; ++first)
			{
				if(!(*dest == *first)) // Note that we always express value comparisons in terms of < or ==.
					*++dest = *first;
			}
			return ++dest;
		}
		return last;
	}


	/// unique
	///
	/// Given a sorted range, this function removes duplicated items.
	/// Note that if you have a container then you will probably want 
	/// to call erase on the container with the return value if your 
	/// goal is to remove the duplicated items from the container.
	///
	/// Effects: Eliminates all but the first element from every consecutive 
	/// group of equal elements referred to by the iterator i in the range 
	/// [first, last) for which the following corresponding condition holds:
	/// predicate(*i, *(i - 1)) != false.
	///
	/// Returns: The end of the resulting range.
	///
	/// Complexity: If the range (last - first) is not empty, exactly (last - first)
	/// applications of the corresponding predicate, otherwise no applications of the predicate.
	///
	template <typename ForwardIterator, typename BinaryPredicate>
	ForwardIterator unique(ForwardIterator first, ForwardIterator last, BinaryPredicate predicate)
	{
		first = eastl::adjacent_find<ForwardIterator, BinaryPredicate>(first, last, predicate);

		if(first != last) // We expect that there are duplicated items, else the user wouldn't be calling this function.
		{
			ForwardIterator dest(first);
			
			for(++first; first != last; ++first)
			{
				if(!predicate(*dest, *first))
					*++dest = *first;
			}
			return ++dest;
		}
		return last;
	}
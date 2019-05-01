	/// move_n
	///
	/// Same as move(InputIterator, InputIterator, OutputIterator) except based on count instead of iterator range.
	///
	template <typename InputIterator, typename Size, typename OutputIterator>
	inline OutputIterator
	move_n_impl(InputIterator first, Size n, OutputIterator result, EASTL_ITC_NS::input_iterator_tag)
	{
		for(; n > 0; --n)
			*result++ = eastl::move(*first++);
		return result;
	}

	template <typename RandomAccessIterator, typename Size, typename OutputIterator>
	inline OutputIterator
	move_n_impl(RandomAccessIterator first, Size n, OutputIterator result, EASTL_ITC_NS::random_access_iterator_tag)
	{ 
		return eastl::move(first, first + n, result); // Take advantage of the optimizations present in the move algorithm.
	}


	template <typename InputIterator, typename Size, typename OutputIterator>
	inline OutputIterator 
	move_n(InputIterator first, Size n, OutputIterator result)
	{
		typedef typename eastl::iterator_traits<InputIterator>::iterator_category IC;
		return eastl::move_n_impl(first, n, result, IC());
	}

	/// search_n
	///
	/// Returns: The first iterator i in the range [first, last count) such that 
	/// for any nonnegative integer n less than count the following corresponding 
	/// conditions hold: *(i + n) == value, pred(*(i + n),value) != false. 
	/// Returns last if no such iterator is found.
	///
	/// Complexity: At most '(last1 - first1) * count' applications of the corresponding predicate.
	///
	template <typename ForwardIterator, typename Size, typename T>
	ForwardIterator
	search_n(ForwardIterator first, ForwardIterator last, Size count, const T& value)
	{
		typedef typename eastl::iterator_traits<ForwardIterator>::iterator_category IC;
		return eastl::search_n_impl(first, last, count, value, IC());
	}

	/// rotate_copy
	///
	/// Similar to rotate except writes the output to the OutputIterator and  
	/// returns an OutputIterator to the element past the last element copied
	/// (i.e. result + (last - first))
	///
	template <typename ForwardIterator, typename OutputIterator>
	OutputIterator rotate_copy(ForwardIterator first, ForwardIterator middle, ForwardIterator last, OutputIterator result)
	{
		return eastl::copy(first, middle, eastl::copy(middle, last, result));
	}

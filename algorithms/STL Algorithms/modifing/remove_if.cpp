	/// remove_if
	///
	/// Effects: Eliminates all the elements referred to by iterator i in the 
	/// range [first, last) for which the following corresponding condition 
	/// holds: predicate(*i) != false.
	///
	/// Returns: The end of the resulting range.
	///
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	/// Note: The predicate version of remove_if is remove and not another variation of remove_if.
	/// This is because both versions would have the same parameter count and there could be ambiguity.
	///
	/// Note: Since this function moves the element to the back of the heap and 
	/// doesn't actually remove it from the given container, the user must call
	/// the container erase function if the user wants to erase the element 
	/// from the container.
	///
	/// Example usage:
	///    vector<int> intArray;
	///    ...
	///    intArray.erase(remove(intArray.begin(), intArray.end(), bind2nd(less<int>(), (int)3)), intArray.end()); // Erase all elements less than 3.
	///
	template <typename ForwardIterator, typename Predicate>
	inline ForwardIterator
	remove_if(ForwardIterator first, ForwardIterator last, Predicate predicate)
	{
		first = eastl::find_if(first, last, predicate);
		if(first != last)
		{
			ForwardIterator i(first);
			return eastl::remove_copy_if<ForwardIterator, ForwardIterator, Predicate>(++i, last, first, predicate);
		}
		return first;
	}



auto main() -> int 
{

	std::vector<int> v;
	std::iota(begin(v), end(v), 1);
	print(v);

	auto is_odd = [](auto e){e % 2 != 0;}
	v.erase(std::remove_if(begin(v), end(v), is_odd), end(v));
	print(v);


	return 0;
} 	
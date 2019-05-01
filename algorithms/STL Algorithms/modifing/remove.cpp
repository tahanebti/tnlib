	/// remove
	///
	/// Effects: Eliminates all the elements referred to by iterator i in the 
	/// range [first, last) for which the following corresponding condition
	/// holds: *i == value.
	///
	/// Returns: The end of the resulting range.
	///
	/// Complexity: Exactly 'last - first' applications of the corresponding predicate.
	///
	/// Note: The predicate version of remove is remove_if and not another variation of remove.
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
	///    intArray.erase(remove(intArray.begin(), intArray.end(), 4), intArray.end()); // Erase all elements of value 4.
	///
	template <typename ForwardIterator, typename T>
	inline ForwardIterator
	remove(ForwardIterator first, ForwardIterator last, const T& value)
	{
		first = eastl::find(first, last, value);
		if(first != last)
		{
			ForwardIterator i(first);
			return eastl::remove_copy(++i, last, first, value);
		}
		return first;
	}


template<typename T>
inline T remove(std::std::vector<T>& v, const T& item)
{
	v.erase(std::remove(begin(v),end(v), item), end(v));
}	

auto main() -> int 
{

	return 0;
} 
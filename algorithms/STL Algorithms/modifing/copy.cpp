	/// copy_n
	///
	/// Same as copy(InputIterator, InputIterator, OutputIterator) except based on count instead of iterator range.
	/// Effects: Copies exactly count values from the range beginning at first to the range beginning at result, if count > 0. Does nothing otherwise. 
	/// Returns: Iterator in the destination range, pointing past the last element copied if count>0 or first otherwise. 
	/// Complexity: Exactly count assignments, if count > 0. 
	///
	template <typename InputIterator, typename Size, typename OutputIterator>
	inline OutputIterator
	copy_n_impl(InputIterator first, Size n, OutputIterator result, EASTL_ITC_NS::input_iterator_tag)
	{
		for(; n > 0; --n)
			*result++ = *first++;
		return result;
	}

	template <typename RandomAccessIterator, typename Size, typename OutputIterator>
	inline OutputIterator
	copy_n_impl(RandomAccessIterator first, Size n, OutputIterator result, EASTL_ITC_NS::random_access_iterator_tag)
	{ 
		return eastl::copy(first, first + n, result); // Take advantage of the optimizations present in the copy algorithm.
	}


	template <typename InputIterator, typename Size, typename OutputIterator>
	inline OutputIterator 
	copy_n(InputIterator first, Size n, OutputIterator result)
	{
		typedef typename eastl::iterator_traits<InputIterator>::iterator_category IC;
		return eastl::copy_n_impl(first, n, result, IC());
	}





	#include <iostream>
#include <vector>
#include <string>

// use the efficient memcpy() if allowed (i.e., if T is trivially copyable):
template<typename T, size_t N>
typename std::enable_if<std::is_trivially_copyable<T>::value>::type
copy(T(&from)[N], T(&to)[N])
{
	std::memcpy(to, from, N * sizeof(T));
}

// otherwise, copy elements one by one using copy assignment:
template<typename T, size_t N>
std::enable_if_t<!std::is_trivially_copyable<T>::value>
copy(T(&from)[N], T(&to)[N])
{
	for (size_t i = 0; i < N; ++i)
		to[i] = from[i];
}

int main()
{
	int arrayFrom[12] = { 0 };
	int arrayTo[12] = { 0 };
	copy(arrayFrom, arrayTo);	// Calls the first copy() implementation.

	std::string vecFrom[2] = { "A", "B" };
	std::string vecTo[2];
	copy(vecFrom, vecTo);		// Calls the second copy() implementation.


	std::cout << std::endl;
}

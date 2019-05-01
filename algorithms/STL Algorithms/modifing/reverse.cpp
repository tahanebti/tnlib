	// reverse
	//
	// We provide helper functions which allow reverse to be implemented more  
	// efficiently for some types of iterators and types.
	//
	template <typename BidirectionalIterator>
	inline void reverse_impl(BidirectionalIterator first, BidirectionalIterator last, EASTL_ITC_NS::bidirectional_iterator_tag)
	{
		for(; (first != last) && (first != --last); ++first) // We are not allowed to use operator <, <=, >, >= with a
			eastl::iter_swap(first, last);                   // generic (bidirectional or otherwise) iterator.
	}

	template <typename RandomAccessIterator>
	inline void reverse_impl(RandomAccessIterator first, RandomAccessIterator last, EASTL_ITC_NS::random_access_iterator_tag)
	{
		if(first != last)
		{
			for(; first < --last; ++first)      // With a random access iterator, we can use operator < to more efficiently implement
				eastl::iter_swap(first, last);  // this algorithm. A generic iterator doesn't necessarily have an operator < defined.
		}
	}

	/// reverse
	///
	/// Reverses the values within the range [first, last).
	///
	/// Effects: For each nonnegative integer i <= (last - first) / 2, 
	/// applies swap to all pairs of iterators first + i, (last i) - 1.
	///
	/// Complexity: Exactly '(last - first) / 2' swaps.
	///
	template <typename BidirectionalIterator>
	inline void reverse(BidirectionalIterator first, BidirectionalIterator last)
	{
		typedef typename eastl::iterator_traits<BidirectionalIterator>::iterator_category IC;
		eastl::reverse_impl(first, last, IC());
	}









	#include <cmath>
#include <limits>
#include <iostream>

#define MAX_DECIMAL_FRACTION 5
#define DEBUGTRACE(x) // do { std::cerr << x; } while (false)

template <typename T, bool is_integer> struct reverse_impl;

template <typename T>
struct reverse_impl<T, true>
{
	static T reverse(T input)
	{
		T output;

		for (output = 0; input; input/=10)
			output = (output * 10) + input % 10;

		return output;
	}
};

template <typename T>
struct reverse_impl<T, false>
{
	static T reverse(T input)
	{
		if (std::abs(input) <= std::numeric_limits<T>::epsilon())
			return T(0);

		// scale input
		int log10 = (int) (std::log(input)/std::log(T(10)));
		input *= std::pow(10, MAX_DECIMAL_FRACTION);
		input = std::floor(input);
		input /= std::pow(10, log10+MAX_DECIMAL_FRACTION);

		DEBUGTRACE("debug: scaled " << input << " digits: ");

		int iteration = std::max(log10+MAX_DECIMAL_FRACTION, MAX_DECIMAL_FRACTION);

		if (std::floor(input) < 1)
		{
			input *= 10;
			iteration--;
		}

		T output;
		for (output = T(0); 
			 iteration-- && std::floor(input) >= 1; 
			 input-=std::floor(input), input*=T(10))
		{
			output = (output / T(10)) + std::floor(input);
			DEBUGTRACE(std::floor(input));
		}

		DEBUGTRACE(std::endl);
		return output * std::pow(10, log10);
	}
};

template <typename T>
T reverse(T input)
{ 
	return reverse_impl<T, std::numeric_limits<T>::is_integer>::reverse(input); 
}

int main()
{
	std::cout << reverse(-123l) << std::endl;
	std::cout << reverse(123ul) << std::endl;

	std::cout << reverse(123456.0) << std::endl;
	std::cout << reverse(0.027f) << std::endl;

	return 0;
}

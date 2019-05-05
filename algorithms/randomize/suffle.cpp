	/// shuffle
	///
	/// New for C++11
	/// Randomizes a sequence of values via a user-supplied UniformRandomNumberGenerator.
	/// The difference between this and the original random_shuffle function is that this uses the more
	/// advanced and flexible UniformRandomNumberGenerator interface as opposed to the more 
	/// limited RandomNumberGenerator interface of random_shuffle.
	///
	/// Effects: Shuffles the elements in the range [first, last) with uniform distribution.
	///
	/// Complexity: Exactly '(last - first) - 1' swaps.
	///
	/// Example usage:
	///     struct Rand{ eastl_size_t operator()(eastl_size_t n) { return (eastl_size_t)(rand() % n); } }; // Note: The C rand function is poor and slow.
	///     Rand randInstance;
	///     shuffle(pArrayBegin, pArrayEnd, randInstance);
	///
	// See the C++11 Standard, 26.5.1.3, Uniform random number generator requirements.
	// Also http://en.cppreference.com/w/cpp/numeric/random/uniform_int_distribution

	template <typename RandomAccessIterator, typename UniformRandomNumberGenerator>
	void shuffle(RandomAccessIterator first, RandomAccessIterator last, UniformRandomNumberGenerator&& urng)
	{
		if(first != last)
		{
			typedef typename eastl::iterator_traits<RandomAccessIterator>::difference_type difference_type;
			typedef typename eastl::make_unsigned<difference_type>::type                   unsigned_difference_type;
			typedef typename eastl::uniform_int_distribution<unsigned_difference_type>     uniform_int_distribution;
			typedef typename uniform_int_distribution::param_type                          uniform_int_distribution_param_type;

			uniform_int_distribution uid;

			for(RandomAccessIterator i = first + 1; i != last; ++i)
				iter_swap(i, first + uid(urng, uniform_int_distribution_param_type(0, i - first)));
		}
	}

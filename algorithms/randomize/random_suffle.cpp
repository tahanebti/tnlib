	/// random_shuffle
	///
	/// Randomizes a sequence of values.
	///
	/// Effects: Shuffles the elements in the range [first, last) with uniform distribution.
	///
	/// Complexity: Exactly '(last - first) - 1' swaps.
	///
	/// Example usage:
	///     eastl_size_t Rand(eastl_size_t n) { return (eastl_size_t)(rand() % n); } // Note: The C rand function is poor and slow.
	///     pointer_to_unary_function<eastl_size_t, eastl_size_t> randInstance(Rand);
	///     random_shuffle(pArrayBegin, pArrayEnd, randInstance);
	///
	/// Example usage:
	///     struct Rand{ eastl_size_t operator()(eastl_size_t n) { return (eastl_size_t)(rand() % n); } }; // Note: The C rand function is poor and slow.
	///     Rand randInstance;
	///     random_shuffle(pArrayBegin, pArrayEnd, randInstance);
	///
	template <typename RandomAccessIterator, typename RandomNumberGenerator>
	inline void random_shuffle(RandomAccessIterator first, RandomAccessIterator last, RandomNumberGenerator&& rng)
	{
		typedef typename eastl::iterator_traits<RandomAccessIterator>::difference_type difference_type;

		// We must do 'rand((i - first) + 1)' here and cannot do 'rand(last - first)',
		// as it turns out that the latter results in unequal distribution probabilities.
		// http://www.cigital.com/papers/download/developer_gambling.php

		for(RandomAccessIterator i = first + 1; i < last; ++i)               
			iter_swap(i, first + (difference_type)rng((eastl_size_t)((i - first) + 1)));
	}

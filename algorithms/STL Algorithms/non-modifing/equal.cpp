	/// equal
	///
	/// Returns: true if for every iterator i in the range [first1, last1) the 
	/// following corresponding conditions hold: predicate(*i, *(first2 + (i - first1))) != false. 
	/// Otherwise, returns false.
	///
	/// Complexity: At most last1 first1 applications of the corresponding predicate.
	///
	/// To consider: Make specializations of this for scalar types and random access
	/// iterators that uses memcmp or some trick memory comparison function. 
	/// We should verify that such a thing results in an improvement.
	///
	template <typename InputIterator1, typename InputIterator2>
	EA_CPP14_CONSTEXPR inline bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
	{
		for(; first1 != last1; ++first1, ++first2)
		{
			if(!(*first1 == *first2)) // Note that we always express value comparisons in terms of < or ==.
				return false;
		}
		return true;
	}

	/* Enable the following if there was shown to be some benefit. A glance and Microsoft VC++ memcmp
		shows that it is not optimized in any way, much less one that would benefit us here.

	inline bool equal(const bool* first1, const bool* last1, const bool* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const char* first1, const char* last1, const char* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const unsigned char* first1, const unsigned char* last1, const unsigned char* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const signed char* first1, const signed char* last1, const signed char* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	#ifndef EA_WCHAR_T_NON_NATIVE
		inline bool equal(const wchar_t* first1, const wchar_t* last1, const wchar_t* first2)
			{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }
	#endif

	inline bool equal(const int16_t* first1, const int16_t* last1, const int16_t* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const uint16_t* first1, const uint16_t* last1, const uint16_t* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const int32_t* first1, const int32_t* last1, const int32_t* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const uint32_t* first1, const uint32_t* last1, const uint32_t* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const int64_t* first1, const int64_t* last1, const int64_t* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }

	inline bool equal(const uint64_t* first1, const uint64_t* last1, const uint64_t* first2)
		{ return (memcmp(first1, first2, (size_t)((uintptr_t)last1 - (uintptr_t)first1)) == 0); }
	*/



	/// equal
	///
	/// Returns: true if for every iterator i in the range [first1, last1) the 
	/// following corresponding conditions hold: pred(*i, *(first2 + (i first1))) != false. 
	/// Otherwise, returns false.
	///
	/// Complexity: At most last1 first1 applications of the corresponding predicate.
	///
	template <typename InputIterator1, typename InputIterator2, typename BinaryPredicate>
	inline bool
	equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate predicate)
	{
		for(; first1 != last1; ++first1, ++first2)
		{
			if(!predicate(*first1, *first2))
				return false;
		}
		return true;
	}

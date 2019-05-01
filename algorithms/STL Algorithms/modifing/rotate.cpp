	/// rotate
	///
	/// Effects: For each non-negative integer i < (last - first), places the element from the 
	/// position first + i into position first + (i + (last - middle)) % (last - first).
	///
	/// Returns: first + (last - middle). That is, returns where first went to.
	/// 
	/// Remarks: This is a left rotate.
	/// 
	/// Requires: [first,middle) and [middle,last) shall be valid ranges. ForwardIterator shall 
	/// satisfy the requirements of ValueSwappable (17.6.3.2). The type of *first shall satisfy 
	/// the requirements of MoveConstructible (Table 20) and the requirements of MoveAssignable.
	///
	/// Complexity: At most last - first swaps.
	///
	/// Note: While rotate works on ForwardIterators (e.g. slist) and BidirectionalIterators (e.g. list), 
	/// you can get much better performance (O(1) instead of O(n)) with slist and list rotation by 
	/// doing splice operations on those lists instead of calling this rotate function. 
	///
	/// http://www.cs.bell-labs.com/cm/cs/pearls/s02b.pdf / http://books.google.com/books?id=kse_7qbWbjsC&pg=PA14&lpg=PA14&dq=Programming+Pearls+flipping+hands
	/// http://books.google.com/books?id=tjOlkl7ecVQC&pg=PA189&lpg=PA189&dq=stepanov+Elements+of+Programming+rotate
	/// http://stackoverflow.com/questions/21160875/why-is-stdrotate-so-fast
	///
	/// Strategy:
	///     - We handle the special case of (middle == first) and (middle == last) no-ops
	///       up front in the main rotate entry point.
	///     - There's a basic ForwardIterator implementation (rotate_general_impl) which is 
	///       a fallback implementation that's not as fast as others but works for all cases.
	///     - There's a slightly better BidirectionalIterator implementation.
	///     - We have specialized versions for rotating elements that are is_trivially_move_assignable.
	///       These versions will use memmove for when we have a RandomAccessIterator.
	///     - We have a specialized version for rotating by only a single position, as that allows us
	///       (with any iterator type) to avoid a lot of logic involved with algorithms like "flipping hands"
	///       and achieve near optimal O(n) behavior. it turns out that rotate-by-one is a common use
	///       case in practice.
	/// 
	namespace Internal
	{
		template<typename ForwardIterator>
		ForwardIterator rotate_general_impl(ForwardIterator first, ForwardIterator middle, ForwardIterator last)
		{
			using eastl::swap;

			ForwardIterator current = middle;

			do {
				swap(*first++, *current++);

				if(first == middle)
					middle = current;
			} while(current != last);

			ForwardIterator result = first;
			current = middle;

			while(current != last)
			{
				swap(*first++, *current++);

				if(first == middle)
					middle = current;
				else if(current == last)
					current = middle;
			}

			return result; // result points to first + (last - middle).
		}


		template <typename ForwardIterator>
		ForwardIterator move_rotate_left_by_one(ForwardIterator first, ForwardIterator last)
		{
			typedef typename eastl::iterator_traits<ForwardIterator>::value_type value_type;

			value_type temp(eastl::move(*first));
			ForwardIterator result = eastl::move(eastl::next(first), last, first); // Note that while our template type is BidirectionalIterator, if the actual
			*result = eastl::move(temp);                                           // iterator is a RandomAccessIterator then this move will be a memmove for trivial types.

			return result; // result points to the final element in the range.
		}


		template <typename BidirectionalIterator>
		BidirectionalIterator move_rotate_right_by_one(BidirectionalIterator first, BidirectionalIterator last)
		{
			typedef typename eastl::iterator_traits<BidirectionalIterator>::value_type value_type;

			BidirectionalIterator beforeLast = eastl::prev(last);
			value_type temp(eastl::move(*beforeLast));
			BidirectionalIterator result = eastl::move_backward(first, beforeLast, last); // Note that while our template type is BidirectionalIterator, if the actual
			*first = eastl::move(temp);                                                   // iterator is a RandomAccessIterator then this move will be a memmove for trivial types.

			return result; // result points to the first element in the range.
		}

		template <typename /*IteratorCategory*/, bool /*is_trivially_move_assignable*/>
		struct rotate_helper
		{
			template <typename ForwardIterator>
			static ForwardIterator rotate_impl(ForwardIterator first, ForwardIterator middle, ForwardIterator last)
				{ return Internal::rotate_general_impl(first, middle, last); }
		};

		template <> 
		struct rotate_helper<EASTL_ITC_NS::forward_iterator_tag, true>
		{
			template <typename ForwardIterator>
			static ForwardIterator rotate_impl(ForwardIterator first, ForwardIterator middle, ForwardIterator last)
			{
				if(eastl::next(first) == middle) // If moving trivial types by a single element, memcpy is fast for that case.
					return Internal::move_rotate_left_by_one(first, last);
				return Internal::rotate_general_impl(first, middle, last);
			}
		};

		template <> 
		struct rotate_helper<EASTL_ITC_NS::bidirectional_iterator_tag, false>
		{
			template <typename BidirectionalIterator>
			static BidirectionalIterator rotate_impl(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last)
				{ return Internal::rotate_general_impl(first, middle, last); } // rotate_general_impl outperforms the flipping hands algorithm.

			/* 
			// Simplest "flipping hands" implementation. Disabled because it's slower on average than rotate_general_impl.
			template <typename BidirectionalIterator>
			static BidirectionalIterator rotate_impl(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last)
			{ 
				eastl::reverse(first, middle);
				eastl::reverse(middle, last);
				eastl::reverse(first, last);
				return first + (last - middle); // This can be slow for large ranges because operator + and - are O(n).
			}

			// Smarter "flipping hands" implementation, but still disabled because benchmarks are showing it to be slower than rotate_general_impl.
			template <typename BidirectionalIterator>
			static BidirectionalIterator rotate_impl(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last)
			{
				// This is the "flipping hands" algorithm.
				eastl::reverse_impl(first,  middle, EASTL_ITC_NS::bidirectional_iterator_tag()); // Reverse the left side.
				eastl::reverse_impl(middle, last,   EASTL_ITC_NS::bidirectional_iterator_tag()); // Reverse the right side.

				// Reverse the entire range.
				while((first != middle) && (middle != last)) 
				{
					eastl::iter_swap(first, --last);
					++first;
				}

				if(first == middle) // Finish reversing the entire range.
				{
					eastl::reverse_impl(middle, last, bidirectional_iterator_tag());
					return last;
				}
				else
				{
					eastl::reverse_impl(first, middle, bidirectional_iterator_tag());
					return first;
				}
			}
			*/
		};

		template <> 
		struct rotate_helper<EASTL_ITC_NS::bidirectional_iterator_tag, true>
		{
			template <typename BidirectionalIterator>
			static BidirectionalIterator rotate_impl(BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last)
			{
				if(eastl::next(first) == middle) // If moving trivial types by a single element, memcpy is fast for that case. 
					return Internal::move_rotate_left_by_one(first, last);
				if(eastl::next(middle) == last)
					return Internal::move_rotate_right_by_one(first, last);
				return Internal::rotate_general_impl(first, middle, last);
			}
		};

		template <typename Integer>
		inline Integer greatest_common_divisor(Integer x, Integer y)
		{
			do {
				Integer t = (x % y);
				x = y;
				y = t;
			} while(y);

			return x;
		}

		template <> 
		struct rotate_helper<EASTL_ITC_NS::random_access_iterator_tag, false>
		{
			// This is the juggling algorithm, using move operations.
			// In practice this implementation is about 25% faster than rotate_general_impl. We may want to 
			// consider sticking with just rotate_general_impl and avoid the code generation of this function.
			template <typename RandomAccessIterator>
			static RandomAccessIterator rotate_impl(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
			{
				typedef typename iterator_traits<RandomAccessIterator>::difference_type difference_type;
				typedef typename iterator_traits<RandomAccessIterator>::value_type value_type;

				const difference_type m1 = (middle - first);
				const difference_type m2 = (last - middle);
				const difference_type g  = Internal::greatest_common_divisor(m1, m2);
				value_type temp;

				for(RandomAccessIterator p = first + g; p != first;)
				{
					temp = eastl::move(*--p);
					RandomAccessIterator p1 = p;
					RandomAccessIterator p2 = p + m1;
					do
					{
						*p1 = eastl::move(*p2);
						p1 = p2;
						const difference_type d = (last - p2);

						if(m1 < d)
							p2 += m1;
						else
							p2 = first + (m1 - d);
					} while(p2 != p);

					*p1 = eastl::move(temp);
				}

				return first + m2;
			}
		};

		template <> 
		struct rotate_helper<EASTL_ITC_NS::random_access_iterator_tag, true>
		{
			// Experiments were done which tested the performance of using an intermediate buffer
			// to do memcpy's to as opposed to executing a swapping algorithm. It turns out this is 
			// actually slower than even rotate_general_impl, partly because the average case involves
			// memcpy'ing a quarter of the element range twice. Experiments were done with various kinds 
			// of PODs with various element counts.

			template <typename RandomAccessIterator>
			static RandomAccessIterator rotate_impl(RandomAccessIterator first, RandomAccessIterator middle, RandomAccessIterator last)
			{
				if(eastl::next(first) == middle) // If moving trivial types by a single element, memcpy is fast for that case. 
					return Internal::move_rotate_left_by_one(first, last);
				if(eastl::next(middle) == last)
					return Internal::move_rotate_right_by_one(first, last);
				if((last - first) < 32) // For small ranges rotate_general_impl is faster.
					return Internal::rotate_general_impl(first, middle, last);
				return Internal::rotate_helper<EASTL_ITC_NS::random_access_iterator_tag, false>::rotate_impl(first, middle, last);
			}
		};

	} // namespace Internal


	template <typename ForwardIterator>
	ForwardIterator rotate(ForwardIterator first, ForwardIterator middle, ForwardIterator last)
	{
		if(middle != first)
		{
			if(middle != last)
			{
				typedef typename eastl::iterator_traits<ForwardIterator>::iterator_category IC;
				typedef typename eastl::iterator_traits<ForwardIterator>::value_type        value_type;

				return Internal::rotate_helper<IC, eastl::is_trivially_move_assignable<value_type>::value || // This is the best way of telling if we can move types via memmove, but without a conforming C++11 compiler it usually returns false.
												   eastl::is_pod<value_type>::value                       || // This is a more conservative way of telling if we can move types via memmove, and most compilers support it, but it doesn't have as full of coverage as is_trivially_move_assignable.
												   eastl::is_scalar<value_type>::value>                      // This is the most conservative means and works with all compilers, but works only for scalars.
											   ::rotate_impl(first, middle, last);
			}

			return first;
		}

		return last;
	}
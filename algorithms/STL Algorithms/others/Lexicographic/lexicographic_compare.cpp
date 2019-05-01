    /// lexicographical_compare
    ///
    /// Returns: true if the sequence of elements defined by the range 
    /// [first1, last1) is lexicographically less than the sequence of 
    /// elements defined by the range [first2, last2). Returns false otherwise.
    ///
    /// Complexity: At most 'min((last1 - first1), (last2 - first2))' applications 
    /// of the corresponding comparison.
    ///
    /// Note: If two sequences have the same number of elements and their 
    /// corresponding elements are equivalent, then neither sequence is 
    /// lexicographically less than the other. If one sequence is a prefix 
    /// of the other, then the shorter sequence is lexicographically less 
    /// than the longer sequence. Otherwise, the lexicographical comparison 
    /// of the sequences yields the same result as the comparison of the first 
    /// corresponding pair of elements that are not equivalent.
    ///
    template <typename InputIterator1, typename InputIterator2>
    inline bool
    lexicographical_compare(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        for(; (first1 != last1) && (first2 != last2); ++first1, ++first2)
        {
            if(*first1 < *first2)
                return true;
            if(*first2 < *first1)
                return false;
        }
        return (first1 == last1) && (first2 != last2);
    }

    inline bool     // Specialization for const char*.
    lexicographical_compare(const char* first1, const char* last1, const char* first2, const char* last2)
    {
        const ptrdiff_t n1(last1 - first1), n2(last2 - first2);
        const int result = memcmp(first1, first2, (size_t)eastl::min_alt(n1, n2));
        return result ? (result < 0) : (n1 < n2);
    }

    inline bool     // Specialization for char*.
    lexicographical_compare(char* first1, char* last1, char* first2, char* last2)
    {
        const ptrdiff_t n1(last1 - first1), n2(last2 - first2);
        const int result = memcmp(first1, first2, (size_t)eastl::min_alt(n1, n2));
        return result ? (result < 0) : (n1 < n2);
    }

    inline bool     // Specialization for const unsigned char*.
    lexicographical_compare(const unsigned char* first1, const unsigned char* last1, const unsigned char* first2, const unsigned char* last2)
    {
        const ptrdiff_t n1(last1 - first1), n2(last2 - first2);
        const int result = memcmp(first1, first2, (size_t)eastl::min_alt(n1, n2));
        return result ? (result < 0) : (n1 < n2);
    }

    inline bool     // Specialization for unsigned char*.
    lexicographical_compare(unsigned char* first1, unsigned char* last1, unsigned char* first2, unsigned char* last2)
    {
        const ptrdiff_t n1(last1 - first1), n2(last2 - first2);
        const int result = memcmp(first1, first2, (size_t)eastl::min_alt(n1, n2));
        return result ? (result < 0) : (n1 < n2);
    }

    inline bool     // Specialization for const signed char*.
    lexicographical_compare(const signed char* first1, const signed char* last1, const signed char* first2, const signed char* last2)
    {
        const ptrdiff_t n1(last1 - first1), n2(last2 - first2);
        const int result = memcmp(first1, first2, (size_t)eastl::min_alt(n1, n2));
        return result ? (result < 0) : (n1 < n2);
    }

    inline bool     // Specialization for signed char*.
    lexicographical_compare(signed char* first1, signed char* last1, signed char* first2, signed char* last2)
    {
        const ptrdiff_t n1(last1 - first1), n2(last2 - first2);
        const int result = memcmp(first1, first2, (size_t)eastl::min_alt(n1, n2));
        return result ? (result < 0) : (n1 < n2);
    }
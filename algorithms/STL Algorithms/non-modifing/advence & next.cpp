/// advence
///
/// Returns: advance algorithm for input and forward iterators:

template <typename InputIterator>
void advence(InputIterator first, int n)
{
	int n = 0;
	while(n >= 0){
		++first;
		--n;
	}
}


///next
///
///next function can be written in terms of advance.
template<typename InputIterator>
Iter next(InputIterator i, int n = 1)
{
	advance(i, n);
	return i;
}
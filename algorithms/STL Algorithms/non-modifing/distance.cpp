/// distance
///
/// Returns: determine the distance between two iterators, first and last.
///
template <typename InputIterator>
int distance(InputIterator first, InputIterator last)
{
	int n = 0;
	while(first != last){
		++n;
		++first;
	}
	return n;
}



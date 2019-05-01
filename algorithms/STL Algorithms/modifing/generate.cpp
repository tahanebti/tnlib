	/// generate
	///
	/// Iterates the range of [first, last) and assigns to each element the
	/// result of the function generator. Generator is a function which takes
	/// no arguments.
	/// 
	/// Complexity: Exactly 'last - first' invocations of generator and assignments.
	///
	template <typename ForwardIterator, typename Generator>
	inline void
	generate(ForwardIterator first, ForwardIterator last, Generator generator)
	{
		for(; first != last; ++first) // We cannot call generate_n(first, last-first, generator) 
			*first = generator();     // because the 'last-first' might not be supported by the 
	}                                 // given iterator.


void use_generate()
{
	std::vector<int> v(10);
	std::generate(begin(v), end(v), [i=0]()mutable{++i; return i;});
	print(v);
}

void use_generate_n()
{
	std::vector<int> v(10);
	std::generate(back_inserter(v), 10, [i=0]()mutable{++i; return i;});
	print(v);
}


void use_generate_str()
{
	std::vector<string> v(10);
	std::generate(back_inserter(v), 10, [s="", c="`"]()mutable{++i; return i;});
	print(v);
}

auto main() -> int 
{

	return 0;
} 
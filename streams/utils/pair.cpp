#include <iostream>
using namespace std;

template <typename T,typename U, typename V,typename W>
auto operator+(const std::pair<T,U> & l,const std::pair<V,W> & r)
-> std::pair<decltype(l.first+r.first),decltype(l.second+r.second)>
{
    return {l.first+r.first,l.second+r.second};
}

int main() {
	std::pair<int, int> a=std::make_pair(1,2);
    std::pair<int, int> b=std::make_pair(3,3);
    std::pair<int, int> c = a+b;


    std::cout<<c.first<<"  "<<c.second;


	return 0;
}

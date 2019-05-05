#include <numeric>
#include <iostream>
#include <map>
#include <string>
#include <utility>

int main()
{
    const std::map<std::string, std::size_t> bla = {{"a", 1}, {"b", 3}};
    const std::size_t result = std::accumulate(std::begin(bla), std::end(bla), 0,
                                          [](const std::size_t previous, const std::pair<const std::string, std::size_t>& p)
                                          { return previous + p.second; });
    std::cout << result << "\n";

/*

If you use C++14, you can improve the readability of the lambda by using a generic lambda instead:

[](const std::size_t previous, const auto& element)
{ return previous + element.second; }

*/

std::map<int, int> m1 = { { 1, 1 }, { 2, 2 }, { 3, 3 }, { 4, 4 } }; 
std::map<int, int> m2 = { { 2, 5 }, { 3, 1 }, { 5, 5 } };

    for ( const auto &p : m1 ) 
    {
        std::cout << "{ " << p.first << ", " << p.second << " } ";
    }

    std::cout << std::endl;

    for ( const auto &p : m2 ) 
    {
        std::cout << "{ " << p.first << ", " << p.second << " } ";
    }

    std::cout << std::endl;

    std::map<int, int> m3 = std::accumulate( m1.begin(), m1.end(), std::map<int, int>(),
        []( std::map<int, int> &m, const std::pair<const int, int> &p )
        {
            return ( m[p.first] +=p.second, m );
        } );

    m3 = std::accumulate( m2.begin(), m2.end(), m3,
        []( std::map<int, int> &m, const std::pair<const int, int> &p )
        {
            return ( m[p.first] +=p.second, m );
        } );

    for ( const auto &p : m3 ) 
    {
        std::cout << "{ " << p.first << ", " << p.second << " } ";
    }

    std::cout << std::endl;




std::map<int, int> m3 = m1;
    m3 = std::accumulate( m2.begin(), m2.end(), m3,
        []( std::map<int, int> &m, const std::pair<const int, int> &p )
        {
            return ( m[p.first] +=p.second, m );
        } );

    return 0;

}
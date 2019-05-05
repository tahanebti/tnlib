// FunctionObjectsApp.cpp : Defines the entry point for the console application.
//

#include <bits/stdc++.h>

void nl() { std::cout << std::endl; }

template<typename T>
using vctr_t = std::vector<T>;

template<typename T>
std::ostream& operator<<(std::ostream& os, const vctr_t<T>& cntr)
{
  if (cntr.empty())
    return os;
  else
  {
    // second to the end element
    auto before_end = --cntr.cend();

    os << "(";

    for (auto itr = cntr.cbegin(); itr != before_end; ++itr)
      os << *itr << ", ";

    os << *before_end << ")" << std::endl;

    return os;
  }
}

template<typename T>
struct Greater
{
  bool operator() (const T& left, const T& right)
  {
    return left > right;
  }
};

template<typename T>
struct Less
{
  bool operator() (const T& left, const T& right)
  {
    return left < right;
  }
};

int main()
{
  // std::vector<int>
  vctr_t<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

  std::cout << v;

  // std::sort(v.begin(), v.end(), std::greater<int>());


  std::sort(v.begin(), v.end(), Greater<int>());
  std::cout << v;


  std::sort(v.begin(), v.end(), Less<int>());
  std::sort(v.begin(), v.end(), std::less<int>());

  std::cout << v;

  std::sort(v.begin(), v.end(),
    [](const int& left, const int& right) { return left > right; });

  std::cout << v;

  std::sort(v.begin(), v.end(),
    [](const int& left, const int& right) { return left < right; });

  std::cout << v;


    return 0;
}

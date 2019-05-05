#pragma once
#include <iostream>
#include <utility>
#include <string>

class console
{
public:
    template <typename T>
    static T get_input(const char *name)
    {
        T val;

        std::cout << "Insert " << name << ": ";
        std::cin >> val;

        return val;
    };

    template <>
    static std::string get_input(const char *name)
    {
        std::string ret;

        std::cout << "Insert " << name << ": ";
        std::getline(std::cin, ret);
        
        return ret;
    };

	static void print_title(int chapter, int quiz, const char *title)
	{
		std::cout << "------------------------------------------" << std::endl;
		std::cout << "    CH " << chapter << " - " << quiz << ". " << title << std::endl;
		std::cout << "------------------------------------------" << std::endl;
	};
    
    template <typename Container>
    static void print_solution(Container &&vec)
    {
        for (auto &&elem : vec)
            print_elem(elem);
    };

private:
    template <typename T>
    static void print_elem(const T &elem)
    {
        std::cout << elem << std::endl;
    };

    template <typename X, typename Y>
    static void print_elem(const std::pair<X, Y> &p)
    {
        std::cout << p.first << ", " << p.second << std::endl;
    };
};
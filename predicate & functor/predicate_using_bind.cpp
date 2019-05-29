//
//  predicate using std::bind
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <functional>

bool checkSize(const std::string& word, std::size_t stringLength)
{
	return (word.size() >= stringLength);
}

std::ostream& printer(std::ostream& os, char delimiter, const std::string& word)
{
	return os << word << delimiter;
}

int main()
{
	std::vector<std::string> words = {"Skarlet", "beaneath", "the", "sky"};
	std::size_t stringLength = 4;
	auto checkSz = std::bind(checkSize, std::placeholders::_1, stringLength);

	auto iter = std::find_if(words.begin(), words.end(), checkSz);
	std::cout <<"Word with 4 characters is : " << *iter << std::endl;

    std::ostream &os  = std::cout;
    std::for_each(words.begin(),  words.end(), std::bind(printer, ref(os), ' ',  std::placeholders::_1));

	std::cout << std::endl;

	return 0;

}

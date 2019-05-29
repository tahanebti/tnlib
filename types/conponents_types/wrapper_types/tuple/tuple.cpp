//
//  std::tuple test
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#include <iostream>
#include <tuple>
#include <string>
#include <typeinfo>

void lineSpace();

int main()
{
    const int index_0 = 0;
    const int index_1 = 1;
    const int index_2 = 2;
    const int index_3 = 3;
    const int index_4 = 4;
    /*There are two ways of creating the tuples*/
    /*1. Using direct-initialization*/
    /*2. Using std::make_tuple function*/

    std::tuple<int, char, double, std::string> tupleOne(40, 'F', 2.4, "Tuple");
    std::tuple<int, char, float> tupleTwo = std::make_tuple(400, 'G', 4.8);

    /*Using std::get() to access the tuples elements -- returs reference to elements*/
    std::cout << "tupleOne[0]: " << std::get<index_0>(tupleOne) << std::endl;
    std::cout << "tupleOne[1]: " << std::get<index_1>(tupleOne) << std::endl;
    std::cout << "tupleOne[2]: " << std::get<index_2>(tupleOne) << std::endl;
    std::cout << "tupleOne[3]: " << std::get<index_3>(tupleOne) << std::endl;

    std::cout << "tupleTwo contents before ...." << std::endl;
    std::cout << "tupleTwo[0]: " << std::get<index_0>(tupleTwo) << std::endl;
    std::cout << "tupleTwo[1]: " << std::get<index_1>(tupleTwo) << std::endl;
    std::cout << "tupleTwo[2]: " << std::get<index_2>(tupleTwo) << std::endl;

    /*Assigning the values to elements of tuple*/
    std::get<index_0>(tupleTwo) = 80;
    std::get<index_1>(tupleTwo) = 'H';
    std::get<index_2>(tupleTwo) = 8.16;

    std::cout << "tupleTwo contents after ...." << std::endl;
    std::cout << "tupleTwo[0]: " << std::get<index_0>(tupleTwo) << std::endl;
    std::cout << "tupleTwo[1]: " << std::get<index_1>(tupleTwo) << std::endl;
    std::cout << "tupleTwo[2]: " << std::get<index_2>(tupleTwo) << std::endl;

    lineSpace();
    /*How to find the size of the tuple using tuple_size*/
    //std::cout << "Type of tupleOne: " << typeid(decltype(tupleOne)).name() << std::endl;
    //std::cout << "Type of tupleTwo: " << typeid(decltype(tupleTwo)).name() << std::endl;

    std::cout << "Size of the tupleOne is: " << std::tuple_size<decltype(tupleOne)>::value << std::endl;
    std::cout << "Size of the tupleTwo is: " << std::tuple_size<decltype(tupleTwo)>::value << std::endl;

    lineSpace();

    /*tuple_element usage*/
    std::cout << "Tuple Type: " << std::endl;
    std::tuple_element<index_0, decltype(tupleOne)>::type firstElement = std::get<index_0>(tupleOne);
    std::tuple_element<index_1, decltype(tupleOne)>::type secondElement = std::get<index_1>(tupleOne);
    std::tuple_element<index_2, decltype(tupleOne)>::type thirdElement = std::get<index_2>(tupleOne);
    auto fourthElement = std::get<index_3>(tupleOne);

    std::cout <<"firstElement: " << firstElement << std::endl;
    std::cout <<"secondElement: " << secondElement << std::endl;
    std::cout <<"thirdElement: " << thirdElement << std::endl;
    std::cout <<"fourthElement: " << fourthElement << std::endl;


    /*tie() function - unpacks the tuple elements into separate elements*/
    int intVar = 0;
    float flaotVar = 0;
    char charVar = '0';

    std::tie(intVar, charVar, flaotVar) = tupleTwo;
    lineSpace();
    std::cout << "intVar: " << intVar << std::endl;
    std::cout << "flaotVar: " << flaotVar << std::endl;
    std::cout << "charVar: " << charVar << std::endl;

    intVar = 100;
    std::cout <<"intVar-after: " << std::get<index_0>(tupleTwo) << std::endl;

    lineSpace();
    /*tie() with std::ignore*/
    std::string name;
    std::tie(std::ignore, std::ignore, std::ignore, name) = tupleOne;
    std::cout << "name is : " << name << std::endl;

    lineSpace();
    /*Concatenation two tuples using tuple_cat*/
    auto tupleThree = std::tuple_cat(tupleOne, tupleTwo);
    std::cout << "contents of tupleThree are ...." << std::endl;
    std::cout << std::get<0>(tupleThree) << " " << std::get<1>(tupleThree) << std::endl;
    std::cout << std::get<2>(tupleThree) << " " << std::get<3>(tupleThree) << std::endl;
    std::cout << std::get<4>(tupleThree) << " " << std::get<5>(tupleThree) << std::endl;
    std::cout << std::get<6>(tupleThree) << std::endl;

    /*comparing two tuples*/
    std::tuple<int, char, float> tupleFour = std::make_tuple(80, 'H', 8.16);
    if(tupleTwo == tupleFour)
    {
        std::cout <<"Tuples are Equal ...." << std::endl;
    }

    std::get<0>(tupleFour) = 10;
    std::get<1>(tupleFour) = 'J';
    std::get<2>(tupleFour) = 9.5;
    if(tupleTwo < tupleFour)
    {
        std::cout <<"TupleTwo is less than TupleFour: " << std::endl;
    }
    /*Swapping two tuples*/
    return 0;
}

void lineSpace()
{
    std::cout << std::endl;
}

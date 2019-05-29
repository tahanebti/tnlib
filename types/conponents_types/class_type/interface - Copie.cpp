//
//  Interface class -- has only pure virtual function
//  Created by taha nebti.
//  Copyright (c) 2019. All rights reserved.
//
#include <iostream>



class Shape
{
    public:
        Shape() = default;
        virtual ~Shape() = default;

        /* Pure virtual function */
        virtual void draw() = 0;
};

class Line : public Shape
{
    public:
        Line() = default;
        virtual ~Line() = default;

        virtual void draw()
        {
            std::cout << "Drawing line ------ ....." << "\n";
        }
};

class Circle : public Shape
{
    public:
        Circle() = default;
        virtual ~Circle() = default;

        virtual void draw()
        {
            std::cout << "Drawing circle () ....." << "\n";
        }
};

class Square : public Shape
{
    public:
        Square() = default;
        virtual ~Square() = default;

        virtual void draw()
        {
            std::cout << "Drawing square []....." << "\n";
        }
};

int main(int argc, char const *argv[])
{
    Line line{};
    Circle circle{};
    Square square{};

    Shape *shapes[]  = {&line, &circle, &square};

    for(auto shape : shapes)
    {
        shape->draw();
    }

    return 0;
}

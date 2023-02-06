#ifndef RECTANGLE_H_INCLUDED
#define RECTANGLE_H_INCLUDED

#include "Shape.h"

class Rectangle:public Shape
{

private:
    int x1;
    int y1;

public:
    Rectangle();
    Rectangle(int valX, int valY, int valX1, int valY1);
    string draw();
};

Rectangle::Rectangle()
{
    x1 = 0;
    y1 = 0;
}

Rectangle::Rectangle(int valX, int valY, int valX1, int valY1):Shape(valX, valY)
{
    x1 = valX1;
    y1 = valY1;
}

string Rectangle::draw()
{
    return "soy un rectangulo " + to_string(x) + " " + to_string(y) + " " + to_string(x1) + " " + to_string(y1);
}

#endif // Rectangle_H_INCLUDED
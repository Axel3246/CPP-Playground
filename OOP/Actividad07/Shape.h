#ifndef SHAPE_H_INCLUDED
#define SHAPE_H_INCLUDED

#include <iostream>

using namespace std;

class Shape
{
protected:
    int x;
    int y;

public:
    Shape();
    Shape(int, int);
    virtual string draw();
    int getValueX() {return x;};
    int getValueY() {return y;};
};

Shape::Shape()
{
    x = 0;
    y = 0;
}

Shape::Shape(int valX, int valY)
{
    x = valX;
    y = valY;
}

string Shape::draw()
{
    return "soy una figura" ;
}

#endif // SHAPE_H_INCLUDED

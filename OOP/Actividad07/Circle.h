#ifndef CIRCLE_H_INCLUDED
#define CIRCLE_H_INCLUDED

#include "Shape.h"

class Circle:public Shape
{

private:
    int r;

public:
    Circle();
    Circle(int valX, int valY, int valR);
    string draw();
};

Circle::Circle()
{
    r = 0;
}

Circle::Circle(int valX, int valY, int valR):Shape(valX, valY)
{
    r = valR;
}

string Circle::draw()
{
    return "soy un círculo " + to_string(x) + " " + to_string(y) + " " + to_string(r);
}

#endif // CIRCLE_H_INCLUDED

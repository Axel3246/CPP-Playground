#ifndef TRIANGLE_H_INCLUDED
#define TRIANGLE_H_INCLUDED

#include "Shape.h"

class Triangle:public Shape{
    
    public:
        Triangle();
        Triangle(int valX, int valY, int A);
        string draw();
        
    private:
        int a;
};

Triangle::Triangle():Shape(){
    a = 0;
}

Triangle::Triangle(int valX, int valY, int A):Shape(valX, valY){
    a = A;
}

string Triangle::draw()
{
    return "soy un triangulo " + to_string(x) + " " + to_string(y) + " " + to_string(a);
}


#endif // TRIANGLE_H_INCLUDED
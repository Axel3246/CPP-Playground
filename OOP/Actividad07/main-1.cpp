#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"


using namespace std;

int main()
{

    Shape *Figuras[10];
    int contFiguras=0;
    Figuras[contFiguras++] = new Circle();
    Figuras[contFiguras++] = new Rectangle();
    Figuras[contFiguras++] = new Circle();
    Figuras[contFiguras++] = new Rectangle(2,2,7,8);
    Figuras[contFiguras++] = new Circle(4,3,1);
    Figuras[contFiguras++] = new Rectangle(1, 1, 4, 6);
    Figuras[contFiguras++] = new Triangle();
    Figuras[contFiguras++] = new Triangle(2, 3, 50);
    Figuras[contFiguras++] = new Triangle(5,23,10);
    
    // Agregar tres objetos tipo Triangle

    for (int i = 0; i<contFiguras; i++) 
    {
        cout << Figuras[i]->draw()<<endl;
    }
    return 0;

}

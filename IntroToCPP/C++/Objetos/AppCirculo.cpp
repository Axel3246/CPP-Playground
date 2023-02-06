//  Nombre: Axel Amós
//  Matricula: A00829837
//  Fecha: 09/11/20
//  Objetivo - aplicación de la clase Circulo
//  main.cpp
//  claseCirculoVocareum


#include <iostream>
#include <cmath>
using namespace std;


#include "Circulo.h"

int main()
{
    Circulo circ1;
    
    circ1.setRadio(10);
    
    cout << "Radio = " << circ1.getRadio()<<endl;
    
    cout << "Area = " << circ1.calcArea()<<endl;
    
    cout << "Perimetro = " << circ1.calcPerim()<<endl;
    
    return 0;
}

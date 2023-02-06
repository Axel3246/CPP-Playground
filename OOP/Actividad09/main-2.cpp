//
//  main.cpp
//  ejempComplejo
//
//  Created by Yolanda Martinez on 01/06/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//
//Axel Amós Hernández Cárdenas - A00829837
//Kevin Alberto Crisóstomo - A00832188

#include <iostream>
#include <cmath>
using namespace std;

#include "Complejo.h"

int main()
{

    Complejo c1(3, 2), c2(5, 6), c3, c4;

    cout << "valores originales " << endl;
    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;
    cout << "C4 = ";
    c4.muestra();
    cout << endl;
    cout << endl;

    cout << endl;
    cout << "La suma de c1 + c2 " << endl;

    c3 = c1 + c2;
    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;

    // prueba del ++
    cout << endl;
    cout << "prueba del ++" << endl;
    ++c2;
    c3 = ++c3;

    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;

    // prueba del --
    cout << endl;
    cout << "prueba del --" << endl;
    --c2;
    c3 = --c3;

    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C3 = ";
    c3.muestra();
    cout << endl;

    cout << endl;
    cout << "La comparación de c1 y c2 " << endl;
    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;

    if (c1 == c2)
        cout << "c1 y c2 son iguales" << endl;
    else
        cout << "c1 y c2 son diferentes" << endl;

    // Complejo c1(3, 2), c2(5, 6), c3, c4;
    //Multiplicacion

    cout << "Prueba de multiplicacion" << endl;
    c4 = c1 * c2;
    cout << "C1 = ";
    c1.muestra();
    cout << endl;
    cout << "C2 = ";
    c2.muestra();
    cout << endl;
    cout << "C4 = ";
    c4.muestra();
    cout << endl;

    cout << "Prueba de mayor" << endl;
    if (c1 > c2)
        cout << "c1 es mayor" << endl;
    else
        cout << "c2 es mayor" << endl;

    return 0;
}

//
//  main.cpp
//  clasePunto


#include <iostream>
#include <cmath>
using namespace std;

#include "Punto.h"

int main()
{
    // Declaración de variables
    double x1, y1, x2, y2;
  
    // Declaración de 2 instancias de la clase Punto
    Punto p1, p2;
    
    // Leer datos de los 2 puntos
    cin >> x1 >> y1 >> x2 >> y2;
    
    // Dar valores a los atributos
    p1.setX(x1); p1.setY(y1);
    p2.setX(x2); p2.setY(y2);
    
    // desplegar los 2 puntos uno con el método muestraPunto() y el otro con los métodos getX y getY
    p1.muestraPunto();
    cout << "<" << p2.getX() << "," << p2.getY() << ">" << endl;
    
    // Calcular y desplegar  la distancia entre los 2 puntos 
    cout << p1.calculaDistancia(p2) << endl;
    
    return 0;
}

/* 
Caso de Prueba 1:
Datos de entrada:
5 6 8 10    

Datos de salida:
<5,6>
<8,10>
5  

Caso de Prueba 2:
Datos de entrada:
0 10 10 10

Datos de salida:
<0,10>
<10,10>                                 
10    

Datos de entrada:
1 0 30 40   
Datos de salida:
<1,0>
<30,40>
49.4065  

*/
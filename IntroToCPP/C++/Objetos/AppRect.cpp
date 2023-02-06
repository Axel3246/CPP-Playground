#include <iostream>
using namespace std;
#include "Rectangulo.h"
 
int main(){
    //Declaracion de un objeto o instancia de la clase rectángulo
    Rectangulo r1, r2;
    double area;
    //Dar valores iniciales a los atributos de la instancia
    r1.setAncho(10);
    r1.setLargo(5);
    

    r2.setLargo(20);
    r2.setAncho(10);
    area = r2.calcularArea();

    cout << "r1 tiene un largo de " << r1.getLargo() << endl;
    cout << "r1 tiene un ancho de " << r1.getAncho() << endl;
    cout << "r2 tiene un largo de " << r2.getLargo() << endl;
    cout << "r2 tiene un ancho de " << r2.getAncho() << endl;
    
    area = r1.calcularArea();
    cout << "r1 tiene un área de " << area << endl; 
    
    area = r2.calcularArea();
    cout << "r2 tiene un área de " << area << endl; 

    return 0;
}
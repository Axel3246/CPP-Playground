#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#include "Fraccion.h"

int main() {

    // lee archivo
    ifstream arch("operaciones.txt"); //se abre el archivo de operaciones

    Fraccion vecFrac[10]; //define la lista de fracciones
    //variables a utilizar
    int ren, r;
    int oper, num1, den1, num2, den2;
    
    // lee el tamaño de la matriz
    arch >> ren;
    
    // lee los datos de la matriz y va realizando las operaciones y deja el resultado en el arreglo
    for (int r = 0; r < ren; r++) { //for que recorre los renglones totales del archivo .txt, dependiendo del numero de renglones que tenga 
    //el archivo
        arch >> oper >> num1 >> den1 >> num2 >> den2; // esta leyendo los 5 numeros de cada renglon
        Fraccion f1(num1,den1); //fraccion 1 con el numerador 1 y denominador 2
        Fraccion f2(num2,den2);//
        if (oper==1) { //si la operacion es 1...
            vecFrac[r]=f2.suma(f1);//sumamos a la fracción la fracción 1, pero tambien funciona al reves y lo guardamos en el vector de fracciones
        }
        else
        {
            vecFrac[r]=f2.multiplicacion(f1);//multiplicamos a la fraccion 2 la fraccion 1.
        }
    }
    for (int r = 0; r < ren; r++){ //for para desplegar las fracciones
        vecFrac[r].imprimir();
        cout << endl;
    }
    return 0;
}
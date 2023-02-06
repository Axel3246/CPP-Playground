//Axel Amós Hernández Cárdenas - A00829837
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#include "Complejo.h"

int main() {
     // lee archivo
    ifstream arch("numerosComplejos.txt"); //se abre el archivo de operaciones

    Complejo vecComplejos[20]; //define la lista de complejos
    Complejo complejoST;
    //variables a utilizar
    int nreal, nimag, r;
    int contC = 0;

    while (arch >> nreal >> nimag){
        vecComplejos[contC].setReal(nreal); // guardamos real en el arreglo
        vecComplejos[contC].setImag(nimag); // guardamos imag en el arreglo
        vecComplejos[contC].muestra(); //muestra el indice del vector
        complejoST = complejoST.suma(vecComplejos[contC]); //va sumando
        contC++; //aumentamos el contador
    }
    cout << "Suma: ";
    complejoST.muestra(); //mostramos la suma
    return 0; // termina el programa
    }

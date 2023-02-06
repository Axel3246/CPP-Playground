#include <iostream>

using namespace std;

#include "BST3.h"

int main(){

    system("cls");

    BST miArbol, miArbol2, miArbol3;
    
    cout << "Probando con Arbol Vacío" << endl;
    cout << "Prints" << endl;
    miArbol3.print(1);
    miArbol3.print(2);
    miArbol3.print(3);
    miArbol3.print(4);

    int nivel;

    cout << "Dato a buscar nivel -> "; cin >> nivel;

    cout << "La altura del Arbol 3 es: " << miArbol3.height() << endl;

    cout << "Los ancestros de A3 " << nivel << " son: ";
    miArbol3.ancestors(nivel);
    cout << endl;

    cout << "El nivel de A3 " << nivel << " es: " << miArbol3.whatLevelAmI(nivel) << endl;

    cout << endl;
    
    cout << "====================================================" << endl;
    cout << "Probando con Arbol de un elemento" << endl;
    
    miArbol2.add(22);

    cout << "Prints" << endl;

    miArbol2.print(4);

    int nivel2;

    cout << "Dato a buscar nivel -> "; cin >> nivel2;

    cout << "La altura del Arbol 2 es: " << miArbol2.height() << endl;

    cout << "Los ancestros de A2 " << nivel2 << " son: ";
    miArbol2.ancestors(nivel2);
    cout << "El nivel de A2 " << nivel2 << " es: " << miArbol2.whatLevelAmI(nivel2) << endl;


    /*
    miArbol.add(10);
    miArbol.add(8);
    miArbol.add(4);
    miArbol.add(14);
    miArbol.add(7);
    miArbol.add(30);
    miArbol.add(23);
    miArbol.add(17);
    miArbol.add(27);
    miArbol.add(9);
    miArbol.add(100);
    */
    cout << "====================================================" << endl;
    cout << "Probando con mas de un elemento" << endl;

    miArbol.add(40);
    miArbol.add(50);
    miArbol.add(6);
    miArbol.add(20);
    miArbol.add(10);;
    miArbol.add(2);
    miArbol.add(22);
    miArbol.print(1)          ;
    miArbol.print(4);

    int nivel3;
    cout << "Dato a buscar nivel -> "; cin >> nivel3;

    cout << "El nivel de " << nivel3 << " es: " << miArbol.whatLevelAmI(nivel3) << endl;

    cout << "La altura del Arbol es: " << miArbol.height() << endl;

    cout << "Los ancestros de " << nivel3 << " son: ";
    miArbol.ancestors(nivel3);
    cout << endl;

    
}
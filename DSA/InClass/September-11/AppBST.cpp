

#include <iostream>

using namespace std;

#include "BST2.h"

int main(){

    system("cls");

    cout << "Arbol Vacio" << endl;

    BST arbolV;

    cout << "El ancho del arbol vacio es: " << arbolV.maxWidth() << endl;
    //cout << "El ancestro mas cercan es: " << arbolV.nearestRelative(1,2) << endl;
    
    BST arbolV2(arbolV);

    cout << "El ancho del arbol vacio 2 es: " << arbolV2.maxWidth() << endl;

    if(arbolV2 == arbolV){
        cout << "Los arboles son iguales" << endl;
    }
    else{
        cout << "Los arboles son diferentes" << endl;
    }

    cout << "==================================" << endl;
    cout << "Arbol con un elemento" << endl;

    BST arbol1Elem;

    arbol1Elem.add(5);

    cout << "El ancho del arbol 1 elemento es: " << arbol1Elem.maxWidth() << endl;

    BST arbol1Elem2(arbol1Elem);
    BST arbolSinElem;
    arbol1Elem2.add(2);

    if(arbolSinElem == arbol1Elem){
        cout << "Los arboles son iguales" << endl;
    }
    else{
        cout << "Los arboles son diferentes" << endl;
    }

    cout << "==================================" << endl;
    cout << "Arbol con muchos elementos" << endl;
    BST miArbol;

    miArbol.add(7);
    miArbol.add(5);
    miArbol.add(12);
    miArbol.add(3);
    miArbol.add(6);
    miArbol.add(9);
    miArbol.add(15);
    miArbol.add(1);
    miArbol.add(4);
    miArbol.add(8);
    miArbol.add(10);
    miArbol.add(13);
    miArbol.add(17);

    cout << "El ancho del arbol com 1+ elementos es: " << miArbol.maxWidth() << endl;
    cout << "El ancestro mas cercano de 8 y 10 es: " << miArbol.nearestRelative(8,10) << endl;

    BST miArbol2(miArbol);

    cout << "El ancho del arbol2 com 1+ elementos es: " << miArbol2.maxWidth() << endl;
    cout << "El ancestro mas cercano 2 de 8 y 17 es: " << miArbol2.nearestRelative(8,17) << endl;
    miArbol2.print(1);
    miArbol.print(1);
    //miArbol2.add(56);
    miArbol2.print(1);
    if(miArbol2 == miArbol){
        cout << "Los arboles son iguales" << endl;
    }
    else{
        cout << "Los arboles son diferentes" << endl;
    }

}
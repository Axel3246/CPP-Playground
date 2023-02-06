#include <iostream>

using namespace std;
#include "LinkedList.h"

void algo()
{
    LinkedList<int> hola;
    hola.addFirst(4);
}

int main()
{
    LinkedList<string> miLista;

    miLista.addFirst("HOLA");
    miLista.addFirst("CRAYOLA");
    miLista.addFirst("YO");
    miLista.addFirst("SOY");
    miLista.addFirst("DE");
    miLista.addFirst("MTY");
    miLista.print();
    cout << "El size es: " << miLista.getSize() << endl;
    cout << "--------------------" << endl;
    cout << "Probando la reversed" << endl;
    miLista.reverse();
    miLista.print();
    cout << "El size es: " << miLista.getSize() << endl;
    cout << "--------------------" << endl;
    cout << "Probando Shift" << endl;
    miLista.shift(1);
    miLista.print();
    // Se invoca automáticamente al destructor
}
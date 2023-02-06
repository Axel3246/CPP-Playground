// * Binary Search

//* Se requiere que el arreglo este ordenado ascendentemente. Es mas eficiente y rapida que el Linear Search
// * Orden: O(log(n))

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system("cls");

    int numeros[] = {1, 2, 3, 4, 5};
    int inf, sup, mitad, dato;
    char elementFound = 'F';

    dato = 4;

    // ? Algoritmo de la busqueda binaria

    inf = 0;
    sup = size(numeros);

    while (inf <= sup)
    {
        mitad = (inf + sup) / 2;

        if (numeros[mitad] == dato)
        {
            elementFound = 'T';
            break;
        }
        if (numeros[mitad] > dato)
        {
            sup = mitad;
            mitad = (inf + sup) / 2;
        }
        if (numeros[mitad] < dato)
        {
            inf = mitad;
            mitad = (inf + sup) / 2;
        }
    }

    if (elementFound == 'F')
    {
        cout << "Numero no encontrado" << endl;
    }
    else if (elementFound == 'T')
    {
        cout << "Numero encontrado en el index " << mitad << endl;
    }

}
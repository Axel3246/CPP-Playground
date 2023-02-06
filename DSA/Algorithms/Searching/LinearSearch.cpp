
// * Linear Search

//* Buscar si un dato determinado existe o no en un array de n elementos. O(1) Mejor Caso, O(n), peor caso

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system("cls");
    int array1[] = {3, 4, 2, 5, 1};
    int i = 0, dato;
    char elementFound = 'F';

    // ? Linear Search

    // * Definimos un valor a buscar en el arreglo
    dato = 4;

    while ((elementFound == 'F') && (i < size(array1)))
    {
        if (array1[i] == dato)
        {
            elementFound = 'T';
        }
        i++;
    }

    // * Definimos si se encontro el dato solicitado

    if (elementFound == 'F')
    {
        cout << "Numero no encontrado" << endl;
    }
    else if (elementFound == 'T')
    {
        cout << "Numero encontrado en la posicion " << i - 1 << endl;
    }
}
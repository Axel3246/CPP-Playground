
// * Insertion Sort

//* Manera natural de ordenar y puede usarse facilmente para ordenamientos en listas arbitrarias. Requiere n^2 operaciones para
//* ordenar n elementos.

//* Big O: Generalmente es de O(n^2).

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system("cls");
    int numeros[] = {4, 3, 13, 2, 5, 1, 0, 19};
    int i, pos, aux;

    // * For que recorreel arreglo
    for (i = 0; i < size(numeros); i++)
    {
        pos = i;
        aux = numeros[i];

        // * Ordenara mientras no este en el indice 0, ademas del condicional escencial que denomina si el numero
        // * a su izquierda es mas grande
        while ((pos > 0) && (numeros[pos - 1] > aux))
        {
            numeros[pos] = numeros[pos - 1];
            // * Recorriendo los numeros a la izquierda
            pos--;

        }
        // * Obteniendo en que posicon va del array
        numeros[pos] = aux;
    }

    cout << "Orden Ascenente" << endl;

    for (i = 0; i < size(numeros); i++)
    {
        cout << numeros[i] << " ";
    }

    cout << endl;
    cout << "Orden Descendente" << endl;

    for (i = size(numeros) - 1; i >= 0; i--)
    {
        cout << numeros[i] << " ";
    }
    
}
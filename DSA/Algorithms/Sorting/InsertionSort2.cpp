
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
    int cantN;
    cout << "Cantidad de Elementos en Array: ";
    cin >> cantN;
    int numeros[cantN];
    int i, pos, aux, num;

    for (i = 0; i < cantN; i++)
    {
        cout << "Numero a ingresar: ";
        cin >> num;
        numeros[i] = num;
    }

    // * For que recorreel arreglo
    for (i = 0; i < cantN; i++)
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

    for (i = 0; i < cantN; i++)
    {
        cout << numeros[i] << " ";
    }

    cout << endl;
    cout << "Orden Descendente" << endl;

    for (i = cantN - 1; i >= 0; i--)
    {
        cout << numeros[i] << " ";
    }
    
}
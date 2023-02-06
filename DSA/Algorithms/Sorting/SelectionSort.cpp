
// * Selection Sort

// * Algoritmo de ordenamiento cuyos pasos son: 1. Buscar el minimo de la lista, 2. Intercambiarlo con el primer elemento,
// * 3. Buscar el minimo del resto de la lista, 4. Intercabiar con el segundo, 5. Repetir hasta tener la lista ordenada.

//* Big O: Generalmente es de O(n^2).

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    system("cls");

    int numeros[] = {32, 5, 4, 1, 2, 0, -12, -13};
    int i, j, aux, min;

    // ? Algoritmo del ordenamiento por seleccion

    for (i = 0; i < size(numeros); i++)
    {
        min = i; // * Suponemos que l minimo es el primer elemento de la lista, por ahora.
        for (j = i + 1; j < size(numeros); j++)
        {
            if (numeros[j] < numeros[min]) // ? este condicional hara que el minimo sea encontrado y sustituido
            {
                min = j;
            }
        }
        aux = numeros[i];          // * Valor actual de la posicion la guardamos en aux
        numeros[i] = numeros[min]; // * Igualamos la primera posicion a la posicion menor encontrado
        numeros[min] = aux;        // * Igualamos la posicion anterior al primer valor del arreglo
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
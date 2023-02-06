
// * Bubble Sort

//* Es un algoritmo sencillo de ordenamiento. Funciona revisando cada elemento de la lista que va ser ordenada siguiente, intercambiandolos
//* de posicion si estan en el orden equivocado. Es necesario revisar la lista varias veces hasta estar claro que no se necesitan mas intercambios

//* Big O: Generalmente es de O(n^2).

#include <iostream>
#include <vector>

using namespace std;

//! Metodo donde se dan los elementos al programa

int main()
{
    // * Array de elementos para el ordenamiento
    int numeros[] = {4, 1, 2, 3, 5, 0};
    int i, j, aux;

    // * Algoritmo para el ordenamiento burbuja a partir de elementos dados

    for (i = 0; i < size(numeros) - 1; i++)
    {
        for (j = 0; j < size(numeros) - 1; j++)
        {
            // * Condicional que evalua: Si el numero actual es mayor al numero siguiente
            if (numeros[j] > numeros[j + 1])
            {
                // * Utilizamos el aux para intercambiar los elementos en el array
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

// * Formas para imprimir los array

    cout << "Orden Ascenente" << endl;

    for (i = 0; i < size(numeros); i++)
    {
        cout << numeros[i];
    }

    cout << endl;
    cout << "Orden Descendente" << endl;

    for (j = size(numeros) - 1; j >= 0; j--)
    {
        cout << numeros[j];
    }
}
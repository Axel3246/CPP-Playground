
// * Bubble Sort

//* Es un algoritmo sencillo de ordenamiento. Funciona revisando cada elemento de la lista que va ser ordenada siguiente, intercambiandolos
//* de posicion si estan en el orden equivocado. Es necesario revisar la lista varias veces hasta estar claro que no se necesitan mas intercambios

//* Big O: Generalmente es de O(n^2), aunque puede disminuir en algunos casos especiales

#include <iostream>
#include <vector>

using namespace std;

//! Metodo donde se le pide al usuario el numero de elementos y los elementos

int main()
{

    int cantN;
    cout << "Cantidad de Elementos en Array: ";
    cin >> cantN;
    int numeros[cantN];
    int i, j, aux, num;

    for (i = 0; i < cantN; i++)
    {
        cout << "Numero a ingresar: ";
        cin >> num;
        numeros[i] = num;
    }

    // * Metodo burbuja
    
    for (i = 0; i < cantN; i++)
    {
        for (j = 0; j < cantN; j++)
        {
            // * Condicional que evalua: Si el numero actual es mayor al numero siguiente
            if (numeros[j] > numeros[j + 1])
            {
                aux = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = aux;
            }
        }
    }

    cout << "Orden Ascenente" << endl;

    for (i = 0; i < cantN; i++)
    {
        cout << numeros[i];
    }

    cout << endl;
    cout << "Orden Descendente" << endl;

    for (j = cantN - 1; j >= 0; j--)
    {
        cout << numeros[j];
    }
}

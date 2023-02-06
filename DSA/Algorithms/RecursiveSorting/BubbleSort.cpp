
// * Bubble Sort

//* Es un algoritmo sencillo de ordenamiento. Funciona revisando cada elemento de la lista que va ser ordenada siguiente, intercambiandolos
//* de posicion si estan en el orden equivocado. Es necesario revisar la lista varias veces hasta estar claro que no se necesitan mas intercambios

//* Big O: Generalmente es de O(n^2).

// C/C++ program for recursive implementation
// of Bubble sort
#include <iostream>
#include <vector>
using namespace std;

// * Funcion para intercambiar numeros
void swap(int &num1, int &num2)
{
    int aux = num1; // * Variable auxiliar para guardar el valor del numero mayor
    num1 = num2;    // * La variable se cambia por el numero menor
    num2 = aux;     // * La variable ahora vale el numero mayor
}

// * Algoritmo recursivo de Bubble Sort
void bubbleSort(vector<int> &array, int n)
{
    // * Si el size del arreglo es 1, simplemente lo devolvemos. (Mejor de los casos)
    if (n == 1)
    {
        return;
    }

    // * Corremos el algoritmo del bubble sort una vez para mmover el elemento mas largo hacia el final
    // * Practicamente es el mismo algoritmo, solo que movemos el size cada recursion

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (array[j + 1] < array[j])
            {
                swap(array[j], array[j + 1]);
            }
        }
    }

    // * Usamos la recursividad para mover el siguiente elemento mas largo al final (n-1)
    bubbleSort(array, n - 1);
}

// * Funcion para imprimir el arreglo
void imprimir(vector<int> array)
{
    for (int i = 0; i < array.size(); i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

// * Funcion para imprimir de forma
void imprimirDescendente(vector<int> array)
{
    for (int j = array.size() - 1; j >= 0; j--)
    {
        cout << array[j] << " ";
    }
    cout << endl;
}

int main()
{
    system("cls");
    vector<int> array1 = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array1) / sizeof(array1[0]);
    imprimir(array1);

    bubbleSort(array1, n);

    cout << "\t.:Arreglo Ordenado:." << endl;
    imprimir(array1);
    
    cout << "\t.:Arreglo Ordenado en Forma Descendente." << endl;
    imprimirDescendente(array1);
    return 0;
}
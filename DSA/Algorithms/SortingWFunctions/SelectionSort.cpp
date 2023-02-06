
// * Selection Sort

// * Algoritmo de ordenamiento cuyos pasos son: 1. Buscar el minimo de la lista, 2. Intercambiarlo con el primer elemento,
// * 3. Buscar el minimo del resto de la lista, 4. Intercabiar con el segundo, 5. Repetir hasta tener la lista ordenada.

//* Big O: Generalmente es de O(n^2).

#include <iostream>
#include <vector>
using namespace std;

// * Funcion para intercambiar los indices del vector en caso de que sea necesario para el ordenamiento
void swap(int &num1, int &num2)
{
    int aux = num1; // * Variable auxiliar para guardar el valor del numero mayor
    num1 = num2;    // * La variable se cambia por el numero menor
    num2 = aux;     // * La variable ahora vale el numero mayor
}

// * Algoritmo de Selection Sort
void selectionSort(vector<int> &array)
{
    int minIndex; // * Variable para guardar el indice con el numero mas chico

    for (int i = 0; i < array.size() - 1; i++)
    {
        minIndex = i; // * Se asume que el indice mas chico por ahora es el 0
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[j] < array[minIndex]) // * Con el for y el condicional, recorremos todo el vectoren busca de un numero mas peque (indice)
            {
                minIndex = j;
            }
        }
        swap(array[i], array[minIndex]); // * Llamamos a la funcion swap al encontrar el par de indices a cambiar
    }
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

// * Funcion para imprimir el arreglo en orden descendente (perferiblemente ordenado)
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
    vector<int> array1 = {32, 5, 4, 1, 2, 0, -12, -13};

    cout << "\t.:Arreglo Desrdenado:." << endl;
    imprimir(array1);

    selectionSort(array1);

    cout << "\t.:Arreglo Ordenado:." << endl;
    imprimir(array1);

    cout << "\t.:Arreglo Ordenado en Forma Descendente." << endl;
    imprimirDescendente(array1);
    return 0;
}
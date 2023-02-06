
// * Selection Sort

// * Algoritmo de ordenamiento cuyos pasos son: 1. Buscar el minimo de la lista, 2. Intercambiarlo con el primer elemento,
// * 3. Buscar el minimo del resto de la lista, 4. Intercabiar con el segundo, 5. Repetir hasta tener la lista ordenada.

//* Big O: Generalmente es de O(n^2).

#include <iostream>
#include <vector>
using namespace std;

int minIndex(vector<int> array, int i, int j)
{
    if (i == j)
    {
        return i;
    }

    int k = minIndex(array, i + 1, j);

    return (array[i] < array[k]) ? i : k;
}

// * Funcion para intercambiar los indices del vector en caso de que sea necesario para el ordenamiento
void swap(int &num1, int &num2)
{
    int aux = num1; // * Variable auxiliar para guardar el valor del numero mayor
    num1 = num2;    // * La variable se cambia por el numero menor
    num2 = aux;     // * La variable ahora vale el numero mayor
}

// * Algoritmo de Selection Sort
void selectionSort(vector<int> &array, int n, int index = 0)
{
    // * Declaramos de una vez que el indice menor es 0

    // * En el mejor de los casos, el array solo sera de size 1, entonces lo regresamos
    if (index == n)
    {
        return;
    }

    int k = minIndex(array, index, n - 1);

    if (k != index)
       swap(array[k], array[index]);
 
    // Recursively calling selection sort function
    selectionSort(array, n, index + 1);
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
    int n = sizeof(array1) / sizeof(array1[0]);

    cout << "\t.:Arreglo Desrdenado:." << endl;
    imprimir(array1);

    selectionSort(array1, n);

    cout << "\t.:Arreglo Ordenado:." << endl;
    imprimir(array1);

    cout << "\t.:Arreglo Ordenado en Forma Descendente." << endl;
    imprimirDescendente(array1);
    return 0;
}

// * Bubble Sort

//* Es un algoritmo sencillo de ordenamiento. Funciona revisando cada elemento de la lista que va ser ordenada siguiente, intercambiandolos
//* de posicion si estan en el orden equivocado. Es necesario revisar la lista varias veces hasta estar claro que no se necesitan mas intercambios

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

// * Algoritmo del ordenamiento burbuja en funcion
void bubbleSort(vector<int> &array)
{
    // * Recorre el arreglo para obtener el primer elemento
    for (int i = 0; i < array.size() - 1; i++)
    {
        // * Recorre el arreglo para obtener el segundo elemento
        for (int j = 0; j < array.size() - 1; j++)
        {
            // * Comparamos los valores, y en caso de que se tenga que hacer un cambio se hace
            if (array[j + 1] < array[j])
            {
                swap(array[j], array[j + 1]);
            }
        }
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


    vector<int> array1 = {13, 2, 5, 9, 1, 0, -12};

    cout << "\t.:Arreglo Desordenado:.\n" << endl;
    imprimir(array1);

    bubbleSort(array1);

    cout << "\t.:Arreglo Ordenado:." << endl;
    imprimir(array1);
    
    cout << "\t.:Arreglo Ordenado en Forma Descendente." << endl;
    imprimirDescendente(array1);
    return 0;
}
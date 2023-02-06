/*

Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 12 de Agosto del 2021
Descripción: Este programa utiliza tres funciones para sumar n números de 1 a n. Se utiliza la iteración, 
la recursividad y la formula matemática directa para ofrecer el resultado que se obtendría de la suma.

*/

#include <iostream>
using namespace std;

// * Funcion que devuelve la suma de 1 a n de forma iterativa, donde n es el numero deseado de iteraicones
// ? Complejidad: O(n)
long sumaIterativa(long n){

    long suma = 0;
    for (int i = 1; i <= n; i++){

        suma += i;
    }

    return suma;
}

// * Funcion que devuelve la suma de 1 a n de forma recursiva, donde n es el numero deseado de recursiones
// ? Complejidad: O(n)
long sumaRecursiva(long n){

    if (n == 1){ // * Si n es 1, devolvemos 1

        return 1;
    }

    return (n + sumaRecursiva(n - 1)); //* Vamos sumando del ultimo valor al primer valor (1)
}

// * Funcion que devuelve la suma de 1 a n de forma directa, donde n es el numero al que se quiere sumar
// ? Complejidad: O(1)
long sumaDirecta(long n){

    long suma = (n * (n + 1)) / 2; // * Formula de la sumatoria n
    return suma;
}

int main(){

    int k;
    long num;
    cin >> k;
    for (int i = 0; i < k; i++){

        cin >> num;
        cout << sumaIterativa(num) << " "
             << sumaRecursiva(num) << " "
             << sumaDirecta(num) << endl;
    }
}
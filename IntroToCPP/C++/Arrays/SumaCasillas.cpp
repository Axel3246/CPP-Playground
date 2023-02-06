    /* Entrada: N Valores, Valores del Arr[]
   Salida: Suma de casillas pares, suma de casillas impares
*/

#include <iostream>
#include <cmath>
using namespace std;


void suma_posiciones(int arr[], int size){ //Paso de Parametros por referencia en el arreglo
    //Leer la cantidad de valores a procesar 
    int N, acumPar = 0, acumImpar = 0;
    cin >> N;
    //Leer los valores a procesar
    for (int i = 0; i < N ; i++){
        cin >> arr[i];
    if (i % 2 == 0)
        acumPar = acumPar + arr[i];
    else
    
        acumImpar = acumImpar + arr[i];
    
    }
    cout << acumPar << " " << acumImpar << endl;

}

int main(){
    int arreglo[1000];
    suma_posiciones(arreglo, 100);
    
}
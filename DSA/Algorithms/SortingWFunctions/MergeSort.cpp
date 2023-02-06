
// * Merge Sort

//* Sirve para ordenad listas/vectores. Primero divide el arreglo a la mitad y luego mezcla (ordena) los valores resultantes

//* Big O: Generalmente es de O(n*log*n).

#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &arreglo,int inicio,int mitad,int final){
    
    int i,j,k;
    int elementosIzq = mitad - inicio + 1;
    int elementosDer = final - mitad;

    vector<int>izquierda(elementosIzq);
    vector<int>derecha(elementosDer);

    for(int i = 0; i < elementosIzq; i++){
        izquierda[i] = arreglo[inicio + i];
    }
    for(int j = 0; j < elementosDer; j++){
        derecha[j] = arreglo[mitad + 1 + j];
    }

    i = 0;
    j = 0;
    k = inicio;

    while(i < elementosIzq && j < elementosDer){
        if(izquierda[i] <= derecha[j]){
            arreglo[k] = izquierda[i];
            i++;
        }else{
            arreglo[k] = derecha[j];
            j++;
        }
        k++;
    }

    while(j < elementosDer){
        arreglo[k] = derecha[j];
        j++;
        k++;
    }

    while(i < elementosIzq){
        arreglo[k] = izquierda[i];
        i++;
        k++;
    }

}

void mergeSort(vector<int> &arr, int inicio, int final){

    if(inicio < final){
        int indxM = inicio + (final - inicio)/2;
        mergeSort(arr, inicio, indxM);
        mergeSort(arr, indxM + 1, final);
        merge(arr, inicio, indxM, final);
    }

}

void imprimir(vector<int> arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main(){

    vector<int> arreglo = {12,0,6,2,9,34,1};;
    imprimir(arreglo);
    mergeSort(arreglo, 0, arreglo.size()-1);
    imprimir(arreglo);
    return 0;
    
}
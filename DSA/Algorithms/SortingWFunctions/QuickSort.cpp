
// * Quick Sort

// * Algoritmo de ordenamiento que divide el arreglo y toma un pivote, a partir del cual se acomodan los valores mayores y menores,
// * generando sublistas las cuales, por medio de la recursividad, se acomodaran de la misma manera como se acomodo el primer pivote.

//* Big O: O(n log n) en el mejor de los casos y O(n²) en el peor

#include <iostream>
#include <vector>

using namespace std;

int partition(vector<int>&arr, int inicio, int final){
    int pivot = arr[inicio];
    int i = inicio + 1;

    for(int j = i; j <= final; j++){
        if(arr[j] < pivot){
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[inicio], arr[i-1]);
    return(i-1);
}


void quickSort(vector<int>&arr, int inicio, int final){

    if(inicio < final){
        int pivot = partition(arr, inicio, final);
        quickSort(arr, inicio, pivot - 1);
        quickSort(arr, pivot + 1, final);
    }
}

void imprimir(vector<int>arr){
    for(int i = 0; i < arr.size(); i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() 
{ 
    vector<int> arr= {10, 7, 8, 9, 1, 5};  
    imprimir(arr);
    quickSort(arr, 0, arr.size()-1); 
    imprimir(arr); 
    return 0; 
} 
#include <iostream>
#include <cmath>
using namespace std;

void suma_par_impar(int arr[], int size){
    int N, sumaPar = 0, sumaImpar = 0;
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> arr[i];
        if(arr[i]%2 == 0)
            sumaPar = sumaPar + arr[i];
        else
            sumaImpar = sumaImpar + arr[i];

}
    cout << sumaPar << " " << sumaImpar << endl; 
}

int main(){
    int arreglo[1000];
    suma_par_impar(arreglo, 1000);
    
}
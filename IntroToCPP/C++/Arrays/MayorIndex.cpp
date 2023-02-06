#include <iostream>
using namespace std;

//Funcion sin retorno
void buscaMayor(int arr[], int size){
    //Variables, se establece un mayor
    int cantidad, contador, mayor = -10000;
    cin >> cantidad;
    //for para iterar
    for (int i = 0; i < cantidad; i++){
        cin >> arr[i];
    if(arr[i] > mayor){ //Si arr[i] es mayor que mayor, se actulaiza y se guarda el index con i
        mayor = arr[i];
        contador = i;
    }

    }
    cout << mayor << " " << contador << endl;

}
//Main
int main(){
    int arreglo[1000];
    buscaMayor(arreglo, 100);
}

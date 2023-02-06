#include <iostream>
#include <cmath>
using namespace std;

int main(){

    double num, suma, promedio;
    int contador;
    contador = 0;

    cin >> num;

    while (num != 0){
        contador = contador + 1;
        suma = suma + num;
        cin >> num;
    }
    contador += 1;
    suma = suma + num;
    promedio = suma / contador;
    cout << promedio << endl;
    return 0;



}
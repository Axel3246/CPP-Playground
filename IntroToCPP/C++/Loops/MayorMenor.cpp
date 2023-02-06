#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //Declaración de Variables + Valor de Referencia para Max y Min
    int repeticion, contador, numero, mayor = -500000, menor = 50000000;
    cin >> repeticion;
    //Validación de Repetición
    if (repeticion <= 0){
            cout << "Error" << endl;
            return 0;
    }
    contador = 0;
    //Ciclo While
    while (contador < repeticion){
        cin >> numero;
        //Asignación de Menor y Mayor
        if (numero < menor){
            menor = numero;
        }
        if (numero > mayor){
            mayor = numero;
        }
        contador += 1;

    }
    //Salida
    cout << menor << " " << mayor << endl;
    return 0;
}
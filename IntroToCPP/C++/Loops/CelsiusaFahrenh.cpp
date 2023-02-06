#include <iostream>
#include <cmath>
using namespace std;

int main(){
    //Inicialización
    int numeroConversiones, incremento, contador;
    float fahrenheit, valorInicial;
    contador = 0;
    cin >> valorInicial;
    cin >> numeroConversiones;
    cin >> incremento;
    //Validación
    if (valorInicial < 0 || numeroConversiones < 0){
        cout << "Error" << endl;
        return 0;
    }
    else if (incremento < 2 || incremento > 10){
        cout << "Error" << endl;
        return 0;
    }
    else{ //Empieza el ciclo
    while (contador < numeroConversiones){
        //Conversiones
        fahrenheit = ((1.8) * valorInicial) + 32;
        cout << valorInicial << " " << fahrenheit << endl;
        valorInicial = valorInicial + incremento;
        contador = contador + 1;
        
    }
    }
    return 0;

}
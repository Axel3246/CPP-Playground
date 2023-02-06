#include <iostream>
#include <cmath>
using namespace std;

int main(){
    
    //Var
    int dia, mes;

    cin >> dia >> mes;

    //Condicionales
    if (
        (mes == 3 && (dia >= 21 && dia <= 31)) || 
        (mes == 4 && (dia >= 1 && dia <= 30)) ||
        (mes == 5 && (dia >= 1 && dia <= 31)) || 
        (mes == 6 && (dia >= 1 && dia <= 21))){
            cout << "PRIMAVERA" << endl;
    }
    else if(
        (mes == 6 && (dia > 21 && dia <= 31)) || 
        (mes == 7 && (dia >= 1 && dia <= 30)) ||
        (mes == 8 && (dia >= 1 && dia <= 31)) || 
        (mes == 9 && (dia >= 1 && dia <= 21))){
            cout << "VERANO" << endl;
    }
    else if(
        (mes == 9  && (dia > 21 && dia <= 30)) || 
        (mes == 10 && (dia >= 1 && dia <= 31)) ||
        (mes == 11 && (dia >= 1 && dia <= 30)) || 
        (mes == 12 && (dia >= 1 && dia <= 21))){
            cout << "OTOÑO" << endl;
    }
    else if(
        (mes == 12 && (dia > 21 && dia <= 31)) || 
        (mes == 1 && (dia >= 1 && dia <= 30)) ||
        (mes == 2 && (dia >= 1 && dia <= 28)) || 
        (mes == 3 && (dia >= 1 && dia <= 21))){
            cout << "INVIERNO" << endl;
    }

    return 0;
    
}
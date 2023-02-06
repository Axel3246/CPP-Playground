#include <iostream>
#include <cmath>
using namespace std;

int main(){

    double num, contador, suma, promedio;
    
    cin >> num;

    if (num == 0){
        cout << num << endl;
        return 0;
    }
    else if (num != 0){
    while (num != 0){
        cin >> num;
        if (num == 0){
            contador += 1;
            suma = suma + num;
            promedio = suma / contador;
            cout << promedio << endl;
            return 0;
        }
        contador += 1;
        suma = suma + num;
    }
    }
    return 0;
}
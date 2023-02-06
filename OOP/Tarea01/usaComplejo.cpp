//Axel Amós Hernández Cárdenas - A00829837
#include <iostream>
using namespace std;
#include "Complejo.h"

int main() {
    
    int real1, imag1, real2, imag2;
    //cout << "teclea los valores para el complejo 1 (real e imag)";
    cin >> real1 >> imag1;
    //cout << "teclea los valores para el complejo 2 (real e imag)";
    cin >> real2 >> imag2;
    // crea los objetos complejo1 y complejo2
    Complejo complejo1, complejo2;
    // asegúrate que los objetos complejo1 y complejo2 tienen los datos dados por el usuario
    complejo1.setReal(real1); complejo2.setReal(real2);
    complejo1.setImag(imag1); complejo2.setImag(imag2);
    // realiza la suma de los objetos complejo1 y complejo2 y deja el resultado en el objeto complejo3
    Complejo complejo3;
    complejo3 = complejo1.suma(complejo2);
    // llama al método muestra con el objeto complejo3
    complejo3.muestra();
    cout << endl;
    
    return 0;
}

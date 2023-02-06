#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Complejo{

public:
    // constructores
    Complejo();
    Complejo(int r, int i);
    // metodos de acceso
	int getReal();
    int getImag();
	// metodos de modificacion
    void setReal(int r);
	void setImag(int i);
    
	void muestra();

    // Agrega el encabezado del método suma de acuerdo con la descripción
    Complejo suma (Complejo c2);
   
    
private:
    
    int real, imag;
    
};

Complejo::Complejo() {
    real = 0;
    imag = 0;
}

Complejo::Complejo(int r, int i) {
    real = r;
    imag = i;
}

int Complejo:: getReal() {
    return real;
}

int Complejo:: getImag() {
    return imag;
}

void Complejo:: setReal(int r) {
    real = r;
}

void Complejo:: setImag(int i) {
    imag = i;
}

void Complejo:: muestra() {
    cout << real << " + " << imag << "i"<< endl;
}

Complejo Complejo::suma(Complejo c2){
    int imagTotal = imag + c2.getImag();
    int realTotal = real + c2.getReal();
    Complejo complejo3(realTotal, imagTotal);
    return complejo3;
}
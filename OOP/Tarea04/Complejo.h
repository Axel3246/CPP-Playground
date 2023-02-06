
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

#ifndef complejos_Header_h
#define complejos_Header_h

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

Complejo Complejo::suma (Complejo c2) {
    Complejo c3;
    c3.real = this->real + c2.real;
    c3.imag = this->imag + c2.imag;
    return c3;
}

    
#endif
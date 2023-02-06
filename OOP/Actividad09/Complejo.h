//
//  Complejo.h
//  ejempComplejo
//
//  Created by Yolanda Martinez on 01/06/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//
//Axel Amós Hernández Cárdenas - A00829837
//Kevin Alberto Crisóstomo - A00832188
#include <iostream>
#include <cmath>
#ifndef Complejo_h
#define Complejo_h
class Complejo
{

public:
    Complejo()
    {
        real = 0;
        imag = 0;
    };
    Complejo(double r, double i)
    {
        real = r;
        imag = i;
    };
    void setReal(double r) { real = r; };
    void setImag(double i) { imag = i; };
    double getReal() { return real; };
    double getImag() { return imag; };
    void muestra();
    Complejo operator+(Complejo c2);
    Complejo operator-(Complejo c2);
    Complejo operator++();
    Complejo operator--();
    bool operator==(Complejo otro);
    Complejo operator*(Complejo c2);
    bool operator>(Complejo c2);

private:
    double real, imag;
};

void Complejo::muestra()
{
    cout << real << " + " << imag << "i ";
}

Complejo Complejo::operator+(Complejo c2)
{
    int realN = this->real + c2.real;
    int imagN = this->imag + c2.imag;
    Complejo nuevo(realN, imagN);
    return nuevo;
}

Complejo Complejo::operator-(Complejo c2)
{
    int realN = real - c2.real;
    int imagN = imag - c2.imag;
    Complejo nuevo(realN, imagN);
    return nuevo;
}

Complejo Complejo::operator++()
{
    this->real++;
    this->imag++;
    return *this;
}

Complejo Complejo::operator--()
{

    Complejo uno(1, 1);

    // objeto complejo this = objeto complejo this - objeto complejo uno
    *this = *this - uno;
    return *this;
}

bool Complejo::operator==(Complejo otro)
{
    if (real == otro.real && imag == otro.imag)
        return true;
    else
        return false;
}

Complejo Complejo::operator*(Complejo c2)
{
    int realN = (this->real * c2.real - this->imag * c2.imag);
    int imagN = (this->real * c2.imag + this->imag * c2.real);
    Complejo multiplication(realN, imagN);
    return multiplication;
}

bool Complejo::operator>(Complejo c2)
{
    double normaC = sqrt(pow(this->real, 2) + pow(this->imag, 2));
    double normaC2 = sqrt(pow(c2.real, 2) + pow(c2.imag, 2));
    if (normaC > normaC2)
        return true;
    else
        return false;
}

#endif /* Complejo_h */

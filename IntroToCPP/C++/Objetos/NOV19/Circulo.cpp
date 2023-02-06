#include <iostream>
using namespace std;
#include "Circulo.h"

Circulo::Circulo(){
    Coordenada c(1,1);
    centro = c;
    iRadio = 1;
}

Circulo::Circulo(Coordenada cen, int valorRadio){
    centro = cen;
    iRadio = valorRadio;
}

void Circulo::setCentro(Coordenada c){
    centro = c;
}

void Circulo::setRadio(int valorRadio){
    iRadio = valorRadio;
}

Coordenada Circulo::getCentro(){
    return centro;
}

int Circulo::getRadio(){
    return iRadio;
}

string Circulo::str(){
    return "Centro:" + centro.str() + ", Radio:" + to_string(iRadio);
}
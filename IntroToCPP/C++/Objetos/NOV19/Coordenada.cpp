#include <iostream>
using namespace std;
#include "Coordenada.h"

Coordenada::Coordenada(){
    iX = 0;
    iY = 0;
}

Coordenada::Coordenada(int _iX, int _iY){
    iX = _iX;
    iY = _iY;
}

void Coordenada::setX(int _iX){
    iX = _iX;
}

void Coordenada::setY(int _iY){
    iY = _iY;
}

int Coordenada::getX(){
    return iX;
}

int Coordenada::getY(){
    return iY;
}

string Coordenada::str(){
    return "(" + to_string(iX) + "," + to_string(iY) + ")";
}

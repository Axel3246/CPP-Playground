#ifndef Fraccion_h
#define Fraccion_h

#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class Fraccion {
public:
    Fraccion(int num, int den);
    Fraccion();
    
    void setNumerador(int num);
    void setDenominador(int den);
   
    int getNumerador();
    int getDenominador();

    void simplifica();
    void imprimir();

    Fraccion suma(Fraccion f2); //la afraccion actual recibe otra fracción
    Fraccion multiplicacion(Fraccion f2); //igualmente a lo de arriba

private:
    int numerador, denominador;
};

Fraccion::Fraccion(int num, int den){ 
    if (num<0 && den<0){ //Si los dos son negativos, los haremos negativos
            numerador = -num; //asignar signo contrario
            denominador = -den;
    }
    else if (num>0 && den<0){ //si el numerador es positivo, pero el denominador negativo lo cambiamos
            numerador = -num;
            denominador = -den;
    }
    else{ //si no pasa nada de lo anterior, lo dejamos como estaba
            numerador = num;
            denominador = den;
    }
    simplifica();
}

Fraccion::Fraccion(){
    numerador = 0;
    denominador = 1;
}

void Fraccion::setNumerador(int num){
    numerador = num;
}

void Fraccion::setDenominador(int den){
    denominador = den;
}

int Fraccion::getNumerador(){
    return numerador;
}

int Fraccion::getDenominador(){
    return denominador;
}

void Fraccion::simplifica() {
    int divisor; //declaramos una variable para guardar
    if (numerador > denominador) //si el numerador es mayor que el numerador
        divisor = denominador; //el divisor es el denominador
    else
        divisor = numerador; //si no, el divisor será el denominador
    while (divisor > 1) { //mientras el divisor sea mayor a 1
        if (numerador % divisor == 0 && denominador % divisor == 0) {// si el numerador dividido entre el divisor o viceversa da como residuo 0, se hará el if
            numerador /= divisor; //se divide el numerador entre el divisor
            denominador /= divisor; //se divide el denominador entre el divisor
        }
        divisor--; //restamos al divisor para ver si lo podemos simplificar más
    }
}

void Fraccion::imprimir(){
     cout<<numerador<<"/"<<denominador;
}

Fraccion Fraccion::suma(Fraccion f2){
    int num=numerador*f2.getDenominador()+f2.getNumerador()*denominador; 
    int den=denominador*f2.getDenominador();
    Fraccion fr(num,den);
    return fr;
}

Fraccion Fraccion::multiplicacion(Fraccion f2){
    int num=numerador*f2.getNumerador();
    int den=denominador*f2.getDenominador();
    Fraccion fr(num,den);
    return fr;
}

#endif /* Fraccion_h */


//Axel Amós Hernández Cárdenas
#ifndef Sobre_H_HEADER
#define Sobre_H_HEADER
#include <iostream>
using namespace std;
#include "Envio.h"

class Sobre:public Envio{
    public:
        Sobre();
        Sobre(Persona _rem, Persona _dest, double _costExt, int _largo, int _ancho , double _cargoAdicional);
        //Metodos GET
        int getLargo(){return largo;}
        int getAncho(){return ancho;}
        int getCarhoAdicional(){return cargoAdicional;}
        //Metodos SET
        void setLargo(int _largo){largo = _largo;}
        void setAncho(int _ancho){ancho = _ancho;}
        void setCargoAdicional(double _cargoadicional){cargoAdicional = _cargoadicional;}
        //Metodo CalculaCosto
        double calculaCosto(double costo);
    private:
        int largo;
        int ancho;
        double cargoAdicional;
};

Sobre::Sobre():Envio(){
    largo = 0;
    ancho = 0;
    cargoAdicional = 0;
}

Sobre::Sobre(Persona _rem, Persona _dest, double _costExt, int _largo, int _ancho , double _cargoAdicional):Envio(_rem,_dest,_costExt){
    largo = _largo;
    ancho = _ancho;
    cargoAdicional = _cargoAdicional;
}

double Sobre::calculaCosto(double costo){
    if((ancho>25)||(largo>30)){
        costo = costo + cargoAdicional;
        return costo;
    }
    else{
        return costo;
    }
}

#endif /* Sobre_H_HEADER */
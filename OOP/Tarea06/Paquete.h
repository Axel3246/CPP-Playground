//Axel Amós Hernández Cárdenas
#ifndef Paquete_H_HEADER
#define Paquete_H_HEADER

#include <iostream>
using namespace std;
#include "Envio.h"

class Paquete:public Envio{
    public:
        Paquete();
        Paquete(Persona _rem, Persona _dest, double _costExt, int _largo, int _ancho, double _profundidad, double _peso, double _costoPorKg);
        //Metodos GET
        int getLargo(){return largo;}
        int getAncho(){return ancho;}
        double getProfundodad(){return profundidad;}
        double getPeso(){return peso;}
        double getCostoXKg(){return costoPorKg;}
        //Metodos SET
        void setLargo(int _largo){largo = _largo;}
        void setAncho(int _ancho){ancho = _ancho;}
        void setProfundidad(double _profundidad){profundidad = _profundidad;}
        void setPeso(double _peso){peso = _peso;}
        void setCostoXKg(double _costoPorKg){costoPorKg = _costoPorKg;}
        //Metodo CalculaCosto
        double calculaCosto(double costo);
    private:
        int largo;
        int ancho;
        double profundidad;
        double peso;
        double costoPorKg;
};

Paquete::Paquete(){
    largo = 0;
    ancho = 0;
    profundidad = 0;
    peso = 0;
    costoPorKg = 0;
}

Paquete::Paquete(Persona _rem, Persona _dest, double _costExt, int _largo, int _ancho, double _profundidad, double _peso, double _costoPorKg):Envio(_rem, _dest, _costExt){
    largo = _largo;
    ancho = _ancho;
    profundidad = _profundidad;
    peso = _peso;
    costoPorKg = _costoPorKg;
}

double Paquete::calculaCosto(double costo){
    costo = costo + (costoPorKg * peso);
    return costo;
}

#endif /* Paquete_H_HEADER */
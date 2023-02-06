//Axel Amos Hernández Cárdenas
#ifndef Envio_H_HEADER
#define Envio_H_HEADER
#include <iostream>
using namespace std;
#include "Persona.h"

class Envio{
    public:
        Envio();
        Envio(Persona _remitente, Persona _destinatario, double _cosEnv);
        //Metodos Get
        int getCostoEnvio() {return cosEnv;}
        //Metodos Set
        void setCostoEnvio(int _cosEnv){cosEnv = _cosEnv;}
        //Metodo calculaCosto
        virtual double calculaCosto(double costo);
    protected:
       double cosEnv;
    private:
        Persona remitente;
        Persona destinatario;
};

Envio::Envio(){
    //Persona remitente
    //Persona destinatario
    //this->remitente = remitente
    //this->destinatario = destinatario
    cosEnv = 0;
}

Envio::Envio(Persona _remitente, Persona _destinatario, double _cosEnv){
    //this->remitente = remitente
    //this->destinatario = destinatario
    cosEnv = _cosEnv;
}

double Envio::calculaCosto(double costo){
    return costo;
}

#endif /* Envio_H_HEADER */
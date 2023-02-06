#ifndef Sobre_h
#define Sobre_h

#include "Envio.h"

// INDICACIONES
// La clase Sobre.h NO se tiene que modificar

class Sobre: public Envio {
private:
    double largo;
    double ancho;
    double cargoAdicional;
public:
    Sobre();
    Sobre(Persona remitente, Persona destinatario, double costoEnvio, double largo, double ancho, double cargoAdicional);
    void setLargo(double largo) {this->largo=largo;}
    double getLargo() {return this->largo;}
    void setAncho(double ancho) {this->ancho=ancho;}
    double getAncho() {return this->ancho;}
    void setCargoAdicional(double cargoAdicional) {this->cargoAdicional=cargoAdicional;}
    double getCargoAdicional() {return this->cargoAdicional;}

    double calculaCosto();
};

Sobre::Sobre() : Envio() {
    largo = 0;
    ancho = 0;
    cargoAdicional = 0;
}

Sobre::Sobre(Persona remitente, Persona destinatario, double costoEnvio, double largo, double ancho, double cargoAdicional) : Envio(remitente, destinatario, costoEnvio) {
    this->largo = largo;
    this->ancho = ancho;
    this->cargoAdicional = cargoAdicional;
}

double Sobre::calculaCosto() {
    if (largo >= 25 && ancho >= 30) {
        return (this->costoEnvio + this->cargoAdicional);
    } else {
        return this->costoEnvio;
    }
}

#endif
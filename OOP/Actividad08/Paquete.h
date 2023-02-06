#ifndef Paquete_h
#define Paquete_h

#include "Envio.h"

// INDICACIONES
// La clase Paquete.h NO se tiene que modificar

class Paquete: public Envio {
private:
    double peso;
    double costoKg;
public:
    Paquete();
    Paquete(Persona remitente, Persona destinatario, double costoEnvio, double peso, double costoKg);
    void setPeso(double peso) {this->peso=peso;}
    double getPeso() {return this->peso;}
    void setCostoKg(double costoKg) {this->costoKg=costoKg;}
    double getCostoKg() {return this->costoKg;}

    double calculaCosto();
};

Paquete::Paquete() : Envio() {
    this->peso = 0;
    this->costoKg = 0;
}

Paquete::Paquete(Persona remitente, Persona destinatario, double costoEnvio, double peso, double costoKg) : Envio(remitente, destinatario, costoEnvio) {

    if (peso < 0) {
        peso = 0;
    }
    this->peso = peso;
    if (costoKg < 0) {
        costoKg = 0;
    }
    this->costoKg = costoKg;
}

double Paquete::calculaCosto() {
    return this->costoEnvio + this->costoKg * this->peso;
}

#endif
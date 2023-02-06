#ifndef Envio_h
#define Envio_h

#include "Persona.h"

// INDICACIONES
// Modifica la clase Envio.h para que sea una clase abstracta

class Envio {

private:
    Persona remitente;
    Persona destinatario;
protected:
    double costoEnvio;

public:
    Envio();
    Envio(Persona remitente, Persona destinatario, double CostoEnvio);
    void setRemitente(Persona remitente) { this->remitente=remitente;}
    Persona getRemitente() {return this->remitente;}
    void setDestinatario(Persona destinatario) { this->destinatario=destinatario;}
    Persona getDestinatario() {return this->destinatario;}
    void setCostoEnvio(double costoEnvio) {this->costoEnvio=costoEnvio;}
    double getCostoEnvio() {return this->costoEnvio;}

    virtual double calculaCosto()=0;
};

Envio::Envio() {
    Persona remitente;
    Persona destinatario;
    this->remitente = remitente;
    this->destinatario = destinatario;
    this->costoEnvio = 0;
}
Envio::Envio(Persona remitente, Persona destinatario, double costoEnvio) {
    this->remitente = remitente;
    this->destinatario = destinatario;
    this->costoEnvio = costoEnvio;
}

#endif
#include <iostream>
#include <string>
#ifndef Persona_h
#define Persona_h
using namespace std;

class Persona
{
private:
    string nombre;
    string estado;
    string ciudad;
    string codigoPostal;

public:
    Persona();
    Persona(string nombre, string estado, string ciudad, string cp);
    void imprimir();
    void setNombre(string nombre) { this->nombre = nombre; }
    string getNombre() { return this->nombre; }
    void setEstado(string estado) { this->estado = estado; }
    string getEstado() { return this->estado; }
    void setCiudad(string ciudad) { this->ciudad = ciudad; }
    string getCiudad() { return this->ciudad; }
    void setCodigoPostal(string codigoPostal) { this->codigoPostal = codigoPostal; }
    string getcodigoPostal() { return this->codigoPostal; }
};

Persona::Persona()
{
    nombre = "";
    estado = "";
    ciudad = "";
    codigoPostal = "";
}

Persona::Persona(string nombre, string estado, string ciudad, string codigoPostal)
{
    this->nombre = nombre;
    this->estado = estado;
    this->ciudad = ciudad;
    this->codigoPostal = codigoPostal;
}

void Persona::imprimir()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Dirección: " << estado << " " << ciudad << " " << codigoPostal << endl;
}

#endif

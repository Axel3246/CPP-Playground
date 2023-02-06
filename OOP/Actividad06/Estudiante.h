
#ifndef Estudiante_h
#define Estudiante_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

#include "Persona.h"

class Estudiante : public Persona {
public:
    Estudiante();
    Estudiante(string, int, string);
    string getCarrera() { return carrera; }
    void setCarrera(string ca) { carrera = ca; }
    void muestraDatos();
private:
    string carrera;
};

Estudiante::Estudiante() : Persona() {
    carrera = "N/A";
}

Estudiante::Estudiante(string nom, int ed, string ca) : Persona(nom, ed) {
    carrera = ca;
}


void Estudiante::muestraDatos() {
    cout<<"Nombre: "<<nombre<<" Edad: "<<edad<<" Carrera: "<<carrera << endl;
}

#endif /* Estudiante_h */

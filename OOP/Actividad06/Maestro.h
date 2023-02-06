

#ifndef Maestro_h
#define Maestro_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#include "Persona.h"

class Maestro : public Persona {
public:
    Maestro();
    Maestro(string, int, string);
    string getDepto() { return depto; };
    void setDepto(string de) {     depto = de; };
    void muestraDatos();
private:
    string depto;
};

Maestro::Maestro() : Persona() {
    depto = "N/A";
}

Maestro::Maestro(string nom, int ed, string ca) : Persona(nom, ed) {
    depto = ca;
}


void Maestro::muestraDatos() {
    cout<<"Nombre: "<<nombre<<" Edad: "<<edad<<" Depto: "<<depto << endl;
}




#endif /* Maestro_h */



#ifndef Persona_h
#define Persona_h
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
class Persona {
public:
    Persona();
    Persona(string, int);
    string getNombre()  { return nombre; };
    void setNombre(string nom) { nombre = nom; };
    int getEdad() { return edad; };
    void setEdad(int ed) { edad = ed; };
    virtual void muestraDatos();     // NOTA QUE EL MÉTODO MUESTRA DATOS ES VIRTUAL
protected:
    string nombre;
    int edad;
};

Persona::Persona() {
    nombre = "N/A";
    edad = 0;
}

Persona::Persona(string nom, int ed) {
    nombre = nom;
    edad = ed;
}


void Persona::muestraDatos() {
    cout<<"Nombre: "<<nombre<<" Edad: "<<edad << endl;
}

#endif /* Persona_h */

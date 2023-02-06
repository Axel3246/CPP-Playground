#include <iostream>
#include <string>
using namespace std;

class Persona{

    public:
        Persona();
        Persona(string _nombre, string _numCel);

        void setNombre(string _nombre);
        void setNumCel(string _numCel);

        string getNombre();
        string getNumCel();

    private:
        string nombre;
        string numCel;

};

Persona::Persona(){
    nombre = "N/A";
    numCel = "N/A";
}

Persona::Persona(string _nombre, string _numCel){
    nombre = _nombre;
    numCel = _numCel;
}

void Persona::setNombre(string _nombre){
    nombre = _nombre;
}

void Persona::setNumCel(string _numCel){
    numCel = _numCel;
}

string Persona::getNombre(){
    return nombre;
}

string Persona::getNumCel(){
    return numCel;
}
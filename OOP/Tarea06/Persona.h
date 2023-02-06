//Axel Amós Hernández Cárdenas
#ifndef Persona_H_HEADER
#define Persona_H_HEADER

#include <iostream>
#include <string>
using namespace std;

class Persona{
    public:
        Persona();
        Persona(string _nombre, string _direccion, string _ciudad, string _estado, string _codePostal);
        //Metodos GET
        string getNombre(){return nombre;}
        string getDireccion() {return direccion;}
        string getCiudad(){return ciudad;}
        string getEstado(){return estado;}
        string getCodePost(){return codePostal;}
        //Metodos SET
        void setNombre(string _nombre){nombre = _nombre;}
        void setDireccion(string _direccion){direccion = _direccion;}
        void setCiudad(string _ciudad){ciudad = _ciudad;}
        void setEstado(string _estado){estado = _estado;}
        void serCodePost(string _codePostal){codePostal = _codePostal;}
        //Metodo muestra
        void mostrar();
    private:
        string nombre, direccion, ciudad, estado, codePostal;

};

Persona::Persona(){
    nombre = "";
    direccion = "";
    ciudad = "";
    estado = "";
    codePostal = "";
}

Persona::Persona(string _nombre, string _direccion, string _ciudad, string _estado, string _codePost){
    nombre = _nombre;
    direccion = _direccion;
    ciudad = _ciudad;
    estado = _estado;
    codePostal = _codePost;
}

void Persona::mostrar(){
    cout << "Nombre: "<< nombre << endl;
    cout << "Direccion: " << direccion << endl;
    cout << "Ciudad: " << ciudad << endl;
    cout << "Estado: " << estado << endl;
    cout << "Código Postal: " << codePostal << endl;
}

#endif /* Persona_H_HEADER */



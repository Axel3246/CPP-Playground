#include <iostream>
#include <typeinfo.h>
#include <string>

#ifndef Name_header
#define Name_header

using namespace std;

class Name{
    public:
        Name();
        Name(string nombre, string edad);
        //Set
        void setNombre(string nombre){this->nombre = nombre;}
        void setEdad(string edad){this->edad = edad;}
        //GET
        string getNombre(){return nombre;}
        string getEdad(){return edad;}
        //Misc
        virtual void muestra() = 0;

    protected:
        string nombre;
        string edad;

};

Name::Name(){
    this->nombre = "";
    this->edad = "";
}

Name::Name(string nombre, string edad){
    this->nombre = nombre;
    this->edad = edad;
}

#endif
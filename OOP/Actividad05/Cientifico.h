//Axel Amós Hernández Cárdenas - A00829837
//Carlos Alberto Ortiz M - A01382584
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#include "Empleado.h"

class Cientifico:public Empleado{
    public:
    Cientifico();
    Cientifico(string nom, int nume, int pub);
    //Set
    void setPublicaciones(int pub){publicaciones = pub;}
    //Get
    int getPublicaciones(){return publicaciones;}
    void mostrar();
    
    private:
    int publicaciones;
};

Cientifico::Cientifico():Empleado(){
    publicaciones = 0;
}

Cientifico::Cientifico(string nom, int nume, int pub):Empleado(nom,nume){
    publicaciones = pub;
}

void Cientifico::mostrar(){
    Empleado::mostrar();
    cout << "Cantidad de publicaciones: " << publicaciones << endl;
}
//Axel Amós Hernández Cárdenas - A00829837
//Carlos Alberto Ortiz M - A01382584
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#include "Empleado.h"

class Gestor:public Empleado{
    public:
    Gestor();
    Gestor(string nom, int nume, string titu, double cuot);
    //Set
    void setCuotasClub(double cuot){CuotasClub = cuot;}
    void setTitulo(string titu){Titulo = titu;}
    //Get
    string getTitulo(){return Titulo;}
    double getCuotasClub(){return CuotasClub;}
    void mostrar();
    
    private:
    double CuotasClub;
    string Titulo;
};

Gestor::Gestor():Empleado(){
    CuotasClub = 0;
    Titulo = "";
}

Gestor::Gestor(string nom, int nume, string titu, double cuot):Empleado(nom,nume){
    CuotasClub = cuot;
    Titulo = titu;
}

void Gestor::mostrar(){
    Empleado::mostrar();
    cout << "Titulo: " << Titulo << "Cuota: " << CuotasClub << endl;
}
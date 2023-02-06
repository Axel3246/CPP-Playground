#include <iostream>
#include <string>
#include "Videos.h"
#ifndef Pelicula_H_HEADER
#define Pelicula_H_HEADER
using namespace std;

class Pelicula: public Videos{

    public:
        Pelicula();
        Pelicula(string _iD, string _nombre, string _genero, string _duracion, double _calificacion);
        //Metodo calculaCalificacionPromedio
        void muestraInformacion();
    private:
    
};

Pelicula::Pelicula():Videos(){

}

Pelicula::Pelicula(string _iD, string _nombre,  string _genero, string _duracion, double _calificacion):Videos(_iD, _nombre, _genero, _duracion, _calificacion){


}

void Pelicula::muestraInformacion(){
    cout << "ID de Pelicula: " << iD << endl;
    cout << "Pelicula: " << nombre <<endl;
    cout << "Genero: " << genero << endl;
    cout << "Duracion: " << duracion << endl;
    cout << "Calificacion: " << calificacion;
    cout << endl;
}

/*
double Pelicula::calculaCalificacionPromedio(){

}
*/
#endif /* Pelicula_H_HEADER */
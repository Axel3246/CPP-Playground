#include <iostream>
#include <string>
#ifndef Videos_H_HEADER
#define Videos_H_HEADER
using namespace std;

class Videos{
    public:
        Videos();
        Videos(string iD, string nombre, string genero, string duracion, int calificacion);
        //Metodos SET
        void setId(string iD){this->iD = iD;}
        void setNombre(string nombre){this->nombre = nombre;}
        void setDuracion(string duracion){this->duracion = duracion;}
        void setGenero(string genero){this->genero = genero;}
        void setCalificacion(int calificacion){this->calificacion = calificacion;}
        //Metodos GET
        string getId(){return this->iD;}
        string getNombre(){return this->nombre;}
        string getDuracion(){return this->duracion;}
        string getGenero(){return this->genero;}
        int getCalificacion(){return this->calificacion;}
        //Metodo calculaCalificacionPromedio
        //virtual double calculaCalificacionPromedio();
        virtual void muestraInformacion() = 0;
    protected:
        string iD, nombre, duracion, genero;
        int calificacion;
};

Videos::Videos(){
    this->iD = "";
    this->nombre = "";
    this->duracion = "";
    this->genero = "";
    this->calificacion = 0;
}

Videos::Videos(string iD, string nombre, string genero, string duracion, int calificacion){
    this->iD = iD;
    this->nombre = nombre;
    this->duracion = duracion;
    this->genero = genero;
    this->calificacion = calificacion;
}

/*
double Videos::calculaCalificacionPromedio(){




}
*/
#endif /* Videos_H_HEADER*/
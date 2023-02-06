#include <iostream>
#include <string>
#ifndef Episodio_H_HEADER
#define Episodio_H_HEADER
using namespace std;
#include "Videos.h"
class Episodio : public Videos
{
    //Public
public:
    //Constructor Omisión
    Episodio();
    //Constructor con parámetros
    Episodio(string _iD, string _nombre, string _genero, string _duracion, int _calificacion, string titulo, int temporada, int calificacionEp);
    //SET
    /*e 210 The_Vanishing_of_Will_Byers Ciencia_ficcion 42 5 Stranger_things T1 5*/
    void setTitulo(string titulo) { this->titulo = titulo; }
    void setTemporada(int temporada) { this->temporada = temporada; }
    //void setCalificacion(double calificacionEp) { this->calificacion = calificacionEp; }
    //GET
    string getTitulo() { return this->titulo; }
    int getTemporada() { return this->temporada; }
    int getCalificacion() { return this->calificacionEp; }
    //Misc Methods
    void muestraInformacion();
    //Privadob

private:
    //Atributos
    string titulo;
    int temporada;
    int calificacionEp;
};

Episodio::Episodio() : Videos()
{
    this->titulo = "";
    this->temporada = 0;
    //this->calificacionEp = 0;
}

Episodio::Episodio(string _iD, string _nombre, string _genero, string _duracion, int _calificacion, string titulo, int temporada, int calificacionEp) : Videos(_iD, _nombre, _genero, _duracion, _calificacion)
{
    this->titulo = titulo;
    this->temporada = temporada;
    this->calificacionEp = calificacionEp;
}

void Episodio::muestraInformacion()
{
    cout << "Episodio: " << nombre << ", Temporada: " << to_string(temporada) << ", Calificación: " << to_string(calificacion) << ", Serie: "<< titulo << endl;
}

#endif /* Episodio_H_HEADER */
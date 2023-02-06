#include <iostream>
#include <string>
using namespace std;

class Episodio
{
    //Public
public:
    //Constructor Omisión
    Episodio();
    //Constructor con parámetros
    Episodio(string _titulo, int _temporada, double _calificacion);
    //SET
    void setTitulo(string _titulo);
    void setTemporada(int _temporada);
    void setCalificacion(double _calificacion);
    //GET
    string getTitulo();
    int getTemporada();
    double getCalificacion();
    //Misc Methods
    void imprimir();
    //Privado
private:
    //Atributos
    string titulo;
    int temporada;
    double calificacion;
};

Episodio::Episodio(){
    titulo = "";
    temporada = 0;
    calificacion = 0;
}

Episodio::Episodio(string _titulo, int _temporada, double _calificacion){
    titulo = _titulo;
    temporada = _temporada;
    calificacion = _calificacion;
}


string Episodio::getTitulo(){
    return titulo;
}

int Episodio::getTemporada(){
    return temporada;
}

double Episodio::getCalificacion(){
    return calificacion;
}

void Episodio::setTitulo(string _titulo){
    titulo = _titulo;
}

void Episodio::setTemporada(int _temporada){
    temporada = _temporada;
}

void Episodio::setCalificacion(double _calificacion){
    calificacion = _calificacion;
}

void Episodio::imprimir(){
     cout << titulo << ", " << temporada << ", " << calificacion << endl;
 }
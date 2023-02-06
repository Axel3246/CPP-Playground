#include <iostream>
#include <string>
#include "Episodio.h"
#ifndef Serie_H_HEADER
#define Serie_H_HEADER
using namespace std;

class Serie
{

public:
    Serie();
    Serie(string iDD, string nombreSerie);
    //Métodos SET
    //void setCantEpisodio(int cantEpisodios) { this->cantEpisodios = cantEpisodios; }
    void setNombreSerie(string nombreSerie) { this->nombreSerie = nombreSerie; }
    void setId(string iD){this->iDD = iDD;}
    //Metodos GET
    string getId(){return this->iDD = iDD;}
    //int getCantEpisodios() { return this->cantEpisodios; }
    string getNombreSerie() { return this->nombreSerie; }
    //Metodo agrega episodio
    //Metodo calculaCalificacionPromedio
    //bool agregaEpisodio(Episodio *episodio);
    void imprimir();

private:
    Episodio *episodio[25];
    string iDD;
    int cantEpisodios;
    string nombreSerie;
};

Serie::Serie()
{
    this->iDD = "";
    this->cantEpisodios = 0;
    this->nombreSerie = "";
}

Serie::Serie(string iDD, string nombreSerie)
{
    this->iDD = iDD;
    this->cantEpisodios = 0;
    this->nombreSerie = nombreSerie;
}

void Serie::imprimir(){
    cout << "Numero de episodios: " << cantEpisodios << endl;
    // for con capitulos?
}

#endif /* Serie_H_HEADER */
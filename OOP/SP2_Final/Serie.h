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
    void setId(string iD) { this->iDD = iDD; }
    //Metodos GET
    string getId() { return this->iDD = iDD; }
    //int getCantEpisodios() { return this->cantEpisodios; }
    string getNombreSerie() { return this->nombreSerie; }
    //Metodo agrega episodio
    //Metodo calculaCalificacionPromedio
    bool agregaEpisodio(Episodio *episodio);
    void imprimir(int calificacion);
    void mostrar();

private:
    Episodio *arrepisodio[100];
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

bool Serie::agregaEpisodio(Episodio *episodio)
{
    if (cantEpisodios < 20)
    {
        arrepisodio[cantEpisodios] = episodio;
        cantEpisodios += 1;
        //cout << "Se agregó epi" << endl;
        return true;
    }
    else
    {
        return false;
    }
}

void Serie::imprimir(int calificacion)
{
    cout << "Serie:" << nombreSerie << endl;
    for (int i = 0; i < cantEpisodios; i++)
    {
        if(arrepisodio[i]->getCalificacion()==calificacion){
            arrepisodio[i]->muestraInformacion();
        }
        else{
            //cout << "No hay episodios con esa calificacion" << endl;
        }
    }
        

    // for con capitulos?
}

void Serie::mostrar(){
    cout << "Serie: " << nombreSerie << endl;
    cout << endl;
    for (int i = 0; i < cantEpisodios; i++){
        cout << "- " << arrepisodio[i]->getNombre() << endl;
    }
}
#endif /* Serie_H_HEADER */
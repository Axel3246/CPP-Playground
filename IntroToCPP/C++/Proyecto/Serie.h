#include <iostream>
#include <string>
using namespace std;
#include "Episodio.h"

class Serie{
    //Public
    public:
    //Constructor Omisión
    Serie();
    //Constructor con parámetros
    Serie(string _iD, string _titulo, string _genero, int _duracion, int _cantEpisodios,
    double _calificacionPromedio, int _num, int _episodio);
    //SET
    void setId(string _iD);
    void setTitulo(string _titulo); 
    void setDuracion(int _duracion);
    void setGenero(string _genero); 
    void setCalificacion(double _calificacionPromedio);
    void setCantidadEpisodios(int _cantEpisodios);
    void setEpisodio(int _num, Episodio _episodio);
    //GET
    string getId();
    string getTitulo();
    string getGenero();
    int getDuracion();
    int getCantidadEpisodios();
    double getCalificacion();
    Episodio getEpisodio(int _Ep);
    //Misc Methods
    void imprimir();
    //imprime la info de la serie que tiene cierta calificacion con ciertoes episodios, con for e if.
    void imprimir(double _calificacion); 
    //si la temporada de la serie dada si la tiene una serie, se imprime el tirulo de la serie
    void imprimir(int _temporada);
    void calculaCalificacionPromedio();
    //altaepisodio(string _, int _, int_);
    //Privado
    private:
    //Atributos
    //Episodio arrEpisodios[20]; //COMPOSICIÓN
    string iD, titulo, genero;
    int duracion, cantEpisodios;
    double calificacionPromedio;
    Episodio Episodios[5];
};

Serie::Serie(){
    iD = "";
    titulo = "";
    genero = "";
    duracion = 0;
    cantEpisodios = 0;
    calificacionPromedio = 0;

    
}
//Constructor con parámetros
Serie::Serie(string _iD, string _titulo, string _genero, int _duracion, int _cantEpisodios, double _calificacionPromedio, int _num, int _episodio){ //Episodio arrEpisodios[] -get-set-
    iD = _iD;
    titulo = _titulo;
    genero = _genero;
    duracion = _duracion;
    cantEpisodios = _cantEpisodios;
    calificacionPromedio = _calificacionPromedio;
}
//SET
void Serie::setId(string _iD){
    iD = _iD;
}
void Serie::setTitulo(string _titulo){
    titulo = _titulo;
}
void Serie::setDuracion(int _duracion){
    duracion = _duracion;
}
void Serie::setGenero(string _genero){
    genero = _genero;
}
void Serie::setCalificacion(double _calificacionPromedio){
    calificacionPromedio = _calificacionPromedio;
}
void Serie::setCantidadEpisodios(int _cantEpisodios){
    cantEpisodios = _cantEpisodios;
}
    
void Serie::setEpisodio(int _num, Episodio _episodio){
     if ((_num >= 0) && (_num <= 4)){
        Episodios[_num] = _episodio;
    }
    else{
        Episodios[0];
    }
}

//GET
string Serie::getId(){
    return iD;
}
string Serie::getTitulo(){
    return titulo;
}
string Serie::getGenero(){
    return genero;
}
int Serie::getDuracion(){
    return duracion;
}
double Serie::getCalificacion(){
    return calificacionPromedio;
}
int Serie::getCantidadEpisodios(){
    return cantEpisodios;
}
Episodio Serie::getEpisodio(int _Ep){
    if ((_Ep >= 0) && (_Ep <= 4)){
        return Episodios[_Ep];
    }
    else{
        return Episodios[0];
    }
}

    void Serie::calculaCalificacionPromedio(){
        double suma = 0;
        double promedio= 0;
        if (cantEpisodios > 0){
        for (int i = 0; i < cantEpisodios; i++){
            suma = suma + Episodios[i].getCalificacion();
        }
        promedio = suma / cantEpisodios;
        calificacionPromedio = promedio;
    }
        else{
            calificacionPromedio = 0;
        }
    }

void Serie::imprimir(){
    cout << iD << ", " << titulo << ", " <<  genero << ", " << duracion << ", " << cantEpisodios << ", " <<  calificacionPromedio << endl;
    for (int e=0; e<cantEpisodios; e++){
        Episodios[e].imprimir(); //WE LOVE C++
    }
}


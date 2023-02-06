#include <iostream>
#include <string>
using namespace std;

class Serie{
    //Public
    public:
    //Constructor Omisión
    Serie();
    //Constructor con parámetros
    Serie(string _iD, string _titulo, string _genero, int _duracion, int _cantEpisodios, double _calificacionPromedio);
    //SET
    void setId(string _iD);
    void setTitulo(string _titulo);
    void setDuracion(int _duracion);
    void setGenero(string _genero);
    void setCalificacion(double _calificacionPromedio);
    void setCantidadEpisodios(int _cantEpisodios);
    //GET
    string getId();
    string getTitulo();
    string getGenero();
    int getDuracion();
    double getCalificacion();
    int getCantidadEpisodios();
    //Misc Methods
    void imprimir();
    //double calculaCalificacionPromedio();
    //altaepisodio(string _, int _, int_);
    //Privado
    private:
    //Atributos
    string iD, titulo, genero;
    int duracion, cantEpisodios;
    double calificacionPromedio;
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
Serie::Serie(string _iD, string _titulo, string _genero, int _duracion, int _cantEpisodios, double _calificacionPromedio){
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
//Misc Methods
void Serie::imprimir(){
    cout << iD << ", " << titulo << ", " << duracion << ", " << genero << ", " << calificacionPromedio << ", " << cantEpisodios <<  endl;
}

//double Serie::calculaCalificacionPromedio();
//Serie::altaepisodio(string _, int _, int_);
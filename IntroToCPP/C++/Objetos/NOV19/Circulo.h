#include "Coordenada.h"

class Circulo{

    private:
        Coordenada centro;
        int iRadio;
    public:
        Circulo();
        Circulo(Coordenada, int);
        void setCentro(Coordenada);
        void setRadio(int);
        Coordenada getCentro();
        int getRadio();
        string str();

};
class Rectangulo{
    public:
     //Metodos modificadores, cambian el valor del atributo
        void setLargo(double);
        void setAncho(double);
    //Metodos de acceso - get - retornan el valor del atributo
        double getLargo();
        double getAncho();
        double calcularArea();

    private:
        double largo;
        double ancho;
};


//Implementacion de los métodos de la clase
 //Metodos modificadores, cambian el valor del atributo
void Rectangulo::setLargo(double la){
    largo = la;
}

void Rectangulo::setAncho(double an){
    ancho = an;
}

//Metodos de acceso - get - retornan el valor del atributo
double Rectangulo::getLargo(){
    return largo;
}

double Rectangulo::getAncho(){
    return ancho;
}

double Rectangulo::calcularArea(){
    return largo * ancho;
}


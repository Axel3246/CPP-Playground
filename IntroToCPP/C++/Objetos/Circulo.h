const double PI = 3.1416;

class Circulo{

    public:
    //Cambian el valor del atributo
        void setRadio(int);
    //Método de Acceso Radio
        int getRadio();
    //Metodo calcula Area
        double calcArea();
    //Metodo calcula perimetro
        double calcPerim();
    
    private:
        int radio;

};

//Cambian el valor del atributo
void Circulo::setRadio(int r){
    radio = r;
}
//Método de Acceso Radio
int Circulo::getRadio(){
    return radio;
}
//Metodo calcula Area
double Circulo::calcArea(){
    return PI * radio * radio;
}
//Metodo calcula perimetro
double Circulo::calcPerim(){
    return 2 * PI * radio;
}
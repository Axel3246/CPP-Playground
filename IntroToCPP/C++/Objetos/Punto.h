
// INSTRUCCIONES: 
// Escribe la clase Punto de acuerdo con 
// los comentarios que se encuentran enseguida
#include <iostream>
#include <cmath>
using namespace std;
// Nombre de la clase: Punto
class Punto{
// parte pública
    public:
   // Nota importante - ten cuidado en los nombres de los métodos - 
     // métodos de modificación x, y : setX, setY
     void setX(double);
     void setY(double);
     // métodos de acceso para x, y: getX, getY
     double getX();
     double getY();
     // método que calcula y retorna la distancia entre dos puntos : calculaDistancia(Punto p2)
     double calculaDistancia(Punto p2);
     // metodo que muestra un punto en el formato <x,y> :muestraPunto
     double muestraPunto();

// parte privada
    private:
        double x;
        double y;
    // atributos x, y, ambos de tipo double

};
// implementación de los métodos
// Nota importante - ten cuidado en los nombres de los métodos - 
// métodos de modificación x, y : setX, setY
void Punto::setX(double ex){
    x = ex;
}
void Punto::setY(double ye){
    y = ye;
}
 // métodos de acceso para x, y: getX, getY
double Punto::getX(){
    return x;
}
double Punto::getY(){
    return y;
}
// método que calcula y retorna la distancia entre dos puntos : calculaDistancia(Punto p2)
double Punto::calculaDistancia(Punto p2){
    return sqrt(pow(p2.getX()-x,2) + pow(p2.getY()-y,2));
}
// metodo que muestra un punto en el formato <x,y> :muestraPunto
double Punto::muestraPunto(){
    cout << "<" << x << "," << y << ">" << endl;
}
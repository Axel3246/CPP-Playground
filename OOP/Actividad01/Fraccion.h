#include <iostream>
#include <string>
using namespace std;

class Fraccion{
    public:
    //Constructor Omisión
    Fraccion();
    //Constructor con parámetros
    Fraccion(int _num, int _denr);
    //SET
    void setNum(int _num);
    void setDen(int _den);
    //GET
    int getNum();
    int getDen();
    //Misc Methods
    double calcValorReal();
    private:
    int num, den;
};

Fraccion::Fraccion(){
    num = 1;
    den = 2;
}

Fraccion::Fraccion(int _num, int _den){
    num = _num;
    den = _den;
}
//SET
void Fraccion::setNum(int _num){
    num = _num;
}
void Fraccion::setDen(int _denominador){
    den = _denominador;
}
//GET
int Fraccion::getNum(){
    return num;
}
int Fraccion::getDen(){
    return den;
}
double Fraccion::calcValorReal(){
    return double(num)/den;
}
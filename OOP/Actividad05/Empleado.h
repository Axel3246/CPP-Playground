//Axel Amós Hernández Cárdenas - A00829837
//Carlos Alberto Ortiz M - A01382584
#ifndef Empleado_h
#define Empleado_h

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Empleado{ 

protected: 
    string nombre; 
    int numero; 

public: 
    Empleado(); 
    Empleado (string nom, int nume); 
    string getNombre(); 
    int getNumero(); 
    void setNombre(string); 
    void setNumero(int); 
    void mostrar(); 
}; 
 
Empleado::Empleado() { 
    nombre = ""; 
    numero = 0; 
} 

Empleado::Empleado (string nom, int nume) { 
    nombre = nom; 
    numero = nume; 
} 

string Empleado::getNombre() { 
    return nombre; 
} 

int Empleado::getNumero() { 
    return numero; 
} 

void Empleado::setNombre(string nom) { 
    nombre = nom; 
} 

void Empleado::setNumero(int nume) { 
    numero = nume; 
} 

void Empleado::mostrar(){ 
    cout<< "La persona de nombre "<< nombre <<" con numero de "<<numero<<endl;  
} 
#endif
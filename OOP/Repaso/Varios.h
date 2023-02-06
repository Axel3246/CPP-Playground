#include <iostream>
#include <typeinfo.h>
#include <string>
#include "Name.h"

#ifndef Varios_header
#define Varios_header

using namespace std;

class Varios : public Name
{
public:
    Varios();
    Varios(string nombre, string edad, int id, string genero);
    //Set
    void setId(int id){this->id = id;}
    void setGenero(string genero){this->genero = genero;}
    //get
    int getId(){return id;}
    string getGenero(){return genero;}
    //Misc
    void muestra();

private:
    int id;
    string genero;
};

Varios::Varios():Name(){
    this->id = 0;
    this->genero = "";
}

Varios::Varios(string nombre, string edad, int id, string genero):Name(nombre, edad){
    this->id = id;
    this->genero = genero;
}

void Varios::muestra(){
    cout << nombre << " " << edad << " " << id << " " << genero;
}

#endif
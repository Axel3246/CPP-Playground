


#include <iostream>
#include <string>
using namespace std;
/*
//* Estructura básica en C++ con datos
struct Persona{ //* Declaración de estructura
    char nombre[20]; //TODO Areglo de nombres
    int edad; //TODO edades
}
persona1 = {"Sayu", 19}, //! Variables
persona2 = {"Ramirez", 23}; //! Variables

int main(){

    cout << "Nombre 1: " << persona1.nombre << endl; //? Para acceder se usa . y nombre del campo
    cout << "Edad 1: " << persona1.edad<< endl;

    cout << "\nNombre 2: " << persona2.nombre<< endl;
    cout << "Edad 2: " << persona2.edad<< endl;
}
*/

//? ¿Qué pasaría si no tuvieramos los datos de las personas?

struct Persona{ //* Declaración de estructura
    char nombre[20]; //TODO Areglo de nombres
    int edad; //TODO edades
}persona1, persona2; //! Variables

int main(){
    cout << "Nombre: ";
    cin.getline(persona1.nombre,20,'\n'); //! cin.getline( guardar, tamaño, acabar)
    cout << "Edad: ";
    cin >> persona1.edad;

    cout << "Name: " << persona1.nombre << "\n" << "Edad: " << persona1.edad;
}
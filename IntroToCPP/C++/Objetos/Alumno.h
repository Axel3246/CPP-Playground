// Escribe la clase Alumno de acuerdo con los comentarios
// Incluye las librerias requeridas
// Utiliza el espacio de trabajo estándar
// implementa los métodos
#include <iostream>
using namespace std;
// Clase Alumno
class Alumno{
// publico
    public: //(+)
    // constructor omisión que inicialice los atributos tipo string en nulo y los atributos numéricos en cero.
    Alumno();
    // constructor con parámetros para matricula, nombre, carrera y edad
    Alumno(string _matricula, string _nombre, string _carrera, int _edad);
    // métodos de acceso para todos los atributos get
    string getMatricula();
    string getNombre();
    string getCarrera();
    int getEdad();
    // métodos de modificación para todos los atributos set
    void setMatricula(string _matricula);
    void setNombre(string _nombre);
    void setCarrera(string _carrera);
    void setEdad(int _edad);
    // método imprimeAlumno que muestre en pantalla los atributos 
    //del alumno en el formato [matricula - nombre - carrera - edad]
    void imprimeAlumno();
    // método cumpleyears que incremente en uno la edad y lo muestre
    void cumpleYears();
// privado
    private: //(--)
    // atributos string matricula, nombre y carrera
    string matricula, nombre, carrera;
    // atributo entero edad
    int edad;
};


Alumno::Alumno(){
    matricula = "";
    nombre = "";
    carrera = "";
    edad = 0;
}

Alumno::Alumno(string _matricula, string _nombre, string _carrera, int _edad){
    matricula = _matricula;
    nombre = _nombre;
    carrera = _carrera;
    edad = _edad;
}

string Alumno::getMatricula(){
    return matricula;
}

string Alumno::getNombre(){
    return nombre;
}

string Alumno::getCarrera(){
    return carrera;
}

int Alumno::getEdad(){
    return edad;
}
// métodos de modificación para todos los atributos set
void Alumno::setMatricula(string _matricula){
    matricula = _matricula;
}
void Alumno::setNombre(string _nombre){
    nombre = _nombre;
}
void Alumno::setCarrera(string _carrera){
    carrera = _carrera;
}
void Alumno::setEdad(int _edad){
    edad = _edad;
}
// método imprimeAlumno que muestre en pantalla los atributos 
//del alumno en el formato [matricula - nombre - carrera - edad]
// si no corre cambiar nombre y matricula
void Alumno::imprimeAlumno(){
    cout << "[" << nombre << "-" << matricula << "-" << carrera << "-" << edad << "]" << endl;  
}   
// método cumpleyears que incremente en uno la edad y lo muestre
void Alumno::cumpleYears(){
    edad = edad + 1;
    cout << edad << endl;
}
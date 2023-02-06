#include <iostream>
#include <string>
using namespace std;

class User{

    public:
        User();
        User(string _nombre, int _edad, int _contador);
        void setNombre(string _nombre);
        void setEdad(int _edad);
        void setContador(int _contador);
        string getNombre();
        int getEdad();
        int getContador();
        void imprimir();

    private:
        string nombre;
        int edad, contador;

};

User::User(){

    nombre = "";
    edad = 0;
    contador = 0;

}

User::User(string _nombre, int _edad, int _contador){
    nombre = _nombre;
    edad = _edad;
    contador = _contador;
}

void User::setNombre(string _nombre){
    nombre = _nombre;
    
}
void User::setEdad(int _edad){
    edad = _edad;

}
void User::setContador(int _contador){
    contador = _contador;
}
string User::getNombre(){
    return nombre;
}
int User::getEdad()
{
    return edad;
}
int User::getContador(){
    return contador;
}
void User::imprimir(){
    cout << "Nombre: " << nombre << endl;
    cout << "Edad: " << edad << endl;
    cout << "Contador: " << contador << endl;
}
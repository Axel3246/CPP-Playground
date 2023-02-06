// !1
//TODO: Hacer una estructura llamada corredor, en la cual se tendran los siguientes campos: Nombre, edad, sexo, club.
//TODO: Deberas pedir los datos al usuario para un corredor y asignar una categoria de competición.
//TODO: Juveil <= 18 años
//TODO: Señor <= 40 años
//TODO: Veterano > 40 años
//TODO: Posteriormente, imprimir todos los datos del corredor, incluida su categoria de competición.
#include <iostream>
#include <string>
using namespace std;

struct Corredor
{
    char nombre[20];
    int edad;
    char sexo[20];
    char club[20];

} corredor1;

int main()
{
    string categoria;
    cin.ignore(256, '\n');
    cout << "Nombre: ";
    cin.getline(corredor1.nombre, 20, '\n'); //! cin.getline( guardar, tamaño, acabar)
    cout << "Edad: ";
    cin >> corredor1.edad;
    cin.ignore(256,'\n');
    cout << "Sexo: ";
    cin.getline(corredor1.sexo, 20, '\n'); //! cin.getline( guardar, tamaño, acabar)
    cout << "Club: ";
    cin.getline(corredor1.club, 20, '\n'); //! cin.getline( guardar, tamaño, acabar)
    if (corredor1.edad <= 18)
    {
        categoria = "Juvenil";
        //*strcpy(categoria,"Juvenil") - si fuera un arreglo
    }
    else if (corredor1.edad > 18 && corredor1.edad <= 40)
    {
        categoria = "Señor";
        //*strcpy(categoria,"Señor") - si fuera un arreglo
    }
    else
    {
        categoria = "Veterano";
        //*strcpy(categoria,"Veterano") - si fuera un arreglo
    }
    cout << "Nombre: " << corredor1.nombre << endl;
    cout << "Edad: " << corredor1.edad << endl;
    cout << "Sexo: " << corredor1.sexo << endl;
    cout << "Club: " << corredor1.club << endl;
    cout << "Categoria: " << categoria;
}
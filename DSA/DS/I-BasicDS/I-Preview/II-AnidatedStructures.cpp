
#include <iostream>
#include <string>
using namespace std;

//* Estructura anidada en C++

struct info_direccion //? Struct
{
    char direccion[30]; // !Var
    char ciudad[20];    // !Var
    char provincia[20]; // !Var
};

struct empleado //? Struct
{
    char nombre[20];                    // !Var
    struct info_direccion dir_empleado; // !Composicion de estructuras
    double salario;                     // !Var
} empleados[2];                         // !Arreglo de Empleados

int main()
{

    for (int i = 0; i < 2; i++)
    {
        fflush(stdin); //! Vaciar el buffer y permitir digitar los valores //cin.ignore(256,'\n')
        cout << "Escribe tu nombre: ";
        cin.getline(empleados[i].nombre, 20, '\n'); //! Guardar datos en un vector de estructura
        cout << "Escribe tu direccion: ";
        cin.getline(empleados[i].dir_empleado.direccion, 30, '\n'); //! Guardar datos en una estructura anidada
        cout << "Escribe tu ciudad: ";
        cin.getline(empleados[i].dir_empleado.ciudad, 20, '\n');
        cout << "Escribe tu provincia: ";
        cin.getline(empleados[i].dir_empleado.provincia, 20, '\n');
        cout << "Escribe el salario: ";
        cin >> empleados[i].salario;
        cout << endl;
    }

    // *Immprimiendo datos
    for (int j = 0; j < 2; j++)
    {
        cout << "Nombre: " << empleados[j].nombre << endl;
        cout << "Direccion: " << empleados[j].dir_empleado.direccion << endl;
        cout << "Ciudad: " << empleados[j].dir_empleado.ciudad << endl;
        cout << "Provincia " << empleados[j].dir_empleado.provincia << endl;
        cout << "Salario: " << empleados[j].salario;
        cout << '\n'
             << endl;
    }
}
//TODO: Realizar un programa que lea un arreglo de estructuras los datos de N empleados de la empresa
//TODO: y que imprima los datos del empleado con mayor y menor salario

#include <iostream>
#include <string>
using namespace std;

struct Empleado
{
    char nombre[50];
    double salario;

} empleados[100];

int main()
{
    int cantEmp, max = 0, min = 99999, imax, imin; // !Var

    cout << "Cantidad de Empleados: ";
    cin >> cantEmp;
    cin.ignore(256, '\n');

    for (int i = 0; i < cantEmp; i++) //!For para asignar valores al vector de empleados
    {
        cout << "Escribe el nombre: ";
        cin.getline(empleados[i].nombre, 20, '\n'); //! Guardar datos en un vector de estructura
        cout << "Escribe el salario: ";
        cin >> empleados[i].salario;
        cin.ignore(256, '\n');

        if (empleados[i].salario > max) // !Validando el salario maximo
        {
            max = empleados[i].salario; // !Asignando el maximo
            imax = i; // !Asignando el index imax
        }
        else if (empleados[i].salario < min) // !Validando el salario minimo
        {
            min = empleados[i].salario; // !Asignando el minimo
            imin = i; // !Asignando el index imin
        }
        cout << endl;
    }

    cout << "El empleado con mejor salario es: " << empleados[imax].nombre << endl;
    cout << "El salario del empleado es: " << empleados[imax].salario << endl;
    cout << endl;
    cout << "El empleado con menor salario es: " << empleados[imin].nombre << endl;
    cout << "El salario del empleado es: " << empleados[imin].salario << endl;
    cout << endl;
}
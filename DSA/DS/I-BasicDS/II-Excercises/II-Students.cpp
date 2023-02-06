//TODO: Hacer una estructura llamada alumno, en la cual se tendrán los siguientes campos: nombre, edad, promedio para 3 alumnos.
//TODO: Se deben pedir los datos al usuario y se debe comprobar cual de los tres tiene el mejor promedio
//TODO: Posteriormente, imprimir todos los datos del alumno

#include <iostream>
#include <string>
using namespace std;

struct Alumno
{
    char nombre[30];
    int edad;
    double promedio;

} alumnos[3];

int main()
{
    double bprom = 0; //!Var
    int index; //!Var

    for (int i = 0; i < 3; i++)
    {
        cout << "Escribe el nombre: ";
        cin.getline(alumnos[i].nombre, 20, '\n'); //! Guardar datos en un vector de estructura
        cout << "Escribe la edad: ";
        cin >> alumnos[i].edad; 
        cout << "Escribe el promedio: ";
        cin >> alumnos[i].promedio;
        cin.ignore(256, '\n');

        if (alumnos[i].promedio > bprom) //! Encontrar el alumno con la mayor calificacion
        {
            bprom = alumnos[i].promedio;
            index = i;
        }
        cout << endl;
    }

    cout << "El alumno con el mejor promedio es: " << alumnos[index].nombre << endl;
    cout << "La edad del alumno es: " << alumnos[index].edad << endl;
    cout << "El promedio del alumno fue: " << alumnos[index].promedio;
}

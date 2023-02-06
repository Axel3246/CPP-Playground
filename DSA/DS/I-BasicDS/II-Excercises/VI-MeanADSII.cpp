//TODO: Hacer 2 estructuras una llamada promedio que tendrá: nota1, nota2, nota3 y otra llamada alumno que tendrá los siguientes miembros:
//TODO: nombre, sexo, edad; hacer que la estructura promedio esté anidada en la estructura alumno, luego pedir los datos para N alumnos,
//TODO: luego calcular cual tiene el mejor promedio y e imprimir sus datos.

#include <iostream>
#include <string>
using namespace std;

struct Promedio // !Struct promedio
{
    double nota1; // !Var
    double nota2; // !Var
    double nota3; // !Var
};

struct Alumno
{
    char nombre[30];      // !Var
    char sexo[30];        // !Var
    int edad;             // !Var
    Promedio mean_alumno; // !Var

} alumnos[100];

int main()
{

    // !Vars
    int index, cantAlumnos, max = 0;
    double mean[100];

    cout << "Cantidad de alumnos: ";
    cin >> cantAlumnos;
    cin.ignore(256,'\n');
    // !Almacenando datos
    for (int i = 0; i < cantAlumnos; i++)
    {
        // !Registrando los datos
        cout << "Nombre: ";
        cin.getline(alumnos[i].nombre, 30, '\n');
        cout << "Género: ";
        cin.getline(alumnos[i].sexo, 30, '\n');
        cout << "Edad: ";
        cin >> alumnos[i].edad;
        cout << "|| " << "Notas del alumno " << i+1 << " ||" << endl;
        cout << "Nota 1: ";
        cin >> alumnos[i].mean_alumno.nota1;
        cout << "Nota 2: ";
        cin >> alumnos[i].mean_alumno.nota2;
        cout << "Nota 2: ";
        cin >> alumnos[i].mean_alumno.nota3;
        cout << endl;
        cin.ignore(256,'\n');
        // !Obteniendo el promedio
        mean[i] = (alumnos[i].mean_alumno.nota1 + alumnos[i].mean_alumno.nota2 + alumnos[i].mean_alumno.nota3) / 3;

        // !Obteniendo la mayor calificacion

        if(mean[i] > max){
            max = mean[i];
            index = i;
        }
    }
    cout << endl;
    cout << "- " << "Alumno destacado" << " -" << endl;
    cout << "Nombre: " << alumnos[index].nombre << endl;
    cout << "Edad: " << alumnos[index].edad << endl;
    cout << "Género: " << alumnos[index].sexo << endl;
    cout << "Promedio: " << mean[index] << endl;
}
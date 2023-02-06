//TODO: Hacer 2 estructuras una llamada promedio que tendrá: nota1, nota2, nota3 y otra llamada alumno que tendrá los siguientes miembros:
//TODO: nombre, sexo, edad; hacer que la estructura promedio esté anidada en la estructura alumno, luego pedir los datos para un alumno,
//TODO: luego calcular su promedio, y por ultimo imprimir todos sus datos incluido el promedio

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

} alumno1;

int main()
{

    // !Var
    double mean;

    // !Almacenando datos
    cout << "Nombre: ";
    cin.getline(alumno1.nombre, 30, '\n');
    cout << "Género: ";
    cin.getline(alumno1.sexo, 30, '\n');
    cout << "Edad: ";
    cin >> alumno1.edad;
    cout << "|| " << "Notas del alumno" << " ||" << endl;
    cout << "Nota 1: ";
    cin >> alumno1.mean_alumno.nota1;
    cout << "Nota 2: ";
    cin >> alumno1.mean_alumno.nota2;
    cout << "Nota 2: ";
    cin >> alumno1.mean_alumno.nota3;

    // !Calculando el promedio
    mean = (alumno1.mean_alumno.nota1 + alumno1.mean_alumno.nota2 + alumno1.mean_alumno.nota3) / 3;

    // !Desplegando los datos
    cout << endl;
    cout << "Nombre: " << alumno1.nombre << endl;
    cout << "Edad: " << alumno1.edad << endl;
    cout << "Género: " << alumno1.sexo << endl;
    cout << "Promedio: " << mean << endl;
}
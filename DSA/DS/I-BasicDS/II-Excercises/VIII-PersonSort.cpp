//TODO: Defina una estructura que sirva para representar a una persona. La estructura debe contener: nombre y un valor bool, que indique
//TODO: si la persona tiene algun tipo de discapacidad. Realice un programa que dado un vector de personas rellene dos nuevos vectores:
//TODO: uno que contenga las personas sin discapacidad y otro que contenga las personas con discapacidad.

#include <iostream>
#include <string.h>
using namespace std;

struct Persona // !Struct
{
    // !Vars
    char nombre[30];
    bool discapacidad;

} personas[100], personassin[100], personascon[100];

int main()
{

    // !Vars
    int cantPersonas, pdisc = 0, pndisc = 0; //!pdisc y pndisc seran los index para los arreglos de discapacidad
    //char disc;
    cout << "Cantidad de personas: ";
    cin >> cantPersonas;
    //cin.ignore(256, '\n');

    // ! Cargando Data
    for (int i = 0; i < cantPersonas; i++)
    {
        cin.ignore(256, '\n');
        cout << "|| Información de la Persona " << i + 1 << " ||" << endl;
        cout << "Nombre: ";
        cin.getline(personas[i].nombre, 30, '\n');
        cout << "¿Cuenta con Discapacidad? (1 / 0): ";
        cin >> personas[i].discapacidad;
        cout << endl;

        if (personas[i].discapacidad == 1) // !Guardando las personas con / sin discapacidad
        {
            strcpy(personascon[pdisc].nombre, personas[i].nombre);
            //* Checkpoint: cout << personascon[pdisc].nombre << endl;
            pdisc += 1; // !Vector nvo requiere nuevos indexes
        }
        else if (personas[i].discapacidad == 0)
        {
            strcpy(personassin[pndisc].nombre, personas[i].nombre);
            //* Checkpoint: cout << personas[pndisc].nombre << endl;
            pndisc += 1; // !Vector nvo requiere nuevos indexes
        }
        //cin.ignore(256, '\n');
    }

    // !Imprimiendo las personas sin / con discapacidad

    cout << "|| Personas sin Discapacidad ||" << endl;

    for (int j = 0; j < cantPersonas; j++)
    {
        cout << personassin[j].nombre << endl;
    }

    cout << "|| Personas con Discapacidad ||" << endl;
    for (int k = 0; k < cantPersonas; k++)
    {
        cout << personascon[k].nombre << endl;
    }
}
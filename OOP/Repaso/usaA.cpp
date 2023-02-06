#include <iostream>
#include <typeinfo.h>
#include <string>
#include <fstream>
#include <sstream>

#include "Name.h"
#include "Varios.h"

using namespace std;

int main()
{

    Name *nombres[10];
    string nombre, edad, genero;
    int id, cantNombres = 0;
    char t;

    ifstream archnom("nombres.txt");

    while (archnom >> nombre >> edad >> id >> genero)
    {
        nombres[cantNombres] = new Varios(nombre, edad, id, genero);
        cantNombres += 1;
    }
    archnom.close();
    cout << "hola";
    do
    {
        cout << endl;
        cout << "a) Mostrar todo" << endl;
        cout << "b) Mostrar nombres" << endl;
        cout << "c) Mostrar edades" << endl;
        cout << "d) Mostrar buscar x nombre" << endl;
        cout << "e) Cerrar Sesion" << endl;
        cout << "Op -> ";
        char opmenu;
        cin >> opmenu;
        cout << endl;
        switch (opmenu)
        {
        case 'a':
        {
            for (int i = 0; i < cantNombres; i++)
            {
                nombres[i]->muestra();
                cout << endl;
            }

            break;
        }
        case 'b':
        {
            for (int i = 0; i < cantNombres; i++)
            {
                cout << nombres[i]->getNombre() << endl;
            }
            break;
        }
        case 'c':
        {
            for (int i = 0; i < cantNombres; i++)
            {
                cout << nombres[i]->getEdad() << endl;
            }
            break;
        }
        case 'd':
        {
            string nom = "";
            cout << "A quien busca: ";
            cin >> nom;
            for (int i = 0; i < cantNombres; i++)
            {
                if (nombres[i]->getNombre() == nom)
                {
                    nombres[i]->muestra();
                    cout << endl;
                }
            }
            break;
        }
        case 'e':
        {
            cout << "Gracias por visitarnos" << endl;
            return 0;
        }
        }
    }
        while (t != 'z')
            ;
        return 0;
    
}

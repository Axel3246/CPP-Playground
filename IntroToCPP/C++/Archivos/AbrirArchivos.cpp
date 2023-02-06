//
//  main.cpp
//  LeerArchivo
//
//  Created by Ma. Guadalupe Roque Díaz de León on 16/11/20.
//

#include <iostream>

#include<fstream>
#include<sstream>
using namespace std;


int main()
{
    string id, nombre, apellido;
    int edad, promedio;
    
   //OUTPUT FILE STREAM
    ofstream fichero;
    fichero.open("fichero.csv",ios::app);

    //CAMBIAR EL VALOR DE iK PARA AUMENTAR LOS ID
    for (int iK = 0; iK < 2; iK++)
    {
        cout << "Ingrese id, nombre, apellido,edad y promedio por favor: \n";
        cin >> id;
        cin.ignore();
        getline(cin,nombre);
        getline(cin, apellido);
        cin >> edad;
        cin >> promedio;

        fichero<<id<<";"<<nombre<<";"<<apellido<<";"<<edad<<";"<<promedio<<"\n";
        system("cls");
    }
    fichero.close();


    ifstream lectura;
    string linea, dato;
   
    lectura.open("fichero.csv",ios::in);
    while (getline(lectura, linea))
    {
        cout << linea << endl;
        stringstream registro(linea);
        

        for (int columna = 0; getline(registro, dato, ';'); ++columna)
        {
            switch (columna)
            {
                case 0: // ID
                    id = dato;
                break;
                case 1: // NOMBRE
                    nombre = dato;
                break;
                case 2: // APELLIDO
                    apellido = dato;
                break;
                case 3: // EDAD
                    edad = std::stoi(dato);
                break;
                case 4: // PROMEDIO
                    promedio = std::stod(dato);
                break;
            }
        }
    
    
    cout <<id<<";"<<nombre<<";"<<apellido<<";"<<edad<<";"<<promedio<<"\n";

    }
    lectura.close();
    return 0;
}

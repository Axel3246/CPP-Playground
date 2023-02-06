/*
Nombre: Eduardo Loya Montes de Oca - A01383049
Nombre: Roberto Abraham Perez Iga - A01384237
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 06 de Septiembre del 2021
Ultima Versión: 10 de Septiembre del 2021
Descripción: El canal de Suez es un canal navegable que conecta el mar 
Mediterráneo con el mar Rojo a través de alrededor de 190 km, uniendo por 
un el lado del mar Mediterráneo desde el puerto Said hasta el golfo de Suez en 
el mar Rojo. Este canal es navegado entre 49 y 97 barcos diariamente.
Objetivos:
1. Solicite el nombre del archivo de entrada (Ej. canal.txt) y lo abra, almacenando los datos en un vector.
2. Ordene la información por UBI + Fecha (primero por UBI, al haber empate ordenar por fecha).
3. Solicite al usuario la serie a buscar (los primeros tres caracteres de el UBI).
4. Despliegue todas las entradas al canal de los buques de esas series en forma ordenada UBI+Fecha.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

// * Struct para el vector que guardara el .txt file
struct logSuez{

    string fecha;
    string hora;
    char entrada;
    string ubi;
    int fechaInt;
};

// * Funcion que transforma un mes a INT
// ? Complejidad: O(1)
int mestoi(string m){

    if (m == "jan"){

        return 1;
    }
    if (m == "feb"){

        return 2;
    }
    if (m == "mar"){

        return 3;
    }
    if (m == "apr"){

        return 4;
    }
    if (m == "may"){

        return 5;
    }
    if (m == "jun"){

        return 6;
    }
    if (m == "jul"){

        return 7;
    }
    if (m == "aug"){

        return 8;
    }
    if (m == "sep"){

        return 9;
    }
    if (m == "oct"){

        return 10;
    }
    if (m == "nov"){

        return 11;
    }
    return 12;
}

// * Funcion que transforma una fecha string a INT
// ? Complejidad: O(n)
int ftoi(string fecha){

    int salida = 0;
    int aux = 0;
    int i = 0;

    while (fecha[i] != '-'){

        aux *= 10;
        aux += (fecha[i] - '0'); // * '5' -'0' == 5 como entero (53-48)
        i++;
    }

    salida += aux;
    i++;
    string mes = "";

    while (fecha[i] != '-'){

        mes += fecha[i];
        i++;
    }

    salida += (mestoi(mes) * 100);
    aux = 0;
    i++;

    while (i < fecha.length()){

        aux *= 10;
        aux += (fecha[i] - '0'); // '5' -'0' == 5 como entero (53-48)
        i++;
    }

    salida += (aux * 10000);
    return salida;
}

// * Función que ordena por UBI y si hay empate por fecha
// ? Complejidad: O(n) - Por la función .compare()
bool acompare(logSuez lhs, logSuez rhs){
    
    if (lhs.ubi == rhs.ubi){

        return lhs.fechaInt < rhs.fechaInt;
    }
    return (lhs.ubi.compare(rhs.ubi) < 0); // * Cuidado como compara 2 strings
}

// * Funcion de busqueda binaria que busca la serie deseada por el usuario y regesa la posicion de la última coincidencia
// ? Compleidad: O(log(n))
int buscaBinaria(vector<logSuez> &vect, string dato, bool &found){

    found = false;
    int inicio = 0, fin = vect.size() - 1, mitad;
    while (inicio <= fin){

        mitad = (inicio + fin) / 2;

        if (vect[mitad].ubi.substr(0, 3) == dato){ // * Busca la serie

            if (mitad == 0 || vect[mitad - 1].ubi.substr(0, 3) != dato){

                found = true;
                return mitad;
            }
            else{

                fin = mitad - 1;
            }
        }
        else{

            if (vect[mitad].ubi.substr(0, 3).compare(dato) > 0){ // * El dato que busco es menor al central

                fin = mitad - 1;
            }
            else{ // * El dato que busco es mayor al central

                inicio = mitad + 1;
            }
        }
    }
    //cout << "No lo encontré" << endl;
    return found;
}

int main(){

    system("cls"); // * Limpiar la terminal

    string date, hour, ub, nomArch;
    int dateInt;
    char entryDate;

    vector<logSuez> vector1;

    cout << "\t .:Archivos Disponibles:.\n" << endl;
    cout << "1. suez.txt" << endl;
    cout << endl;
    cout << "Abrir archivo -> ";
    cin >> nomArch;
    cout << endl;

    while (nomArch != "suez.txt"){

        cout << "Archivo no encontrado. Proporcione otro nombre -> ";
        cin >> nomArch;
        cout << endl;
    }

    ifstream datosSuez;
    datosSuez.open("suez.txt");

    while (datosSuez >> date >> hour >> entryDate >> ub){

        logSuez registro;

        registro.fecha = date;
        registro.hora = hour;
        registro.entrada = entryDate;
        registro.ubi = ub;
        registro.fechaInt = ftoi(date);
        vector1.push_back(registro);
    }

    datosSuez.close();

    cout << "Ordenando Datos..." << endl;
    cout << endl;
    
    sort(vector1.begin(), vector1.end(), acompare); // * Ordenando el vector

    // ! Output file
    /*
    ofstream file_out("test.txt");
    for (int i = 0; i < vector1.size(); ++i){
        file_out << vector1[i].fecha << " " << vector1[i].hora << " " << vector1[i].entrada << " " << vector1[i].ubi << " " << vector1[i].fechaInt << endl;
        }
    */

    string serieSearch;

    cout << "Serie a buscar -> ";
    cin >> serieSearch;

    bool elementFound;
    int posBus = buscaBinaria(vector1, serieSearch, elementFound);

    if (elementFound){

        while (elementFound == true){

            if (vector1[posBus].ubi.substr(0, 3) == serieSearch){

                cout << vector1[posBus].ubi << " " << vector1[posBus].fecha << endl;
                posBus++;
            }
            else{

                elementFound = false;
            }
        }
    }
    else{

        cout << "Serie no encontrada" << endl;
    }
}
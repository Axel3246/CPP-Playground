/*
Nombre: Eduardo Loya Montes de Oca - A01383049
Nombre: Roberto Abraham Perez Iga - A01384237
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 25 de Noviembre del 2021
Ultima Versión: 25 de Noviembre del 2021

Descripción: 
La primera línea de entrada contiene 2 números enteros positivos: m ≤ 1,000, 
el número de palabras en diccionario "Unlimited Seas", y n ≤ 100, el número de descripciones de puestos. 
Las siguientes m líneas; cada una contiene una palabra y un valor en dólares (un número entero entre 0 y 1,000,000). 
A continuación, se encuentran las n descripciones de puestos. Cada descripción de puesto de trabajo consta de uno o más
 líneas de texto; para mayor facilidad, el texto se ha convertido a minúsculas y no tiene más caracteres que letras, números
y espacios. Cada descripción de puesto de trabajo con una línea que contiene un punto.
*/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main(){
    
    cout << " ==Introduce Datos== " << endl;
    int desc, cantParr, valorDolar;
    string palabra;
    cin >> desc >> cantParr;
    //  Lees descriptores
    unordered_map<string, int> umapa;

    for(int i=0; i < desc; i++){

        cin >> palabra >> valorDolar;
        if(umapa.find(palabra) == umapa.end()){ // * Encontramos si ya se ocupó la key
            
            umapa[palabra] = valorDolar;
        }
        else{
            umapa[palabra]++;
        }
    }

    int total = 0;
    string s;
    
    while(cantParr){ // * Entero NO CERO = true, 0 es false

        cin >> s;
        if (s == "."){

            cantParr--;
            cout << "El total es: " << total << endl;
            total = 0;
        }
        else{
            if(umapa.find(s) == umapa.end()){
                //cout << "No encontrado" << endl;
            }
            else{
                total += umapa[s];
            }
        }
    }
}

    

    

    

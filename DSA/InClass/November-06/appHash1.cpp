/*
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 23 de Noviembre del 2021
Descripción: Programa para la actividad 5.1 - Hashing con Open
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// * Función que verifica si un numero es primmo
// ? Complejidad: O(sqrt(n))
bool isPrime(int tam){

    for(int i=2; i <= sqrt(tam); i++){
        
        if(tam % i == 0){

            return false;
        }
    }
    return true;
}

// * Función que utiliza el método de hashing: chain
// ? Complejidad: O(n)
void open(vector<int> &hash, int n){

    int dato, tam = hash.size();

    for(int i=0; i<n; i++){

        cin >> dato;
        int idx = dato % tam;

        while(hash[idx] != 0){
            /*
            idx++;
            if(idx == (n)){ idx = 0; }
            */
            idx = (idx + 1) % tam;
        }
        hash[idx] = dato;
    }

}

// * Función para imprimir el vector
// ? Complejidad: O(n)
void print(vector<int> hash){

    for(int i=0; i < hash.size(); i++){

        cout << i << " - " << hash[i] << endl;
    }
}

// * n = Cantidad Datos
// * tam = Tamaño de la tabla en numero primo
int main(){

    // * Cant Datos
    int n, tam; 
    cout << " == Inserte Datos ==" << endl;
    cin >> n;
    tam = n;

    // * Buscamos que la tabla tenga un tamaño primo
    while(!isPrime(tam)){

        tam++;
    }
    
    vector<int> hash(tam, 0); // * 0 = está desocupada la casilla
    open(hash, n);
    cout << "== La tabla de hash es ==" << endl;
    print(hash);

    return 0;
}


/*
9
100
123
423
111
18
14
99
21
109
*/

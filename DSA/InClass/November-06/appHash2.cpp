/*
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 23 de Noviembre del 2021
Descripción: Programa para la actividad 5.1 - Hashing con Chain
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
void chain(vector<vector<int>> &hash, int n){

    int dato, tam = hash.size();

    for(int i = 0; i < n; i++){

        cin >> dato;

        int idx = dato % tam;
        hash[idx].push_back(dato);
    }
}

// * Función que imprime el vector de vectores  
// ? Complejidad: O(n^2)
void print(vector<vector<int>> hash){

    for(int i=0; i < hash.size(); i++){

            cout << i << " - ";

        for(int j=0; j < hash[i].size(); j++){

            cout << hash[i][j] << ", ";
        }
        cout << endl;
    }
}

int main(){

    // * Cant Datos
    int n, tam; 
    cout << " == Inserte Datos ==" << endl;
    cin >> n;
    tam = n;

    while(!isPrime(tam)){

        tam++;
    }

    vector<vector<int>> hash(tam);
    chain(hash, n);
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

#include <iostream>
#include <unordered_map>

using namespace std;

int main(){

    int cantEdades;
    int edad;

    unordered_map<int, int> mapa; // Llave y contenido

    cin >> cantEdades;

    for(int i=0; i < cantEdades; i++){

        cin >> edad;
        if(mapa.find(edad) == mapa.end()){ // No está el dato
            
            mapa[edad] = 1;
        }
        else{
            mapa[edad]++;
        }
    }
    cout << "Se insertaron " << cantEdades << " pero solamente hay " << 
    mapa.size() << " diferentes" << endl;

    int q;

    cout << "-----------------" << endl;

    cin >> q;
    for (int i=0; i<q; i++){

        cin >> edad;

        if(mapa.find(edad) == mapa.end()){ // *find o(1)

            cout << "La edad " << edad << " no está en el mapa" << endl;
        }
        else{
            cout << "Mapa con edad " << edad << " tiene " << mapa[edad] << " alumnos" << endl;
        }
    }

}
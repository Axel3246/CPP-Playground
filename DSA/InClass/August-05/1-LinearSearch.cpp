
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ? Complejidad: O(n)
void print(vector<int> &vect){

    for (int i = 0; i < vect.size(); i++){

        cout << vect[i] << " ";
    }
    cout << endl;
}

int busquedaSecuencial(vector<int> &vect, int dato){

    for(int i = 0; i < vect.size(); i++){

        if(vect[i] == dato){

            return i;
        }
    }
    return -1;
}

int main()
{

    int num, n, dato;
    /*vector<int> vector1; // * Vector con 0 casillas
    cout << "Inserta numeros. Pon 0 si ya no quieres insertar: ";
    do
    {
        cin >> num;
        vector1.push_back(num);
    } while (num != 0);*/

    // * Vector con casillas predefinidas
    cin >> n;
    vector<int> vect(n);

    for (int i = 0; i < n; i++){

        cin >> vect[i];
    }
    print(vect);

    cin >> dato;

    int posicionBusqueda = busquedaSecuencial(vect, dato);
    int cantComparaciones = (posicionBusqueda == -1 ? vect.size() : posicionBusqueda + 1);
    
    cout << "Posicion: " << posicionBusqueda << " Comparaciones: " << cantComparaciones << endl;;

    sort(vect.begin(),vect.end());
    cout << "Datos Ordenados Ascendentes: ";
    print(vect);

    sort(vect.begin(),vect.end(), greater<int>());
    cout << "Datos Ordenados Descendentes: ";
    print(vect);
}
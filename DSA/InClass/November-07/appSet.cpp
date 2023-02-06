// Poner en un conjunto las dades de mis alumnos.


#include <iostream>
#include <unordered_set>

using namespace std;

int main(){

    int cantEdades;
    int edad;

    unordered_set<int> conj;

    cin >> cantEdades;

    for(int i=0; i < cantEdades; i++){

        cin >> edad;

        conj.insert(edad);

    }
    cout << "Se insertaron " << cantEdades << " pero solamente hay " << conj.size() << " diferentes" << endl;

    int q;

    cout << "-----------------" << endl;

    cin >> q;
    for (int i=0; i<q; i++){

        cin >> edad;

        if(conj.find(edad) == conj.end()){ // *find o(1)

            cout << "La edad " << edad << " no está en el conjunto" << endl;
        }
        else{
            cout << "La edad " << edad << " si está en el conjunto" << endl;
        }
    }

}

/*
10
19
20
19
18
21
10
19
18
21
19
*/
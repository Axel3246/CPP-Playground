/*
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 08 de Noviembre del 2021
Ultima Versión: 10 de Noviembre del 2021
Descripción: Act 4.2 - Grafo: Algoritmos Complementarios. 

- Se ha realizado el topological Sort (Khan's Algorithm)
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// * Función para cargar los valores del Grafo en la lista adyacente
// ? Complejidad: O(m)
void loadGraph(vector<vector<int>> &listAdj, vector<int> &inDegree, int m, int n){

    int a, b;

    for(int i = 0; i < m; i++){

        cin >> a >> b;

        // * Dirigido y no aciclico
        listAdj[a-1].push_back(b-1);
        inDegree[b-1]++;
    }
}

// * Función para realizar el topologicalSort en un grafo DAG
// ? Complejidad: O(|V| + |E|)
vector<int> topologicalSort(vector<vector<int>> &listAdj, vector<int> inDegree, int m, int n){

    // * Vector de inDegree con el numero de Nodos (inicialmente en 0)
    // * vector que devolveremos
    vector<int> grafoSort;  
    int dato;
    queue<int> fila;
    
    for(int i = 0; i < n; i++){

        if(inDegree[i] == 0){
            
            fila.push(i);
            //cout << "Frente Iteracion " << i << ": " << fila.front() << endl;    
        }
    }
    while(!fila.empty()){

        dato = fila.front();
        //cout << "Frente: " << dato << endl;
        fila.pop();
        grafoSort.push_back(dato+1);

        for (int j:listAdj[dato]){

            if(inDegree[j] > 0){
            
                inDegree[j]--;
            
                if(inDegree[j] == 0){
                
                    fila.push(j);
                }
            }
        }
    }
    return grafoSort;
}

int main(){

    cout << "== Inserte Datos ==" << endl;

    // * n = cant de nodos (base - 1)
    // * m = cant de arcos
    int n,m;
    cin >> n >> m;

    vector<vector<int>> listAdj(n);
    vector<int> inDegree(n,0);
    
    loadGraph(listAdj, inDegree, m, n);
    //printListAdj(listAdj);

    vector<int> solucion;
    solucion = topologicalSort(listAdj, inDegree, m,n);

    cout << "== Topological Order ==" << endl;
    
    for(int z = 0; z < solucion.size(); z++){

        cout << solucion[z] << " ";
    }

}

/*
9 13
1 2
1 3
2 3
2 4
3 4
3 5
4 8
5 6
5 7
6 8
7 8
9 3
9 5

1 9 2 5 3 4 6 7 8
1 9 2 3 4 5 6 7 8


*/
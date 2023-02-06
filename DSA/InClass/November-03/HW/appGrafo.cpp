/*
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 06 de Noviembre del 2021
Ultima Versión: 08 de Noviembre del 2021
Descripción: Act 4.1 - Grafo: sus representaciones y sus recorridos

- Se ha realizado BFS con Lista de Adyacencia
- Se ha realizado DFS con Matriz de Adyacencia
*/

#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define MAX 10

// * Función para inicializar la matriz de adyacencia en Falso
// ? Complejidad: O(n^2)
void iniMatAdj(bool matAdj[MAX][MAX]){

    for(int i = 0; i < MAX; i++){

        for(int j = 0; j < MAX; j++){

            matAdj[i][j] = false;
        }
    }
}

// * Función para cargar los valores del Grafo en la matriz y lista
// ? Complejidad: O(m)
void loadGraph(bool matAdj[MAX][MAX], vector<vector<int>> &listAdj, int m, int n){

    int a, b;

    for(int i = 0; i < m; i++){

        cin >> a >> b;

        // * Manejo de base 1 en la matriz
        matAdj[a-1][b-1] = matAdj[b-1][a-1] = true;

        // * Manejo de base 0 en las listas
        listAdj[a-1].push_back(b-1);
        listAdj[b-1].push_back(a-1);
    }
}

// * Funcion para el recorrido BFS con Lista de Adyacencia
// ? Complejidad: O(|V| + |E|)
void BFS(vector<vector<int>> &listAdj){

    // * Estructuras Necesarias
    queue<int> fila;
    vector<bool> status(listAdj.size(), false);
    // * Valor que irá actualizando el frente de la fila
    int dato;

    for(int j = 0; j < listAdj.size(); j++){
        
        if(!status[j]){ // * If para transformar el elemento a True si es False
        
            fila.push(j); // * Insertamos a la fila
            status[j] = true; // * Cambiamos su estado

            while(!fila.empty()){ 
                
                dato = fila.front(); // * Igualamos dato a fila front (Nodo)
                fila.pop();
                cout << (dato + 1) << " "; // * Desplegamos
                /*
                    for (int i = 0; i < listAdj[dato].size(); i++){

                        if(!status[listaAdj[dato][i]]){

                            fila.push([listaAdj[dato][i]]);
                            status[[listaAdj[dato][i]]] = true;
                        }
                    }
                */
                for(int i : listAdj[dato]){ // * Por cada int del vector de vectores de dato

                    if(!status[i]){ // * Si ese int en status es falso

                        fila.push(i); // * Lo metemos a fila
                        status[i] = true; // * Cambiamos su estado
                    }
                }
            }
        }
    }
    cout << endl;
}

// * Funcion para el recorrido BFS con Lista de Adyacencia
// ? Complejidad: O(|V|^2)
void DFS(bool matAdj[MAX][MAX], int n){

    stack<int> pila;
    int dato;
    vector<bool> status(n ,false);
    int cantVisitados = 0;

    for(int i = 0; i < n && cantVisitados != n; i++){

        if(!status[i]){

            pila.push(i);

            while(!pila.empty() && cantVisitados != n){

                dato = pila.top();
                pila.pop();

                if(!status[dato]){

                    status[dato] = true;
                    cantVisitados++;
                    cout << (dato + 1) << " ";
                
                    for(int j = n-1; j >= 0; j--){
                    
                        if(matAdj[dato][j] && !status[j]){
                        
                            pila.push(j);     
                        }
                    }
                }
            }
        }
    }
    cout << endl;
}

int main(){

    cout << "== Inserte Datos ==" << endl;

    bool matAdj[MAX][MAX];

    int n, m;

    // * n = cant de nodos (base - 1)
    // * m = cant de arcos

    cin >> n >> m;
    vector<vector<int>> listAdj(n);
    
    iniMatAdj(matAdj);
    loadGraph(matAdj, listAdj, m, n);

    cout << "== Recorrido BFS ==" << endl;
    BFS(listAdj);
    cout << "== Recorrido DFS ==" << endl;
    DFS(matAdj, n);

    
}

/*
== Casos de Prueba ==

7 11
1 2
1 3
1 4
2 3  
2 5
3 4
3 5
4 5
4 6
5 7
6 7

BFS: 1 2 3 4 5 6 7 
DFS: 1 2 3 4 5 7 6 

7 6
1 2
2 3  
2 5
3 4
4 6
5 7

BFS: 1 2 3 5 4 7 6 
DFS: 1 2 3 4 6 5 7 
*/

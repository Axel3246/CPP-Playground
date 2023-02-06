/*
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 06 de Noviembre del 2021
Ultima Versión: 09 de Septiembre del 2021
Descripción: Act 4.1 - Grafo: sus representaciones y sus recorridos 
*/


#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

#define MAX 10

// * Función para inicializar la matriz de adyacencia en Falso
// ? Complejidad: O(n) o O(MAX)
void iniMatAdj(bool matAdj[MAX][MAX]){

    for(int i = 0; i < MAX; i++){

        for(int j = 0; j < MAX; j++){

            matAdj[i][j] = false;
        }
    }
}

// * Función para cargar los valores del Grafo en la matriz y lista
// ? Complejidad: O(n) o O(m)
void loadGraph(bool matAdj[MAX][MAX], vector<vector<int>> &listAdj, int m){

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
void BFS(vector<vector<int>> &listAdj, int n){

    // * Estructuras Necesarias
    queue<int> fila;
    vector<bool> status(n, false);
    // * Valor que irá actualizando el frente de la fila
    int dato;

    for(int j = 0; j < n; j++){
        
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


}

void printMatAdj(bool matAdj[MAX][MAX], int n){

    for (int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << matAdj[i][j] << " ";
        }
        cout << endl;
    }
}

void printListAdj(vector<vector<int>> &listAdj){

    for(int i = 0; i < listAdj.size(); i++){

        cout << (i+1) << " ";
        
        for (int j = 0; j < listAdj[i].size(); j++){
            cout << " -> " << (listAdj[i][j] + 1);
        }
    cout << endl;
    }
}

int main(){

    //system("cls");
    //cout << "Run" << endl;

    bool matAdj[MAX][MAX];

    int n, m;

    // * n = cant de nodos (base - 1)
    // * m = cant de arcos

    cin >> n >> m;
    vector<vector<int>> listAdj(n);
    
    iniMatAdj(matAdj);
    loadGraph(matAdj, listAdj, m);
    /*
    cout << "Matriz" << endl;
    printMatAdj(matAdj, n);
    cout << "Lista" << endl;
    printListAdj(listAdj);

*/
    BFS(listAdj, n);

    
}
/*
0 1 0 0 0 0 0 0 
1 0 1 0 1 0 0 0
0 1 0 1 0 0 0 0
0 0 1 0 0 1 0 0
0 1 0 0 0 0 1 0
0 0 0 1 0 0 1 0
0 0 0 0 1 1 0 0
0 0 0 0 0 0 0 0
*/
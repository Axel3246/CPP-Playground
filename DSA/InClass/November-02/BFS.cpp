
// * BFS con matriz de adyacencia, Grafo No_Dirigido y No_Ponderado

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

#define MAX 10

void iniMatAdj(bool matAdj[MAX][MAX]){

    for(int i = 0; i < MAX; i++){

        for(int j = 0; j < MAX; j++){

            matAdj[i][j] = false;
        }
    }
}

void leeMatAdj(bool matAdj[MAX][MAX], int m){

    int a, b;

    for (int i = 0; i < m; i++){

        cin >> a >> b; // ? >> c
        // * Recordar que el usuario tiene como primer nodo al 1
        // * y en la matAdj el primer nodo es el nodo 0, por eso
        // * le rebajamos 1 a A y B
        
        matAdj[a-1][b-1] = matAdj[b-1][a-1] = true; // ? = c

    }
}

void printMatAdj(bool matAdj[MAX][MAX], int n){

    for (int i = 0; i < n; i++){

        for(int j = 0; j < n; j++){

            cout << matAdj[i][j] << " ";
        }
        cout << endl;
    }
}

// ? Complejidad: O(n^2)
void BFS(bool matAdj[MAX][MAX], int n){

    queue<int> fila;
    vector<bool> status(n, false);
    int dato;

    for(int i = 0; i < n; i++){

        if(!status[i]){ // * No ha sido visitado

            fila.push(i);
            status[i] = true;
            while(!fila.empty()){
                
                dato = fila.front();
                fila.pop();
                cout << (dato+1) << " ";
                // * Le sumamos 1 para mostrarlo como el usuario lo pide (base 1)

                // * Checar el renglon (Dato) en la matAdk con cada columna y si es true
                // * luego checo el status de esa columa par aver si no ha sido procesado
                // * para entonces meterlo a fila

                for (int j = 0; j < n; j++){

                    if(matAdj[dato][j] && !status[j]){

                        fila.push(j);
                        status[j] = true;
                    }
                }
            }
        }
    }
    cout << endl;
}

int main(){

    // * Matriz de adyacencias (base - 0) Renglon = Nodo_Origen, Columna = Nodo_Destino
    
    bool matAdj[MAX][MAX];
    int n, m;

    // * n = cant de nodos (base - 1)
    // * m = cant de arcos

    cin >> n >> m;  
    
    iniMatAdj(matAdj);
    leeMatAdj(matAdj,m);
    //printMatAdj(matAdj, n);

    BFS(matAdj, n);
    //printMatAdj(matAdj, n);
}

/*
Datos del Grafo1 solo falta agregar el nodo de arranque

n = cant de nodos (base - 1)
m = cant de arcos

/*
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
Resultado: 1 2 3 4 5 6 7 
------------------------
7 6
1 2
2 3  
2 5
3 4
4 6
5 7
Resultado: 1 2 3 5 4 7 6 
------------------------

9 9
1 7
1 2
2 3  
2 5
3 4
4 6
5 7
7 6
7 4
----------------

9 9
1 3
1 6
1 8
3 2
6 4
6 8
8 7
4 9
7 9


*/


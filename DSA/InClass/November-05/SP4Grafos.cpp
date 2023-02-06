#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct puertoSuez{

    string nombre;
    int numero;
};

// * Función que utiliza la búsqueda secuencial para obtener el # del puerto
// ? Complejidad: O(n)
int port2Int(vector<puertoSuez> vect, string dato){

    for(int i = 0; i < vect.size(); i++){

        if(vect[i].nombre == dato){ // * Compara el nombre

            return vect[i].numero; // * Regresa el index de ese nombre
        }
    }
    return -1;
}

// * Función para cargar los valores del Grafo la lista
// ? Complejidad: O(m)
void loadGraph(vector<vector<int>> &listAdj,vector<puertoSuez> &vect, int m, int n){

    string a, b;
    int c, d;

    for(int i = 0; i < m; i++){

        cin >> a >> b;
        // * Obteniendo el valor del puerto (posición)
        c = port2Int(vect,a);
        d = port2Int(vect,b);

        listAdj[c-1].push_back(d-1);
        listAdj[d-1].push_back(c-1);
        /*
        listAdj[port2Int(vect, a)-1].push_back(port2Int(vect,b)-1);
        listAdj[port2Int(vect, b)-1].push_back(port2Int(vect,a)-1);
        */
    }
}

// TODO: Encontrar la forma de hacer el recorrido
// * Funcion para el recorrido BFS con Lista de Adyacencia
// ? Complejidad: O(|V| + |E|)
int DFS(vector<vector<int>> &listAdj, vector<puertoSuez> vect, string queryStr, int sizePuertos, int MNP){

    stack<pair<int,int>> pila;
    vector<bool> status(listAdj.size(), false);
    int dato, cantVisitados = 0, contNivel = 0, dockNum;

    dockNum = port2Int(vect, queryStr) - 1;
    
    //for(int i = dockNum; i < listAdj.size() && cantVisitados != listAdj.size(); i++){
    //if(!status[dockNum]){ // * Puede omitrese
        pair<int,int> p1(dockNum, contNivel);
        pila.push(p1);
        
        while(!pila.empty()){ // && cont != MNP, esto va mas abajo

                // TODO: Mis ideas (no se guíen por esto, son puros pensamientos)
                // * 1. No podemos hacer true al nodo hasta llegar al cont = 3 (Maximo MNP)
                // * 2. Debemos saber una forma de contabilizar bien el MNP (size)
                // * 3. No podemos hacer pop, hasta llegar a MNP = 3
            dato = pila.top().first;
            
            if(!status[dato]){ // * Niveles (oye ya visité un nodo, pero ese nodo aun puede ir a otro nodo y cumplir MNP)
                status[dato] = true;
                cantVisitados++;
                sizePuertos--;
            }
            contNivel = pila.top().second + 1;
            
            pila.pop();

            if(contNivel <= MNP ){

                for(int j = listAdj[dato].size()-1; j >= 0; j--){

                        if(!status[listAdj[dato][j]]){
                            
                            pair<int,int> p2(listAdj[dato][j], contNivel);
                            pila.push(p2);
                        }
                    }
                }
        //    }
        }
    return(sizePuertos);
}

// * Función que imprime la listaAdj
// ? Complejidad: O( ) 
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

    // * Entrada de puertos
    // * n = cantidad de puertos (cantidad de nodos)
    // * m = cantidad de conexiones (cantidad de arcos)

    // * Variables para inicializar el programa
    int n, m, posPuerto = 0, NQ, MNP, sizePuertos, queryInt;
    string nombrePuerto, nombreQuerie;

    // * Obtención de N y M
    cout << " == Introduce n y m ==" << endl;
    cin >> n >> m;

    // * Vectores de struct para el # puerto y la listaAdj
    vector<puertoSuez> puertos;
    vector<vector<int>> listAdj(n);

    // * For para almacenar nombre y # de puerto en el vector de struct
    for(int i = 0; i < n; i++){

        puertoSuez registro;    
        cin >> nombrePuerto;
        registro.nombre = nombrePuerto;
        posPuerto++;
        registro.numero = posPuerto;
        puertos.push_back(registro);
    }

    // ? Creo que servirá mas delante en el stack
    sizePuertos = posPuerto + 1;

    // * Empezamos a llenar la lista de adyacencia
    loadGraph(listAdj, puertos, m, n);
    cout << endl;
    printListAdj(listAdj);
    cin >> NQ;
    
    for(int j = 0; j < NQ; j++){

        //cout << "Inserta el Puerto y el MNP: ";
        cin >>  nombreQuerie >> MNP;
        
        cout << "Case " << j+1 << ": "<< DFS(listAdj, puertos, nombreQuerie, sizePuertos, MNP) -1
        << " ports not reachable from port " << nombreQuerie << " with MNP = " << MNP << endl;
    }
}

/*
== Caso de Prueba de Ejemplo ==

Puerto      |  Num  

Alexandria      1 
Algeciras       2 
Ambarli         3
Antwerp         4
Balboa          5
Bandar          6
Barcelona       7
Bremen          8
Busan           9
Cai_Mep         10 
Callao          11
Cartagena       12 
Charleston      13

== Conexiones entre puertos ==

Travesía de Puertos   |   N-N

Alexandria Algeciras    (1 - 2)
Algeciras Ambarli       (2 - 3)
Ambarli Antwerp         (3 - 4)
Alexandria Balboa       (1 - 5)
Balboa Bandar           (5 - 6)
Bandar Barcelona        (6 - 7)
Antwerp Bremen          (4 - 8)
Bremen Busan            (8 - 9)
Algeciras Cai_Mep       (2 - 10)
Cai_Mep Callao          (10 - 11)
Ambarli Cartagena       (3 - 12)
Barcelona Callao        (7 - 11)
Cai_Mep Cartagena       (10 - 12)
Callao Charleston       (11 - 13)
Cartagena Charleston    (12 - 13)
Charleston Busan        (13 - 9)

== Lista de Adyacencia Esperada ==

1 -> 2 -> 5
2 -> 1 -> 3 -> 10
3 -> 2 -> 4 -> 12
4 -> 3 -> 8
5 -> 1 -> 6
6 -> 5 -> 7
7 -> 6 -> 11
8 -> 4 -> 9
9 -> 8 -> 13
10 -> 2 -> 11 -> 12
11 -> 10 -> 7 -> 13
12 -> 3 -> 10 -> 13
13 -> 11 -> 12 -> 9

Comprobada, sale igual...

== Caso de Prueba == 

13 16
Alexandria
Algeciras
Ambarli
Antwerp
Balboa
Bandar
Barcelona
Bremen
Busan
Cai_Mep
Callao
Cartagena
Charleston
Alexandria Algeciras
Algeciras Ambarli
Ambarli Antwerp
Alexandria Balboa
Balboa Bandar
Bandar Barcelona
Antwerp Bremen
Bremen Busan
Algeciras Cai_Mep
Cai_Mep Callao
Ambarli Cartagena
Barcelona Callao
Cai_Mep Cartagena
Callao Charleston
Cartagena Charleston
Charleston Busan
5         
Cai_Mep 2  
Cai_Mep 3 
*/
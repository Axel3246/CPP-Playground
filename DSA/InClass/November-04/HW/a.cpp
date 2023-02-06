#include <iostream>
#include <queue>
#include <vector>

using namespace std;

//  Funciones 
//  Indegree, cuantas arcos dirigidos estan apuntando a un nodo 
void loadGraph(int n, int m,vector<vector<int> > &listAdj, vector<int> &indegree){
  int a, b;
  for(int i=0; i<m; i++){
    cin >> a >> b;
    listAdj [a-1].push_back(b-1);
    indegree [b-1]++; 
  } 
}

vector<int> topologicalSort(int m, int n, vector<vector<int>> &listAdj, vector <int> indegree){
  queue<int> fila;
  vector<int> status;
  int dato;

  for(int i=0; i<n; i++){
    if(status[i] == 0){
      fila.push(i); //  Indegree de ceros 
    }
  }
  while(!fila.empty()){
    dato = fila.front();
    fila.pop();
    status.push_back(dato+1);   //  Sin el mas uno te va a poner cero 
    
    for(int j=0; j<listAdj[dato].size(); j++){
    
      if(indegree[j] > 0){
        indegree[j]--;
     
        if(indegree[j] == 0){
     
          fila.push(j);
        }
      }
    }
  }
  return status;
}

int main() {

    int n,m;
    cin >> n >> m;

    vector<vector<int>> listAdj(n);
    vector<int> indegree(n);
    
    loadGraph(n, m, listAdj, indegree);
    vector<int> statusFinal;
    statusFinal = topologicalSort(m, n, listAdj,indegree);
    for(int i=0; i<statusFinal.size(); i++){
      cout << "Status final: " << endl;
      cout << statusFinal[i] << endl;
    }
} 
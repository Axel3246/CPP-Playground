#include <iostream>
using namespace std;

int main(){

    //Declaración de Variables
    int matriz[100][100], renglones, columnas, mayor = -100000, reng = 0, colum = 0;
    cin >> renglones >> columnas;

    //Almacenando Elementos en la matriz
    for (int i = 0; i<renglones; i++){
        for (int j=0; j<columnas; j++)
            cin >> matriz[i][j];
    }

    //Mostrar la matriz, no aplica, solo quería saber si salía bien
    //for (int i = 0; i<renglones; i++){
      //  for (int j=0; j<columnas; j++){
        //    cout << matriz[i][j];
    //}
    //cout << endl;
    //}

    //Valor Maximo, Renglon y Fila con ciclo anidado
    for (int i = 0; i<renglones; i++){
        for (int j=0; j<columnas; j++)
            if(matriz[i][j] > mayor){
                mayor = matriz[i][j];
                reng = i;
                colum = j;
            }
    }        
        cout << mayor << " " << reng << " " << colum << endl; 

}
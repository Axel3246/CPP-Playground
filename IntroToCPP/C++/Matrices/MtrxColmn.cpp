#include <iostream>
using namespace std;

int main(){

    //Declaración de Variables
    int matriz[100][100], seleccion, renglones, columnas;
    cin >> renglones;
    cin >> columnas;
    cin >> seleccion;
    //Almacenando Elementos en la matriz
    for (int i = 0; i<renglones; i++){
        for (int j=0; j<columnas; j++)
            cin >> matriz[i][j];
    }

    //For para desplegar la columna deseada
    for (int i = 0; i<renglones; i++){
        cout << matriz[i][seleccion] << endl;
        
            }
    }        
        


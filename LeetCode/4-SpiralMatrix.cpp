
/* Given an m x n matrix, return all elements of the matrix in spiral order.*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

class Solution
{

public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        // * Variables que nos indicaran la direccion y posicion de los valores
        int m = matrix.size(), n = m ? matrix[0].size() : 0, techomtrx = 0, pisomtrx = m - 1, izqMtrx = 0, derMtrx = n - 1, indx = 0;

        // * Se crea una matriz en forma de vector
        vector<int> matriz(m * n);

        // * Traspasamos los datos de la matriz existente a la matriz que acabamos de crear
        while (techomtrx <= pisomtrx && izqMtrx <= derMtrx)
        {

            for (int column = izqMtrx; column <= derMtrx; column++)
            {

                matriz[indx++] = matrix[techomtrx][column];
            }
            // * Asegurando que no se rompan los limites de la matriz
            if (++techomtrx > pisomtrx)
            {

                break;
            }
            // * Recorriendo la primera fila de la matriz, asegurando que no se pase de la ultima fila
            for (int fila = techomtrx; fila <= pisomtrx; fila++)
            {
                // * Llenando los datos en la matriz creada
                matriz[indx++] = matrix[fila][derMtrx];
            }
            // * Cuando lleguemos al limite derecho cambiamos de direccion
            if (--derMtrx < 1)
            {
                break;
            }
            // * Ahora pasamos a la columna derecha, la cual deberia tomar el valor derecho de en medio
            for (int columna = derMtrx; columna >= izqMtrx; columna--)
            {
                matriz[indx++] = matrix[pisomtrx][columna];
            }
            // * Cambio de direccion
            if (--pisomtrx < techomtrx)
            {
                break;
            }
            for (int fila = pisomtrx; fila >= techomtrx; fila--)
            {
                matriz[indx++] = matrix[fila][izqMtrx];
            }
            if (izqMtrx++ > derMtrx)
            {
                break;
            }
        }
        return matriz;
    }
};
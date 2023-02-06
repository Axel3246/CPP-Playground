/*
There is a function signFunc(x) that returns:

1 if x is positive.
-1 if x is negative.
0 if x is equal to 0.
You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).
*/


#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    // Sube la info del array
    int arraySign(vector<int> &nums)
    {
        int contador;
        
        // * For que recorre el array
        for (int i = 0; i < nums.size(); i++)
        {
            // * Si el numero es 0 ya regresamos un 0
            if (nums[i] == 0)
            {

                return 0;
            }
            // * Si el numero es negativo agregamos uno al contador, pues el negativo sera el que decidira si es positivo
            else if (nums[i] < 0)
            {
                contador++;
            }
        }
        // * Si el contador de negativos dividido entre 2 da 0, quiere decir que se tuvieron una cantidad par de numeros negativos
        // * por lo que el resultante sera positivo
        return (contador % 2 == 0) ? 1 : -1;
    }
};
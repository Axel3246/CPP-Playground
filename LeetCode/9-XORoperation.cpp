/*
Given an integer n and an integer start.

Define an array nums where nums[i] = start + 2*i (0-indexed) and n == nums.length.

Return the bitwise XOR of all elements of nums.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int xorOperation(int n, int start)
    {
        // * Variable que nos contara todos los ^

        int valor = start;

        // * Loopearemos de 1 hasta n, pues valor ya tiene el valor de start (nums[0])
        for (int i = 1; i < n; i++)
        {
            // * Iremos usando la exponencial
            valor = valor ^ (start + 2*i);
        }
        // * Retornamos el valor obtenido del XOR
        return valor;
    }
        
};
#include <iostream>
using namespace std;

/*
Given a signed 32-bit integer x, return x with its digits reversed. 
If reversing x causes the value to go outside the signed 32-bit integer range 
[-231, 231 - 1], then return 0. 
*/

class Solution
{
public:
    int reverse(int x)
    {
        // *long mantiene la respuesta en 32 bits
        long respuesta = 0;
        // *encontraremos el reverso multiplicando respuesta por 10 y a eso sumarle el 
        // *modulo de x por cada iteraicon mientras x no sea igual a 0
        while (x != 0)
        {
            respuesta = respuesta * 10 + x % 10;
            x /= 10;
        }
        // *finalmente, regresamos la respuesta con un if simplificado, siendo si se excede
        // *las condiciones daremos 0, y si no, simplemente se pasa la respuesta.
        return (respuesta > INT_MAX or respuesta < INT_MIN) ? 0 : respuesta;
    }
};
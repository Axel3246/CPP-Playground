/*
You are working in a ball factory where you have n balls numbered from lowLimit up to highLimit inclusive (i.e., n == highLimit - lowLimit + 1), and an infinite number of boxes numbered from 1 to infinity.

Your job at this factory is to put each ball in the box with a number equal to the sum of digits of the ball's number. For example, the ball number 321 will be put in the box number 3 + 2 + 1 = 6 and the ball number 10 will be put in the box number 1 + 0 = 1.

Given two integers lowLimit and highLimit, return the number of balls in the box with the most balls.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    int countBalls(int lowLimit, int highLimit)
    {
        // * 45 cajas son lo maximo
        int boxes[46] = {};
        int sol = 1;
        for (int i = lowLimit; i <= highLimit; i++)
        {   
            // * Varables para el while loop por digito
            int sum = 0, num = i;
            // * While para usmar digito por digito
            while (num)
            {
                sum += num % 10;
                num /= 10;
            }   
            // * Se agrega el valor a la lista
            boxes[sum]++;
            // * Usamos una variable auxiliar para encontrar el maximo entre la auxiliar
            // * y el arreglo que guarda los valores
            sol = max(sol, boxes[sum]);
        }
        // * Retornamos la mayor cantidad de pelotas
        return sol;
    }
};
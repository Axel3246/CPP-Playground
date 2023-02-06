#include <iostream>

using namespace std;

class Solution
{
public:
    string longestDiverseString(int a, int b, int c)
    {
        int total = a + b + c; // * Suma total de a b c (longitud de string)
        int ocurrenciaA = 0, ocurrenciaB = 0, ocurrenciaC = 0;
        string hapStr = ""; // * Variable string que se formará
        while (total != 0) // * se ira evaluando cada que se cumpla, al menos, un if, disminuyendo el total
        {
            // * Cada if tendrá como objetivo validar cual letra (a b c) tiene la mayor ocurrencia, y dependiendo,
            // * empezará el string con esa letra, hasta que se convierta en 2 o se acabe la longitud de la letra
            // * por lo que se pasara a otro if, reevaluando las ocurrencias de los demas en 0

            if ((a >= b && a >= c && ocurrenciaA != 2) || (a > 0 && (ocurrenciaB == 2 || ocurrenciaC == 2)))
            {
                hapStr += 'a'; 
                a--; // * disminuimos la ocurrencia de la letra
                ocurrenciaA++;
                ocurrenciaB = ocurrenciaC = 0;
            }
            else if ((b >= a && b >= c && ocurrenciaB != 2) || (b > 0 && (ocurrenciaA == 2 || ocurrenciaC == 2)))
            {
                hapStr += 'b';
                b--;
                ocurrenciaB++;
                ocurrenciaA = ocurrenciaC = 0;
            }
            else if ((c >= a && c >= b && ocurrenciaC != 2) || (c > 0 && (ocurrenciaA == 2 || ocurrenciaB == 2)))
            {
                hapStr += 'c';
                c--;
                ocurrenciaC++;
                ocurrenciaA = ocurrenciaB = 0;
            }
            total--;
        }
        return hapStr;
    }
};
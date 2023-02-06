
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

// ? Complejidad: O(n)
int potenciaIterativa(int a, int b)
{
    int total = 1;
    for (int i = 1; i <= b; i++)
    {
        total *= a;
    }
    return total;
}

// ? Complejidad: O(n)
int potenciaRecursiva(int a, int b)
{
    if (b == 1)
    {
        return a;
    }
    
    return a * potenciaRecursiva(a, b-1);
}

int main()
{

    int x, y;
    cin >> x;
    cin >> y;

    cout << "Iterativo " << potenciaIterativa(x, y) << endl;
    cout << "Recursiva " << potenciaRecursiva(x, y) << endl;
}
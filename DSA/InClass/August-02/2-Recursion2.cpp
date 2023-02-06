
#include <iostream>
#include <vector>
using namespace std;

// ? Complejidad O(n)
int fibonacciIterativc(int n)
{
    int suma = n, act = 1, ant = 0;
    for (int i = 2; i <= n; i++){
        suma = ant + act;
        ant = act;
        act = suma;
    }
    return suma;
    
}

// ? Complejidad O(2^n)
// * Precondicion: n sea no-negativo
int fibonacciRecursivo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1)
    {
        return 1;
    }
    else
    {
        return fibonacciRecursivo(n-1) + fibonacciRecursivo(n-2);
    }
}

int main()
{
    int n;
    cin >> n;

    cout << "Iterativo " << fibonacciIterativc(n) << endl;
    cout << "Iterativo " << fibonacciRecursivo(n) << endl;
}
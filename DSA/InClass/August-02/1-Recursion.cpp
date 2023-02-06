
#include <iostream>

using namespace std;

// ? Complejidad: O(n)
long long factorialIterativo(int n)
{
    long long acum = 1;

    for (int i = 1; i <= n; i++)
    {
        acum *= i;
    }
    return acum;
}

// ? Complejidad: O(n)
long long factoralRecursivo(int n)
{

    if (n == 0)
    {
        return 1;
    }
    else
    {
        return (n * (factoralRecursivo(n - 1)));
    }
}

int main()
{
    system("cls");
    int n;
    cin >> n;

    cout << "\t.:Factorial Iterativo:." << factorialIterativo(n) << endl;

    cout << "\t.:Factorial Recursivo:." << factoralRecursivo(n) << endl;
}
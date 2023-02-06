#include <iostream>

using namespace std;

int sumaIterativa(int arr[], int n)
{

    int suma = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] % 2 == 1)
        {
            suma += arr[i];
        }
    }
    return suma;
}

int sumaRecursiva(int arr[], int n)
{

    if (n == 1)
    {
        return (arr[0] % 2 == 1) ? arr[0] : 0;
    }

    return ((arr[n-1] % 2 == 1) ? arr[n - 1] : 0) + sumaRecursiva(arr, n - 1);
    //return (arr[n-1] % 2 == 1) ? arr[n-1] : 0 + sumaRecursiva(arr, n-1) ;
}

int main()
{
    int array1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = 10;

    cout << "Iterativa: " << sumaIterativa(array1, n) << endl;
    cout << "Recursiva: " << sumaRecursiva(array1, n) << endl;
}
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main()
{

    queue<int> fila;
    stack<int> pila;

    priority_queue<int> pq1;                            // * Prioridad al valor mayor
    priority_queue<int, vector<int>, greater<int>> pq2; // * Prioridad al valor menor

    int n, dato;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> dato;
        fila.push(dato);
        pila.push(dato);
        pq1.push(dato);
        pq2.push(dato);
    }

    cout << endl;
    cout << "Fila (queue) tiene " << fila.size() << " elementos: ";

    while (!fila.empty())
    {
        cout << fila.front() << " "; // *Observa el frente de la pila
        fila.pop();                  // * saca el elemento del frente de la pila
    }

    cout << endl
         << "Pila (stack) tiene " << pila.size() << " elementos: ";

    while (!pila.empty())
    {
        cout << pila.top() << " "; // * observa el tope de la pila
        pila.pop();                // * solamente saca, no observa
    }

    cout << endl;
    cout << "pq 1 tiene " << pq1.size() << " elementos: ";

    while (!pq1.empty())
    {
        cout << pq1.top() << " "; // * Observa el frente de la priority queue
        pq1.pop();                // * Saca el elemento de mayor prioridad
    }

    cout << endl;
    cout << "pq 2 tiene " << pq2.size() << " elementos: ";

    while (!pq2.empty())
    {
        cout << pq2.top() << " "; // * Observa el frente de la priority queue
        pq2.pop();                // * Saca el elemento de mayor prioridad
    }
}

/*
5
100
50
75
120
95

queue: pop, push, front, empty y size: O(1)

stackL pop, push, top, empty y size: O(1)

priority_queue: top, empty, size: O(1); pop y push: O(log(n))

*/
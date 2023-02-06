//TODO: Hacer un programa en C++ utilizando queues que contenga el siguiente menu:
//TODO: 1. Insertar un caracter a cola, 2. Mostrar elementos de la cola, 3. Salir.

#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Node // !Las queue utilizan nodos para apuntar a los elementos siguientes, constan de:
{
    char data;  // !Un dato
    Node *next; // !Un apuntador
};

//* Functions to add data to a queue

bool empty_queue(Node *frente)
{
    return (frente == NULL) ? true : false; // ?One liner
}

void addQueue(Node *&frente, Node *&fin, char n)
{
    Node *new_node = new Node(); //!P1: Reservar espacio de memoria
    new_node->data = n;          //!P2: Igualamos al campo de data al parametro
    new_node->next = NULL;       //!P2: Igualamos el siguiente nodo a NULL

    if (empty_queue(frente)) //!P3: Saber si la cola esta vacía o no
    {
        frente = new_node;
    }
    else
    {
        fin->next = new_node;
    }
    fin = new_node;

    cout << "\nEl elemento " << n << " se ha insertado en la queue" << endl;
}

//* Funcion para determinar si la cola esta vacia

void removeQueue(Node *&frente, Node *&fin, char &n)
{
    n = frente->data;   //!P1: Obtener el valor del nodo
    Node *aux = frente; //!P2: Crear un nodo auxiliar

    if (frente == fin)
    { //!P3: Determinar la cantidad de nodos
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->next;
    }
    delete aux;
}

int main()
{
    Node *frente = NULL;
    Node *fin = NULL;

    int opcion;
    char caracter;
    do
    {
        cout << endl;
        cout << "\t.:Opciones:." << endl;
        cout << "1. Agregar caracteres" << endl;
        cout << "2. Mostrar caracteres" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion -> ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cout << "Caracter: ";
            cin >> caracter;
            addQueue(frente, fin, caracter);
            break;
        case 2:
            while (frente != NULL)
            {
                removeQueue(frente, fin, caracter);
                if (frente != NULL)
                {
                    cout << caracter;
                }
                else
                {
                    cout << caracter;
                }
            }
            break;
        case 3:
            break;
        }
    } while (opcion != 3);
}
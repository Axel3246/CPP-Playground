//!Concepto de Queues
//!El primero en entrar es el primero en salir.
// ? IN : MAC , OUT: MAC.

#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Node // !Los stack utilizan nodos para apuntar a los elementos siguientes, constan de:
{
    int data;   // !Un dato
    Node *next; // !Un apuntador
};

//* Functions to add data to a queue

void addQueue(Node *&frente, Node *&fin, int n)
{
    Node *new_node = new Node(); //!P1: Reservar espacio de memoria
    new_node->data = n;          //!P2: Igualamos al campo de data al parametro
    new_node->next = NULL;       //!P2: Igualamos el siguiente nodo a NULL

    if (empty_queue(frente))
    {
        frente = new_node;
    }
    else
    {
        fin->next = new_node;
    }
    fin = new_node;
}

bool empty_queue(Node *frente)
{

    return (frente == NULL) ? true : false; // ?One liner
}

//* Function to delete data from a queue

void removeQueue(Node *&frente, Node *&fin, int &n){
    n = frente->data; //!P1: Obtener el valor del nodo
    Node *aux = frente; //!P2: Crear un nodo auxiliar

    if (frente == fin){ //!P3: Determinar la cantidad de nodos
        frente = NULL;
        fin = NULL;
    }
    else{
        frente = frente->next;
    }
    delete aux;
}

//* Display a queue's data

void mostrar(Node *frente, Node *fin, int &n)
{
    cout << "\n\n\tFrente==>Fin :: Los datos almacenados en la cola son: \n";
    int i = 0;
    while (frente != NULL)
    {
        i++;
        n = frente->data;
        frente = frente->next;
        cout << "\tDato[" << i << "]: " << n << endl;
    }
    cout << endl;
    i = 0;
}
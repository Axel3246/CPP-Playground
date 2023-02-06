#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Node // !Las queue utilizan nodos para apuntar a los elementos siguientes, constan de:
{
    int data;   // !Un dato
    Node *next; // !Un apuntador
};

//* Functions to add data to a queue

bool empty_queue(Node *frente)
{

    return (frente == NULL) ? true : false; // ?One liner
    /*
    if(frente == NULL){ //! Si frente == NULL, la cola esta vacía
        return true;
    }
    else{  //! Si frente != NULL, la cola no esta vacia
        return false; 
    }
    */
}

void addQueue(Node *&frente, Node *&fin, int n)
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

int main()
{

    Node *frente = NULL;
    Node *fin = NULL;

    int dato;

    cout << "Numero: ";
    cin >> dato;
    addQueue(frente, fin, dato);
    cout << "Numero: ";
    cin >> dato;
    addQueue(frente, fin, dato);
}
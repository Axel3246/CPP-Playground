
#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Node
{
    int data;   // !Un dato
    Node *next; // !Un apuntador
};

void addList(Node *&lista, int n)
{
    Node *nuevo_node = new Node();
    nuevo_node->data = n;
    Node *aux1 = lista; //! aux1 empieza en NULL como lista
    Node *aux2;
    // *Insertar elementos a la lista
    while ((aux1 != NULL) && (aux1->data < n)) //!ELEMENTOS DE FORMA ORDENADA EL SEGUNDO CONDICIONAL. Si no se requiere se elimina y no se usa aux 2
    {
        aux2 = aux1;
        aux1 = aux1->next;
    }
    if (lista == aux1) //!Elemento al inicio de la lista (principio)
    { 
        lista = nuevo_node;
    }
    else //!Se entra al while
    {
        aux2->next = nuevo_node;
    }
    nuevo_node->next = aux1;
    cout << "Elemento " << n << " agregado." << endl;
}

int main()
{
    Node *lista = NULL;

    int dato;
    cout << "Numero: "; cin >> dato;
    addList(lista, dato);
    cout << "Numero: "; cin >> dato;
    addList(lista, dato);
    cout << "Numero: "; cin >> dato;
    addList(lista, dato);
}
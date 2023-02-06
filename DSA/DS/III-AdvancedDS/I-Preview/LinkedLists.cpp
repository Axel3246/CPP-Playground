//!Concepto de Linked List

#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Node // !Las linked list tambien utilizan nodos para apuntar a los elementos siguientes, constan de:
{
    int data;   // !Un dato
    Node *next; // !Un apuntador
};

// *Function to add a List (sorted)

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

// *Funtion to add a list (unsorted), could be wrong

void addList(Node *&lista, int n)
{
    Node *nuevo_node = new Node();
    nuevo_node->data = n;
    Node *aux1 = lista; //! aux1 empieza en NULL como lista
    // *Insertar elementos a la lista
    if (lista == aux1) //!Elemento al inicio de la lista (principio)
    {
        lista = nuevo_node;
    }
    nuevo_node->next = aux1;
    cout << "Elemento " << n << " agregado." << endl;
}

// *Funtion to show list

void showList(Node *lista)
{
    Node *actual_node = new Node();
    actual_node = lista;
    while (actual_node != NULL) // !Mientras el nodo no sea NULL, aun habrá elementos en la lista
    {
        cout << actual_node->data;
        actual_node = actual_node->next;
    }
}

// *Function to search an element (sorted)

void searchList(Node *lista, int esearch)
{
    bool elementFound = false;
    int i = 0;

    while ((lista != NULL) && (lista->data <= esearch)) //!La segunda condicion solo sirve si la lista está ordenada
    {
        if (lista->data == esearch)
        {
            elementFound = true;
        }
        lista = lista->next;
        i++;
    }

    if (elementFound == true)
    {
        cout << "Se encontró el elemento " << esearch << " en la iteración " << i << endl;
    }
    else
    {
        cout << "No se encontró el elemento " << esearch << " en la lista" << endl;
    }
}

// *Function to search an element (unsorted)

void searchList(Node *lista, int esearch)
{
    bool elementFound = false;
    int i = 0;

    while ((lista != NULL))
    {
        if (lista->data == esearch)
        {
            elementFound = true;
        }
        lista = lista->next;
        i++;
    }

    if (elementFound == true)
    {
        cout << "Se encontró el elemento " << esearch << " en la iteración " << i << endl;
    }
    else
    {
        cout << "No se encontró el elemento " << esearch << " en la lista" << endl;
    }
}

// *Function to delete an element (ONLY ONE - FIRST ELEMENT FOUND (DOESN'T CHECK FOR DUPES))

void dListElement(Node *&lista, int esearch)
{
    if (lista != NULL)
    { // !Verificacion de lista (no) vacia
        //!Punteros Esenciales
        Node *aux_delete;
        Node *anterior = NULL;
        //!Igualacion del puntero auxiliar para el recorrido de la lista
        aux_delete = lista;
        //!Recorrer la lista
        while ((aux_delete != NULL) && (aux_delete->data != esearch))
        {
            anterior = aux_delete;
            aux_delete = aux_delete->next;
        }

        if (aux_delete == NULL)
        { // !Elemento no encontrado
            cout << "El elemento no existe" << endl;
        }
        else if (anterior == NULL)
        { // !Element encontrado en el Primer Nodo
            lista = lista->next;
            delete aux_delete;
        }
        else
        { // !Elemento en la lista, pero no el primer Nodo
            anterior->next = aux_delete->next;
            delete aux_delete;
        }
    }
}

// *Function to delete Linked List (All of it)

void deleteLinkedList(Node *&lista, int &delement)
{
    //!P1: Crear un nodo auxiliar e igualarlo a lista
    Node *aux = lista;
    //!P2: Definir el valor al nodo auxiliar
    delement = aux->data;
    //!P3: Pasar lista al siguiente nodo
    lista = aux->next;
    //!P4: Eliminar aux
    delete aux;
}
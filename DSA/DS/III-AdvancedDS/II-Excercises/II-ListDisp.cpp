
#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Node
{
    int data;   // !Un dato
    Node *next; // !Un apuntador
};

Node *lista = NULL; //!Variable Global

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
    cout << "Elemento " << n << " agregado.";
   
}

void showList(Node *lista)
{
    Node *actual_node = new Node();
    actual_node = lista;
    while (actual_node != NULL) // !Mientras el nodo no sea NULL, aun habrá elementos en la lista
    {
        cout << actual_node->data << "->";
        actual_node = actual_node->next;
    }
}

void menu()
{
    // *Var
    int opcion, dato;

    do
    {
        cout << endl;
        cout << "\t.:Menu:." << endl;
        cout << "1. Agregar Elemento" << endl;
        cout << "2. Mostrar Lista" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion -> ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            int dato;
            cout << "Numero: ";
            cin >> dato;
            addList(lista, dato);
            break;

        case 2:

            showList(lista);
            cout << endl;
            break;

        case 3:
            break;
        }
    } while (opcion != 3);
}

int main()
{
    //? Node *lista = NULL;
    menu();
}
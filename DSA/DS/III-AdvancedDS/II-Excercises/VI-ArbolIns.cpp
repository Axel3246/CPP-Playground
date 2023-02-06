//!Concepto de Arbol Binario

#include <iostream>
#include <string.h>

using namespace std;

// *Node Structure for a Binary Tree

struct Node
{
    int data;  // !Un dato
    Node *der; // !Un apuntador al hijo der (si hay)
    Node *izq; // !Un apuntador al hijo izq (si hay)
};

// *Creacion de nodo para arbol binario

Node *createNode(int n)
{
    Node *new_node = new Node();

    new_node->data = n;
    new_node->der = NULL;
    new_node->izq = NULL;

    return new_node;
}

// *Prototipos

void menu();
void insert(Node *&arbol, int n);
Node *arbol = NULL; //! Variabe

int main()
{
    menu();
}

void menu()
{
    int opcion, dato;
    do
    {
        cout << endl;
        cout << "\t.:Menu:." << endl;
        cout << "1. Agregar Nodo" << endl;
        cout << "2. Salir" << endl;
        cout << "Opcion -> ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:

            int dato;
            cout << "Numero: ";
            cin >> dato;
            insert(arbol, dato);
            break;

        case 2:
            break;
        }
    } while (opcion != 2);
}

// !Funcion para insertar un nodo al arbol
// ! El arbol puede estar vacio o con nodos

void insert(Node *&arbol, int n)
{

    if (arbol == NULL)
    {
        Node *new_node = createNode(n);
        arbol = new_node;
    }
    else
    {
        int nodeVal = arbol->data; //!Obtenemos el valor de la raiz del arbol
        if (n < nodeVal)
        {
            insert(arbol->izq, n); // !Si n es menor a la raiz lo acomodamos a la izquierda
        }
        else
        {
            insert(arbol->der, n); // !Si n es mayor a la raiz lo acomodamos a la derecha
        }
    }
    
}
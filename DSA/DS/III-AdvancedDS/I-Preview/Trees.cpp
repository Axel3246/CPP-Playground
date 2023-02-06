//!Concepto de Arbol Binario

#include <iostream>
#include <string.h>

using namespace std;

// *Node Structure for a Binary Tree

struct Node 
{
    int data;   // !Un dato
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

// *Funcion para insertar un nodo al arbol
// *El arbol puede estar vacio o con nodos

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

// *Funcion para mostrar un arbol binario

void showTree(Node *arbol, int contador)
{

    //!Si el arbol esta vacio

    if (arbol == NULL)
    {
        return;
    }
    else
    {
        showTree(arbol->der, contador + 1); //*Se empieza con el lado derecho del arbol
        for (int i = 0; i < contador; i++)  //*Separacion de caracteres
            cout << "   ";
    }
    cout << arbol->data << endl; // *Impresion del dato del nodo
    showTree(arbol->izq, contador + 1);//*Ahora es el turno de imprimir el lado izquierdo del arbol
}

//*Funcion para buscar un elemento en el arbol binario

bool searchNode(Node *arbol, int n)
{

    //!Si el arbol esta vacio (Caso 1)
    if (arbol == NULL)
    {
        return false; // *El elemento no ha sido encontrado
    }
    else if (arbol->data == n)
    { //*Si encontramos el elemento (en la raiz)
        return true;
    }
    else if (n < arbol->data)
    {
        return searchNode(arbol->izq, n); //*Dependiendo del numero a buscar, nos inclinaremos hacia ese lado del arbol
    }
    else
    {
        return searchNode(arbol->der, n); //*Dependiendo del numero a buscar, nos inclinaremos hacia ese lado del arbol
    }
}

// *Funcion para recorrido en PreOrden (direccion y por subramas)

void preOrden(Node *arbol)
{

    //*Se debe conoer si el arbol esta vacio, para eso sirve este primer condicional
    if (arbol == NULL)
    {
        return;
    }
    else
    { //*Este else indica que el arbol no esta vacio
        cout << arbol->data;
        preOrden(arbol->izq); //?RECORRE EL LADO IZQUIERDO
        preOrden(arbol->der); //?RECORRE EL LADO DERECHO
    }
}

//!Concepto de Stack
//!Tener un espacio de memoria, uno dentro de otro. El ultimo en entrar es el primero en salir. 
// ? IN : MAC , OUT: CAM.

#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Node // !Los stack utilizan nodos para apuntar a los elementos siguientes, constan de:
{
    int data; // !Un dato
    Node *next; // !Un apuntador

};

// *Function to add Stack

void addStack(Node *&stack, int dato) // *Se pasa el apuntador y el dato para el nodo
{                                // *Función protoripo para agregar un nuevo nodo
    Node *new_node = new Node(); //!P1: Reservar el espacio de memoria
    new_node->data = dato;       //!P2: Rellenar el dato
    new_node->next = stack;      //!P3: Llenar el apuntador
    stack = new_node;            //!P4: Cambiar el valor del apuntado
}

// *Function to deleteStack

void deleteStack(Node *&stack, int &dato) // *Se pasa el apuntador y el dato por referencia
{
    Node *aux = stack; //!P1: Crear una variable auxiliar de apuntador tipo Nodo
    dato = aux->data;  //!P2: Hacer que la variable apunte al dato del nodo
    stack = aux->next; //!P3: Hacer que el apuntador original recorra al nodo siguiente
    delete aux;        //!P4: Eliminar la variable auxiliar, por lo tanto, el nodo
}
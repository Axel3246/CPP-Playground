#include <iostream>
#include <string.h>

using namespace std;

struct Node
{
    int data;   // !dato
    Node *next; // !apuntador
};

// *Función  para agregar un nuevo nodo (con elementos)
void addStack(Node *&stack, int dato) // *Se pasa el apuntador y el dato para el nodo
{
    Node *new_node = new Node(); //!P1: Reservar el espacio de memoria
    new_node->data = dato;       //!P2: Rellenar el dato
    new_node->next = stack;      //!P3: Llenar el apuntador
    stack = new_node;            //!P4: Cambiar el valor del apuntado

    cout << "\nElemento " << dato << " agregado al stack." << endl;
}

// *Función  para eliminar un nodo
void deleteStack(Node *&stack, int &dato) // *Se pasa el apuntador y el dato por referencia
{
    Node *aux = stack; //!P1: Crear una variable auxiliar de apuntador tipo Nodo
    dato = aux->data;  //!P2: Hacer que la variable apunte al dato del nodo
    stack = aux->next; //!P3: Hacer que el apuntador original recorra al nodo siguiente
    delete aux;        //!P4: Eliminar la variable auxiliar, por lo tanto, el nodo
}
    
int main()
{

    Node *stack = NULL; //!Inicializando una variable NULL (fondo del stack)
    int dato;

    cout << "Digite un numero: ";
    cin >> dato;
    addStack(stack, dato); // *Llamando a la función addStack

    cout << "\nDigite otro numero: ";
    cin >> dato;
    addStack(stack, dato); // *Llamando a la función addStack

    cout << "\nEliminando los elementos del stack" << endl;

    while (stack != NULL)//!Mientras no se acabe el stack (hay mas elementos)
    { 
        deleteStack(stack, dato);
        if (stack != NULL) //!Mientras stack no sea NULL ve imprimiendo
        {
            cout << dato << ", ";
        }
        else{ //!Si stack es NULL imprime el ultimo dato
            cout << dato << ".";
        }
    }
}

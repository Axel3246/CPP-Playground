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

int main()
{

    Node *stack = NULL; //!Inicializando una variable NULL (fondo del stack)
    int n1, n2;

    cout << "Digite un numero: "; cin >> n1;
    addStack(stack, n1); // *Llamando a la función addStack

    cout << "\nDigite otro numero: "; cin >> n2;
    addStack(stack, n2); // *Llamando a la función addStack

}

//TODO: Ejercicio 2: Hacer un programa en C++, utilizando Pilas que contenga el siguiente menu:

//TODO: 1. Insertar un caracter a la pila, 2. Mostrar todos los elementos de la pila, 3. Salir

#include <iostream>
#include <string.h>

using namespace std;

//!Node struct
struct Node
{
    char caracter;
    Node *next;
};

//!Funcion para agregar stacks
void addStack(Node *&stack, char car)
{
    Node *new_node = new Node();
    new_node->caracter = car;
    new_node->next = stack;
    stack = new_node;

    cout << "Se ha agregado " << car << endl;
    cout << endl;
}

//!Funcion para quitar stacks
void deleteStack(Node *&stack, char &car)
{
    Node *aux = stack;
    car = aux->caracter;
    stack = aux->next;
    delete aux;
}

int main()
{
    Node *stack = NULL;
    int op;
    char caracter;

    do
    {
        cout << endl;
        cout << "1. Insertar caracter al Stack" << endl;
        cout << "2. Mostrar los elementos del Stack" << endl;
        cout << "3. Salir" << endl;

        cout << "Opcion: ";
        cin >> op;

        switch (op)
        {
        case 1: // !Agregar datos

            cout << "Caracter a agregar: ";
            cin >> caracter;
            addStack(stack, caracter);
            break;

        case 2: // !Eliminar stack (mostrar datos)

            while (stack != NULL)
            {
                deleteStack(stack, caracter);
                if (stack != NULL)
                {
                    cout << caracter;
                }
                else
                {
                    cout << caracter;
                }
            }
            break;

        case 3:

            break;
        }
    } while (op != 3);
}
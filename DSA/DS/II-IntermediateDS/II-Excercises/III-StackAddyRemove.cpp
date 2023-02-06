//TODO: Ejercicio 1: Hacer un programa para agregar números enteros a una pila, hasta que el usuario lo decida,
//TODO: después mostrar todos los números introducidos en la pila.

#include <iostream>
#include <string.h>

using namespace std;

//!Node struct
struct Node
{
    int number;
    Node *next;
};

//!Funcion para agregar stacks
void addStack(Node *&stack, int num)
{
    Node *new_node = new Node();
    new_node->number = num;
    new_node->next = stack;
    stack = new_node;

    cout << "\tEl numero " << num << " se ha agregado.";
}

//!Funcion para quitar stacks
void deleteStack(Node *&stack, int &num)
{
    Node *aux = stack;
    num = aux->number;
    stack = aux->next;
    delete aux;
}

int main()
{
    Node *stack = NULL;
    int numero;
    char opcion;

    // !Do while para iterar hasta que el usuario lo decida
    do{
        cout << "Introduzca un número entero: "; cin >> numero;
        addStack(stack, numero);
        cout << "\n¿Seguir? (s/n): "; cin >> opcion;

    }while(opcion == 'S' || opcion == 's');

    cout << "\nSacando los elementos de la pila" << endl;

    while(stack != NULL){ // !Mientras no sea el final del Stack
        deleteStack(stack,numero);
        if (stack != NULL){
            cout << numero;
        }
        else{
            cout << numero;
        }
    }   
}
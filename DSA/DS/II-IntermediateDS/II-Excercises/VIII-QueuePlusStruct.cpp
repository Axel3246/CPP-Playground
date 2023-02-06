// TODO: Ejercicio 2: Hacer un programa que guarde datos de clientes de un banco,
// TODO: los almacene en cola, y por ultimo muestre los clientes en el orden correcto.*/

#include <iostream>
#include <string.h>

using namespace std;

// *Structure for Node

struct Cliente
{
    char nombre[40];
    char tarjeta[40];
    int edad;
};
struct Node // !Las queue utilizan nodos para apuntar a los elementos siguientes, constan de:
{
    Cliente c;  // !Un dato
    Node *next; // !Un apuntador
};
bool empty_queue(Node *frente)
{
    return (frente == NULL) ? true : false; // ?One liner
}
void addQueue(Node *&frente, Node *&fin, Cliente n)
{
    Node *new_node = new Node(); //!P1: Reservar espacio de memoria
    new_node->c = n;             //!P2: Igualamos al campo de data al parametro
    new_node->next = NULL;       //!P2: Igualamos el siguiente nodo a NULL

    if (empty_queue(frente)) //!P3: Saber si la cola esta vacía o no
    {
        frente = new_node;
    }
    else
    {
        fin->next = new_node;
    }
    fin = new_node;
}
void removeQueue(Node *&frente, Node *&fin, Cliente &n)
{
    n = frente->c;      //!P1: Obtener el valor del nodo
    Node *aux = frente; //!P2: Crear un nodo auxiliar

    if (frente == fin)
    { //!P3: Determinar la cantidad de nodos
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->next;
    }
    delete aux;
}

int main()
{
    // *Apuntadores
    Node *frente = NULL;
    Node *fin = NULL;

    Cliente c;
    int op;

    do
    {
        cout << endl;
        cout << "\t.:Opciones:." << endl;
        cout << "1. Agregar cuentas" << endl;
        cout << "2. Mostrar cuentas" << endl;
        cout << "3. Salir" << endl;
        cout << "Opcion -> ";
        cin >> op;
        cin.ignore(256, '\n');
        switch (op)
        {
        case 1:

            cout << "Nombre: ";
            cin.getline(c.nombre, 40, '\n');
            cout << "Tarjeta: ";
            cin.getline(c.tarjeta, 40, '\n');
            cout << "Edad: ";
            cin >> c.edad;
            addQueue(frente, fin, c);
            break;

        case 2:
            while (frente != NULL)
            {
                removeQueue(frente, fin, c);

                cout << "Nombre: " << c.nombre << endl;
                cout << "Tarjeta: " << c.tarjeta << endl;
                cout << "Edad: " << c.edad << endl;
                cout << '\n';
            }
            break;
        case 3:
            break;
        }

    } while (op != 3);
}
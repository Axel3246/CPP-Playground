
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

// *Funtions
void addList(Node *&lista, int n);
void showList(Node *lista);
void searchList(Node *lista);
void deleteListElement(Node *lista, int esearch);
void menu();

int main()
{
    menu();
}

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
        cout << "3. Buscar en Lista" << endl;
        cout << "4. Eliminar en Lista" << endl;
        cout << "5. Salir" << endl;
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

            cout << "Dato a buscar: ";
            cin >> dato;
            searchList(lista, dato);
            break;

        case 4:
            cout << "Dato a eliminar: ";
            cin >> dato;
            dListElement(lista, dato);
            break;

        case 5:
            break;
        }
    } while (opcion != 5);
}
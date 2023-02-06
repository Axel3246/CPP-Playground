
#include <iostream>
#include <string.h>

using namespace std;

//* El recorrido PreOrden, recorre un arbol desde la raiz, siguiendo despues la rama izquierda y, finalmente, la derecha
//* Para eso, hay que utilizar la recursividad en cada nodo, empezando desde la raiz

//TODO: 1. Visitar la raiz
//TODO: 2. Atravesar el la rama izquierda (toda la subrama)
//TODO: 3. Atravesar la rama derecha (toda la subrama)

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
void showTree(Node *arbol, int contador);
bool searchNode(Node *arbol, int n);
void preOrden(Node *arbol);
Node *arbol = NULL; //! Variabe

int main()
{
    menu();
}

void menu()
{
    int opcion, dato, contador = 0;
    do
    {
        cout << endl;
        cout << "\t.:Menu:." << endl;
        cout << "1. Agregar Nodo" << endl;
        cout << "2. Mostrar Arbol" << endl;
        cout << "3. Buscar Elemento" << endl;
        cout << "4. Recorrer en PreOrden" << endl;
        cout << "5. Salir" << endl;
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
            cout << endl;
            showTree(arbol, contador);
            break;

        case 3:

            cout << "Elemento a buscar: ";
            cin >> dato;
            if (searchNode(arbol, dato) == true)
            {
                cout << "El elemento " << dato << " ha sido encontrado." << endl;
            }
            else
            {
                cout << "El elemento " << dato << " no ha sido encontrado." << endl;
            }
            break;

        case 4:

            cout << endl;
            preOrden(arbol);
            break;
        }

    } while (opcion != 5);
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

// !Funcion para mostrar el arbol

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
    cout << arbol->data << endl;        // *Impresion del dato del nodo
    showTree(arbol->izq, contador + 1); //*Ahora es el turno de imprimir el lado izquierdo del arbol
}

// !Funcion para buscar un nodo en el arbol

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

//! Funcion para recorrido pre orden (por direccion y subraices)

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

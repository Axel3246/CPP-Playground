
#include <iostream>
#include <string.h>

using namespace std;

//* Para eliminar un Nodo,  es recomendable que cada nodo recuerde quien es su padre, para esto, debemos modificar el programa

// *Node Structure for a Binary Tree

struct Node
{
    int data;
    Node *der;
    Node *izq;
    Node *padre; //! Esta linea nos guardara el nodo padre de cada nodo
};

//*Prototipos

void menu();
Node *createNode(int n, Node *padre);          //! A esta funcion le pasaremos ahora, como extra, el nodo padre
void insert(Node *&arbol, int n, Node *padre); //!A esta funcion tambien se debe de pasarle el nodo padre
void showTree(Node *arbol, int contador);
bool searchNode(Node *arbol, int n);
void preOrden(Node *arbol);
void inOrden(Node *arbol);
void postOrden(Node *arbol);
void eliminate(Node *arbol, int n);            // !Funcion para recorrer el arbol y encontrar el nodo
void eliminateNode(Node *n_delete);            // !Funcion para eliminar el nodo
Node *minimo(Node *arbol);                     // !Funcion para encontrar el minimo a la hora de eliminar un nodo
void reemplazar(Node *arbol, Node *nuevoNodo); // !Funcion para reemplazar el nodo cuando solo se tiene un solo hijo
void destruirNode(Node *node);                 // !Funcion para quitar un nodo en caso de que solo tenga un hijo y se quiera eliminar
Node *arbol = NULL;

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
        cout << "5. Recorrer en InOrden" << endl;
        cout << "6. Recorrer en PostOrden" << endl;
        cout << "7. Eliminar un Nodo" << endl;
        cout << "8. Salir" << endl;
        cout << "Opcion -> ";
        cin >> opcion;

        switch (opcion)
        {

        case 1:

            int dato;
            cout << "Numero: ";
            cin >> dato;
            insert(arbol, dato, NULL); // ?Como no sabemos quien es el padre, simplemente ponemos NULL
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

        case 5:

            cout << endl;
            inOrden(arbol);
            break;

        case 6:

            cout << endl;
            postOrden(arbol);
            break;

        case 7:

            cout << "Digite el nodo a eliminar: ";
            cin >> dato;
            eliminate(arbol, dato);
            break;
        }

    } while (opcion != 8);
}

Node *createNode(int n, Node *padre) //! Asi quedaria la funcion para crear un nuevo nodo
{
    Node *new_node = new Node();

    new_node->data = n;
    new_node->der = NULL;
    new_node->izq = NULL;
    new_node->padre = padre; //!Le asignamos el padre al nuevo nodo creado

    return new_node;
}

// !Funcion para insertar un nodo al arbol
// ! El arbol puede estar vacio o con nodos

void insert(Node *&arbol, int n, Node *padre)
{

    if (arbol == NULL)
    {
        Node *new_node = createNode(n, padre); //! Indicamos quien es el padre del nuevo nodo creado
        arbol = new_node;
    }
    else
    {
        int nodeVal = arbol->data; //!Obtenemos el valor de la raiz del arbol
        if (n < nodeVal)
        {
            insert(arbol->izq, n, arbol); // !Si n es menor a la raiz lo acomodamos a la izquierda, indicamos quien es el padre
        }
        else
        {
            insert(arbol->der, n, arbol); // !Si n es mayor a la raiz lo acomodamos a la derecha, indicamos quien es el padre
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

// !Funcion para recorrido en profundidad - InOrden

void inOrden(Node *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        inOrden(arbol->izq);
        cout << arbol->data;
        inOrden(arbol->der);
    }
}

//! Funcion para recorrido en profundidad - PostOrden

void postOrden(Node *arbol)
{
    if (arbol == NULL)
    {
        return;
    }
    else
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout << arbol->data;
    }
}

/* --PARTE 1-- */

//! Funcion para iterar el arbol y encontrar un nodo para eliminar

void eliminate(Node *arbol, int n)
{
    if (arbol == NULL)
    { //*Si el arbol esta vacio no tengo nada que eliminar, entonces solo retorno
        return;
    }
    else if (n < arbol->data)
    { // *Si el valor es menor, buscar por la izquierda
        eliminate(arbol->izq, n);
    }
    else if (n > arbol->data)
    { // *Si el valor es mayor, buscar por la derecha
        eliminate(arbol->der, n);
    }
    else
    { //* Si se encuentra el valor se llama a la funcion
        eliminateNode(arbol);
    }
}

/* --PARTE 2-- */

//! Funcion para determinar el Nodo mas izquierdo posible

Node *minimo(Node *arbol)
{
    if (arbol == NULL)
    { //*Si el arbol esta vacio le retornamos un NULL
        return NULL;
    }
    else if (arbol->izq)
    {                              // *Si tiene hijo izquierdo
        return minimo(arbol->izq); //*buscamos la parte mas izquierda posible
    }
    else
    { // *si no tiene hijo izquierdo retornamos el mismo nodo
        return arbol;
    }
}

//! Funcion para reemplazar un nodo

/* --PARTE 3-- */

void reemplazar(Node *arbol, Node *nuevoNodo)
{
    if (arbol->padre) //! Si el valor tiene padre (si el nodo cuenta con un padre)
    {
        // ? a arbol->padre hay que asignarle su nuevo hijo
        if (arbol->data == arbol->padre->izq->data) // *en caso de que sea un hijo izquierdo y couerde con el nodo a eliminar
        {
            arbol->padre->izq = nuevoNodo;
        }
        else if (arbol->data == arbol->padre->der->data) // *en caso de que sea un hijo derecho y concuerde con el nodo a eliminar
        {
            arbol->padre->der = nuevoNodo;
        }
    }
    if (nuevoNodo)
    {
        // ? se proede a asignarle el nuevo padre al nodo que reemplazara al eliminado
        nuevoNodo->padre = arbol->padre;
    }
}

//! Funcion para destruir un nodo

void destruirNode(Node *node)
{
    node->izq = NULL; // *le quitamos el hijo izquierdo
    node->der = NULL; // *le quitamos el hijo derecho
    delete node;      // *finalmente, eliminamos el nodo
}

//! Funcion para eliminar un nodo

// TODO: Debemos tener en cuenta si el nodo es hoja (no tiee hijos)
// TODO: Debemos tener en cuenta si el nodo tiene un hijo izquierdo o derecho
// TODO: Debemos tener en cuenta si el nodo tiene dos hijos
// ?La eliminacion depende de lo anterior

void eliminateNode(Node *n_delete)
{

    // *Caso 1: Nodo con dos subarboles hijos (2 hijos)
    // *Para esto recorremos un lugar hacia la derecha y vamos lo mas a la izquierda posible para reemplazar el nodo a eliminar

    if (n_delete->izq && n_delete->der)
    { // *Comprobando que el nodo tiene dos hijos
        Node *menor = minimo(n_delete->der);
        n_delete->data = menor->data; // *Asignamos el menor valor encontrado
        eliminateNode(menor);         // *se elimina el nodo al que se usara para reemplazar
    }

    /* --PARTE 3-- */

    // *Caso 2: Nodo con solo un hijo
    // *Lo que hay que hacer es que el hijo sera el nuevo nodo por el que se reemplazara, es decir, el hijo toma su lugar

    else if (n_delete->izq) //*si el nodo tiene el hijo izquierdo
    {
        reemplazar(n_delete, n_delete->izq);
        destruirNode(n_delete);
    }

    else if (n_delete->der) //*si el nodo tiene el hijo derecho
    {
        reemplazar(n_delete, n_delete->der);
        destruirNode(n_delete);
    }

    /* --PARTE 4-- */
    // *Ultimo caso: Nodo sin Hijos
    else
    {
        reemplazar(n_delete, NULL);
        destruirNode(n_delete);
    }
}

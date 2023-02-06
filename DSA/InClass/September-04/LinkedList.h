
#include "Node.h"

template <class T>
class LinkedList
{
    // * Atributos publicos
public:
    LinkedList();
    LinkedList(const LinkedList<T> &otra);
    ~LinkedList();
    void addFirst(T data);
    void addLast(T data);
    bool add(T data, int pos);
    void deleteFirst();
    void deleteLast();
    void del(int pos);
    int deleteAll();
    bool isEmpty();
    int getSize();
    T get(int pos);
    T set(T data, int pos);
    void change(int pos1, int pos2);
    void reverse();
    void shift(int n);
    bool operator==(const LinkedList<T> &otra);
    void operator+=(const LinkedList<T> &otra);
    void operator=(const LinkedList<T> &otra);
    void print();

    // * Atributos privados
private:
    Node<T> *head;
    int size;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    size = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    // ! TBD
}

template <class T>
// * Método que agrega un nodo al inicio de la lista
// ? Complejidad: O(1)
void LinkedList<T>::addFirst(T data)
{
    // * Se crea un nuevo nodo, tomando en cuenta que
    // * head es de tipo nodo
    head = new Node<T>(data, head);
    size++;
}

template <class T>
// * Método que agrega un nodo al final de la lista
// ? Complejidad: O(n)
void LinkedList<T>::addLast(T data)
{
    // * Si no hay nada, llama a addFirtst
    if (size == 0)
    {
        addFirst(data);
    }
    else
    {
        Node<T> *curr = head;
        while (curr->getNext() != nullptr)
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data));
        size++;
    }
}

template <class T>
// * Método que agrega un nodo dada una posicion de la lista
// ? Complejidad: O(n)
bool LinkedList<T>::add(T data, int pos)
{

    if (pos > size)
    {
        return false;
    }
    if (pos == 0)
    {
        addFirst(data);
    }
    else if (pos == size)
    {
        addLast(data);
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++) // * Garantizar que entre pos - 1 veces
        {
            curr = curr->getNext();
        }
        curr->setNext(new Node<T>(data, curr->getNext()));
        size++;
    }
    return true;
}

template <class T>
// * Método que elimina el primer nodo de la lista
// ? Complejidad: O(1
void LinkedList<T>::deleteFirst()
{
    // * Si hay algo lo elimina, y si no, no hace nada
    if (size != 0)
    {
        Node<T> *curr = head;
        head = head->getNext();
        delete curr;
        size--;
    }
}

template <class T>
// * Método que elimina el ultimo nodo de la lista
// ? Complejidad: O(n)
void LinkedList<T>::deleteLast()
{
    // * Sio solo hay un elemento llama a deleteFirst
    if (size <= 1)
    {
        deleteFirst();
    }
    else
    {
        // * Nodo "auxiliar"
        Node<T> *curr = head;
        while (curr->getNext()->getNext() != nullptr) // * Estara viendo a que apunta dos posiciones de enfrente
        {
            curr = curr->getNext();
        }
        delete curr->getNext(); // * Elimina la lista siguiente
        curr->setNext(nullptr); // * Establece NULL a la lista actual
        size--;                 // * Reduce el contador del tamaño del linked list
    }
}

template <class T>
// * Método que elimina un nodo dada una posicion de la lista
// ? Complejidad: O(n)
void LinkedList<T>::del(int pos)
{

    if (pos == 0)
    {
        deleteFirst();
    }
    else if (pos == size - 1)
    {
        deleteLast();
    }
    else
    {
        Node<T> *curr = head;
        for (int i = 1; i < pos; i++)
        {

            curr = curr->getNext();
        }
        Node<T> *aux = curr->getNext();
        curr->setNext(aux->getNext()); // curr->setNext(curr->getNext->getNext())
        delete aux;
        size--;
    }
}

template <class T>
// * Método que elimina todos los nodos de la lista
// ? Complejidad: O(n)
int LinkedList<T>::deleteAll()
{
    Node<T> *curr = head;
    while (head != nullptr)
    {
        head = head->getNext();
        delete curr;
        curr = head;
    }
    int cant = size;
    size = 0;
    return cant;
}

template <class T>
// * Método que regresa verifica si la lista esta vacía
// ? Complejidad: O(1)
bool LinkedList<T>::isEmpty()
{
    return (size == 0); // ? return (head == nullptr);
}

template <class T>
// * Método que regresa el tamaño de la lista enlazada
// ? Complejidad: O(1)
int LinkedList<T>::getSize()
{
    return size;
}

template <class T>
// * Método que obtiene el dato contenido en el nodo de la posición dada
// ? Complejidad: O(n)
T LinkedList<T>::get(int pos)
{
    Node<T> *curr = head;

    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    return curr->getData();
}

template <class T>
// * Metodo que cambia el dato contenido en el nodo de la posicion dada y
// * regresa el valor del dato anterior
// ? Complejidad: O(n)
T LinkedList<T>::set(T data, int pos)
{

    Node<T> *curr = head;
    for (int i = 1; i <= pos; i++)
    {
        curr = curr->getNext();
    }
    T dataAux = curr->getData();
    curr->setData(data);
    return dataAux;
}

template <class T>
// * Metodo que intercamba los datos de dos nodos
// ? Complejidad: O(n)
void LinkedList<T>::change(int pos1, int pos2)
{
    if (pos1 != pos2)
    {
        int posMen = (pos1 < pos2) ? pos1 : pos2;
        int posMay = (pos1 > pos2) ? pos1 : pos2;

        Node<T> *curr1 = head;

        for (int i = 1; i <= posMen; i++)
        {
            curr1 = curr1->getNext();
        }
        Node<T> *curr2 = curr1;

        for (int i = 1; i <= (posMay - posMen); i++)
        {
            curr2 = curr2->getNext();
        }

        T dataAux = curr1->getData();
        curr1->setData(curr2->getData());
        curr2->setData(dataAux);
    }
}

template <class T>
// * Metodo que imprime la lista enlazada
// ? Complejidad: O(1)
void LinkedList<T>::print()
{
    Node<T> *curr = head;
    while (curr != nullptr)
    {
        cout << curr->getData();
        cout << endl;
        curr = curr->getNext();
    }
}
/*
template <class T>
// * Método que regresa la lista de forma inversa
// ? Complejidad: O(n)
void LinkedList<T>::reverse()
{ // ! cero nodos, un nodo, dos, muchos
    if (size > 1)
    {
        // * curr apuntara a head como comienzo
        // * siguiente sera el sustituto de head->getNext()
        // * aux sera el que ayudara a reversear los nodos
        Node<T> *curr = head, *siguiente = nullptr, *aux = nullptr;
        while (curr != nullptr)
        {
            // * Siguiente de head (curr)
            siguiente = curr->getNext();
            // * Se establece que el nodo de head ahora apunta a null
            // * (y ahora cada nodo apuntara a su anterior)
            curr->setNext(aux);
            // * movemos una posicion a aux
            aux = curr;
            // * movemos una posicion a curr
            curr = siguiente;
        }
        // * al estar linkeado al reves, se iguala head a aux
        head = aux;
    }
}

template <class T>
// * Método que recorre la lista n posiciones
// ? Complejidad: O(n)
void LinkedList<T>::shift(int n)
{
    if (this->size > 1)
    {
        Node<T> *curr = head, *aux = nullptr;
        int res = n % size, saltos = 0;
        if (res < 0)
        {
            res += size;
        }
        saltos = size - res;

        for (int i = 0; i < saltos; i++)
        {
            aux = head;
            head = head->getNext();
        }
        aux->setNext(nullptr);
        aux = head;

        while (aux->getNext() != nullptr)
        {
            aux = aux->getNext();
        }
        aux->setNext(curr);
    }
}

template <class T>
// * Método que compara si dos listas son iguales
// ? Complejidad: O(n)
bool LinkedList<T>::operator==(const LinkedList<T> &otra)
{
    if (otra.size == this->size)
    {
        Node<T> *curr1 = this->head, *curr2 = otra.head;
        for (int i = 0; i < size; i++)
        {
            if (curr1->getData() != curr2->getData())
            {
                return false;
            }
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
        return true;
    }
    return false;
}

template <class T>
// * Metodo que agrega los valores de una lista a otra (al final)
// ? Complejidad: O(n)
void LinkedList<T>::operator+=(const LinkedList<T> &otra)
{
    if (otra.size > 0)
    {

        Node<T> *curr1, *curr2 = otra.head;
        if (this->size == 0)
        {
            head = (new Node<T>(curr2->getData()));
            curr2 = curr2->getNext();
        }
        curr1 = head;
        // * Iteracion para llegar al final de la primera lista
        while (curr1->getNext() != nullptr)
        {
            curr1 = curr1->getNext();
        }

        // * Iteracion para agregar los nodos
        while (curr2 != nullptr)
        {
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
            
        }
        size += otra.size;
        
    }
}

template <class T>
// * Metodo que borra iguala una lista a otra
// ? Complejidad: O(n)
void LinkedList<T>::operator=(const LinkedList<T> &otra)
{

    this->deleteAll();
    // vacia
    if (otra.size > 0)
    {
        Node<T> *curr1 = head, *curr2 = otra.head;
        head = new Node<T>(otra.head->getData());
        curr1 = head;
        curr2 = otra.head->getNext();

        while (curr2 != nullptr)
        {
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
        this->size = otra.size;
    }
}

template <class T>
// * Constructor que clona una lista en otra
// ? Complejidad: O(n)
LinkedList<T>::LinkedList(const LinkedList<T> &otra)
{
    this->head = nullptr;
    size = 0;

    if (otra.size > 0)
    {
        Node<T> *curr1 = head, *curr2 = otra.head;
        head = new Node<T>(otra.head->getData());
        curr1 = head;
        curr2 = otra.head->getNext();

        while (curr2 != nullptr)
        {
            curr1->setNext(new Node<T>(curr2->getData()));
            curr1 = curr1->getNext();
            curr2 = curr2->getNext();
        }
        this->size = otra.size;
    }
}
*/

#include "LinkedList_2_1.h"
#include "LinkedList_2_2.h"

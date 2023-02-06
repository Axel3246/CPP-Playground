/*

Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 01 de Octubre del 2021
Descripción: Este programa agrega metodos adicionales a la clase Linked List

*/

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
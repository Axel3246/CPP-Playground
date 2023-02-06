/*

Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 28 de Septiembre del 2021
Descripción: Este programa agrega metodos adicionales a la clase Linked List

*/

template <class T>
// * Método que regresa la lista de forma inversa
// ? Complejidad: O(n)
void LinkedList<T>::reverse()
{ 
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

template <class T>
// * Método que regresa la lista de forma inversa
// ? Complejidad: O(n)
void LinkedList<T>::reverse()
{
    if (size <= 0)
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
// * Método que
// ? Complejidad: O(n)
void LinkedList<T>::shift(int n)
{
    if (size != 0)
    {
        Node<T> *curr = head, *curr2 = head, *fin = head;
        int saltos = n % size;
        if (saltos < 0)
        {
            saltos = saltos + size;
        }
        while(fin != nullptr){
            fin->getNext();
        }
        fin->setNext(head);

        for (int j = 0; j < saltos; j++){
            curr2->getNext();
        }
        for(int i = 0; i < saltos; i++){
            
        }

        curr2->setNext(nullptr);

    }
}

template <class T>
// * Método que compara si dos listas son iguales
// ? Complejidad: O(n)
bool LinkedList<T>::operator==(const LinkedList<T> &otra)
{
    if (size == otra.size)
    {
        Node<T> *curr1 = head, *curr2 = otra.head;
        for (int i = 0; i < size; i++)
        {
            if (curr1->getData() == curr2->getData())
            {
                curr1->getNext();
                curr2->getNext();
            }
            else
            {
                return false;
                break;
            }
        }
        return true;
        
    }
    return false;
    
}
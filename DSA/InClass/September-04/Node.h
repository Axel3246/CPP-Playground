
template <class T>
class Node
{

public:
    // * Atributos publicos
    Node(T data);
    Node(T data, Node<T> *next);
    T getData();
    Node<T>* getNext(); // * Regresa un apuntador
    void setData(T data);
    void setNext(Node<T> *next);
    
    // * Atributos privados
private:
    T data;
    Node<T> *next;
};

template <class T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr; // * NULL
}

template <class T>
Node<T>::Node(T data, Node<T> *next)
{
    this->data = data;
    this->next = next;
}

template <class T>
T Node<T>::getData(){
    return data;    
}

template <class T>
Node<T>* Node<T>::getNext(){
    return next;
}

template <class T>
void Node<T>::setData(T data){
    this->data = data;
}

template <class T>
void Node<T>::setNext(Node<T> *next){
    this->next = next;
}
#include "Node.h"
template <class T>
class stack
{
public:
	stack();
	~stack();
	void push(T data);
	void pop();
	T top();
	int size();
	bool empty();

private:
	Node<T> *tope;
	int tam;
};

template <class T>
stack<T>::stack()
{
	tope = nullptr;
	tam = 0;
}

template <class T>
stack<T>::~stack()
{
	Node<T> *curr = tope;
	while (tope != nullptr)
	{
		tope = tope->getNext();
		delete curr;
		curr = tope;
	}
}

//Complejidad: O(1)
template <class T>
void stack<T>::push(T data)
{
	tope = new Node<T>(data, tope);
	tam++;
}

//Complejidad: O(1)
//Precondición es que al menos haya 1 elemento
template <class T>
void stack<T>::pop()
{
	Node<T> *curr = tope;
	tope = tope->getNext();
	delete curr;
	tam--;
}

//Complejidad: O(1)
//Precondición es que al menos haya 1 elemento
template <class T>
T stack<T>::top()
{
	return tope->getData();
}

//Complejidad: O(1)
template <class T>
int stack<T>::size()
{
	return tam;
}

//Complejidad: O(1)
template <class T>
bool stack<T>::empty()
{
	return tam == 0;
}

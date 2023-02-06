#include "Node.h"
template <class T>
class queue
{
public:
	queue();
	~queue();
	void push(T data);
	void pop();
	T front();
	int size();
	bool empty();

private:
	Node<T> *fin;
	int tam;
};

template <class T>
queue<T>::queue()
{
	fin = nullptr;
	tam = 0;
}

template <class T>
queue<T>::~queue()
{
	if (fin != nullptr)
	{
		Node<T> *curr = fin->getNext();
		fin->setNext(nullptr);
		fin = curr;
		while (fin != nullptr)
		{
			fin = fin->getNext();
			delete curr;
			curr = fin;
		}
	}
}

//Complejidad: O(1)
template <class T>
void queue<T>::push(T data)
{
	if (fin == nullptr)
	{
		fin = new Node<T>(data);
		fin->setNext(fin);
	}
	else
	{
		fin->setNext(new Node<T>(data, fin->getNext()));
		fin = fin->getNext();
	}
	tam++;
}

//Complejidad: O(1)
//Precondición que exista al menos 1 elemento
template <class T>
void queue<T>::pop()
{
	Node<T> *curr = fin->getNext();
	if (fin->getNext() == fin)
	{ //Hay 1 solo elemento
		fin = nullptr;
	}
	else
	{
		fin->setNext(curr->getNext());
	}
	delete curr;
	tam--;
}

//Complejidad: O(1)
//Precondición que exista al menos 1 elemento
template <class T>
T queue<T>::front()
{
	return fin->getNext()->getData();
}

//Complejidad: O(1)
template <class T>
int queue<T>::size()
{
	return tam;
}

//Complejidad: O(1)
template <class T>
bool queue<T>::empty()
{
	return tam == 0;
}

// AG01-I
// Aplicación para probar la Actividad AG01 en la parte I
// Autor: Ing. Luis H. González Guerra#include <iostream>

#include <iostream>
#include "2.1-Lista.h"

using namespace std;

int main()
{
	// * Creando un objeto (array) de la clase lista
	Lista miLista;
	
	// * Insertando valores en la lista a traves de los metodos en la clase
	miLista.insert(154);
	miLista.insert(587);
	miLista.insert(874);

	// * Imprimiendo la lista
	miLista.print();
	cout << "La lista tiene: " << miLista.getSize() << " datos" << endl;

	// * Insertando valores en la lista a traves de los metodos en la clase
	miLista.insert(999);
	miLista.insert(888);

	// *Cout misc
	cout << "La lista tiene: " << miLista.getSize() << " datos" << endl;
	cout << "En la posición 3 esta: " << miLista.getData(3) << endl;
	cout << "Voy a borrar el último y fue: " << endl;

	// * Usando el metodo de erase
	miLista.erase();

	// *Enumerado y eliminando los elemntos de la lista
	int cant = miLista.getSize();
	cout << "La lista tiene: " << cant << " datos" << endl;
	for (int i = 0; i < cant; i++)
	{
		miLista.erase();
	}
}
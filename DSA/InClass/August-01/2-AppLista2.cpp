// AG01-II
// Aplicación para probar la Actividad AG01 en la parte II
// Autor: Ing. Luis H. González Guerra


#include <iostream>

using namespace std;

#include "2.2-Lista2.h"

int main(){

	// ? Declaramos que esta lista sera de enteros < int >
	Lista<int> miLista1;

	// * Insertamos valores a la lista de int
	miLista1.insert(154);
	miLista1.insert(587);
	miLista1.insert(874);

	// * Cout misc
	miLista1.print();
	cout << "La lista tiene: "<< miLista1.getSize() << " datos"<<endl;
	
	// *Insertamos mas valores
	miLista1.insert(999);
	miLista1.insert(888);

	// * Cout misc
	cout << "La lista tiene: "<< miLista1.getSize() << " datos"<<endl;
	cout << "En la posición 3 esta: "<<miLista1.getData(3)<<endl;
	cout << "Voy a borrar el último y fue: "<< endl;
	miLista1.erase();

	// * Desplegamos y vamos eliminando la lista
	int cant = miLista1.getSize();
	cout << "La lista tiene: "<< cant << " datos"<<endl;
	for (int i=0; i<cant; i++){
		miLista1.erase();
	}

	cout << "---------------------"<<endl; // ! Cambio de "Seccion"

	// ? Declaramos que esta lista sera de strings < string >
	Lista<string> miLista2;

	// * Insertamos valores a la lista de strings
	miLista2.insert("HOLA");
	miLista2.insert("CRAYOLA");
	miLista2.insert("COMO");

	// * Cout misc
	miLista2.print();
	cout << "La lista tiene: "<< miLista2.getSize() << " datos"<<endl;

	// *Insertamos mas strings
	miLista2.insert("TE");
	miLista2.insert("VA?");

	// * Cout misc
	cout << "La lista tiene: "<< miLista2.getSize() << " datos"<<endl;
	cout << "En la posición 3 esta: "<<miLista2.getData(3)<<endl;
	cout << "Voy a borrar el último y fue: "<< endl;
	miLista2.erase();

	// * Desplegamos y vamos eliminando la lista de strings
	cant = miLista2.getSize();
	cout << "La lista tiene: "<< cant << " datos"<<endl;
	for (int i=0; i<cant; i++){
		miLista2.erase();
	}
}
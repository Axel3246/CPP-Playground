#include <iostream>

using namespace std;

#include "LinkedList.h"
void algo(){
	LinkedList<int> hola;
	hola.addFirst(4);
}

int main(){
	LinkedList<string> miLista;

	miLista.addFirst("HOLA");
	miLista.addFirst("CRAYOLA");
	miLista.addFirst("YO");
	miLista.addFirst("SOY");
	miLista.addFirst("DE");
	miLista.addFirst("MTY");
	miLista.print();
	cout << "El size es: " << miLista.getSize() << endl;
	cout << "--------------------" << endl;
	miLista.addLast("ITESM");
	miLista.addLast("Monterrey");
	miLista.print();
	cout << "El size es: " << miLista.getSize() << endl;
	cout << "--------------------" << endl;
	if (miLista.add("MEXICO", 40)){
		cout << "SI se pudo en la 40" << endl;
	}
	else{
		cout << "NO se pudo en la 40" << endl;
	}
	if (miLista.add("OJOS", 3)){
		cout << "SI se pudo en la 3" << endl;
	}
	else{
		cout << "NO se pudo en la 3" << endl;
	}
	miLista.print();
	cout << "El size es: " << miLista.getSize() << endl;
	cout << "--------------------" << endl;
	miLista.deleteFirst();
	miLista.print();
	cout << "El size es: " << miLista.getSize() << endl;
	cout << "--------------------" << endl;
	miLista.deleteLast();
	miLista.print();
	cout << "El size es: " << miLista.getSize() << endl;
	cout << "--------------------" << endl;
	miLista.deleteAll();
	miLista.print();
	cout << "El size es: " << miLista.getSize() << endl;
	cout << "--------------------" << endl;
	LinkedList<int> miLista2;
	miLista2.addLast(100);
	miLista2.addFirst(200);
	miLista2.addLast(300);
	miLista2.addFirst(400);
	miLista2.print();
	cout << "El size es: " << miLista2.getSize() << endl;
	cout << "--------------------" << endl;
	cout << miLista2.get(2) << endl;
	cout << miLista2.set(1000,3) << endl;
	cout << "--------------------" << endl;
	miLista2.print();
	cout << "--------------------" << endl;
	miLista2.change(1,2);	
	miLista2.print();
	cout << "--------------------" << endl;
	miLista2.change(3,3);
	miLista2.print();
	cout << "--------------------" << endl;
	miLista2.change(3,0);
	miLista2.print();
	cout << "--------------------" << endl;
	// Se invoca automáticamente al destructor
	cout << "Reversed" << endl;
	miLista2.reverse();
	miLista2.print();
	cout << "--------------------" << endl;
	cout << "Shift" << endl;
	miLista2.shift(1);
	miLista2.print();
	cout << "--------------------" << endl;
	cout << "Operator==" << endl;
	LinkedList<int> miLista3, miLista4, miLista4_1;
	miLista3.addFirst(100);
	miLista3.addFirst(300);
	//miLista3.addFirst(300);
	miLista4.addFirst(100);
	miLista4.addFirst(200);
	if(miLista3 == miLista4){
		cout << "Son iguales" << endl;
	}
	else{
		cout << "No son iguales" << endl;
	}
	cout << "--------------------" << endl;
	cout << "OPerator+=" << endl;
	LinkedList<int> miLista5;
	miLista5.addFirst(99);
	miLista5.addLast(69);
	miLista5+=miLista3;
	miLista5.print();
	cout << "--------------------" << endl;
	cout << "Operator =" << endl;
	LinkedList<int> miLista6;
	
	miLista6 = miLista5;
	miLista6.print();
	cout << "--------------------" << endl;
	cout << "Clone Constructor" << endl;
	LinkedList<int> miLista7(miLista2);
	miLista7.print();
	cout << "--------------------" << endl;
}




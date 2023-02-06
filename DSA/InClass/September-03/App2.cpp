#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{

    cout << "---------- Operator == ----------" << endl;

    LinkedList<int> l1;
    LinkedList<int> l2;

    l1.addLast(1000);
    l1.addLast(2000);
    l1.addLast(4000);
    l2.addLast(1000);
    l2.addLast(2000);
    l2.addLast(3000);

    if(l1 == l2){
		cout << "Son iguales" << endl;
	}
	else{
		cout << "No son iguales" << endl;
	}

    l1.print();
    l2.print();
    
    l1.addLast(10);
    l1.addLast(20);
    l1.print();
    l2.addLast(400);
    l2.print();

    cout << "-----------------------" << endl;

    cout << "-----------------------" << endl;

    cout << "-----------------------" << endl;

    cout << "-----------------------" << endl;
}
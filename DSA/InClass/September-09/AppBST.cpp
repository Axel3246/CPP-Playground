#include <iostream>
using namespace std;

#include "BST.h"

int main(){

    system("cls");

    BST miArbol;

    miArbol.add(22);
    miArbol.add(10);
    miArbol.add(8);
    miArbol.add(4);
    miArbol.add(14);
    miArbol.add(7);
    miArbol.add(30);
    miArbol.add(23);
    miArbol.add(17);
    miArbol.add(27);
    miArbol.add(9);
    miArbol.add(100);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);

    cout << "El size de miArbol es " << miArbol.size() << endl; 
    cout << "--------------------------" << endl;
    if(miArbol.search(9)){
        cout << "SI encontre al 9" << endl;
    }
    else{
        cout << "NO encontré al 9" << endl;
    }

    if(miArbol.search(22)){
        cout << "SI encontre al 22" << endl;
    }
    else{
        cout << "NO encontré al 22" << endl;
    }

    if(miArbol.search(90)){
        cout << "SI encontre al 90" << endl;
    }
    else{
        cout << "NO encontré al 90" << endl;
    }

    if(miArbol.search(8)){
        cout << "SI encontre al 8" << endl;
    }
    else{
        cout << "NO encontré al 8" << endl;
    }

    cout << "--------------------------" << endl;
    miArbol.remove(170);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    cout << "--------------------------" << endl;
    miArbol.remove(22);
    miArbol.print(1);
    miArbol.print(2);
    miArbol.print(3);
    cout << "--------------------------" << endl;
    cout << "El size de miArbol es " << miArbol.size() << endl;
}
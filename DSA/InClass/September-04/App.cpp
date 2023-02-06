#include <iostream>

using namespace std;

#include "LinkedList.h"

int main()
{
    system("cls");
    /*
    cout << "---------- Operator == ----------" << endl;
    cout << "\n";
    LinkedList<int> l1;
    LinkedList<int> l2;

    l1.addLast(1000);
    //l1.addLast(2000);
    l1.addLast(4000);
    l2.addLast(1000);
    l2.addLast(2000);
    //l2.addLast(4000);

    if (l1 == l2)
    {
        cout << "L1 y L2 son iguales" << endl;
    }
    else
    {
        cout << "L1 y L2 no son iguales" << endl;
    }
    cout << "\n";

    cout << "Lista 1: " << endl;
    l1.print();
    cout << "\n";
    cout << "Lista 2: " << endl;
    l2.print();

    cout << "\n";

    l1.addLast(10);
    l1.addLast(20);
    cout << "Lista 1: " << endl;
    l1.print();
    cout << "\n";
    l2.addLast(400);
    l2.addFirst(20);
    cout << "Lista 2: " << endl;
    l2.print();
    cout << "\n";

    if (l1 == l2)
    {
        cout << "L1 y L2 son iguales" << endl;
    }
    else
    {
        cout << "L1 y L2 no son iguales" << endl;
    }
    cout << "\n";

    l1.deleteAll();
    l2.deleteAll();

    if (l1 == l2)
    {
        cout << "L1 y L2 son iguales" << endl;
    }
    else
    {
        cout << "L1 y L2 no son iguales" << endl;
    }
    cout << "\n";

    // ! Checar casos de size bajo

*/
    /*
    cout << "---------- Shift ----------"  << endl;

    LinkedList<int> l5;
    l5.shift(10);
    cout << "Lista 5: " << endl;
    cout << "\n";
    l5.print();

    l5.addFirst(100);
    cout << "Lista 5: " << endl;
    l5.print();
    cout << "\n";

    LinkedList<int> l6;

    l6.addFirst(200);
    l6.shift(-10);
    cout << "Lista 6: " << endl;
    l6.print();
    cout << "\n";
    l6.addLast(300);
    cout << "Lista 6: " << endl;
    l6.print();
    cout << endl;

    LinkedList<int> l7;

    l7.addFirst(100);
    l7.addFirst(200);
    l7.addFirst(300);
    l7.addFirst(400);
    l7.addFirst(500);
    l7.addFirst(600);
    cout << "Lista 7: " << endl;
    l7.print();
    cout << "\n";
    l7.shift(1);
    cout << "Lista 7: " << endl;
    l7.print();
    cout << "\n";
    l7.shift(2);
    cout << "Lista 7: " << endl;
    l7.print();
    cout << "\n";
    l7.shift(3);
    cout << "Lista 7: " << endl;
    l7.print();
    cout << "\n";
    l7.addLast(5);
    cout << "Lista 7: " << endl;
    l7.print();

*/
    cout << "---------- Reverse ----------"  << endl;

    LinkedList<int> l8;

    l8.reverse();
    cout << "Lista 8: " << endl;
    l8.print();
    cout << "\n";
    l8.print();

    l8.addLast(100);
    cout << "Lista 8: " << endl;
    l8.print();
    cout << "\n";

    l8.reverse();
    cout << "Lista 8: " << endl;
    l8.print();
    cout << "\n";

    l8.addLast(200);
    l8.addLast(300);
    l8.addLast(400);
    cout << "Lista 8: " << endl;
    l8.print();
    cout << "\n";
    l8.reverse();
    cout << "Lista 8: " << endl;
    l8.print();
    cout << "\n";

    l8.addFirst(50);
    cout << "Lista 8: " << endl;
    l8.print();
    cout << "\n";

    l8.reverse();
    cout << "Lista 8: " << endl;
    l8.print();
    cout << "\n";





    cout << "---------- Operator+= ----------" << endl;

    cout << "\n";
    LinkedList<int> l9;
    LinkedList<int> l10;

    l9+=l10;

    cout << "Lista 9: " << endl;
    l9.print();
    cout << "\n";

    cout << "Lista 10: " << endl;
    l10.print();
    cout << "\n";

    l10.addLast(55);
    l10.addLast(66);
    //l10.addLast(77);

    cout << "Lista 9: " << endl;
    l9.print();
    cout << "\n";

    cout << "Lista 10: " << endl;
    l10.print();
    cout << "\n";

    cout << "Haciendo el +=";
    cout << "\n";

    l9 += l10;

    cout << "Lista 9: " << endl;
    l9.print();
    cout << "\n";

    cout << "Lista 10: " << endl;
    l10.print();
    cout << "\n";

    l9.addLast(100);
    l10.addLast(10000);

    cout << "Lista 9: " << endl;
    l9.print();
    cout << "\n";

    cout << "Lista 10: " << endl;
    l10.print();
    cout << "\n";

    cout << "Realizando el segundo +=";
    cout << "\n";

    l9 += l10;

    cout << "Lista 9: " << endl;
    l9.print();
    cout << "\n";

    cout << l9.getSize();


    
/*
    cout << "---------- Operator= ----------"  << endl;

    cout << "\n";
    LinkedList<int> l11;
    LinkedList<int> l12;

    cout << "Primer  =" << endl;
    l11 = l12;
    cout << "\n";

    l12.addLast(10);
    l11 = l12;

    cout << "Lista 11: " << endl;
    l11.print();
    cout << "\n";

    cout << "Lista 12: " << endl;
    l12.print();
    cout << "\n";

    l11.addLast(1000);
    l12.addLast(20000);

    cout << "Lista 11: " << endl;
    l11.print();
    cout << "\n";

    cout << "Lista 12: " << endl;
    l12.print();
    cout << "\n";

    l11.deleteAll();

    cout << "l11 = l12" << endl;
    cout << "\n";
    l11 = l12;

    cout << "Lista 11: " << endl;
    l11.print();
    cout << "\n";

    cout << "Lista 12: " << endl;
    l12.print();
    cout << "\n";

    l11.addFirst(100000);

    cout << "l12 = l11" << endl;
    cout << "\n";
    l12 = l11;

    cout << "Lista 11: " << endl;
    l11.print();
    cout << "\n";

    cout << "Lista 12: " << endl;
    l12.print();
    cout << "\n";

    l11.addLast(111);
    l12.addLast(2222);

    cout << "Lista 11: " << endl;
    l11.print();
    cout << "\n";

    cout << "Lista 12: " << endl;
    l12.print();
    cout << "\n";

*/

/*
    cout << "---------- Copy Constructor ----------"  << endl;
    cout << "\n";

    LinkedList<int> l13;
    LinkedList<int> l14(l13);

    cout << "Lista 13: " << endl;
    l13.print();
    cout << "\n";

    cout << "Lista 14: " << endl;
    l14.print();
    cout << "\n";

    l13.addFirst(1111);
    l13.addFirst(2222);
    l14.addLast(4444);

    cout << "Lista 13: " << endl;
    l13.print();
    cout << "\n";

    cout << "Lista 14: " << endl;
    l14.print();
    cout << "\n";

    LinkedList<int> l15(l13);

    cout << "Lista 13: " << endl;
    l13.print();
    cout << "\n";

    cout << "Lista 15: " << endl;
    l15.print();
    cout << "\n";

    l13.addFirst(1111);
    l13.addFirst(2222);
    l15.addLast(4444);

    cout << "Lista 13: " << endl;
    l13.print();
    cout << "\n";

    cout << "Lista 15: " << endl;
    l15.print();
    cout << "\n";

    LinkedList<int> l16(l13);

    cout << "Lista 13: " << endl;
    l13.print();
    cout << "\n";

    cout << "Lista 16: " << endl;
    l16.print();
    cout << "\n";
*/
/*
    LinkedList<char> l1;
    l1.addLast('K');
    l1.addLast('J');
    l1.addLast('I');
    l1.addLast('H');

    l1.print();
    cout << endl;
    l1.shift(2);
    l1.print();
    cout << endl;
*/
}
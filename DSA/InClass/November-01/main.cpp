#include <iostream>
#include <vector>

using namespace std;

#include "priority_queue.h"

int main(){

    priority_queue pq;

    pq.push(10);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(4);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(2);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(10);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(7);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(9);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(14);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(8);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(1);
    cout << "El tope es: " << pq.top() << endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(4);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(3);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "=============================" << endl;

    pq.push(5);
    cout << "El tope es: " << pq.top()<< endl;
    pq.print();

    cout << "-----------------------------" << endl;

    cout << "El size es: " << pq.size() << endl;

    cout << "-----------------------------" << endl;

    while(!pq.empty()){

        cout << "Sale: " << pq.top() << ", ";
        pq.pop();
    }

    return 0;
}
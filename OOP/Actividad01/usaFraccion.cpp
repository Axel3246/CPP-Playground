#include <iostream>
#include <string>
using namespace std;

#include "Fraccion.h"

int main () {

    Fraccion fracc1, fracc2(3,4);
    
    cout << "Fraccion 1 " << fracc1.getNum()
         << "/" << fracc1.getDen() << " = " << fracc1.calcValorReal() << endl;
    
    fracc1.setNum(2);
    fracc1.setDen(5);
    
    cout << "Fraccion 1 " << fracc1.getNum()
         << "/" << fracc1.getDen() << " = " << fracc1.calcValorReal() << endl;
    
    cout << "Fraccion 2 " << fracc2.getNum()
    << "/" << fracc2.getDen() << " = " << fracc2.calcValorReal() << endl;
    
    return 0;
}

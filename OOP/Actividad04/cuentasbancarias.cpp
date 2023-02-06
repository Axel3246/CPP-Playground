#include <iostream>
using namespace std;

#include "CtaComision.h"

int main() {
    CtaComision cc;
    CtaBanc cb;
    int numCta;
    double saldo, com;
    
    //cout << "Teclea el numero de cuenta de la cuenta bancaria ";
    cin >> numCta;
    
    cb.setNumCuenta(numCta);
    
    //cout << "Teclea el saldo inicial para el cliente de la cuenta bancaria ";
    cin >> saldo;
    
    cb.setSaldo(saldo);
    
    //cout << "Teclea el numero de cuenta con comisión ";
    cin >> numCta;
    
    cc.setNumCuenta(numCta);
    
    //cout << "Teclea el saldo inicial para el cliente de la cuenta con comisión ";
    cin >> saldo;
    
    cc.setSaldo(saldo);
    
    //cout << "Teclea  la comision por retiro ";
    cin >> com;
    
    cc.setComision(com);
    
    cout << "Los datos de la cuenta bancaria son " << endl;
    cb.mostrar();
    
    cout << "Los datos de la cuenta con comisión son " << endl;
    cc.mostrar();
    
    cb.retira(100);
    cc.retira(100);
    
    cout << "despues de retirar datos de cuenta bancaria " << endl;
    cb.mostrar();
    
    cout << "despues de retirar datos de cuenta con comision " << endl;
    cc.mostrar();

    return 0;
}



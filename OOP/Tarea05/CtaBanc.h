#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
#ifndef CtaBanc_Header_h
#define CtaBanc_Header_h

class CtaBanc {
public:
    CtaBanc();
    CtaBanc(int n, double s);
    int getNumCuenta() {return numCuenta;};
    void setNumCuenta(int n) {numCuenta = n;};
    void setSaldo(double s) { saldo = s; };
    double getSaldo(){return saldo;};
    void deposita(double cant);
    virtual bool retira(double cant);  
    virtual void mostrar();           
protected:
    int numCuenta;
    double saldo;
};

CtaBanc::CtaBanc() {
    numCuenta = 0;
    saldo = 0;
}

CtaBanc::CtaBanc(int n, double s) {
    numCuenta = n;
    saldo = s;
}

void CtaBanc::deposita(double cant) {
    saldo += cant;
}

// si hay suficiente saldo resta cant del saldo de la cuenta y manda true, si no hay suficiente saldo, solo manda false
bool CtaBanc::retira(double cant) {
    if (saldo >= cant) {
        saldo -= cant;
        return true;
    }
    else
        return false;
}

void CtaBanc::mostrar() {
    cout << "Cuenta: "<< numCuenta<<"\t";
    cout << "Saldo: "<< saldo <<endl;
}

#endif

/*
CtaBanc::CtaBanc(int numCuenta, double saldo) {
    this->numCuenta = numCuenta;
    this->saldo = saldo;
}
*/
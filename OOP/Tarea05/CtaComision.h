 //Axel Amós Hernandez Cárdenas 17/05/2021
#ifndef CtaComision_Header_h
#define CtaComision_Header_h
#include "CtaBanc.h"
// Escribe la clase 
class CtaComision:public CtaBanc{
    //Publico
    public:
        CtaComision();
        CtaComision(int n, double s, double com);
        int getComision() { return comision;}
        void setComision(double com) {comision = com;}
        bool retira(double cant);
        void mostrar();

    private:
        double comision;
};

CtaComision::CtaComision():CtaBanc(){
    comision = 0;
}

CtaComision::CtaComision(int n, double s, double com):CtaBanc(n,s){
    comision = com;
}

bool CtaComision::retira(double cant) {
    if ((saldo) >= (cant+comision)) { // if ((saldo+comision) >= (cant))
        saldo = saldo - (cant + comision);
        return true;
    }
    else
        return false;
}

/*bool CtaComision::retira(double cant) {
    if ((saldo+comision) >= cant) {
        saldo -= (cant + comision);
        return true;
    }
    else
        return false;
}
*/

void CtaComision::mostrar(){
    CtaBanc::mostrar();
    cout << "Comision: " << comision << endl;
}

// Usa estas líneas para mostrar los datos de una cuenta por comision.
// En la primera línea muestras los datos de la cuenta bancaria
// y en la línea de abajo muestras la comisión de la cuenta.
//    CtaBanc:: mostrar();     
//    cout <<"Comision: " << comision << endl;

#endif
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Empleado.h"
using namespace std;

// Escribe aquí la clase Vendedor
class Vendedor:public Empleado{
    //Public
    public:
        Vendedor();
        Vendedor(int ide, double suel, double percent, int vent);
        int getVentas() {return ventas;}
        double getPorcentaje(){return porcentaje;}
        void setVentas(int vent){ventas = vent;}
        void setPorcentaje(double percent){porcentaje = percent;}
        double calculaPago();
        void muestra();
    //private
    private:
        double porcentaje;
        int ventas;
};

Vendedor::Vendedor():Empleado(){
    porcentaje = 0;
    ventas = 0;
}

Vendedor::Vendedor(int ide, double suel, double percent, int vent):Empleado(ide,suel){
    porcentaje = percent;
    ventas = vent;
}

double Vendedor::calculaPago() {
    sueldo = sueldo + (porcentaje*ventas);
    return sueldo;
}

void Vendedor::muestra(){
    cout << "Id de empleado " << ident;
    cout << " sueldo $" << sueldo;
    cout << " %comision " << porcentaje;
    cout << " ventas " << ventas << endl;
}
// usa estos cout para mostrar los datos de un vendedor
//    cout << "Id de empleado " << ident;
//    cout << " sueldo $" << sueldo;
//    cout << " %comision " << porcentajeComision;
//    cout << " ventas " << ventas << endl;
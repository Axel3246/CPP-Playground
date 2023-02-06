//
//  main.cpp
//  DeptoEmpleados
//


#include <iostream>
#include <string>
using namespace std;

#include "Empleado.h"


void cargaDatosEmp(Empleado listaEmp[], int &cantEmp) {
    int numEmp, numDep;
    string nom;
    
    cout << "Cantidad de empleados? ";
    cin >> cantEmp;
    
    for (int cont = 0; cont < cantEmp; cont++){
        
        cout << "Número de empleado-> ";
        cin >> numEmp;
        cout << "Nombre-> ";
        cin >> nom;
        cout << "Número del departamento-> ";
        cin >> numDep;
        
        listaEmp[cont].setNumEmp(numEmp);
        listaEmp[cont].setNombre(nom);
        listaEmp[cont].setNumDepto(numDep);
    }
    cout <<"Fin captura de datos"<<endl;
}

void muestraDatosEmp(Empleado listaEmp[], int cantEmp) {
    cout <<endl<<"Lista de Empleados"<<endl;
    for (int cont = 0; cont < cantEmp; cont++) {
        cout << listaEmp[cont].getNumEmp() << " ";
        cout << listaEmp[cont].getNombre() << " ";
        cout << listaEmp[cont].getNumDepto() << endl;
    }
    cout<<endl;
}

int main() {
    Empleado listaEmp[10];
    int cantEmp;
    
    cargaDatosEmp(listaEmp, cantEmp);
    muestraDatosEmp(listaEmp, cantEmp);
    
    return 0;
}

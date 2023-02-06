//
//  starter.cpp
//  claseTaxiTutoring
//
//  Created by Yolanda Martinez on 2/21/19.
//  Copyright © 2019 com.itesm. All rights reserved.
//


#include <iostream>
using namespace std;
#include "Tahi.h"


int main() {
    char opcion;
    
    cin >> opcion;
    
    switch (opcion) {
        case 'a':  // constructor default y métodos de acceso
        {
            // Crea un objeto de la clase Taxi con el constructor default
            Taxi unidad;
            // muestra el id del Taxi (obtenlo del objeto creado), termina con endl
            cout <<  unidad.getIdent()  << endl;
            
            // muestra el nombre del responsable, un espacio y el celular del responsable, al final endl
            cout << unidad.getRespondable().getNombre() << " " << unidad.getRespondable().getNumCel()  << endl;
            
            break;
        }
        case 'b':  // constructor con parámetros y métodos de acceso
        {
            
            // Crea un objeto Persona con el constructor con parámetros y ponle nombre = "Jorge", numCel = "24681209"
            Persona persona1("Jorge", "24681209");       
            // Crea un objeto Taxi con id = 123 y responsable = el objeto persona que acabas de definir
            Taxi unidad1;
            unidad1.setIdent(123);
            unidad1.setResponsable(persona1);           
            // muestra el id del Taxi (obtenlo del objeto creado), termina con endl
            cout << unidad1.getIdent() << endl;
            
            // muestra el nombre del responsable, un espacio y el celular del responsable, al final endl
            cout << persona1.getNombre() << " " << persona1.getNumCel() << endl;
           
            break;
        }
        case 'c':  // métodos de modificación y métodos de acceso
        {
             // Crea un objeto Taxi con el constructor default
            Taxi unidad3;
            
            // Crea un objeto Persona con el constructor con parámetros y ponle de valores nombre = "Martha" y numCel = "54637654"
            Persona persona2("Martha","54619654");
            //Taxi unidad3 (987, persona2);
            // Modifica el objeto Taxi poniendo como id = 987 y como responsable al objeto persona que acabas de crear (Martha)
            unidad3.setResponsable(persona2);
            unidad3.setIdent(987);
            // muestra el id del Taxi (obtenlo del objeto creado), termina con endl
            cout <<  unidad3.getIdent() << endl;
            
            // muestra el nombre del responsable, un espacio y el celular del responsable, al final endl
            cout << persona2.getNombre()  << " " << persona2.getNumCel()   << endl;
            
            
            break;
        }
    }
    return 0;
}


//
//  main.cpp
//  arregloComplejos
//
//  Created by Yolanda Martínez on 9/16/13.
//  Copyright (c) 2013 Yolanda Martínez. All rights reserved.
// Axel Amós Hernández Cárdenas - A00829837
#include <iostream>
#include <fstream>
using namespace std;

#include "Complejo.h"

int main() {
    
    ifstream archComplejos;
    // Se define arreglo de apuntadores a 20 objetos tipo Complejo
    Complejo *numComp[20]; 
    

    int contComplejos;
    int r, i;
    
    // cargo los datos del archivo al arreglo de objetos
    archComplejos.open("numerosComplejos.txt");
    
    contComplejos = 0;
    while (archComplejos >> r >> i) {
        // Escribe las instrucciones para ir creando cada objeto tipo Complejo y agregarlo en el arreglo
        numComp[contComplejos++] = new Complejo(r,i);
    }

    archComplejos.close();
    
    // muestro la lista de complejos
    for (int c = 0; c < contComplejos; c++) {
        // Escribe las instrucciones para llamar al método mostrar de cada objeto
        numComp[c]->muestra();
    }
    
    // hago la sumatoria de valores complejos
    Complejo total(0,0);
    for (int c = 0; c < contComplejos; c++) {
        total = total.suma(*numComp[c]);
    }
    cout << "Suma: ";
    total.muestra();
                
    return 0;
}

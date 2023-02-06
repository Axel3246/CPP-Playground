//
//  main.cpp
//  ClaseReloj
//
//  Created by Ma. Guadalupe Roque Díaz de León on 11/11/20.
//

#include <iostream>
#include "RelojDo.h"
using namespace std;


int main() {
    // Declaración de un objeto de la clase RelojD y declaración de variables
    RelojD rolex(9,0);
    int hora, min;
    
    // Desplegar la hora del rolex
    rolex.imprime();
    
    // Leer la nueva hora y minutos
    cin >> hora;
    cin >> min;
    
    // Actualizar la hora y minutos usando los métodos set correspondientes
    rolex.setHr(hora);
    rolex.setMin(min);
    
    // Desplegar la hora del rolex
    rolex.imprime();
    
    // Desplegar la hora del rolex usando los métodos get
    //cout << setw(2) << setfill('0') << rolex.getHr() << ":" << setw(2) << setfill ('0') << rolex.getMin() << endl;
    //cout << (0 > hora > 25 ? "0" : "") << rolex.getHr() << ":" << (0 > min > 59 ? "0" : "") << rolex.getMin() << endl;
    cout << rolex.getHr()  << ":" << rolex.getMin() << endl; 
    
    // Ciclo para incrementar minutos
    for (int minutos = 0; minutos < 55 ; minutos = minutos + 5)
    {
       // Cambiar los minutos con el método setMinutos
        rolex.setMin(minutos);
        // Desplegar la hora del rolex
        rolex.imprime();
    }
    
    // Ciclo para incrementar los minutos
    for (int minutos = 0; minutos < 15 ; minutos++)
    {
        // Inicia el funcionameinto de rolex llamando al método incrementaMinutos
        rolex.incrementaMinutos();
        
        // Desplegar la hora actualizada del rolex
        rolex.imprime();
    }
    
    return 0;
}


/*
Casos de prueba
Datos de entrada:
11
59
Datos de salida:
09:00
11:59
11:59
11:00
11:05
11:10
11:15
11:20
11:25
11:30
11:35
11:40
11:45
11:50
11:51
11:52
11:53
11:54
11:55
11:56
11:57
11:58
11:59
12:00
12:01
12:02
12:03
12:04
12:05



*/
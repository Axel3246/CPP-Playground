
//
//  main.cpp
//  SituacionProblemaFinal - caso 1 - Avance 1  - y caso 2 - Avance 2 
//
//  Created by Ma. Guadalupe Roque on 12/11/20.
//  Copyright © 2020 Invitado. All rights reserved.
//
// ********************************************* DETALLE IMPORTANTE -********************************************************************

//. el método imprimir de la clase Serie (version anterior )despliega los atributos en el siguiente orden:
// cout << id << ", " << titulo << ", " <<  duracion << ", " << genero << ", " << cantidad << ", " <<  calificacion << endl;
// tambien va a imprimir todos los epido

// método imprimir( ) de Episodio
// cout << titulo << ", " <<  temporada << ", " <<  calificacion << endl;

// ********************************************* DETALLE IMPORTANTE -********************************************************************




#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

// NOTA IMPORTANTE - Añade los include que se requieran dependiendo de tu avance
//#include "Serie.hpp"
//#include "Episodio.hpp"
#include "Series.h"



int main() {
   
    Series negocio;
    
    int iOpcion;
  
    cin >> iOpcion;
    
    // leer todas las series desde el archivo -
    negocio.leerArchivo();
    
    switch (iOpcion) {
        case 1:
             negocio.setSerie(0,  negocio.getSerie(5));
             negocio.getSerie(5).imprimir();
             negocio.getSerie(0).imprimir();
             negocio.calculaCalPromedioSerie(); //NO DESPLIEGA SOLO ACTUALIZA
             negocio.reporteTodasSeries();

            break;
        case 2:
            // Retorna la cantiadad de series que tenemos en existencia
            cout << negocio.getCantidadSeries() << endl;
            negocio.consultaEpisodiosConCalificacion(9.5);
            break;
        case 3:
            negocio.reporteConCalificacion(4.5);
            break;
            
        case 4:
            // Calcula la calificación promedio de todas las serie en base a sus episodios y despliega su titulo y su calificación promedio
               negocio.calculaCalPromedioSerie();
               negocio.reporteConCalificacion(0);
               //negocio.reporteTodasSeries();
            break;
        case 5:
            // Reporte de Series que tienen cierto genero -
               negocio.reporteGenero("Ciencia ficcion");
            break;
       
    }
    
   
    return 0;
}


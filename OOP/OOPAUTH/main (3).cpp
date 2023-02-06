//
//  main.cpp
//  libroListaAutores
//
//  Created by Yolanda Martinez on 27/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;

#include "Autor.h"
//#include "Libro.h"

void cargaDatosAutores(Autor *listaAutores[], int &cantAutores) {
    
    string nombre;
    int ide;
    
    ifstream archivo;
    archivo.open("datosAutores.txt");
    
    cantAutores = 0;
    while (archivo >> ide >> nombre) {
        listaAutores[cantAutores++] = new Autor(ide, nombre);
    }
    archivo.close();
}

void muestraAutores(Autor *listaAutores[], int cantAutores) {
    for (int i = 0; i < cantAutores; i++) {
        listaAutores[i]->muestra();
    }
}

void cargaDatosLibros(Libro *listaLibros[], int &cantLibros, Autor *listaAutores[], int cantAutores) {
    
    string titulo;
    int idAutor;
    int cantAutoresDelLibro;
    
    cout << "Cuantos libros? ";
    cin >> cantLibros;
    
    for (int contL = 0; contL < cantLibros; contL++) {
        cout << "Titulo? ";
        cin >> titulo;
            
        listaLibros[contL] = new Libro(titulo);

        cout << "Cuantos autores? ";
        cin >> cantAutoresDelLibro;
        
        // agrego el autor al libro
        for (int contA = 0; contA < cantAutoresDelLibro; contA++) {

            cout << "Teclea el id del autor ";
            cin >> idAutor;

            for (int i=0; i<cantAutores; i++) {
                if (listaAutores[i]->getIden()==idAutor)
                    if (!listaLibros[contL]->agregaAutor(listaAutores[i]))
                        cout << "No hay espacio para más autores";
            }
        }
    }
}


void muestraLibrosConAutores(Libro *listaLibros[], int cantLibros,
                             Autor *listaAutores[], int cantAutores) {
    
    int idAutor;
    Autor *autoresDelLibro[10];
    int cantAutoresDelLibro;
    
    for (int i = 0; i < cantLibros; i++) {
        listaLibros[i]->muestra();
    
    }
}

int main() {
    
    Libro *listaLibros[20];
    int cantLibros;
    
    Autor *listaAutores[20];
    int cantAutores;
    
    cargaDatosAutores(listaAutores, cantAutores);
    muestraAutores(listaAutores, cantAutores);
    
    cargaDatosLibros(listaLibros, cantLibros, listaAutores, cantAutores);
    
    muestraLibrosConAutores(listaLibros, cantLibros, listaAutores, cantAutores);
    
    return 0;
}

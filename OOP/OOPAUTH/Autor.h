//
//  Autor.h
//  libroListaAutores
//
//  Created by Yolanda Martinez on 27/05/20.
//  Copyright © 2020 com.itesm. All rights reserved.
//

#ifndef Autor_h
#define Autor_h

class Autor {
public:
    Autor();
    Autor(int iden, string nombre);
    int getIden() {return iden;}
    void setIden(int iden) {this->iden = iden;}
    string getNombre() {return nombre;}
    void setNombre(string nombre) {this->nombre = nombre;}
    void muestra();
private:
    int iden;
    string nombre;
};

Autor :: Autor(){
    iden = 0;
    nombre = '-';
}
Autor :: Autor(int iden, string nombre){
    this->iden = iden;
    this->nombre = nombre;
}

void Autor::muestra() {
    cout << "Id: " << iden << " Nombre: " << nombre << endl;
}


#endif /* Autor_h */

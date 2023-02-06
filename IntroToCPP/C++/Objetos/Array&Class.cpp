//Declaración de Arreglo de Objetos
#include <iostream>
using namespace std;
#include "Rectangulo.h"
#include "Episodio.h"

int main(){
Rectangulo arrRect[3];

// Se llama al contructor default Rectangulo::Rectangulo()}{
// largo = 0;
// Ancho = 0,
//}

/*
El arreglo se crearía de la siguiente manera, por el constructor default:
                arrRect
          largo        ancho
   0        0            0
   1        0            0
   2        0            0

*/

// Uso del -SET- para un asignar valores a un arreglo

arrRect[0].setLargo(10);
arrRect[0].setAncho(30);

/*
El arreglo se crearía de la siguiente manera, por el metodo SET:
                arrRect
          largo        ancho
   0        10           30
   1        0            0
   2        0            0

*/

// Uso del -GET- para un accesar valores a un arreglo

cout << "Dimensiones: " << arrRect[0].getLargo() << "X" << arrRect[0].getAncho() << endl;

// El cout desplegaría  Dimensiones: 10 X 30

//Oara usar cualquier otro método, simplemente se debe indicar el index que se quiere manejar y luego el .calcArea()

cout << "Area Rectangulo: " << arrRect[0].calcArea() << endl;


//EJEMPLO DE FUNCION QUE LEE UN ARREGLO DESDE EL MAIN

void leerArregloEpisodio(Episodio arrEpisodio[]){
    string sTitulo;
    int iTemporada;
    double dCalificacion;

    for (int iE = 0; iE < 10 ; iE++){
        cout << "Ingresa el titulo: ";
        getline(cin, sTitulo);
        arrEpisodio[iE].setTitulo(sTitulo);

        cout << "Ingresa temporada";
        cin >> iTemporada;
        arrEpisodio[iE].setTemporada(iTemporada);

        cout << "Ingresa calificacion (double)";
        cin >> dCalificacion;
        arrEpisodio[iE].setCalificacion(dCalificacion);

        cin.ignore();
                
    }
}

//EJEMPLO DE FUNCION QUE DESPLIEGA IUN ARREGLO DE EPISODIOS DESDE EL MAIN

void desplegarArregloEpisodio(Episodio arrEpisodio[]){

    for (int iE = 0; iE < 10; iE++){
        arrEpisodio[iE].imprimir();
    }
}
}
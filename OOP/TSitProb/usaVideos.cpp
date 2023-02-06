#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h> // Header para el sleep

#include "Serie.h"
#include "Videos.h"
#include "Pelicula.h"
#include "Episodio.h"

int main()
{

    Videos *listaVideos[30];
    string iD_, nombre_, duracion_, genero_, titulo_, nombreSerie_;
    int calificacion_, calificacionEp_, contPeliculas;
    int temporada_, cantEpisodios_, cantVideos_;
    char tipoVideo;
    char opcionMenu;

    cout << "¡Bienvenido al sistema!";
    cout << " "
         << "Teclea 1 para empezar la carga de datos: " << endl;
    cin >> opcionMenu;
    while (opcionMenu != '1')
    {
        cout << "¡Se necesita la carga de datos! Porfavor teclee 1: ";
        cin >> opcionMenu;
    }
    //Se declara aqui el apuntador de Episodios o algo de series?

    ifstream datosVideos("testdatos.txt");
    // ifstream datosSeries("datosSeries.txt");?
    cantVideos_ = 0;

    while (datosVideos >> tipoVideo)
    {
        if (tipoVideo == 'p')
        {
            datosVideos >> iD_ >> nombre_ >> genero_ >> duracion_ >> calificacion_;
            listaVideos[cantVideos_] = new Pelicula(iD_, nombre_, genero_, duracion_, calificacion_);
            cantVideos_ += 1;
            contPeliculas += 1;
        }
        else if (tipoVideo == 'e')
        {
            datosVideos >> iD_ >> nombre_ >> genero_ >> duracion_ >> calificacion_ >> titulo_ >> temporada_;
            //¿Como definiria el array de apuntadores de episodio aqui de la clase serie
            listaVideos[cantVideos_] = new Episodio(iD_, nombre_, genero_, duracion_, calificacion_, titulo_, temporada_, calificacionEp_);

            cantVideos_ += 1;
        }
    }
    datosVideos.close();
    //sleep(2);
    cout << endl;
    cout << "¡Carga de datos completada!";
    cout << endl;

    //sleep(2);

    do
    {
        int calificacionB, calificacionE, calificacionP;
        string opgenero, opserie;
        cout << "¿Qué deseas hacer? Menu de opciones: " << endl;
        cout << endl;
        //sleep(1);
        cout << "a) Mostrar Videos con Cierta Calificación " << endl;
        cout << "b) Mostrar Videos con Cierto Género" << endl;
        cout << "c) Mostrar Episodios de Serie con Calificación Determinada " << endl;
        cout << "d) Mostrar peliculas con cierta calificacion " << endl;
        cout << "e) Calificar un Video" << endl;
        cout << "f) Terminar Sesión " << endl;
        //sleep(2);
        cout << endl;
        cout << "Opción: ";
        cin >> opcionMenu;

        switch (opcionMenu)
        {
        case 'a':
        {
            calificacionB = 0;
            cout << endl;
            cout << "¿Qué calificación (1-5) quieres que busquemos?" << endl;
            ;
            cout << "Calificacion: ";
            cin >> calificacionB;
            while ((calificacionB <= 0) || (calificacionB > 5))
            {
                cout << endl;
                cout << "Introduce una calificacion valida, porfavor: ";
                cin >> calificacionB;
            }
            cout << "A continuación veras los videos con calificacion: " << calificacionB << endl;
            for (int i = 0; i <= cantVideos_; i++)
            {
                if (listaVideos[i]->getCalificacion() == calificacionB)
                {
                    cout << listaVideos[i]->getNombre() << endl;
                    sleep(1);
                }
               //delete[]listaVideos[i];
            }
            sleep(1);
            break;
        }
        case 'b':
        {
            cout << "¿Qué genero deseas consultar?" << endl;
            cout << "1. Ciencia_ficcion " << endl;
            cout << "2. Accion" << endl;
            cout << "3. Drama " << endl;
            cout << "4. Animacion" << endl;
            cout << "5. Comedia" << endl;
            cout << "Genero: ";
            cin >> opgenero;
            cout << "A continuación veras los videos con el genero: " << opgenero << endl;

            for (int j = 0; j <= cantVideos_; j++)
            {
                if (listaVideos[j]->getGenero() == opgenero)
                {
                    cout << listaVideos[j]->getNombre() << endl;

                    sleep(1);
                }
                //delete[]listaVideos[j];
            }
            break;
        }
        case 'c':
        {
            calificacionE = 0;
            cout << "¿Qué serie deseas consultar?" << endl;
            cin >> opserie;
            cout << "¿Qué calificación quieres?" << endl;
            cin >> calificacionE;
            cout << "A continuación veras los episodios de la serie: " << opserie << " ,con calificacion de: " << calificacionE << endl;

            for (int k = 0; k <= cantVideos_; k++)
            {
                //Me imagino esto es con el arreglo de series, pero no se me viene la idea de como iniciarlo e ir guardando
                //Pienso en un doble if
            }
            break;
        }
        case 'd':
        {
            calificacionP;
            cout << "¿Que calificacion (1-5) quieres para desplegar las peliculas? Calificacion: ";
            cin >> calificacionP;
            while ((calificacionP <= 0) || (calificacionP > 5))
            {
                cout << endl;
                cout << "Introduce una calificacion valida, porfavor: ";
                cin >> calificacionP;
            }
            for (int p = 0; p < contPeliculas; p++)
            {
                if (listaVideos[p]->getCalificacion() == calificacionP)
                {
                    cout << listaVideos[p]->getNombre() << endl;
                    sleep(1);
                }
                //delete[]listaVideos[p];
            }

            break;
        }

        case 'e':
        {
            string opGeneral;
            double preCal, posCal;
            int calificacionGnrl;
            cout << "¡Califica tus episodios/series/peliculas favoritas!" << endl;
            cout << "¿Cual episodio/serie/pelicula quieres calificar? Tu opcion: ";
            cin >> opGeneral;
            cout << "¿Cual es la calificacion que le quieres dar? Calificacion: ";
            cin >> calificacionGnrl;

            for(int y=0; y <= cantVideos_ ; y++){
                if (listaVideos[y]->getNombre() == opGeneral){
                    preCal = listaVideos[y]->getCalificacion();
                    posCal = (preCal + calificacionGnrl)/2;
                }
                //delete[]listaVideos[y];
            }
            cout << "La calificacion anterior de " << opGeneral << " era: " << preCal << endl;
            sleep(1);
            cout << "La nueva calificacion de " << opGeneral << " es: " << posCal << endl;
            sleep(1);
            cout << "Gracias por compartirnos tu opinión :)" << endl;
            sleep(1);
            break;
        }
        case 'f':
        {
            cout << endl;
            cout << "Gracias por preferir nuestro servicio. ¡Vuelva pronto!" << endl;
            cout << endl;
            return 0;
        }
        }

    } while (opcionMenu != 'z');
    return 0;
}
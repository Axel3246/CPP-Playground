#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unistd.h> // Header para el sleep
#include <typeinfo.h>

#include "Serie.h"
#include "Videos.h"
#include "Pelicula.h"
#include "Episodio.h"

//Aqui se cargan las series
void cargarSeries(Serie *arrSeries[], int &cantSeries)
{
    //Videos en General
    //Mas para episodios
    string nombreSerie_, iDD_;
    //Casting para serie
    //MISC
    cantSeries = 0;
    cout << "Iniciando carga de Series" << endl;
    ifstream datosSeries;
    datosSeries.open("datosSeries.txt");
    while (datosSeries >> iDD_ >> nombreSerie_)
    {
        arrSeries[cantSeries] = new Serie(iDD_, nombreSerie_);
        cantSeries += 1;
    }
    datosSeries.close();
}

//Aqui se cargan los videos
void cargarVideos(Videos *listaVideos[], Serie *arrSeries[], int &cantVideos_, int &cantSeries)
{
    //Videos en General
    string iD_, nombre_, duracion_, genero_, titulo_;
    //Mas para episodios
    string nombreSerie_, nombreS_, iDD_;
    //Casting para serie
    Episodio *unEpi;
    //MISC
    int calificacion_, calificacionEp_;
    int temporada_, cantEpisodios_;
    char tipoVideo;
    cout << "Iniciando carga de Videos" << endl;
    cantVideos_ = 0;
    ifstream datosVideos("datostest.txt");
    while (datosVideos >> tipoVideo)
    {
        if (tipoVideo == 'e')
        {
            datosVideos >> iD_ >> nombre_ >> genero_ >> duracion_ >> calificacion_ >> titulo_ >> temporada_ >> calificacionEp_;
            //¿Como definiria el array de apuntadores de episodio aqui de la clase serie
            unEpi = new Episodio(iD_, nombre_, genero_, duracion_, calificacion_, titulo_, temporada_, calificacionEp_);
            listaVideos[cantVideos_] = unEpi;
            cantVideos_ += 1;
            for (int i = 0; i < cantSeries; i++)
            {
                if (arrSeries[i]->getNombreSerie() == titulo_)
                {
                    arrSeries[i]->agregaEpisodio(unEpi);
                }
            }
        }
        else if (tipoVideo == 'p')
        {
            datosVideos >> iD_ >> nombre_ >> genero_ >> duracion_ >> calificacion_;
            listaVideos[cantVideos_] = new Pelicula(iD_, nombre_, genero_, duracion_, calificacion_);
            cantVideos_ += 1;
        }
    }

    datosVideos.close();
}

//Esta funcion muestra todos los videos
void mostrarLosVideos(Videos *listaVideos[], int cantVideos_)
{
    cout << "Los videos disponibles son:" << endl;
    for (int i = 0; i < cantVideos_; i++)
    {
        listaVideos[i]->muestraInformacion();
        cout << endl;
        //sleep(1);
    }
}

//Esta funcion muestra los videos con cierta calificacion
void mostrarVideosConCalif(Videos *listaVideos[], int cantVideos_)
{

    int calificacionB;
    cout << "Nota: Si no hay videos con esa calificación, no se desplegará ninguno." << endl;
    cout << "¿Que calificacion (1-5) quieres que busquemos?" << endl;
    cout << "Calificacion: ";
    cin >> calificacionB;
    while ((calificacionB <= 0) || (calificacionB > 5))
    {
        cout << endl;
        cout << "Introduce una calificacion valida, porfavor: ";
        cin >> calificacionB;
    }
    cout << "A continuación veras los videos con calificacion: " << calificacionB << endl;
    cout << endl;
    for (int i = 0; i < cantVideos_; i++)
    {
        if (listaVideos[i]->getCalificacion() == calificacionB)
        {
            //cout << "- " << listaVideos[i]->muestraInformacion() << endl;
            listaVideos[i]->muestraInformacion();
            cout << endl;
            sleep(1);
        }
    }
}

//mostrar videos con cierto genero
void mostrarVideosConGenero(Videos *listaVideos[], int cantVideos_)
{
    string opgenero = "";
    cout << "¿Que genero deseas consultar?" << endl;
    cout << endl;
    cout << "1. Ciencia_ficcion " << endl;
    cout << "2. Accion" << endl;
    cout << "3. Drama " << endl;
    cout << "4. Animacion" << endl;
    cout << "5. Comedia" << endl;
    cout << "Escribe el genero: ";
    cin >> opgenero;
    cout << endl;
    cout << "A continuacion veras los videos con el genero: " << opgenero << endl;
    cout << endl;
    for (int j = 0; j < cantVideos_; j++)
    {
        if (listaVideos[j]->getGenero() == opgenero)
        {
            listaVideos[j]->muestraInformacion();
            cout << endl;
            sleep(1);
        }
    }
}

//mostrar episodios de series a partir de una calificacion determinada
void mostrarEpisodiosDeSeries(Videos *listaVideos[], Serie *arrSeries[], int cantVideos_, int cantSeries)
{
    string conserie = "";
    Episodio *episode;
    int califEpisodio = 0;
    cout << "¿Que serie quieres consultar?" << endl;
    cout << endl;
    cout << "1. Stranger_things " << endl;
    cout << "2. How_I_met_your_mother" << endl;
    cout << "3. Friends" << endl;
    cout << "4. Rick_y_Morty" << endl;
    cout << "5. Arrow" << endl;
    cout << "6. Breaking_Bad" << endl;
    cout << "7. Gravity_Falls" << endl;
    cout << "8. Konosuba" << endl;
    cout << "9. Neon_Genesis_Evangelion" << endl;
    cout << "10. Drake_y_Josh" << endl;
    cout << "11. Black_Clover" << endl;
    cout << endl;
    cout << "Escribe la serie: ";
    cin >> conserie;
    cout << endl;
    cout << "Nota: Si no hay capitulos con calificación, no se desplegará ninguno." << endl;
    cout << "'¿Que calificacion (1-5)quieres que despleguemos? Calificacion: ";
    cout << endl;
    cin >> califEpisodio;
    while ((califEpisodio <= 0) || (califEpisodio > 5))
    {
        cout << endl;
        cout << "Introduce una calificacion valida, porfavor: ";
        cin >> califEpisodio;
    }
    for (int i = 0; i < cantSeries; i++)
    {
        if (arrSeries[i]->getNombreSerie() == conserie)
        {
            arrSeries[i]->imprimir(califEpisodio);
        }
    } //COMO REGRESAR AL MAIN SI NO HAY EPISODIOS
}

//mostrar peliculas con calificación determinada
void peliculasConCalif(Videos *listaVideos[], int cantVideos)
{
    int calificacionP = 0;
    Pelicula *unaPeli;
    cout << "¿Que calificacion (1-5) quieres para desplegar las peliculas? Calificacion: ";
    cin >> calificacionP;
    cout << endl;
    while ((calificacionP <= 0) || (calificacionP > 5))
    {
        cout << endl;
        cout << "Introduce una calificacion valida, porfavor: ";
        cin >> calificacionP;
    }

    for (int i = 0; i < cantVideos; i++)
    {
        if (typeid(*listaVideos[i]) == typeid(Pelicula))
        {
            unaPeli = (Pelicula *)listaVideos[i];
            if (unaPeli->getCalificacion() == calificacionP)
            {
                unaPeli->muestraInformacion();
                sleep(1);
                cout << endl;
            }
        }
    }
}

//despliega todas las series
void despliegaSeries(Serie *arrSeries[], int cantSeries)
{
    cout << endl;
    for (int s = 0; s < cantSeries; s++)
    {
        cout << "iD:" << arrSeries[s]->getId() << ", "
             << "Serie: " << arrSeries[s]->getNombreSerie() << endl;
        cout << endl;
        sleep(1);
    }
}

//mostrar todas las series con sus episodios
void seriesYepisodios(Serie *arrSeries[], int cantSeries)
{
    for (int s = 0; s < cantSeries; s++)
    {
        cout << endl;
        arrSeries[s]->mostrar();
        sleep(1);
        cout << endl;
    }
}

//Califica un video - cambia la calificación
void calificaVideos(Videos *listaVideos[], int cantVideos_)
{
    string opGeneral = "";
    double preCal, posCal;
    int calificacionGnrl = 0;
    cout << "¡Califica tus episodios/peliculas favoritas!" << endl;
    cout << "¿Cual episodio/pelicula quieres calificar? Tu opcion: ";
    cin >> opGeneral;
    cout << "¿Cual es la calificacion que le quieres dar? Calificacion: ";
    cin >> calificacionGnrl;
    while ((calificacionGnrl < 0) || (calificacionGnrl > 5))
    {
        cout << endl;
        cout << "Introduce una calificacion valida, porfavor: ";
        cin >> calificacionGnrl;
    }
    for (int y = 0; y < cantVideos_; y++)
    {
        if (listaVideos[y]->getNombre() == opGeneral)
        {
            preCal = listaVideos[y]->getCalificacion();
            listaVideos[y]->setCalificacion(calificacionGnrl);
            cout << "La calificacion anterior de " << opGeneral << " era: " << preCal << endl;
            sleep(1);
            cout << "La nueva calificacion de " << opGeneral << " es: " << listaVideos[y]->getCalificacion() << endl;
            sleep(1);
            cout << "Gracias por compartirnos tu opinión :)" << endl;
            sleep(1);
        }
    }
}

int main()
{
    char t;

    //Arreglos de Apuntadores
    Videos *listaVideos[100];
    Serie *arrSeries[100];
    //Para Videos
    int cantVideos_;
    //Para Peliculas
    int contPeliculas;
    //Para Series
    int cantSeries;
    //Misc
    char opcionMenu;
    cout << endl;
    cout << "Bienvenido! No se te olvide cargar los archivos!" << endl;
    do
    {
        cout << endl;
        cout << "a) Cargar Archivos" << endl;
        cout << "b) Mostrar Todos los Videos" << endl;
        cout << "c) Mostrar Videos con Cierta Calificacion " << endl;
        cout << "d) Mostrar Videos con Cierto Genero" << endl;
        cout << "e) Mostrar Episodios de Serie con Calificacion Determinada " << endl;
        cout << "f) Mostrar Peliculas con Calificacion Determinada" << endl;
        cout << "g) Despliega Todas las Series" << endl;
        cout << "h) Despliega Series con Episodios" << endl;
        cout << "i) Calificar un Video" << endl;
        cout << "j) Terminar Sesion " << endl;
        cout << endl;
        cout << "Opcion -> ";
        cin >> opcionMenu;
        cout << endl;
        switch (opcionMenu)
        {
        case 'a': //Mensaje de que ya se cargaron los archivos, recordando que es precarga
        {
            cargarSeries(arrSeries, cantSeries);
            cargarVideos(listaVideos, arrSeries, cantVideos_, cantSeries);
            cout << "Carga completa" << endl;
            break;
        }
        case 'b':
        {
            mostrarLosVideos(listaVideos, cantVideos_);
            cout << endl;
            break;
        }

        case 'c':
        {
            mostrarVideosConCalif(listaVideos, cantVideos_);
            break;
        }
        case 'd':
        {
            mostrarVideosConGenero(listaVideos, cantVideos_);
            break;
        }
        case 'e':
        {
            mostrarEpisodiosDeSeries(listaVideos, arrSeries, cantVideos_, cantSeries);
            break;
        }
        case 'f':
        {
            peliculasConCalif(listaVideos, cantVideos_);
            break;
        }
        case 'g':
        {
            despliegaSeries(arrSeries, cantSeries);
            break;
        }

        case 'h':
        {
            seriesYepisodios(arrSeries, cantSeries);
            break;
        }
        case 'i':
        {
            calificaVideos(listaVideos, cantVideos_);
            break;
        }
        case 'j':
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

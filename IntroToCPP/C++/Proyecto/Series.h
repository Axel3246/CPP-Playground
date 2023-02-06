#include <iostream>
#include<fstream>
#include<sstream>
using namespace std;
#include "Serie.h"

class Series
{

public:
    //Constructor que inicializa iCant = 0  
    Series();
    //Lee las Series desde un archivo CVS y las carga en el arreglo y lee el archivo de Episodios
    void leerArchivo();
    //Reporte de todas las series -
    //al final del mismo muestra la calificacion promedio de todas las series
    void reporteTodasSeries();
    //Reporte de Series que tienen cierta calificacion
    void reporteConCalificacion(double);
    //Reporte de series que tienen cierto género
    void reporteGenero(string);
    //Calcula la claificacion promedio de todas las series en base a sus episodios y despliega su titulo y su calificación promedio
    void calculaCalPromedioSerie();
    //Da de alta una nueva serie
    //sirve para cuando se ingresan los datos del teclado desde el main
    //void ingresarSerieTeclado(Serie serie);
    //Retorna el objeto serie que esta en la posición iS
    Serie getSerie(int iS);
    //Cambie el contenido de una serie por el que recibe como parámetro de entrada
    void setSerie(int iSerie, Serie _serie);
    //Retorn la cantidad de series que tenemos en existencia
    int getCantidadSeries();
    //Mostrar series con los episodios con calificacion especificada en el parámetro de entrada
    void consultaEpisodiosConCalificacion(double dCal);
    // opcional -
    //void consultarTemporadaXSerie(int temporada);
private:
    //Arreglo de la clase Serie
    Serie arrSeries[100]; //Composición
    //Cantidad de series dadas de alta
    int iCant; //Cantidad de series dadas de alta - inicial con 0
};



Series::Series(){
    iCant = 0;
}

//Lee las Series desde un archivo CVS y las carga en el arreglo y lee el archivo de Episodios
//arrSeries[100]
void Series::leerArchivo(){
    string sId, sTitulo, sGenero, linea, dato;
    int iR;

    //cout << "leer archivo\n"; //Borrar
    
    fstream lectura;
    lectura.open("Series.csv", ios::in);
    iR = 0;
    while (getline(lectura, linea)) //lee una serie
    {
      //  cout << linea << endl; //BORRAR
        //500,Mr.Robot,2175,Drama,4.5,4

        std::stringstream registro(linea);
        int columna = 0;
        while(getline(registro, dato, ',')) //separamos los elementos de la serie leída
        {
            switch (columna++)
            {
                case 0: // ID
                    arrSeries[iR].setId(dato);
                break;
                case 1: // NOMBRE
                    arrSeries[iR].setTitulo(dato);
                break;
                case 2: // Duracion
                    arrSeries[iR].setDuracion(stoi(dato)); //stoi string a entero
                break;
                case 3: // Genero
                    arrSeries[iR].setGenero(dato);
                break;
                case 4: // PROMedio
                    arrSeries[iR].setCalificacion(stod(dato));//stod string a double
                break;
                case 5: // CantEpi - inicializar con 0
                    arrSeries[iR].setCantidadEpisodios(0);
                break;
            }
        }
        //para verificar si se leyó correctamente
        //arrSeries[iR].imprimir(); //borrar
        iR++; //Vamos por la siguiente serie del archivo
}
    //Actualizar el atributo iCant
    iCant = iR;
    lectura.close();

    //LEER LOS EPISODIOS
    int iS, cantEpisodios;

    //cout << "leer archivo\n"; //Borrar

    Episodio ep; //Se inicializa con el default
        iS = 0;
        lectura.open("Episodios.txt", ios::in);
            while (getline(lectura, linea)){ //lee una serie
               // cout << linea << endl; //BORRAR
                //500,Mr.Robot,2175,Drama,4.5,4
                stringstream registro(linea);
                int columna = 0;
                while (getline(registro, dato, ',')) //separamos los elementos de la serie leída
                {
                    switch (columna++)
                    {
                    case 0: // ID - convertir int - sacar la posicion de la serie
                        iS = stoi(dato) - 100;
                        break;
                    case 1: // Titulo
                        ep.setTitulo(dato);
                        break;
                    case 2:  // Temporada
                        ep.setTemporada(stoi(dato)); //stoi string a entero
                        break;
                    case 3: // Calificacion
                        ep.setCalificacion(stod(dato));
                        break;
                    }
                }
            //para verificar si se leyó correctamente
            cantEpisodios = arrSeries[iS].getCantidadEpisodios();
            if (cantEpisodios < 5){
                //
                arrSeries[iS].setEpisodio(cantEpisodios, ep);
                arrSeries[iS].setCantidadEpisodios(cantEpisodios + 1);
            }
                           //Vamos por la siguiente serie del archivo
        }
        //Cerrar el archivo
        lectura.close();

}

//Reporte de todas las series -
//al final del mismo muestra la calificacion promedio de todas las series
//ciclo 0 < iCant
//Importante al final del mismo muestra la calificacion promedio de todas las series
//usando la calificación que tiene cada serie
void Series::reporteTodasSeries()
{
    double suma = 0;
    double promedio = 0;
    cout << "ReporteSeries" << endl;
    if (iCant > 0)
    {
        for (int iS = 0; iS < iCant; iS++)
        {
            arrSeries[iS].imprimir();
            cout << endl;
            suma = suma + arrSeries[iS].getCalificacion();
        }
        promedio = suma / iCant;
        cout << "Promedio Series :" << promedio << endl;
    }
}

//Reporte de Series que tienen cierta calificacion
//ciclo iR = 0; iR < iCant ; R++
//solo desplegar aquellas que tienen calificacion ==_cal (.imprimir())
void Series::reporteConCalificacion(double _cal)
{
    //arrSeries[iR].getCalificacion()
    cout << "ReporteSeriesConCalificacion:" << _cal << endl;
    for (int iS = 0; iS < iCant; iS++)
    {
        if (arrSeries[iS].getCalificacion() == _cal)
        {
            //if(arrSeries[iS].getCalificacion() == _cal){
            arrSeries[iS].imprimir();
            cout << endl;   
        }
    }
}

//Reporte de series que tienen cierto género
//Ciclo iR - 0 < iCant
// for (int iR = 0 ; iR < iCant; iR++)
//Verificar si la serie pertenece al _genero == arrSeries[iR].getGenero --> .imprimir()

void Series::reporteGenero(string _genero)
{
    cout << "ReporteGenero:"
         << " " << _genero << endl;
    for (int iX = 0; iX < iCant; iX++)
    {
        if (arrSeries[iX].getGenero() == _genero)
        {
            arrSeries[iX].imprimir();
            cout << endl;
        }
    }
}

//void Series::reporteGenero(string _genero){
//  for(int iS = 0; iS < iCant; iS++){
//  if(_genero == arrSeries[iS].getGenero()){
//     arrSeries[iS].imprimir();
//}
//}
//}

//Calcula la claificacion promedio de todas las series en base a sus episodios y despliega su titulo y su calificación promedio
//Ciclo iR - 0.. < iCant
//for int iR = 0, iR < iCant; R++, arrSeries[iR].calculaCalificacionPrimedio()
void Series::calculaCalPromedioSerie()
{
    for (int iW = 0; iW < iCant; iW++)
    {
        arrSeries[iW].calculaCalificacionPromedio();
    }
}

//Da de alta una nueva serie -ELIMINADO-
//sirve para cuando se ingresan los datos del teclado desde el main
//void Series::ingresarSerieTeclado(Serie serie){

//}

//Retorna el objeto serie que esta en la posición iS
//que recibió como parametro de entrada, si no existe, retorna 0
Serie Series::getSerie(int iS)
{ //Verificar si esta entre iS >= 0 && iS < iCant
    if (iS >= 0 && iS < iCant)
        return arrSeries[iS];
    else
        return arrSeries[0];
}

//Cambie el contenido de una serie por el que recibe como parámetro de entrada
//Verificar si esta entre iS >= 0 && iS < iCant
//si si está en el rango se actualiza el elemento correspondiente del arreglo
//si no - no cambia nada - no lleva else
void Series::setSerie(int iSerie, Serie _serie)
{
    if ((iSerie >= 0) && (iSerie < iCant))
    {
        arrSeries[iSerie] = _serie;
    }
}

//Retorna la cantidad de series que tenemos en existencia
int Series::getCantidadSeries()
{
    return iCant;
}

//Mostrar series con los episodios con calificacion especificada en el parámetro de entrada
// Recorrer todo el arreglo se series con calificacion específica
// arrSeries[iR].imprimir(dCal)
//solo mostrar las series que tienen episodios con esa calificacion, si no, no se deberán imprimir
void Series::consultaEpisodiosConCalificacion(double dCal)
{
    cout << "ReporteEpisodiosConCalificacion:" << dCal << endl;
    for (int iS = 0; iS < iCant; iS++)
    {

        for (int iE = 0; iE < 5; iE++)
        {
            if (arrSeries[iS].getEpisodio(iE).getCalificacion() == dCal) // Sigue la distribución de .imprimir()
            {
                cout << arrSeries[iS].getId() << ", " << arrSeries[iS].getTitulo() << ", " <<
                arrSeries[iS].getGenero() << ", " << arrSeries[iS].getDuracion() << ", " << 
                arrSeries[iS].getCantidadEpisodios() << ", " << arrSeries[iS].getCalificacion() << endl;
                break;
            }
        }

        for (int iE = 0; iE < 5; iE++)
        {

            if (arrSeries[iS].getEpisodio(iE).getCalificacion() == dCal)
            {
                arrSeries[iS].getEpisodio(iE).imprimir();
            }
        }

        for (int iE = 0; iE < 5; iE++)
        {
            if (arrSeries[iS].getEpisodio(iE).getCalificacion() == dCal)
            {
                cout << endl;
                break;
            }
        }
    }
}

// -opcional- Mostrar todas aquellas series que tienen episodios en una temporada específica
//void consultarTemporadaXSerie(int temporada){

//}

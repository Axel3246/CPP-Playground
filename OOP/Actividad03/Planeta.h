#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class Planeta
{
public:
    Planeta();
    Planeta(int pos, string nom, int sat);
    void setPosicion(int pos) { posicion = pos; } //las llaves fucnionan como el set
    void setNombre(string nom) { nombre = nom; }
    void setSatelites(int sat) { satelites = sat; }
    int getPosicion() {   return posicion; }
    string getNombre() { return nombre; }
    int getSatelites() { return satelites; }
    void muestra();

protected:
    int posicion;
    string nombre;
    int satelites;
};

Planeta::Planeta() {
    posicion = 0;
    nombre = "-";
    satelites = 0;
}

Planeta::Planeta(int pos, string nom, int sat) {
    posicion = pos;
    nombre = nom;
    satelites = sat;
}

void Planeta::muestra() {
    cout << "Posición " << posicion;
    cout << " planeta con nombre " << nombre;
    cout << " y con " << satelites << " satélite(s)" << endl;
}


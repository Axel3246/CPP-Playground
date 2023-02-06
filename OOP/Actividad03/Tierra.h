#include "Planeta.h"

class Tierra : public Planeta {
public:
    Tierra();
    Tierra( int pos, string nom, int sat, double hab);
    int getHabitantes() { return habitantes; }
    void setHabitantes(int hab) { habitantes = hab; }
    void muestra();
private:
    double habitantes;
};

Tierra::Tierra():Planeta() {
    habitantes = 0;
}

Tierra::Tierra(int pos, string nom, int sat, double hab):Planeta(pos, nom, sat) {
    habitantes = hab;
}

void Tierra::muestra() {
    cout << "Posición " << posicion;
    cout << " planeta con nombre " << nombre;
    cout << " y con " << satelites << " satélite";
    cout << " y con " << habitantes << " habitantes" << endl;
}


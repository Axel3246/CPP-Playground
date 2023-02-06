#include <iostream>
using namespace std;

class Coordenada{

    private:
        int iX;
        int iY;
    public:
        Coordenada();
        Coordenada(int, int);
        void setX(int);
        void setY(int);
        int getY();
        int getX();
        string str();

};

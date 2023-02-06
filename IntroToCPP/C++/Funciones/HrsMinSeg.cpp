#include <iostream>
using namespace std;

//Sin retorno, pues es con referencia
void conversion(int &x, int &hr, int &min, int &seg){
    //Asignando variables para el cambio en el tiempo
    int refer, x1, x2;
    refer = x;
    //Procesos para la conversión
    hr = x / 3600;
    //Bajar los segundos
    x1 = x - (hr * 3600);
    min = x1 / 60;
    //Bajar los segundos
    x2 = x1 - (min * 60);
    seg = x2;
}
//Main
int main(){
    int valor, horas= 0, minutos = 0, segundos = 0;
    cin >> valor;
    conversion(valor, horas, minutos, segundos);
    cout << horas << " " << minutos << " " << segundos << endl;
    return 0;
}
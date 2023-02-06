#include <iostream>
using namespace std;

//Funciones convertidoras
float pie(int x){
    float pies2Cm;
    pies2Cm = x * 30.48;
    return pies2Cm;
}

float pulg(int x){
    float pulgds2Cm;
    pulgds2Cm = x * 2.54;
    return pulgds2Cm;
}

float yar(int x){
    float yard2Cm;
    yard2Cm = x * 91.44;
    return yard2Cm;
}


int main(){

    char seleccion;
    int valor;
    cin >> seleccion;
    cin >> valor;
    
    //Validación HAY UN ERROR EN B Y C, DONDE EL 0 PASA
    if (valor > 0 && ((seleccion == 'a') || (seleccion == 'b') || (seleccion == 'c'))){
        //Selección
        if (seleccion == 'a'){
            cout << pie(valor) << endl;
            return 0;
        }
        else if (seleccion == 'b'){
            cout << pulg(valor) << endl;
            return 0;
        }
            
        else if (seleccion == 'c'){
                cout << yar(valor) << endl;
                return 0;
            }
    }
    else cout <<"Error" << endl;

}

        



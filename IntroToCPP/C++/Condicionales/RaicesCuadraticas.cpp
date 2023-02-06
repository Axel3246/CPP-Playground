#include <iostream>
#include <cmath>
using namespace std;

int main(){

  //Declaración de Variables

  int a; 
  int b, c, disC, x1, x2, uniKo;

  cin >> a;
  //Validación A
  if (a == 0){
    cout << "No tiene solucion" << endl;
    return 0;
  }
  //Continua Proceso
  else if (a > 0){
    cin >> b;
    cin >> c;
    //Obtencion del determinante
    disC = ((b*b) - (4*a*c));
    //Condicionales para el determinante
    if (disC < 0){
      cout << "Raices complejas" << endl;
    }
    else if (disC > 0){
      x1 = ((-b) + sqrt(disC)) / (2*a);
      x2 = ((-b) - sqrt(disC)) / (2*a);
      cout << x1 << endl;
      cout << x2 << endl;
    }
    else if (disC == 0){
      uniKo = (-b) / (2*a);
      cout << uniKo << endl;
    }

    //End
  }
  return 0;
}
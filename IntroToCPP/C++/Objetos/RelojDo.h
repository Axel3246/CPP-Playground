//Inclusion de librerias
#include <iostream>
#include <iomanip>
using namespace std;

// Clase RelojD
class RelojD{
  // miembros publicos
    public:
    //Metodos constructores con parámetros hr min y el otro constructor default sin parámetros
    RelojD();
    RelojD(int _hr, int _min);
    //Metodos modificadores setHr, setMin
    void setHr(int _hr);
    void setMin(int _min);
    //Metodos de acceso getHr, getMin
    int getHr();
    int getMin();
    //Metodos incrementaMinutos - cada vez que se llama a ete método se incrementa en 1 el minuto - 
    void incrementaMinutos();
    // función void llamada imprime que despliega la hr y minutos en el formato 01:05 o 12:12
    void imprime();
    // atributos privados - hr, min
    private:
        int hr;
        int min;
};

//RelojD::RelojD(){
  //  hr = 0;
    //min = 0;
//}
// Implementación de los métodos
RelojD::RelojD(int _hr, int _min){
  if (((_hr < 0) && (_hr > 23))){
    _hr = 0;
    hr = _hr;
  }
  if ((_min < 0) && (_min > 59)){
    _min = 0;
    min = _min;
  }
  else{
    hr = _hr;
    min = _min;
  }
}
//Verifica que la hora y los minutos esten dentro de un rango, de lo 
//contrario, se establecen como 0 y 0
int RelojD::getHr(){
    return hr;
}
int RelojD::getMin(){
    return min;
}

void RelojD::setHr(int _hr){ //AQUÍ ESTA EL ERROR DEL SEGUNDO COUT
  if ((_hr < 0) || (_hr >= 24)){
    _hr = 0;
    hr = _hr;
  }
  else
    hr = _hr;
}


void RelojD::setMin(int _min){
  if (_min < 0){
    _min = 0;
    min = _min;
  }
  else if (_min >= 60){
    _min = 0;
    min = _min;
  }
  else
    min = _min;
}

void RelojD::incrementaMinutos(){
  if (min >= 59){
    min = 0;
      if(hr < 23){
        hr = hr + 1;
  }
         else{
             hr = 0;
      }
  }  
  else{
    min = min + 1;
  }

}

void RelojD::imprime(){ //Si hr es menor a 10 despliega el 0, igual con minutos    
    cout << (hr < 10 ? "0" : "") << hr << ":" << (min < 10 ? "0" : "") << min << endl;
  //else
    //cout << (hr < 10 ? "0" : "") << hr << ":" << (min < 10 ? "0" : "") << min << endl;
}




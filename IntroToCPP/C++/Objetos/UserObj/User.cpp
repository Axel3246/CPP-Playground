#include <iostream>
#include "User.h"
using namespace std;

int main()
{
    User persona;
    
    int Age = 0, Count = 0;
    string Nom;
    
    cout << "Nombre: ";
    cin >> Nom;
    if(Nom == "Aurelio"){
        persona.setNombre(Nom);
    }
    else{
        cout << "Tu nombre no nos sirve" << endl;  
        return 0; 
    }
    

    cout << "Edad: ";
    cin >> Age;
    cout << endl;
    persona.setEdad(Age);

    cout << "Contador: ";
    cin >> Count;
    cout << endl;
    persona.setContador(Count);
    
    persona.imprimir();
    
    return 0;
}

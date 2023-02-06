//TODO: Hacer un arreglo de estructura llamada atleta para N atletas que contenga: nombre, pais, numero_medallas y devuelva los
//TODO: datos (Nombre, país) del atleta que ha ganado el mayor numero de medallas

#include <iostream>
#include <string>
using namespace std;

struct Atleta
{
    // !Vars
    char nombre[30];
    char pais[30];
    int numero_medallas;

} atletas[100]; // !Arrays

int main()
{
    int cantatletas, index, max = 0; // !Vars
    cout << "Cantidad atletas: ";
    cin >> cantatletas;
    cin.ignore(256, '\n');

    for (int i = 0; i < cantatletas; i++)
    {
        cout << "Escribe el nombre: ";
        cin.getline(atletas[i].nombre, 30, '\n'); //! Guardar datos en un vector de estructura
        cout << "Escribe el pais: ";
        cin >> atletas[i].pais;
        cout << "Escribe la cantidad de medallas: ";
        cin >> atletas[i].numero_medallas;
        cin.ignore(256, '\n');

        if (atletas[i].numero_medallas > max) // !Encontrando el atleta con el mayor numero de medallas
        {
            max = atletas[i].numero_medallas;
            index = i;
        }
        cout << endl;
    }

    cout << "El atleta con el mayor numero de medallas es: " << atletas[index].nombre << endl;
    cout << "Su país de procedencia es: " << atletas[index].pais << endl;
    cout << "Numero de medallas ganadas: " << atletas[index].numero_medallas;
}
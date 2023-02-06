//TODO: Defina una estructura que indique el tiempo empleado por un ciclista en una etapa. La estructura debe tener tres campos:
//TODO: horas, minutos y segundos. Escriba un programa que dada n etapas calcule el tiempo total empleado en correr todas las etapas.

#include <iostream>
#include <string>
using namespace std;

struct Tiempo // !Struct
{
    // !Vars
    int horas;
    int minutos;
    int segundos;

} tiempos[1000]; // !Array

int main()
{
    // !Vars
    int cantEtapas = 0, horasT = 0, minutosT = 0, segundosT = 0;
    cout << "Cantidad de Etapas: ";
    cin >> cantEtapas;

    // !For para el tiempo en las etapas
    for (int i = 0; i < cantEtapas; i++)
    {
        cout << "|| "
             << "Etapa " << i + 1 << " ||" << endl;
        cout << "Horas: ";
        cin >> tiempos[i].horas;
        cout << "Minutos: ";
        cin >> tiempos[i].minutos;
        cout << "Segundos: ";
        cin >> tiempos[i].segundos;

        segundosT = segundosT + tiempos[i].segundos;
        if (segundosT >= 60) //!Segundos -> Minutos
        {
            segundosT -= 60;
            minutosT++;
        }
        minutosT = minutosT + tiempos[i].minutos;
        if (minutosT >= 60) //!Minutos -> Horas
        {
            minutosT -= 60;
            horasT++;
        }

        horasT = horasT + tiempos[i].horas;
    }

    cout << "- Tiempo Total -" << endl;
    cout << horasT << " HORAS" << endl;
    cout << minutosT << " MINUTOS" << endl;
    cout << segundosT << " SEGUNDOS";
}
//Axel Amós Hernández Cárdenas
#include <iostream>
using namespace std;
#include "Envio.h"
#include "Paquete.h"
#include "Persona.h"
#include "Sobre.h"

int main()
{
    Envio *listaEnvios[20];
    int numEnv, plargo, pancho, slargo, sancho;
    char tipoEnvio, opcion;
    double profundidad, peso, costoXKg, costoEnvio, cargoAdicional;
    string rnombre, rdireccion, rciudad, restado, rcodePost;
    string dnombre, ddireccion, dciudad, destado, dcodePost;

    cout << "¿Cuántos envíos realizará?" << endl;
    cin >> numEnv;

    cout << "Introduzca la información del remitente, use guión bajo para espacios" << endl;
    cout << "Nombre:";
    cin >> rnombre;
    cout << "Dirección: ";
    cin >> rdireccion;
    cout << "Ciudad: ";
    cin >> rciudad;
    cout << "Estado: ";
    cin >> restado;
    cout << "Código Postal: ";
    cin >> rcodePost;
    cout << endl;

    cout << "Introduzca la información del destinatario, use guión bajo para espacios" << endl;
    cout << "Nombre:";
    cin >> dnombre;
    cout << "Dirección: ";
    cin >> ddireccion;
    cout << "Ciudad: ";
    cin >> dciudad;
    cout << "Estado: ";
    cin >> destado;
    cout << "Código Postal: ";
    cin >> dcodePost;

    Persona remitente(rnombre, rdireccion, rciudad, restado, rcodePost);
    Persona destinatario(dnombre, ddireccion, dciudad, destado, dcodePost);

    for (int c = 0; c < numEnv; c++)
    {

        cout << "¿Qué tipo de envio quiere realizar?" << endl;
        cout << "Sobre -> Teclee la letra (s)" << endl;
        cout << "Paquete -> Teclee la letra (p)" << endl;
        cout << "Envio -> Teclee la letra (e)" << endl;
        cin >> tipoEnvio;

        if (tipoEnvio == 's')
        {
            cout << "Introduzca el largo (en numero entero): ";
            cin >> slargo;
            cout << "Introduzca el ancho (en numero entero): ";
            cin >> sancho;
            cout << "Introduzca el costo de envio: ";
            cin >> costoEnvio;
            cout << "Introuzca el cargo adicional si supera las dimensiones (25 x 30): ";
            cin >> cargoAdicional;

            listaEnvios[c] = new Sobre(remitente, destinatario, costoEnvio, slargo, sancho, cargoAdicional);
        }

        else if (tipoEnvio == 'p')
        {
            cout << "Introduzca el largo (en numero entero): ";
            cin >> plargo;
            cout << "Introduzca el ancho (en numero entero): ";
            cin >> pancho;
            cout << "Introduzca el costo de envio: ";
            cin >> costoEnvio;
            cout << "Introduzca la profundidad: ";
            cin >> profundidad;
            cout << "Introduzca el peso: ";
            cin >> peso;
            while (peso <= 0)
            {
                cout << "Introduzca un valor positivo" << endl;
                cin >> peso; //validar
            }
            cout << "Introduzca el costo por Kilo: ";
            cin >> costoXKg;
            while (costoXKg <= 0)
            {
                cout << "Introduzca un valor positivo" << endl;
                cin >> costoXKg;
            }
            listaEnvios[c] = new Paquete(remitente, destinatario, costoEnvio, plargo, pancho, profundidad, peso, costoXKg);
        }
        else if (tipoEnvio == 'e')
        {
            cout << "Introduzca el costo de envío: ";
            cin >> costoEnvio;
            listaEnvios[c] = new Envio(remitente, destinatario, costoEnvio);
        }
    }
    cout << endl;
    do
    {
        cout << "Menu de opciones " << endl;
        cout << endl;
        cout << "a) Mostrar Remitente y Destinatario " << endl;
        cout << "b) Calcular Costo de Envios " << endl;
        cout << "c) Terminar Sesión " << endl;
        cout << "Opción: ";
        cin >> opcion;

        switch (opcion)
        {
        case 'a':
        {
            cout << endl;
            cout << "Remitente: " << endl;
            remitente.mostrar();
            cout << endl;
            cout << "Destinatario: " << endl;;
            destinatario.mostrar();
            cout << endl;
        break;
        }

        case 'b':
        {
            cout << endl;
            for (int j = 0; j < numEnv; j++)
            {
                cout << "El costo de su envio número " << j+1 << " es de: $" << listaEnvios[j]->calculaCosto(costoEnvio) << endl;
            }
            cout << endl;
            break;
        }

        case 'c':
        {
            cout << endl;
            cout << "Gracias por preferir nuestra paquetería. ¡Vuelva pronto!" << endl;
            cout << endl;
            return 0;
        break;
        }
        }
        
    }
        while (opcion != 'd');
        return 0;
}

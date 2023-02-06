#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "Paquete.h"
#include "Sobre.h"

// INSTRUCCIONES
// Modifica la clase Envio.h para que sea una clase abstracta
// Las clases Persona.h, Paquete.h y Sobre.h no se modifican

int main()
{

    Envio *listaEnvios[20];
    int cantEnvios, renglones, ren;
    char tipoEnvio;
    string nombreR, estadoR, ciudadR, cpR, nombreD, estadoD, ciudadD, cpD;
    double costoEstandar, peso, costoKg, largo, ancho, cargoAdicional;

    ifstream archivo("datosEnvios.txt");
    cantEnvios = 0;
    // INSTRUCCIONES
    // Incluye el código para abrir el archivo y cargar la información de los envíos

    while  (archivo >> tipoEnvio)
    {
        if (tipoEnvio == 'p')
        {
            archivo >> nombreR >> estadoR >> ciudadR >> cpR >> nombreD >> estadoD >> ciudadD >> cpD >> costoEstandar >> peso >> costoKg;

            Persona remitente(nombreR, estadoR, ciudadR, cpR);
            Persona destinatario(nombreD, estadoD, ciudadD, cpD);
            listaEnvios[cantEnvios] = new Paquete(remitente, destinatario, costoEstandar, peso, costoKg);
            cantEnvios += 1;
        }
        else if (tipoEnvio = 's')
        {
            archivo >> nombreR >> estadoR >> ciudadR >> cpR >> nombreD >> estadoD >> ciudadD >> cpD >> costoEstandar >> largo >> ancho >> cargoAdicional;
            Persona remitente(nombreR, estadoR, ciudadR, cpR);
            Persona destinatario(nombreD, estadoD, ciudadD, cpD);
            listaEnvios[cantEnvios] = new Sobre(remitente, destinatario, costoEstandar, largo, ancho, cargoAdicional);
            cantEnvios += 1;

        } // Incluye el código para desplegar la lista de los envíos y calcular el total a pagar
    }
    archivo.close();
    double costoEnvio = 0, totalEnvios = 0;
    for (int i = 0; i < cantEnvios; i++)
    {
        // Utiliza las siguientes instrucciones para los cout que vas a utilizar
        cout << "Remitente: " << endl;
        listaEnvios[i]->getRemitente().imprimir();
        cout << "Destinatario: " << endl;
        listaEnvios[i]->getDestinatario().imprimir();
        costoEnvio = listaEnvios[i]->calculaCosto();
        cout << "Costo: " << costoEnvio << endl;
        totalEnvios = totalEnvios + costoEnvio;
    }
    cout << "Total envios: " << totalEnvios << endl;

    return 0;
}

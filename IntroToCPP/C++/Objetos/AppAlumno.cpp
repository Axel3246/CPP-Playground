#include <iostream>
#include <string>
using namespace std;

#include "Alumno.h"

// agrega el código que se indica en las instrucciones. Atiende a la secuencia. Recuerda que debe ser exacta.

int main () {

    // Declara una variable alumno1 con el contstructor default
    Alumno alumno1;
    // Imprime los valores de alumno1 usando imprimeAlumno
    alumno1.imprimeAlumno();
    // Declara una variable alumno2 con el constructor con parámetros e inicializa con "Georgina", "A001420000", "ITC" y 18
    Alumno alumno2("A01420000", "Georgina", "ITC", 18);
    // Completa con una llamada al método imprimeAlumno 
    //con el objeto alumno2
    alumno2.imprimeAlumno();
    // Usa el método modificador 
    //para cambiar el nombre del alumno1 por "Andrea¨ y 
    //su edad por 19.
    alumno1.setNombre("Andrea");
    alumno1.setEdad(19);
    // Muestra el objeto alumno1
    alumno1.imprimeAlumno();
    // Usa el método cumpleanios con el objeto alumno2
    alumno2.cumpleYears();
    // Usa el método para imprimir el objeto alumno2
    alumno2.imprimeAlumno();
    
    return 0;
}
/*
[---0]                                                                                                                                                                                              
[Georgina-A01420000-ITC-18]                                                                                                                                                                         
[Andrea---19]                                                                                                                                                                                       
19                                                                                                                                                                                                  
[Georgina-A01420000-ITC-19] 
*/
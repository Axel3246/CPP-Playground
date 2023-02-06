#include <iostream>

using namespace std;

// *Funcion para regresar el menor de 2 int
int menorInt(int a1, int a2){
    if (a1 < a2){
        return a1;
    }
    else{
        return a2;
    }
}

// *Funcion para regresar el menor de 2 float
float menorFloat(float b1, float b2){
    if (b1 < b2){
        return b1;
    }
    else{
        return b2;
    }
}

// *Funcion para regresar el menor de 2 tipos de dato
template <typename T>
T menor (T c1, T c2){
    /* // *
    if (c1 <c2){
        return c1;
    }
    else{
        return c2;
    }
    */ // *Operador condicional (ternario)
    return(c1 < c2) ? c1 : c2;
    // * Op. Unario = tiene 1 solo operando acum++ --fin
    // * Op. Binario = tiene dos operandos a+b c-d g/6
    // * Op. Ternario = tiene 3 operandos
    // * Operador Condicional ==> condicion ? verdad : falso
}

int main(){
    // *Variables
    int a1, a2;
    float b1, b2;
    cin >> a1 >> a2;
    // * Podemos ahora usar el template sin tener que preocuparnos
    // * por el tipo de dato de las variables introducidas
    cout << menor(a1,a2) << endl;
    cin >> b1 >> b2;
    cout << menor(b1,b2) << endl;
}


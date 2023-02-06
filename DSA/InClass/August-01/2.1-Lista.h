#include <iostream>
#define MAX 100 // * Definiendo que MAX vale 100

using namespace std;

class Lista{
    
    public:

        Lista();
        
        // * GET
        int getData(int pos); // ? Se le pasa la posicion del dato que se quiere regresar al usuario
        int getSize(); // * Retorna el size del array
        // *MISC
        void insert(int dato); // ? Se inserta el dato en el array (tipo INT)
        void erase();
        void print();

    private:
        int data[MAX];
        int size;

};

Lista::Lista(){
    size = 0; // *Se inicializa en 0, pues no hay elementos
}

// *Se le pasa el dato al arreglo
void Lista::insert(int dato){
    if(size < MAX){ // * Si el size no supera el maximo de elementos, se agregara y se sumara uno al size
        data[size] = dato;
        size ++;
    }
}

void Lista::erase(){
    if (size > 0){ // * Minetreeas size sea mayor a 0, eliminaremos el ultimo valor y desplegamos el dato actual con el valor nvo de size.
        size --;
        cout << "[" << size << "] - " << data[size] << endl;
    }
    else{ // * En caso de que no se cumpla el condicional, optaremos por decir que no hay elementos
        cout << "No hay elementos" << endl;
    }
}

int Lista::getData(int pos){ // * Se retorna el dato de la posicion deseada
    return data[pos];
}

int Lista::getSize(){
    return size;
}

void Lista::print(){
    for (int i = 0; i < size; i++){
        cout << "[" << i << "] - " << data[i] << endl;
    }
}
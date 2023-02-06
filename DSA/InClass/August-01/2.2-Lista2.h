#include <iostream>
#define MAX 100

using namespace std;

template <class T> // ? Creamos un template y ajustamos algunos de los metodos para poder usarlos con cualquier tipo de dato
class Lista{

    public:
        Lista();
        // ? Lista(T algo); en caso de tener elementos extra que requieran el class T
        // *GET
        T getData(int pos); // * Aqui es T getData porque dependera del dato que tenga el arreglo
        int getSize();
        // *MISC
        void insert(T dato); // * Aqui es T dato porque dependera del dato que se le quiera insertar al arreglo
        void erase();
        void print();

    private:
        T data[MAX]; // * El array es de tipo T porque dependera de los datos que se le pasen
        int size;

};

template <class T> // ? A cada metodo hay que ponerle este encabezado
Lista<T>::Lista(){ // ? Hay que poner el <T> en cada lugar despues de la declaracion de la claseF
    size = 0;
}

/* // * Ejemplo con un constructor tipo T
template <class T>
Lista<T>::Lista(T algo){
    data [0] = algo;
    size = 1;
}
*/

// *Se le pasa el dato al arreglo
template <class T>
void Lista<T>::insert(T dato){
    if(size < MAX){
        data[size] = dato;
        size ++;
    }
}

template <class T>
void Lista<T>::erase(){
    if (size > 0){
        size --;
        cout << "[" << size << "] - " << data[size] << endl;
    }
    else{
        cout << "No hay elementos" << endl;
    }
}

template <class T>
T Lista<T>::getData(int pos){
    return data[pos];
}

template <class T>
int Lista<T>::getSize(){
    return size;
}

template <class T>
void Lista<T>::print(){
    for (int i = 0; i < size; i++){
        cout << "[" << i << "] - " << data[i] << endl;
    }
}

// ! Exactamente lo mismo, solo que declarado T donde se requiera
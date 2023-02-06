/*
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 01 de Noviembre del 2021
Descripción: Este programa es la clase de Heap de priority queue
*/

class priority_queue{

    public:

        priority_queue();
        void push(int dato);  // * Meter a la priority queue
        void pop();          // * Sacar el dato de la PQ
        int top();         // * Observa el dato con mayor prioridad
        bool empty();      
        int size();
        void print();

    private:
        vector<int> datos;
};

// * Método constructor de la priority queue
priority_queue::priority_queue(){

    datos.push_back(-999999);
}

// * Metódo que inserta un dato a la priority queue
// ? Complejidad: O(log (n))
void priority_queue::push(int dato){

    datos.push_back(dato);
    int pos = datos.size()-1;
    bool sigue = true;

    while(pos > 1 && sigue){

        int posPadre = pos / 2;
        
        if(datos[pos] > datos[posPadre]){
            
            int temp = datos[pos];
            datos[pos] = datos[posPadre];
            datos[posPadre] = temp;
            pos = posPadre;

        }
        else{

            sigue = false;
        }
    }
}

// * Metodo que remueve un elemento de la priority queue
// ? Complejidad: O(log(n))
void priority_queue::pop(){

    datos[1] = datos[datos.size()-1];
    datos.pop_back();

    if(datos.size() > 1){

        int pos = 1;
        bool sigue = true;

        // * Reacomodando la posición
        while(pos * 2 < datos.size() && sigue){

            // * Detectar la posición del hijo mayor
            int posHijoMayor = pos * 2;
            // * Si existe un segundo hijo
            if(posHijoMayor+1 < datos.size()){

                if(datos[posHijoMayor] < datos[posHijoMayor + 1]){
                    
                    posHijoMayor++;
                }
            }
            // * Comparar al dato con el hijoMayor
            if (datos[pos] < datos[posHijoMayor]){
                int temp = datos[posHijoMayor];
                datos[posHijoMayor] = datos[pos];
                datos[pos] = temp;
                pos = posHijoMayor;
            }
            else{

                sigue = false;
            }
        }
    }
}

// * Método que regresa el top de la priority queue
// ? Complejidad: O(1);
int priority_queue::top(){

    return datos[1];
}

// * Método que regresa un booleano que determina si la priority queue está vacía
// ? Complejidad: O(1);
bool priority_queue::empty(){

    return datos.size() == 1;
}

// * Método que regresa el size de la priority queue
// ? Complejidad: O(1)
int priority_queue::size(){

    return datos.size()-1;
}

// * Método que imprime la priority queue
// ? Complejidad: O(n)
void priority_queue::print(){

    for(int i = 1; i < datos.size(); i++){

        cout << datos[i] << " ";
    }

    cout << endl;
}
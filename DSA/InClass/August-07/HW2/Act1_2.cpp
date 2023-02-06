/*

Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 30 de Agosto del 2021
Descripción: Este programa utiliza los algoritmos de ordenamiento y de busqueda para ofrecer al usuario el
numero de comparaciones y la posicion de el dato de un arreglo al ser ordenado
*/

#include <iostream>
#include <vector>

using namespace std;

// ! Funciones de Busqueda

// * Funcion que busca un dato por medio de la busqueda secuencial y regresa el numero de comparaciones su posicion
// ? Complejidad: Mejor caso: O(1), Peor caso: O(n)
long busquedaSecuencial(vector<long> vect, long query){
    
    for (long i = 0; i < vect.size(); i++){
        
        if (vect[i] == query){

            return i;
        }
    }
    return -1;
}

// * Funcion que busca un dato por medio de la busqueda binaria y regresa el numero de comparaciones su posicion
// ? Complejidad: Mejor caso: O(1), Peor caso: O(log(n))
long binarySearch(vector<long> vect, long query, long &comp){

    comp = 0;
    long inicio = 0, fin = vect.size() - 1, mitad;

    while (inicio <= fin){
        
        mitad = (inicio + fin) / 2;
        comp++;
        if (vect[mitad] == query){

            return mitad;
        }

        if (vect[mitad] > query){ // El dato que busco es menor al central
            
            fin = mitad - 1;
        }
        else{ // El dato que busco es mayor al central

            inicio = mitad + 1;
        }
    }
    return -1;
}

// ! Funciones de Ordenamiento

// * Funcion que ordena un array / vector por el metodo de longercambio y regresa las comparaciones (mas el vector ordenado)
// ? Complejidad: O(n^2)
long sortIntercambio(vector<long> &vec){

    long comp = 0, temp;

    for (long i = 0; i < vec.size() - 1; i++){

        for (long j = i + 1; j < vec.size(); j++){

            comp++; // Medir las comparaciones

            if (vec[i] > vec[j]){

                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    return comp;
}

// * Funcion que ordena un array / vector por el metodo burbuja y regresa las comparaciones (mas el vector ordenado)
// ? Complejidad: Mejor caso: O(n), Peor caso: O(n^2)
long bubbleSort(vector<long> &vec){

    bool longerruptor = true;
    long temp, comp = 0;

    for (long pasada = 0; pasada < vec.size() && longerruptor; pasada++){

        longerruptor = false;

        for (long j = 0; j < vec.size() - 1 - pasada; j++){

            comp++;

            if (vec[j + 1] < vec[j]){

                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                longerruptor = true;
            }
        }
    }
    return comp;
}

// * Funcion que ordena un array / vector por el metodo mergeSort y regresa las comparaciones (mas el vector ordenado)
// ? Complejidad: O(n)
long merge(vector<long> &vec, long inicio, long mitad, long fin, long &comp){

    vector<long> aux(vec.size());
    long i = inicio, j = mitad + 1, k = inicio;

    while (i <= mitad && j <= fin){

        comp++;

        if (vec[i] <= vec[j]){

            aux[k++] = vec[i++];
        }
        else{

            aux[k++] = vec[j++];
        }
    }
    if (i > mitad){

        for (long a = j; a <= fin; a++){

            aux[k++] = vec[a];
        }
    }
    else{

        for (long a = i; a <= mitad; a++){

            aux[k++] = vec[a];
        }
    }
    for (long a = inicio; a <= fin; a++){

        vec[a] = aux[a];
    }
    return comp;
}

// * Funcion que ordena y divide en subarrays por recursividad para llevar a cabo mergeSort
// ? Complejidad: Mejor caso: O(nlog(n)), Peor caso: O(nlog(n))
void mergeSort(vector<long> &vec, long inicio, long fin, long &comp){

    if (inicio < fin){

        long mitad = (inicio + fin) / 2;
        mergeSort(vec, inicio, mitad, comp);
        mergeSort(vec, mitad + 1, fin, comp);
        merge(vec, inicio, mitad, fin, comp);
    }
}

int main(){

    long nums, n, cont, queries, query;
    cin >> nums;

    // * vect1 == Ordenar con longercambio
    // * vect2 == Ordenar con Búrbuja
    // * vect3 == Ordenar con Merge
    vector<long> vect1, vect2, vect3;

    for (long i = 0; i < nums; i++){

        cin >> n;
        vect1.push_back(n);
        vect2.push_back(n);
        vect3.push_back(n);
    }

    
    // * sortlongercambio
    long complongercambio = sortIntercambio(vect1);
    //prlong(vect1);

    // * bubbleSort
    long compBurbuja = bubbleSort(vect2);
    //prlong(vect2);

    // * mergeSort
    long compMerge = 0;
    mergeSort(vect3, 0, nums - 1, compMerge);
    //prlong(vect3);
    cout << complongercambio << " " << compBurbuja << " " << compMerge << endl;

    cin >> queries;

    for (long j = 0; j < queries; j++){
        
        cin >> query;
        long cantCompBB = 0;
        long posBusBinaria = binarySearch(vect1, query, cantCompBB);
        long posBusSecuencial = busquedaSecuencial(vect1, query);
        long cantCompBS = (posBusSecuencial == -1 ? vect1.size() : posBusSecuencial + 1);

        cout << posBusSecuencial << " " << cantCompBS << " " << cantCompBB << endl;
    }
}


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ? Complejidad: O(n)
void print(vector<int> &vect)
{

    for (int i = 0; i < vect.size(); i++)
    {

        cout << vect[i] << " ";
    }
    cout << endl;
}

// * O(n), best O(1)
int buscaSecuencial(vector<int> &vect, int dato)
{

    for (int i = 0; i < vect.size(); i++)
    {

        if (vect[i] == dato)
        {

            return i;
        }
    }
    return -1;
}

// ? Complejidad: O(log(n)) o O(1)
int buscaBinaria(vector<int> &vect, int dato, int &comp)
{
    comp = 0;

    int inicio = 0, fin = vect.size() - 1, mitad;
    while (inicio <= fin)
    {
        mitad = (inicio + fin) / 2;
        comp++;
        if (vect[mitad] == dato)
        {
            return mitad;
        }
        if (vect[mitad] > dato)
        { // El dato que busco es menor al central
            fin = mitad - 1;
        }
        else
        { // El dato que busco es mayor al central
            inicio = mitad + 1;
        }
    }
    return -1;
}

// ? Complejidad: O(n^2)
int sortIntercambio(vector<int> &vec)
{
    int comp = 0, temp;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = i + 1; j < vec.size(); j++)
        {
            comp++; // Medir las comparaciones
            if (vec[i] > vec[j])
            {
                temp = vec[i];
                vec[i] = vec[j];
                vec[j] = temp;
            }
        }
    }
    return comp;
}

// ? O(n) o O(n^2)
int sortBurbuja(vector<int> &vec)
{
    bool interruptor = true;
    int temp, comp = 0;
    for (int pasada = 0; pasada < vec.size() && interruptor; pasada++)
    {
        interruptor = false;
        for (int j = 0; j < vec.size() - 1 - pasada; j++)
        {
            comp++;
            if (vec[j + 1] < vec[j])
            {
                temp = vec[j];
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
                interruptor = true;
            }
        }
    }
    return comp;
}

// ? O(n^2)
int sortSeleccion(vector<int> &vec)
{
    int indiceMenor, temp, comp = 0;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        indiceMenor = i;
        for (int j = i + 1; j < vec.size(); j++)
        {
            comp++;
            if (vec[j] < vec[indiceMenor])
            {
                indiceMenor = j;
            }
        }
        if (i != indiceMenor)
        {
            temp = vec[i];
            vec[i] = vec[indiceMenor];
            vec[indiceMenor] = temp;
        }
    }
    return comp;
}

// ? O(n) , O(n^2)
int sortInsercion(vector<int> &vec)
{
    int temp, cont = 0;
    for (int i = 1; i < vec.size(); i++)
    { // Tenemos n-1 pasadas
        int j = i;
        temp = vec[j];
        while (j > 0 && temp < vec[j - 1]) // Realizando el desplazamiento
        {
            cont++;
            vec[j] = vec[j - 1];
            j--;
        }
        if (j > 0)
        {
            cont++;
        }
        vec[j] = temp;
    }
    return cont;
}

int merge(vector<int> &vec, int inicio, int mitad, int fin, int &comp)
{
    vector<int> aux(vec.size());
    int i = inicio, j = mitad + 1, k = inicio;
    while (i <= mitad && j <= fin)
    {
        comp++;
        if (vec[i] <= vec[j])
        {
            aux[k++] = vec[i++];
        }
        else
        {
            aux[k++] = vec[j++];
        }
    }
    if (i > mitad)
    {
        for (int a = j; a <= fin; a++)
        {
            aux[k++] = vec[a];
        }
    }
    else
    {
        for (int a = i; a <= mitad; a++)
        {
            aux[k++] = vec[a];
        }
    }
    for (int a = inicio; a <= fin; a++)
    {
        vec[a] = aux[a];
    }
    return comp;
}

// ? Peor O(nlogn), mejor O(nlog)
void mergeSort(vector<int> &vec, int inicio, int fin, int &comp)
{
    if (inicio < fin)
    {
        int mitad = (inicio + fin) / 2;
        mergeSort(vec, inicio, mitad, comp);
        mergeSort(vec, mitad + 1, fin, comp);
        merge(vec, inicio, mitad, fin, comp);
    }
}

// ? O(n)
void particion(vector<int> &vec, int inicio, int final, int &pivote, int &comp)
{
    int elemPivote = vec[inicio];
    int j = inicio; // * Ultima posicion de los menores
    int aux;
    for (int i = inicio + 1; i <= final; i++)   
    {
        comp++;
        if (vec[i] < elemPivote)
        {
            j++;
            aux = vec[i];
            vec[i] = vec[j];
            vec[j] = aux;
        }
    }
    pivote = j; // * Posicionar al pivote en su posicion final
    aux = vec[pivote];
    vec[pivote] = vec[inicio];
    vec[inicio] = aux;
}

// ? Mejor: O(nlogn), peor O(n^2)
void quickSort(vector<int> &vec, int inicio, int final, int &comp)
{

    if (inicio < final)
    {
        int pivote;
        particion(vec, inicio, final, pivote, comp); // * Ordeno a los menores
        quickSort(vec, inicio, pivote - 1, comp);    // * Ordeno a los mayores
        quickSort(vec, pivote + 1, final, comp);
    }
}

int main()
{
    int n, dato, datoBusca;
    cin >> n;
    // vec1 == Ordenar con Intercambio
    // vec2 == Ordenar con Búrbuja
    // vec3 == Ordenar con Seleccion menor
    // vec4 == Ordenar con Insercion
    // vec5 == Ordenar con Merge
    // vec6 == Ordenar con QuickSort
    vector<int> vec1, vec2, vec3, vec4, vec5, vec6; // Construiste el vector con 0 casillas
    for (int i = 0; i < n; i++)
    {
        cin >> dato;
        vec1.push_back(dato); // Empujando al final una nueva casilla
        vec2.push_back(dato); // Empujando al final una nueva casilla
        vec3.push_back(dato); // Empujando al final una nueva casilla
        vec4.push_back(dato); // Empujando al final una nueva casilla
        vec5.push_back(dato);
        vec6.push_back(dato);
    }
    /*	vector<int> vec(n);  // Construiste el vector con n casillas
	for (int i=0; i<n; i++){
		cin >> vec[i];
	}
*/
    cout << "==================" << endl;
    cout << "Datos Originales: ";
    print(vec1);
    cout << "==================" << endl;
    cin >> datoBusca;
    int posBusSecuencial = buscaSecuencial(vec1, datoBusca);
    int cantCompBS = (posBusSecuencial == -1 ? vec1.size() : posBusSecuencial + 1);

    /*
	int cantCompBS;
	if (posBusSencial == -1){
		cantCompBS = vec.size();
	}
	else{
		cantCompBS = posBusSecuencial+1;
	}
*/
    // ? Secuencial
    cout << "posBusSecuencial: " << posBusSecuencial << endl;
    cout << "cantCompBS:	   " << cantCompBS << endl;
    cout << "==================" << endl;
    cout << "Datos Ordenados Intercambio:  ";

    // ? Intercambio
    int compIntercambio = sortIntercambio(vec1);
    print(vec1);
    cout << "Comparaciones Intercambio: " << compIntercambio << endl;
    cout << "==================" << endl;
    cout << "Datos Ordenados Búrbuja:  ";

    // ? Burbuja
    int compBurbuja = sortBurbuja(vec2);
    print(vec2);
    cout << "Comparaciones Búrbuja: " << compBurbuja << endl;

    // ? Seleccion
    cout << "==================" << endl;
    cout << "Datos Ordenados Seleccion Menor: ";
    int compSeleccion = sortSeleccion(vec3);
    print(vec3);
    cout << "cantCompSeleccion:	   " << compSeleccion << endl;
    cout << "==================" << endl;

    // ? Insercion
    cout << "==================" << endl;
    cout << "Datos Ordenados Insercion: ";
    int compInsercion = sortInsercion(vec4);
    print(vec4);
    cout << "cantCompInsercion:	   " << compInsercion << endl;
    cout << "==================" << endl;

    // ? Merge Sort

    cout << "==================" << endl;
    cout << "Datos Ordenados Merge: ";
    int compMerge = 0;
    mergeSort(vec5, 0, n - 1, compMerge);
    print(vec5);
    cout << "cantCompMerge:	   " << compMerge << endl;
    cout << "==================" << endl;

    // ? QuickSort
    cout << "==================" << endl;
    cout << "Datos Ordenados Quick: ";
    int compQuick = 0;
    quickSort(vec5, 0, n - 1, compQuick);
    print(vec5);
    cout << "cantCompQuick:	   " << compQuick << endl;
    cout << "==================" << endl;

    //	sort(vec.begin(), vec.end());
    //	print(vec);
    int cantCompBB;
    int posBusBinaria = buscaBinaria(vec1, datoBusca, cantCompBB);
    cout << "==================" << endl;
    cout << "posBusBinaria:    " << posBusBinaria << endl;
    cout << "cantCompBB:	   " << cantCompBB << endl;
    cout << "==================" << endl;
    /*	cout << "Datos Ordenados Descententemente: ";
	sort(vec.begin(), vec.end(), greater<int>());
	print(vec);
	cout << "==================" << endl;
*/
}

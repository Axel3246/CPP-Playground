
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
        for (int j = i + 1; j < vec.size() - 1; j++)
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

int main()
{
    int n, dato, datoBusca;
    cin >> n;
    // vec1 == Ordenar con Intercambio
    // vec2 == Ordenar con Búrbuja
    vector<int> vec1, vec2, vec3, vec4; // Construiste el vector con 0 casillas
    for (int i = 0; i < n; i++)
    {
        cin >> dato;
        vec1.push_back(dato); // Empujando al final una nueva casilla
        vec2.push_back(dato); // Empujando al final una nueva casilla
        vec3.push_back(dato); // Empujando al final una nueva casilla
        vec4.push_back(dato); // Empujando al final una nueva casilla
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
    cout << "posBusSecuencial: " << posBusSecuencial << endl;
    cout << "cantCompBS:	   " << cantCompBS << endl;
    cout << "==================" << endl;
    cout << "Datos Ordenados Intercambio:  ";

    int compIntercambio = sortIntercambio(vec1);
    print(vec1);
    cout << "Comparaciones Intercambio: " << compIntercambio << endl;
    cout << "==================" << endl;
    cout << "Datos Ordenados Búrbuja:  ";

    int compBurbuja = sortBurbuja(vec2);
    print(vec2);
    cout << "Comparaciones Búrbuja: " << compBurbuja << endl;

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



#include <iostream>

using namespace std;

void dibuja_pastel(int largo, int ancho){
    
    for(int iR = 1, iK = 0; iR <= largo; iR++, iK++ ){
        cout << iK ;
        for (int iC = 1; iC <= iR; iC++)
            cout <<  " 🎂 ";
        cout << endl;
    }
}

// function that multiplies a number by 2
int timesTwo(int num) {
    /* return type int which indicates
     that an integer is being returned */
    return num * 2;
}

// except it does not anything it only outputs to the console
void timesTwoVoid(int num) {
    /* return type void which indicates
     that an nothing is being returned */
    cout<< num*2<<endl;
}

// returns the square root of a number as a double
double squareroot(double n) { /*return type double which indicates
                               that a decimal is being returned*/
    double root = n / 2;
    
    for (int i = 0; i < 20; i++) {
        root = (.5) * (root + (n / root));
    }
    
    return root;
}

void dogWalk(int steps){
    for (int step = 0; step < steps; step++){
        cout << "dog walked "<< step << " steps!"<< endl;
    }
}

// Notice that this function does not return anything!
void swap_values(int &variable1, int &variable2) {
    int temp;           // temporary storage for swap
    
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
}

// Notice that this function does not return anything!
void no_swap_values(int variable1, int variable2) {
    int temp;           // temporary storage for swap
    
    temp = variable1;
    variable1 = variable2;
    variable2 = temp;
    
}

int menu(){
    int iValor;
    
    cout << "1. timesTwo" <<
    "\n2. timesTwoVoid" <<
    "\n3. squareroot" <<
    "\n4. dogWalk" <<
    "\n5. swap_values - Paso de parámetros por referencia" <<
    "\n6. no_swap_values - Paso de parámetros por valor" <<
    "\n7. pastel" <<
    "\n0. Terminar" <<
    "\nTeclea la opcion:";
    cin >> iValor;
    
    return iValor;
    
}

void suma_posiciones(int arr[], int size){
 // Leer la cantidad de valores a procesar
    int iN, iAcumPares, iAcumImpares;
    cin >> iN;
    iAcumPares = 0;
    iAcumImpares = 0;
    // Leer los valores a procesar
    for (int iR = 0;  iR < iN ; iR++){
        cin >> arr[iR];
        if (  iR % 2 == 0 ) // Par
        {
            iAcumPares = iAcumPares + arr[iR];
        }
    }
        
        
    
    
    
    
    
}

int main() {
    int first_num, second_num, iValor, largo, ancho;
    double result;
    int arreglo[100];
    

    
    //1. Inicializar la vcc antes del ciclo
    iValor = menu();
    
    while (iValor != 0)
    {
        switch (iValor) {
            case 1:
                cout << timesTwo(5) << endl;
                break;
            case 2:
                timesTwoVoid(5);
                break;
            case 3:
                
                result = squareroot(788);
                cout << "Resultado sqrt(788) =" << result << endl;
                
            case 4:
                dogWalk(10);
                break;
            case 5:
                first_num = 7;
                second_num = 8;
                
                cout << "Two numbers before swap function: 1) " << first_num << " 2) " << second_num << endl;
                swap_values(first_num, second_num);;
                cout << "The numbers after swap function: 1) " << first_num << " 2) " << second_num << "\n";
                break;
            case 6:
                first_num = 7;
                second_num = 8;
                cout << "Two numbers before swap function: 1) " << first_num << " 2) " << second_num << endl;
                no_swap_values(first_num, second_num);
                cout << "The numbers after swap function: 1) " << first_num << " 2) " << second_num << endl;
                break;
            case 7:
                cout << "largo:" ;
                cin >> largo;
                cout << "ancho:";
                cin >> ancho;
                dibuja_pastel(largo, ancho);
                break;
            default:
                cout << "Opcion incorrecta!!\n";
                
        } // fin switch
        
        // Actualizar la vcc dentro del ciclo
        iValor = menu();
    }// fin while
   
   
   
    return 0;
}

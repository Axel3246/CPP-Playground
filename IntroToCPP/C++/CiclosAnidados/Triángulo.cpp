#include <iostream>
using namespace std;

void triangulo(int v){
    //Determinación Largo
    for(int l = 1, a = 0; l <= v; l++, a++){
        //cout de asteriscos
        for (int j = 1; j <= l; j++)
            cout << '*';
        cout << endl;
        
    }
}
//Main con los datos iniciales
int main(){
    int n;
    cin >> n;
    triangulo(n);
}
#include <iostream>
#include <string>
using namespace std;

#include "Tierra.h"

int main() {

    Planeta planeta1(1, "Mercurio", 0);
    Tierra planeta2(3, "Tierra", 1, 7700000000);
    cout.precision(2);
    cout << fixed;
    
    cout << endl;
    planeta1.muestra();
    planeta2.muestra();
    cout << endl;
    
    return 0;
}

/*
Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {

        // *Se crea un vector auxiliar 
        vector<int> zero;
        // * Recorremos el vector arr original y si encontramos un 0, le hacemos doble pushback
        for(int i=0; i < arr.size(); i++){
            if(arr[i] == 0){
                zero.push_back(arr[i]);
                zero.push_back(arr[i]);
            }
            // * si no es cero simplemente lo pasamos igual
            else if (arr[i] != 0){
                zero.push_back(arr[i]);
            }
        }
        // * Finalmente, hacemos override al vector original con el vector auxiliar
        for(int i=0; i < arr.size(); i++){
            arr[i] = zero[i];
        }
    }
};  
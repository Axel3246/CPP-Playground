#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/

class Solution
{
public:
    //* Se tiene un vector de enteros con numeros y un target al que se quiere llegar
    //* Proporcionado por LeetCode
    vector<int> twoSum(vector<int> &nums, int target)
    {
        //*Mapa con el valor y el indice
        unordered_map<int, int> indice;
        //*Ciclo que recorrera todo el vector q se le este pasando,
        //*el cual es nums y puede cambiar por el &
        for (int i = 0; i < nums.size(); i++)
        {
            // * NumeroBuscado servira como B - C = A, por lo que
            // * practicamente estamos viendo si el residuo se encuentra
            // * en el vector dado
            int numeroBuscado = target - nums[i];
            // *En esta seccion usamos find(), funcion de los unordered map
            // *para saber si encontramos el valor que se estaba buscando
            // *El operador end define cuando se acaba la tabla hash
            if (indice.find(numeroBuscado) != indice.end())
            {
                // *Retornamos el indice del numero encontrado y el segundo numero
                // *que se necesitaba
                return {indice[numeroBuscado], i};
            }
            // ? Agregamos el numero a la tabla hash, la cual nos ayudara a encontrar el resultado
            indice[nums[i]] = i;
        }
        // !Lei por ahi que se retorna NULL, algo vacio.
        return {};
    }
};
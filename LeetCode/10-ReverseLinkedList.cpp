/*
Given the head of a singly linked list, reverse the list, and return the reversed list.
*/

// Definition for singly-linked list.

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        // * Inicializamos a curr en NULL
        ListNode* curr = NULL;
        // * Mientras tengamos
        while (head) {
            // * Creamos un puntero auxiliar para reversear la linked list, la cual estara apuntando al segundo elemento de la lista original
            ListNode* next = head -> next;
            // * el segundo elemento de la linked list ahora apuntara a nada, por lo que solo se queda con el primer elemento
            head -> next = curr;
            // * Guardamos el valor de head en curr, ser iran agregando los ultimos elementos (al ser iguales solo se copian)
            curr = head;
            // * Igualamos head a next para comenzar a iterar la lista ocn los vlaores restantes de los nodos
            head = next;
        }
        return curr;
    }
};


#include <iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:

    int buenosNodos = 0;

    void searchGn(TreeNode *root, int valorMaxNodo){

        // * Primera condicion para la recursividad, si root = nullptr solo se regresa
        if (root == nullptr){
            return;
        }
        // * Segunda condicion: checando que el nodo actual (root) tenga mas valor que el maximo que se tenga
        if(root->val >= valorMaxNodo){
            buenosNodos += 1; // * Decimos que es bueno y se añade uno al contador
            valorMaxNodo = root->val; // * cambiamos el valor maximo al de la raiz
        }

        // * se usa el recorrido preorden, en este caso, para analizar los buenos nodos
        searchGn(root->left, valorMaxNodo); // * Nos movemos al hijo izquierdo y se compara
        searchGn(root->right, valorMaxNodo); // * luego cuando ya no exista izquierdos, pasamos al derecho
    }


    int goodNodes(TreeNode *root)
    {
        searchGn(root, -9999999); // * se pasa la raiz y un valor muy bajo, pues el nodo puede salir negativo
        return buenosNodos;
    }
};



#include <iostream>
#include <queue>
#include <stack>

using namespace std;

// * Actividad 3.1
// * Matricula: A00829837
// * Nombre: Axel Amós Hernández Cárdenas

// * Método que regresa la impresion de un arbol por el recorrido:
// * 1 : PreOrden
// * 2 : Inorden
// * 3 : PostOrden
// * 4 : LevelByLevel
// ? Complejidad: O(1)
void BST::print(int tipo){

    switch(tipo){

        case 1: preOrden(root);
        break;

        case 2: inOrden(root);
        break;

        case 3: postOrden(root);
        break;

		case 4: levelByLevel(root);
		break;
    }
    cout << endl;
}

// * Método que imprime un arbol nivel por nivel
// ? Complejidad: O(n)
void BST::levelByLevel(NodeT *r){
    // * Si root no es nulo, hacemos el recorrido
    if(r != nullptr){

        // * Creacion de la lista y el apuntador al frente de la lista
        NodeT *frente;
        queue<NodeT*> fila;

        // * El primer valor a mandar es root, pues es el nivel 0
        fila.push(r);

        while(fila.size() > 0){
            
            frente = fila.front();

            // * Se imprime el valor del frente (nodo root -> nizq -> nder...)
            cout << frente->getData() << " ";

            // * Sacamos el valor
            fila.pop();

            // * Agregamos hijo izquierdo si encuentra uno
            if(frente->getLeft() != nullptr){
                fila.push(frente->getLeft());
            }

            // * Agragamos hijo derecho si encuentra uno
            if(frente->getRight() != nullptr){
                fila.push(frente->getRight());
            }    
            // * Se vuelve a iterar y ahora el nodo es el hijo izq de root, o en todo caso,
            // * el derecho.
        }
    }
}

// * Método que retorna la altura de un arbol
// ? Complejidad: O(n)
int BST::height(){
    
    return height_Helper(root);
}

// * Método helper que calcula la altura de un arbol recursivamente
// ? Complejidad: O(n)
int BST::height_Helper(NodeT *r){
    
    if (r != nullptr){
        /*
        int alturaIzq = height_Helper(r->getLeft());
        int alturaDer = height_Helper(r->getRight());
        return (alturaIzq > alturaDer) ? 1 + alturaIzq : 1 + alturaDer
        */
        // * Retornamos 1 + la altura máxima de los izquierdos y derechos (como en el size)
        return 1 + max(height_Helper(r->getLeft()), height_Helper(r->getRight()));
    }
    else{
        return 0;
    }
}

// * Método que regresa los ancestros de un nodo
// ? Complejidad: O(n) 
void BST::ancestors(int data){

    if(root != nullptr){
        
        NodeT *curr = root;

        if(curr->getData() == data){

            cout << "SIN ANCESTROS" << endl;
            return;
        }

        stack<int> ancestor;
        int found = 0;
        while(curr != nullptr && curr->getData() != data){

            ancestor.push(curr->getData());
            curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();    
        }
        if(curr == nullptr){
            cout << "DATO INEXISTENTE" << endl;
        }
        else{

            while (!ancestor.empty()){
                cout << ancestor.top() << " "; // * observa el tope de la pila
                ancestor.pop();    
            }
            cout << endl;            
        }
    }
}


// * Método que regresa el nivel de un nodo en un árbol binario
// ? Complejidad: O(n) 
int BST::whatLevelAmI(int data){
    
    if(root != nullptr){

        NodeT *curr = root;
        int nivel = 0;
        // * Si es root, esta en el nivel 0
        while(curr != nullptr){
            if (curr->getData() == data){

                return nivel;
            }
            // * Aumentamos el contador
            nivel++;
            // * Buscamos el dato con curr
            curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        }
    }    
    return -1;
}

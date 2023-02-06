/*
Nombre: Axel Amos Hernández Cárdenas - A00829837
Fecha de Creación: 15 de Octubre del 2021
Descripción: Este programa es la clase de BST con metodos extra de la tarea 3.1 + 3.2
*/

#include "NodeT.h"

#include <queue>
#include <stack>

class BST{  

    public:

        BST();
        ~BST();
        bool search(int data);
        void add(int data);
        void remove(int data);
        void print(int tipo);
        int size();
        int height();
        void ancestors(int data);
        int whatLevelAmI(int data);
		BST(const BST &otro); // simular preorden
		int maxWidth();
		int nearestRelative(int data1, int data2);
		bool operator==(const BST &otro); // simular preorden

    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int pred(NodeT *r);
        int succ(NodeT *r);
        void preOrden(NodeT *r);
        void inOrden(NodeT *r);
        void postOrden(NodeT *r);
        void levelByLevel(NodeT *r);
        void destuye_Helper(NodeT *r);
        int size_Helper(NodeT *r);
        int height_Helper(NodeT *r);
		bool oper_Helper(NodeT *lhs, NodeT *rhs);
		NodeT* BST_Helper(NodeT *r);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destuye_Helper(root);
}

// * Método de ayuda para el destroyer de HELPER
// ? Complejidad O(n)
void BST::destuye_Helper(NodeT *r){
	if (r != nullptr){
		destuye_Helper(r->getLeft());
		destuye_Helper(r->getRight());
		delete r;
	}
}

// * Método que retorna el numero de hijos de un nodo
// ? Complejidad O(n)
int BST::howManyChildren(NodeT *r){
	int cont = 0;
	if (r->getLeft() != nullptr){
		cont++;
	}
	if (r->getRight() != nullptr){
		cont++;
	}
	return cont;
}

// * Predecesor solo se manda ejecutar con nodos que tienen 2 hijos
// *		==> es el mayor de los menores
// ? Complejidad: O(n)
int BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}

// * Sucesor solo se manda ejecutar con nodos que tienen 2 hijos.
// *     ==> es el menor de los mayores
// ? Complejidad: O(n)
int BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

// * Metodo que busca un dato en el arbol
// ? Complejidad: O(n)
bool BST::search(int data){
	NodeT *curr = root;
	while (curr != nullptr){
		if (curr->getData() == data){ // Si encontré el dato
		 	return true;
		}
		// if (curr->getData() > data){
		// 	curr = curr->getLeft();
		// }
		// else{
		// 	curr = curr->getRight();
		// }
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false;  // si root es nullptr o que el dato no esta.
}

// * Metodo que agrega un dato en el arbol
// ? Complejidad: O(n)
void BST::add(int data){
	if (root == nullptr){
		root = new NodeT(data);
	}
	else{
		NodeT *curr = root;
		NodeT *parent = nullptr;
		while (curr != nullptr){
			if (curr->getData() == data){
				return;
			}
			parent = curr;
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		}
		// if (parent->getData() > data){
		// 	parent->setLeft(new NodeT(data));
		// }
		// else{
		// 	parent->setRight(new NodeT(data));
		// }
		parent->getData() > data ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}

// * Metodo que elimina un dato en el arbol
// ? Complejidad: O(n)
void BST::remove(int data){
	// localizar al dato que se quiere borrar
	// si se esta el dato, checar cuantos hijos tiene, y dependiendo de esto procedemos a borra
	NodeT *curr = root;
	NodeT *parent = nullptr;
	// cicla hasta que no está o lo localiza
	while (curr != nullptr && curr->getData() != data){ 
		parent = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (curr == nullptr){
		return; // El dato no existe
	}
	int cantHijos = howManyChildren(curr);
	switch (cantHijos){
		case 0: if (parent == nullptr){
					root = nullptr;
				}
				else{
					if (parent->getData() > data){
						parent->setLeft(nullptr);
					}
					else{
						parent->setRight(nullptr);
					}
				}
				delete curr;
				break;
		case 1: if (parent == nullptr){		// El que quiero borrar es root y tiene 1 hijp
					if (curr->getLeft() != nullptr){
						root = curr->getLeft();
					}
					else{
						root = curr->getRight();
					}
				}
				else{
					if (parent->getData() > data){
						// El dato que quiero borrar es hijo izq de parent
						if (curr->getLeft() != nullptr){
							// El único hijo del que quiero borrar esta a la izq
							parent->setLeft(curr->getLeft());
						}
						else{
							// El único hijo del que quiero borrar esta a la der
							parent->setLeft(curr->getRight());
						}
					}
					else{
						// El dato que quiero borrar es hijo der de parent
						if (curr->getLeft() != nullptr){
							// El único hijo del que quiero borrar esta a la izq
							parent->setRight(curr->getLeft());
						}
						else{
							// El único hijo del que quiero borrar esta a la der
							parent->setRight(curr->getRight());
						}
					}
				}
				delete curr;
				break;
		case 2:	int sucesor = succ(curr);
				remove(sucesor);
				curr->setData(sucesor);
				break;
	}
}

// * Método que regresa la impresion de un arbol por el recorrido:
// * 1 : PreOrden
// * 2 : Inorden
// * 3 : PostOrden
// * 4 : LevelByLevel
// ? Complejidad: O(1)
void BST::print(int tipo){
	switch (tipo){
		case 1 : preOrden(root);
				 break;
		case 2 : inOrden(root);
				 break;
		case 3 : postOrden(root);
				 break;
	    case 4: levelByLevel(root);
		         break;
    }
    cout << endl;
}

// * Metodo que recorre el arbol en preOrden
// ? Complejidad: O(n)
void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

// * Metodo que recorre el arbol en inOrden
// ? Complejidad: O(n)
void BST::inOrden(NodeT *r){
	if (r != nullptr){
		inOrden(r->getLeft());
		cout << r->getData() << " ";
		inOrden(r->getRight());
	}
}

// * Metodo que recorre el arbol en postOrden
// ? Complejidad: O(n)
void BST::postOrden(NodeT *r){
	if (r != nullptr){
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData() << " ";
	}
}

// * Metodo que regresa el size del Arbo
// ? Complejodad: O(n)
int BST::size(){
	return size_Helper(root);
}

// * Metodo helper de Size
// ? Complejodad: O(n)
int BST::size_Helper(NodeT *r){
	if (r != nullptr){
		return 1 + size_Helper(r->getLeft()) + size_Helper(r->getRight());
	}
	else{
		return 0;
	}
}

// * Metodo que recorre el arbol en levelByLevel
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

// * Método que regresa los ancestros de un nodo dado
// ? Complejidad: O(n) 
void BST::ancestors(int data){

    if(root != nullptr){
        
        NodeT *curr = root;

        if(curr->getData() == data){

            cout << "SIN ANCESTROS" << endl;
            //return;
        }

        stack<int> ancestor;
        
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

// * Método que regresa un entero con la máxima anchura del árbol
// ? Complejidad: O(n)
int BST::maxWidth(){
	
	if(root != nullptr){

		NodeT *frente;
		int width = 0;
		queue<NodeT*> queue1, queue2;

		queue1.push(root);

		while(queue1.size() > 0){

			while(!queue1.empty()){

				frente = queue1.front();
				queue2.push(frente);
				queue1.pop();
			}
			if(queue2.size() > width){

				width = queue2.size();
				
			}

			while(!queue2.empty()){

				frente = queue2.front();
				queue2.pop();
			
				if(frente->getLeft() != nullptr){

					queue1.push(frente->getLeft());
				}
				if(frente->getRight() != nullptr){

					queue1.push(frente->getRight());
				}
			}
		}
		return width;
	}
	return 0;
}	// push q1, push q2, pop q1, validate size, push nodos hijo, repeat

// * Método que regresa el ancestro más cercano de dos datos
// ? Complejidad: O(height)
int BST::nearestRelative(int data1, int data2){
        
        NodeT *curr1 = root, *curr2 = root;
		int nearRelative = 0;

		queue<int> queue1, queue2;

		while(curr1->getData() != data1){

            queue1.push(curr1->getData());
            curr1 = (curr1->getData() > data1) ? curr1->getLeft() : curr1->getRight();    
        }

		while(curr2->getData() != data2){

            queue2.push(curr2->getData());
            curr2 = (curr2->getData() > data2) ? curr2->getLeft() : curr2->getRight();    
        }

		while(!queue1.empty() && !queue2.empty()){

			if(queue1.front() == queue2.front()){
				nearRelative = queue1.front();
			}
			queue1.pop();
			queue2.pop();	
		}
		return nearRelative;
}

// * Clon constructor de BST
// ? Complejidad: O(n)
BST::BST(const BST &otra){

	root = BST_Helper(otra.root);
}

// * Método que regresa un clon de un arbol
// ? Complejidad: O(n)
NodeT* BST::BST_Helper(NodeT *r){

	if(r == nullptr){
		return nullptr;
	}
		NodeT* curr = new NodeT(r->getData());
		curr->setLeft(BST_Helper(r->getLeft()));
		curr->setRight(BST_Helper(r->getRight()));	
	return curr;
}

// * Método que valida si dos arboles son iguales
// ? Complejidad: O(n)
bool BST::operator==(const BST &otro){

	//NodeT *root2 = otro.root;
	return oper_Helper(root, otro.root);
}

// * Método helper que valida si dos arboles son iguales
// ? Complejidad: O(n)
bool BST::oper_Helper(NodeT *lhs, NodeT *rhs){

	
	if((lhs == nullptr) && (rhs == nullptr)){
		return true;
	}
	if(lhs == nullptr && (rhs != nullptr) || (lhs != nullptr) && (rhs == nullptr)){
		
		return false;
	}
	
	return (lhs->getData() == rhs->getData() && oper_Helper(lhs->getLeft(), rhs->getLeft()) && oper_Helper(lhs->getRight(), rhs->getRight()));
            
}	



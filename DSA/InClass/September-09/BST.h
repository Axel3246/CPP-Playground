
#include "NodeT.h"

class BST{  

    public:

        BST();
        ~BST();
        bool search(int data);
        void add(int data);
        void remove(int data);
        void print(int tipo);
        int size();

    private:
        NodeT *root;
        int howManyChildren(NodeT *r);
        int succ(NodeT *r);
        int pred(NodeT *r);
        void preOrden(NodeT *r);
        void inOrden(NodeT *r);
        void postOrden(NodeT *r);
        void destruye_Helper(NodeT *r);
        int size_Helper(NodeT *r);
};

BST::BST(){

    root = nullptr;
}

BST::~BST(){

    destruye_Helper(root);
}

void BST::destruye_Helper(NodeT *r){ // * Idea del postOrden

    if (r != nullptr){
        destruye_Helper(r->getLeft());
        destruye_Helper(r->getRight());
        delete r;
    }
}

int BST::howManyChildren(NodeT *r){

    int cont = 0;
    if (r->getLeft() != nullptr){
        cont++;
    }
    if(r->getRight() != nullptr){
        cont++;
    }
    return cont;
}

// * Predecesor solo se manda ejecutar con nodos que tienen dos hijos
// *            =====> Mayor de los menores
int BST::pred(NodeT *r){

    NodeT *curr = r->getLeft();

    while(curr->getRight() != nullptr){
        curr = curr->getRight();
    }
    return curr->getData();
    
}

// * Predecesor solo se manda ejecutar con nodos que tienen dos hijos
// *            =====> Menor de los mayores
int BST::succ(NodeT *r){
    
    NodeT *curr = r->getRight();

    while(curr->getLeft() != nullptr){
        curr = curr->getLeft();
    }
    return curr->getData();
    
}

bool BST::search(int data){

    NodeT *curr = root;
    while (curr != nullptr){

        if (curr->getData() == data){
            
            return true;
        } 
        /*
        if(curr->getData() > data){
            curr = curr->getLeft();
        }
        else{
            curr = curr->getRight();
        }
        */
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
    }
    return false; // * Si root es null o el dato no esta
}

void BST::add(int data){

    if(root == nullptr){
        
        root = new NodeT(data);
    }
    else{

        NodeT *curr = root;
        NodeT *parent = nullptr;

        while(curr != nullptr){

            if(curr->getData() == data){

                return;
            }
            parent = curr;
            curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
        }
        /*
        if(parent->getData() > data){
            parent->setLeft(new NodeT(data));
        }
        else{
            parent->setRight(new NodeT(data));
        }
        */
        parent->getData() > data ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
    }
}

void BST::remove(int data){

    NodeT *curr = root;
    NodeT *parent = nullptr;

    // * Ciclar hasta que vea que no está en el arbol o lo encuentre

    while(curr != nullptr && curr->getData() != data){

        parent = curr;
        curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();

    }

    if(curr == nullptr){

        return; // * Me salgo al no encontrar el dato
    }

    // * Debemos visualizar cuantos hijos tiene
    int cantHijos = howManyChildren(curr);

    switch (cantHijos){

    case 0:

        if (parent == nullptr){
            
            root = nullptr;
            //delete curr;
        }
        else{

            if(parent->getData() > data){
                // * El que quieor borrar esta a la izq del padre
                parent->setLeft(nullptr);
                //delete curr;
            }
            else{
                // * El que quieor borrar esta a la der del padre
                parent->setRight(nullptr);
                //delete curr;
            }
        }
        delete curr;
        break;
    
    case 1:

        if(parent == nullptr){ // * El que quiero borrar es root
            // * El que quiero borrar está como root y tiene un hijo
            if(curr->getLeft() != nullptr){ // * Unico hijo a la izquierda
                
                root = curr->getLeft();
            }
            else{ // * El unico hijo esta a la derecga
                root = curr->getRight();
            }
        }
        else{ // * El que quieor borrar está dentro del arbol

            if(parent->getData() > data){ // * El que quiero borrar está a la izq de parent
                
                if(curr->getLeft() != nullptr){ // * Unico hijo a la izquierda

                    parent->setLeft(curr->getLeft()); // * Izq - Izq
                }
                else{ // * Unico hijo a la derecha de curr

                    parent->setLeft(curr->getRight()); // * Izq - Der
                }
            }
            else{ // * El que quiero borrar esta a la der de parent

                if(curr->getLeft() != nullptr){ // * El unico hijo está a la izq de curr
                    
                    parent->setRight(curr->getLeft()); // * Der - Izq
                }
                else{ // * Unico hijo a la derecha de curr
                    parent->setRight(curr->getRight()); // * Der - Der
                }
            }
        }
        delete curr;
        break;

    case 2:

        int sucesor = succ(curr); // * curr tiene 2 hijos
        remove(sucesor); // * sucesor tiene garantia que tiene 0 ó 1 hijo
        curr->setData(sucesor); // * cambio la info del nodo
        break;

    }
}

// * Tipo:
// * 1 : PreOrden
// * 2 : Inorden
// * 3 : PostOrden

void BST::print(int tipo){

    switch(tipo){

        case 1: preOrden(root);
        break;

        case 2: inOrden(root);
        break;

        case 3: postOrden(root);
        break;
    }
    cout << endl;
}

void BST::preOrden(NodeT *r){

    if(r != nullptr){
        cout << r->getData() << " ";
        preOrden(r->getLeft());
        preOrden(r->getRight());
    }
}

void BST::inOrden(NodeT *r){

    if(r != nullptr){

        inOrden(r->getLeft());
        cout << r->getData() << " ";
        inOrden(r->getRight());
    }
}

void BST::postOrden(NodeT *r){

    if(r != nullptr){

        postOrden(r->getLeft());
        postOrden(r->getRight());
        cout << r->getData() << " ";
    }
}

int BST::size(){

    return size_Helper(root);
}

int BST::size_Helper(NodeT *r){

    if(r != nullptr){
        return 1 + size_Helper(r->getLeft()) + size_Helper(r->getRight());
    }
    else{
        return 0;
    }
}

//#include "BST_3_1.h"

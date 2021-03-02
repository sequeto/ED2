#include <iostream>
#include "QuadTree.h"
#include "Node.h"

using namespace std;


// -----------------------------------------------------------
// Construtor
QuadTree::QuadTree(){
    this->root = NULL;
}

// -----------------------------------------------------------
// Destrutor

QuadTree::~QuadTree(){

}

// -----------------------------------------------------------
// Retorna valor na Raiz da Árvore
int QuadTree::getRoot(){
    if(this->root == NULL){
        cout << "Arvore Vazia" << endl;
        return -1;
    }

    else{
        return this->root->getInfo();
    }
}

// -----------------------------------------------------------
// Verifica se Árvore está vazia
bool QuadTree::isEmpty(){
    return(this->root == NULL);
}

// -----------------------------------------------------------
// Verifica se o valor está na Árvore
bool QuadTree::search(int value){
    return auxSearch(this->root, value);
}

// -----------------------------------------------------------
bool QuadTree::auxSearch(Node* p, int value){
    if(p == NULL){
        return false;
    }

    else if(p->getInfo() == value){
        return true;
    }

    else{
        // Implementar
    }
}

// -----------------------------------------------------------
// Insere um elemento na árvore com o valor definido
void QuadTree::insert(int value){
    this->root = auxInsert(this->root, value);
}

// -----------------------------------------------------------
Node* QuadTree::auxInsert(Node* p, int value){
    if(p == NULL){
        p = new Node();
        p->setInfo(value);
        // Implementar
    }

    else {
        // Implementar
    }

    return p;
}
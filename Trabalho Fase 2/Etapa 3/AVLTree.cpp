#include <iostream>
#include "AVLTree.h"

AVLTree::AVLTree(){
    this->raiz = NULL;
}

AVLTree::~AVLTree(){
    this->raiz = NULL;
}

bool AVLTree::busca(int info){
    return auxBusca(this->raiz, info);
}

bool AVLTree::auxBusca(Node* p, int info){
    if(p == NULL){
        return false;
    }

    else if(p->getInfo() == info){
        return true;
    }

    else{
        if(info < p->getInfo()){
            return auxBusca(p->getEsq(), info);
        }

        else{
            return auxBusca(p->getDir(), info);
        }
    }
}

void AVLTree::rotacaoEsquerda(Node  * p){
	Node * q = p->getDir();
	p->setDir(q->getEsq());
	q->setEsq(p);
}

void AVLTree::rotacaoDireita(Node  * p){
	Node * q = p->getDir();
	p->setEsq(q->getDir());
	q->setDir(p);
}

void AVLTree::duplaRotacaoEsquerda(Node  * p){
	rotacaoDireita(p->getDir());
	rotacaoEsquerda(p);
}

void AVLTree::duplaRotacaoDireita(Node  * p){
	rotacaoEsquerda(p->getEsq());
	rotacaoDireita(p);
}
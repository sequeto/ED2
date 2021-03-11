#include <iostream>
#include "Node.h"


Node::Node(int info){
    this->fatorBalanceamento = 0; 
    this->info = info;
    this->pai = NULL;
    this->esq = NULL;
    this->dir = NULL;
}


Node::~Node(){
    
}

int Node::getInfo(){ 
    return this->info;
}

int Node::getFatorBalanceamento(){ 
    return this->fatorBalanceamento;
}

Node* Node::getEsq(){ 
    return esq;
}
Node* Node::getDir(){ 
    return this->dir;
}
Node* Node::getPai(){ 
    return this->pai;
}

void Node::setInfo(int info){ 
    this->info = info;
}

void Node::setFatorBalanceamento(int fator){ 
    this->fatorBalanceamento = fator;
}

void Node::setEsq(Node* p){ 
    this->esq = p;
}

void Node::setDir(Node* p){ 
    this->dir = p;
}

void Node::setPai(Node* p){ 
    this->pai = p;
}


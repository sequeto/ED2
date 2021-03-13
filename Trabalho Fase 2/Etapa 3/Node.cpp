#include <iostream>
#include "Node.h"


Node::Node(){

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


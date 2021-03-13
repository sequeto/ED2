#include <iostream>
#include "NodeAVL.h"


NodeAVL::NodeAVL(){

}

NodeAVL::~NodeAVL(){
    
}

int NodeAVL::getInfo(){ 
    return this->info;
}

int NodeAVL::getFatorBalanceamento(){ 
    return this->fatorBalanceamento;
}

NodeAVL* NodeAVL::getEsq(){ 
    return esq;
}
NodeAVL* NodeAVL::getDir(){ 
    return this->dir;
}

void NodeAVL::setInfo(int info){ 
    this->info = info;
}

void NodeAVL::setFatorBalanceamento(int fator){ 
    this->fatorBalanceamento = fator;
}

void NodeAVL::setEsq(NodeAVL* p){ 
    this->esq = p;
}

void NodeAVL::setDir(NodeAVL* p){ 
    this->dir = p;
}


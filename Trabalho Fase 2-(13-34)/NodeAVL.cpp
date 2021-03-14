/**
    UNIVERSIDADE FEDERAL DE JUIZ DE FORA
    INSTITUTO DE CIÊNCIAS EXATAS
    DEPARTAMENTO DA CIẼNCIA DA COMPUTAÇÃO

    TRABALHO DE ESTRUTURA DE DADOS 2(||) - 2020.3 (ERE)
    PROF.DR.MARCELO CANIATO RENHE

    GRUPO:
    BEATRIZ CUNHA RODRIGUES        MAT 201776038
    IVANYLSON HONORIO GONÇALVES    MAT 201776002
    JOÃO PEDRO SEQUETO NASCIMENTO  MAT 201776022

    main.cpp
    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 *.h *.cpp  -o main && ./main brazil_covid19_cities.csv
    WINDOWS:    cls & g++ -std=c++11 *.h *.cpp  -o main & main brazil_covid19_cities.csv

*/
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


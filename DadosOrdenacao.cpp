#include <iostream>
#include "DadosOrdenacao.h"

DadosOrdenacao::DadosOrdenacao(){
    qntComparacoes = 0;
    qntTrocas = 0;
}

DadosOrdenacao::~DadosOrdenacao(){
    qntComparacoes = 0;
    qntTrocas = 0;
}

void DadosOrdenacao::incrementaTrocas(){
    qntTrocas++;
}

int DadosOrdenacao::getTrocas(){
    return qntTrocas;
}

void DadosOrdenacao::incrementaComparacoes(){
    qntComparacoes++;
}

int DadosOrdenacao::getComparacoes(){
    return qntComparacoes;
}

void DadosOrdenacao::clear(){
    qntComparacoes = 0;
    qntTrocas = 0;
}
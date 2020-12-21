#include <iostream>
#include "Estado.h"
#include "Cidade.h"

Estado::Estado(){

}

Estado::~Estado(){

}

string Estado::getNome(){
    return this->nome;
}

void Estado::setNome(string nome){
    this->nome = nome;
}

void Estado::setCidade(Cidade cidade){
    this->cidades.push_back(cidade);
}

Cidade Estado::getCidadeAt(int index){
    return this->cidades.at(index);
}

void Estado::ordenaCidades(){

}

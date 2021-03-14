#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Hash.h"
#include "Data_Casos.h"

using namespace std;

Hash::Hash(int tamanho){
    this->tamanho = tamanho;
    registros = new ListaEncad* [tamanho];
    for(int i=0; i < tamanho; i++){
        registros[i] = new ListaEncad();
    }
}

Hash::~Hash() {
    for(int i=0; i < tamanho; i++){
        delete registros[i];
    }
    delete [] registros;
}

int Hash::funcaoHash(string data, string codigo){
    long long int cod = stol(codigo);
    data.replace(4,1,"");
    data.replace(6,1,"");
    long long int dataConv = stol(data);

    long long int chave = (cod + dataConv) * (cod + dataConv);
    long long int index = (chave % this->tamanho);
    return index;
}

void Hash::insere(Data_Casos* data){
    int index = funcaoHash(data->getData(), data->getCodigo());
    No* elemento;

    elemento = registros[index]->busca(data);

    if(elemento == NULL) {
        elemento = registros[index]->insereInicio(data);
    }
}


No* Hash::busca(Data_Casos* data) {
    No* elemento;
    int index = funcaoHash(data->getData(), data->getCodigo());

    elemento = registros[index]->busca(data);
    return elemento;
}
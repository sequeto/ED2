#include <iostream>
#include <string>
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
    // 27-03-2020
    int cod = stoi(codigo);
    data.replace(2,1,"");
    data.replace(4,1,"");
    int dataConv = stoi(data);

    int soma = cod + data;
    int index = (soma % 5) % this->tamanho;
    
    return index;
}

void Hash::insere(Data_Casos* data, int tamanho){
    //fazer o tratamento de colis�o
    int index = funcaoHash(tamanho, data->getData(), data->getCodigo());
    No* elemento;

    elemento = registros[index]->busca(data);

    if(elemento == NULL) {
        elemento = registros[index]->insereInicio(data);
    }
}


No* Hash::busca(int key, Data_Casos* data) {
    No* elemento;
    int index = funcaoHash(tamanho, data->getData(), data->getCodigo());

    elemento = registros[index]->busca(data);
    return elemento;
}
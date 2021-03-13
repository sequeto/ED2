#include <iostream>
#include "Hash.h"
#include "Data_Casos.h"

using namespace std;

Hash::Hash(int tamanho){
    this->tamanho = tamanho;
    for(int i=0;i<tamanho;i++)
        data[i] = NULL;
}

Hash::~Hash() {}

int Hash::funcaoHash(int tamanho, string data, string codigo){


}

void Hash::insere(Data_Casos* data, int tamanho){
    //fazer o tratamento de colisão
    int index = funcaoHash(tamanho, data->data, data->codigo);


}

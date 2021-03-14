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
    int cod = stoi(codigo);
    data.replace(4,1,"");
    data.replace(6,1,"");
    int dataConv = stoi(data);


    int soma = (cod + dataConv);
    int index = (soma % this->tamanho);
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
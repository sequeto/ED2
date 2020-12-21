#include <iostream>
#include "Cidade.h"
#include "Data_Casos.h"

Cidade::Cidade(){

}

Cidade::~Cidade(){

}

string Cidade::getNome(){
    return this->nome;
}

void Cidade::setNome(string nome){
    this->nome = nome;
}

string Cidade::getCodigo(){
    return this->codigo;
}

void Cidade::setCodigo(string codigo){
    this->codigo = codigo;
}

void Cidade::setDataCasos(Data_Casos data){
    this->dataCasos.push_back(data);
    cout << "setou" << endl;
}

Data_Casos Cidade::getDataCasoAt(int index){
    return this->dataCasos.at(index);
}

void Cidade::ordenaDataCasos(){

}

int Cidade::getNumeroCasos(){
    return this->dataCasos.size();
}

void Cidade::setEstado(string estado){
    this->estado = estado;
}

string Cidade::getEstado(){
    return this->estado;
}
#include <iostream>
#include "Data_Casos.h"

Data_Casos::Data_Casos(){

}

Data_Casos::~Data_Casos(){

}

// retorna a data (string)
string Data_Casos::getData(){
    return this->data;
}

void Data_Casos::setData(string data){
    this->data = data;
}

// retorna numero de casos no dia
int Data_Casos::getCasos(){
    return this->casos;
}

void Data_Casos::setCasos(int casos){
    this->casos = casos;
}

// retorna numero de mortes no dia
int Data_Casos::getMortes(){
    return this->mortes;
}

void Data_Casos::setMortes(int mortes){
    this->mortes = mortes;
}

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
#include "NodeQ.h"
#include "City.h"

NodeQ::NodeQ(){

}
NodeQ::~NodeQ(){

}

// Getters
City* NodeQ::getCity(){
    return this->city;
}

NodeQ* NodeQ::getSW(){
    return this->sw;
}

NodeQ* NodeQ::getSE(){
    return this->se;
}

NodeQ* NodeQ::getNW(){
    return this->nw;
}

NodeQ* NodeQ::getNE(){
    return this->ne;
}

int NodeQ::getCoordX(){
    return this->coordx;
}

int NodeQ::getCoordY(){
    return this->coordy;
}

// Setters
void NodeQ::setCity(City* city){
    this->city = city;
}

void NodeQ::setNW(NodeQ* nw){
    this->nw = nw;
}

void NodeQ::setNE(NodeQ* ne){
    this->ne = ne;
}

void NodeQ::setSW(NodeQ* sw){
    this->sw = sw;
}

void NodeQ::setSE(NodeQ* se){
    this->se = se;
}

void NodeQ::setCoordX(int x){
    this->coordx = x;
}

void NodeQ::setCoordY(int y){
    this->coordy = y;
}
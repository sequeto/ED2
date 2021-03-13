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
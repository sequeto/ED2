#include <iostream>
#include "Node.h"
#include "City.h"

Node::Node(){

}
Node::~Node(){

}

// Getters
City* Node::getCity(){
    return this->city;
}

Node* Node::getSW(){
    return this->sw;
}

Node* Node::getSE(){
    return this->se;
}

Node* Node::getNW(){
    return this->nw;
}

Node* Node::getNE(){
    return this->ne;
}

int Node::getCoordX(){
    return this->coordx;
}

int Node::getCoordY(){
    return this->coordy;
}

// Setters
void Node::setCity(City* city){
    this->city = city;
}

void Node::setNW(Node* nw){
    this->nw = nw;
}

void Node::setNE(Node* ne){
    this->ne = ne;
}

void Node::setSW(Node* sw){
    this->sw = sw;
}

void Node::setSE(Node* se){
    this->se = se;
}

void Node::setCoordX(int x){
    this->coordx = x;
}

void Node::setCoordY(int y){
    this->coordy = y;
}
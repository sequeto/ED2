#include <iostream>
#include "Node.h"

Node::Node(){

}
Node::~Node(){

}

// Getters
int Node::getInfo(){
    return this->info;
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
void Node::setInfo(int info){
    this->info = info;
}

void Node::setNW(Node nw){
    this->nw = nw;
}

void Node::setNE(Node ne){
    this->ne = ne;
}

void Node::setSW(Node sw){
    this->sw = sw;
}

void Node::setSE(Node se){
    this->se = se;
}

void Node::setCoordX(int x){
    this->coordx = x;
}

void Node::setCoordY(int y){
    this->coordy = y;
}
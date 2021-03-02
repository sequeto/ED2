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

// Setters
void Node::setInfo(int info){
    this->info = info;
}

void setNW(Node nw){
    this->nw = nw;
}

void setNE(Node ne){
    this->ne = ne;
}

void setSW(Node sw){
    this->sw = sw;
}

void setSE(Node se){
    this->se = se;
}

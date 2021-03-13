#include "No.h"
#include <iostream>

using namespace std;


No::No(){

}

No::~No(){

}

Data_Casos* No::getInfo(){
    return info;
}

No* No::getProx(){
    return prox;
}

void No::setInfo(Data_Casos* val){
    this->info = val;
}

void No::setProx(No* p){
    this->prox = p;
}
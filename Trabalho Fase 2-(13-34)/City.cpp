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
#include "City.h"

using namespace std;

City::City(){

}

City::~City(){
    
}

// Getters
int City::getState(){
    return this->state_code;
}

int City::getCity(){
    return this->city_code;
}

string City::getName(){
    return this->city_name;
}

float City::getLatitude(){
    return this->latitude;
}

float City::getLongitude(){
    return this->longitude;
}
bool City::getCapital(){
    return this->capital;
}

// Setters
void City::setState(int state){
    this->state_code = state;
}

void City::setCity(int city){
    this->city_code = city;
}

void City::setName(string name){
    this->city_name = name;
}

void City::setLatitude(float lati){
    this->latitude = lati;
}

void City::setLongitude(float longi){
    this->longitude = longi;
}

void City::setCapital(bool capital){
    this->capital = capital;
}
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
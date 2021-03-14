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
#ifndef CITY_H_INCLUDED
#define CITY_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;

/*
Latitude - Coord X 
Longitude - Coord Y 

*/

class City
{
    public:
        City();
        virtual ~City();
        
        // Getters
        int getState(); // Retorna código do estado
        int getCity(); // Retorna código da cidade
        string getName(); // Retorna nome da cidade
        float getLatitude(); // Retorna latitude da cidade
        float getLongitude(); // Retorna longitude da cidade
        bool getCapital(); // Retorna se a cidade é capital
        
        // Setters
        void setState(int state); 
        void setCity(int city); 
        void setName(string name); 
        void setLatitude(float lati);
        void setLongitude(float longi); 
        void setCapital(bool capital);
        

    private:
        int state_code;
        int city_code;
        string city_name;
        float  latitude;
        float  longitude;
        bool capital;

};

#endif

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
#ifndef NODEQ_H_INCLUDED
#define NODEQ_H_INCLUDED

#include "City.h"

#include <iostream>

using namespace std;

class NodeQ
{
    public:
        NodeQ();
        virtual ~NodeQ();
        
        // Getters
        City* getCity();

        NodeQ* getSW();
        NodeQ* getSE();

        NodeQ* getNW();
        NodeQ* getNE();

        int getCoordX();
        int getCoordY();

        // Setters
        void setCity(City* city);
        
        void setNW(NodeQ* nw);
        void setNE(NodeQ* ne);

        void setSW(NodeQ* sw);
        void setSE(NodeQ* se);

        void setCoordX(int x);
        void setCoordY(int y);

    private:
        NodeQ* nw;
        NodeQ* ne;
        NodeQ* sw;
        NodeQ* se;
        int coordx;
        int coordy;
        City* city;

};

#endif

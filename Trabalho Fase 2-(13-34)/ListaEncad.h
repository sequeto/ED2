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
#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"
#include "No.h"

#include <iostream>

using namespace std;

class ListaEncad
{
    public:
        ListaEncad();
        ~ListaEncad();
        No* insereInicio(Data_Casos* val);
        No* busca(Data_Casos* val);
        bool listaVazia();
    private:
        No* primeiro; // ponteiro para o primeiro
};

#endif 

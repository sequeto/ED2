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
#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

// Inclusão dos TADs
#include "AVLTree.h"
#include "ArvoreB.h"
#include "QuadTree.h"
#include "City.h"
#include "Hash.h"
#include "Data_Casos.h"

using namespace std;

class Testes
{
    public:
        Testes();
        ~Testes();
        void testeQuadtree(int n);
        void testeHash(int n);
        void testeAVL(int n);
        void testeB(int n);
};

#endif //TESTES_H_INCLUDED

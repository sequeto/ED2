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
#ifndef NODEAVL_H_INCLUDED
#define NODEAVL_H_INCLUDED

#include <iostream>



class NodeAVL{
    public:
        NodeAVL();
        virtual ~NodeAVL();
        int getInfo();
        void setInfo(int info);

        int getFatorBalanceamento();
        void setFatorBalanceamento(int fator);

        NodeAVL* getEsq();
        void setEsq(NodeAVL* p);

        NodeAVL* getDir();
        void setDir(NodeAVL* p);


    private:
        int info;
        int fatorBalanceamento;
        NodeAVL* esq;
        NodeAVL* dir;
};

#endif

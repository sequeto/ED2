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
#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "Data_Casos.h"
#include "ListaEncad.h"

class Hash
{
    public:
        Hash(int tamanho);
        virtual ~Hash();
        int funcaoHash(string data, string codigo);
        void insere(Data_Casos* registros);
        No* busca(Data_Casos* data);
    

    private:
        int tamanho;
        ListaEncad** registros;
};

#endif // HASH_H_INCLUDED

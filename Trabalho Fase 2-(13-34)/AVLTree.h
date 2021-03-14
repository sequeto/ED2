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
#ifndef AVLTREE_H_INCLUDED
#define AVLTREE_H_INCLUDED

#include "NodeAVL.h"
#include "Estatisticas.h"
#include <fstream>

class AVLTree{
    public:
        AVLTree();
        virtual ~AVLTree();   
        
        int getAltura();
        bool busca(int info, Estatisticas* statistics);
        void insercao(int info);
        void imprime();
        NodeAVL* verificaBalanceamento(NodeAVL* p);

    private:
        NodeAVL* raiz;
        bool auxBusca(NodeAVL* p, int info, Estatisticas* statistics);
        int auxGetAltura(NodeAVL* p);
        NodeAVL* auxInsercao(NodeAVL* p, NodeAVL* pai, int info);

        void auxImprime(NodeAVL* p, int k);

        NodeAVL*  rotacaoDireita(NodeAVL* p);
        NodeAVL*  rotacaoEsquerda(NodeAVL* p);
};

#endif //

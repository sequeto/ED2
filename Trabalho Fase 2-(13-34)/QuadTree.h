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
#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include <string>
#include "NodeQ.h"

using namespace std;

// Árvore Binária de Busca com Representação Encadeada

class QuadTree
{
    public:
        QuadTree();
        virtual ~QuadTree();

        string getRoot(); // Retorna valor na Raiz da Árvore
        bool isEmpty(); // Verifica se Árvore está vazia
        // bool search(int value); // Verifica se o valor está na Árvore
        void insert(City* city); // Insere um elemento na árvore com o valor definido
        string comparaQuadrantes(NodeQ* r, City* p); // Compara as coordenadas de dois nós para indicar o quadrante de localização de p  em relação a r

        
        void imprime();
        void auxImprime(NodeQ* p, int k);
    private:
        NodeQ* root; // Ponteiro para o nó raiz
        // bool auxSearch(NodeQ* p, int value);
        NodeQ* auxInsert(NodeQ* p, City* city);
        // NodeQ* free(NodeQ* p);
};

#endif

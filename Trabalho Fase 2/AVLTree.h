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
        void insercao(int info, Estatisticas* statistics);
        void imprime();
        NodeAVL* verificaBalanceamento(NodeAVL* p);

    private:
        NodeAVL* raiz;
        bool auxBusca(NodeAVL* p, int info, Estatisticas* statistics);
        int auxGetAltura(NodeAVL* p);
        NodeAVL* auxInsercao(NodeAVL* p, NodeAVL* pai, int info, Estatisticas* statistics);

        void auxImprime(NodeAVL* p, int k);

        NodeAVL*  rotacaoDireita(NodeAVL* p);
        NodeAVL*  rotacaoEsquerda(NodeAVL* p);
};

#endif //
#include "NodeAVL.h"

class AVLTree{
    public:
        AVLTree();
        virtual ~AVLTree();   
        
        int getAltura();
        bool busca(int info);
        void insercao(int info);
        void imprime();
        NodeAVL* verificaBalanceamento(NodeAVL* p);

    private:
        NodeAVL* raiz;
        bool auxBusca(NodeAVL* p, int info);
        int auxGetAltura(NodeAVL* p);
        NodeAVL* auxInsercao(NodeAVL* p, NodeAVL* pai, int info);

        void auxImprime(NodeAVL* p, int k);

        NodeAVL*  rotacaoDireita(NodeAVL* p);
        NodeAVL*  rotacaoEsquerda(NodeAVL* p);
};
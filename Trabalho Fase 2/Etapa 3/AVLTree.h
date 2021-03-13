#include "Node.h"

class AVLTree{
    public:
        AVLTree();
        virtual ~AVLTree();   
        
        int getAltura();
        bool busca(int info);
        void insercao(int info);
        void imprime();
        Node* verificaBalanceamento(Node* p);

    private:
        Node* raiz;
        bool auxBusca(Node* p, int info);
        int auxGetAltura(Node* p);
        Node* auxInsercao(Node* p, Node* pai, int info);

        void auxImprime(Node* p, int k);

        Node*  rotacaoDireita(Node* p);
        Node*  rotacaoEsquerda(Node* p);
};
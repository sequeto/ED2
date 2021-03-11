#include "Node.h"

class AVLTree{
    public:
        AVLTree();
        virtual ~AVLTree();   
        
        int getAltura();
        bool busca(int info);

    private:
        Node* raiz;
        bool auxBusca(Node* p, int info);

        void rotacaoDireita(Node* p);
        void rotacaoEsquerda(Node* p);
        void duplaRotacaoDireita(Node* p);
        void duplaRotacaoEsquerda(Node* p);
};
#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include "Node.h"

using namespace std;

// Árvore Binária de Busca com Representação Encadeada

class QuadTree
{
    public:
        QuadTree();
        virtual ~QuadTree();

        int getRoot(); // Retorna valor na Raiz da Árvore
        bool isEmpty(); // Verifica se Árvore está vazia
        bool search(int value); // Verifica se o valor está na Árvore
        void insert(int value); // Insere um elemento na árvore com o valor definido


    private:
        Node root;
        Node* root; // Ponteiro para o nó raiz
        bool auxSearch(Node* p, int value);
        Node* auxInsert(Node* p, int value);
        Node* free(Node* p);
};

#endif
#ifndef QUADTREE_H_INCLUDED
#define QUADTREE_H_INCLUDED

#include <iostream>
#include <string>
#include "Node.h"

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
        string comparaQuadrantes(Node* r, City* p); // Compara as coordenadas de dois nós para indicar o quadrante de localização de p  em relação a r

        
        void imprime();
        void auxImprime(Node* p, int k);
    private:
        Node* root; // Ponteiro para o nó raiz
        // bool auxSearch(Node* p, int value);
        Node* auxInsert(Node* p, City* city);
        // Node* free(Node* p);
};

#endif
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


    private:
        Node root;
};

#endif
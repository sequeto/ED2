#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include <iostream>

using namespace std;

// Classe Nó para Lista Encadeada de Inteiros

class Node
{
    public:
        Node();
        virtual ~Node();
        
        // Getters
        int getInfo();

        Node* getSW();
        Node* getSE();

        Node* getNW();
        Node* getNE();

        int getCoordX();
        int getCoordY();

        // Setters
        void setInfo(int info);
        
        void setNW(Node nw);
        void setNE(Node ne);

        void setSW(Node sw);
        void setSE(Node se);

        void setCoordX(int x);
        void setCoordY(int y);

    private:
        Node* nw;
        Node* ne;
        Node* sw;
        Node* se;,
        int coordx;
        int coordy;
        int info;

};

#endif
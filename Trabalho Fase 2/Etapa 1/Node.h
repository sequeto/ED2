#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED

#include "City.h"

#include <iostream>

using namespace std;

class Node
{
    public:
        Node();
        virtual ~Node();
        
        // Getters
        City* getCity();

        Node* getSW();
        Node* getSE();

        Node* getNW();
        Node* getNE();

        int getCoordX();
        int getCoordY();

        // Setters
        void setCity(City* city);
        
        void setNW(Node* nw);
        void setNE(Node* ne);

        void setSW(Node* sw);
        void setSE(Node* se);

        void setCoordX(int x);
        void setCoordY(int y);

    private:
        Node* nw;
        Node* ne;
        Node* sw;
        Node* se;
        int coordx;
        int coordy;
        City* city;

};

#endif
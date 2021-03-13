#ifndef NODEQ_H_INCLUDED
#define NODEQ_H_INCLUDED

#include "City.h"

#include <iostream>

using namespace std;

class NodeQ
{
    public:
        NodeQ();
        virtual ~NodeQ();
        
        // Getters
        City* getCity();

        NodeQ* getSW();
        NodeQ* getSE();

        NodeQ* getNW();
        NodeQ* getNE();

        int getCoordX();
        int getCoordY();

        // Setters
        void setCity(City* city);
        
        void setNW(NodeQ* nw);
        void setNE(NodeQ* ne);

        void setSW(NodeQ* sw);
        void setSE(NodeQ* se);

        void setCoordX(int x);
        void setCoordY(int y);

    private:
        NodeQ* nw;
        NodeQ* ne;
        NodeQ* sw;
        NodeQ* se;
        int coordx;
        int coordy;
        City* city;

};

#endif
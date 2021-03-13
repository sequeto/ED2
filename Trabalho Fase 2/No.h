#ifndef NO_H_INCLUDED
#define NO_H_INCLUDED

#include <iostream>
#include "Data_Casos.h"

using namespace std;

class No
{
    public:
        No();
        ~No();
        Data_Casos* getInfo();
        No* getProx();
        void setInfo(Data_Casos* val);
        void setProx(No* p);

    private:
        Data_Casos* info;
        No* prox;
};

#endif
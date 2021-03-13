#ifndef LISTAENCAD_H_INCLUDED
#define LISTAENCAD_H_INCLUDED
#include "No.h"
#include "No.h"

#include <iostream>

using namespace std;

class ListaEncad
{
    public:
        ListaEncad();
        ~ListaEncad();
        No* insereInicio(Data_Casos* val);
        No* busca(Data_Casos* val);
        bool listaVazia();
    private:
        No* primeiro; // ponteiro para o primeiro
};

#endif 
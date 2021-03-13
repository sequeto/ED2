#include "ListaEncad.h"
#include <iostream>

using namespace std;

ListaEncad::ListaEncad()
{
    primeiro = NULL;
}

ListaEncad::~ListaEncad()
{
    No* p = primeiro;
    while(p != NULL)
    {
        No* t = p->getProx();
        delete p;
        p = t;
    }
}

No* ListaEncad::insereInicio(Data_Casos* reg)
{
    No* p = new No(); // cria No apontado por p
    p->setInfo(reg); // preenche informacao
    p->setProx(primeiro); // preenche proximo
    primeiro = p; // no apontado por p passa a ser o primeiro da lista
    return p;
}

No* ListaEncad::busca(Data_Casos* cod)
{
    No* p;
    for(p = primeiro; p != NULL; p = p->getProx())
    {
        if(p->getInfo() == cod){
            return p;
        }
    }
    return NULL;
}

bool ListaEncad::listaVazia(){
    if(primeiro == NULL) {
        return true;
    }
    
    return false;
}
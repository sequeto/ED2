#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "Data_Casos.h"
#include "ListaEncad.h"

class Hash
{
    public:
        Hash(int tamanho);
        virtual ~Hash();
        int funcaoHash(int tamanho, string data, string codigo);
        void insere(Data_Casos* registros, int tamanho);
        No* busca(int key, Data_Casos* data);
    

    private:
        int tamanho;
        ListaEncad** registros;
};

#endif // HASH_H_INCLUDED
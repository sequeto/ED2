#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "Data_Casos.h"
#include "ListaEncad.h"

class Hash
{
    public:
        Hash(int tamanho);
        virtual ~Hash();
        int funcaoHash(string data, string codigo);
        void insere(Data_Casos* registros);
        No* busca(Data_Casos* data);
    

    private:
        long long int tamanho;
        ListaEncad** registros;
};

#endif // HASH_H_INCLUDED

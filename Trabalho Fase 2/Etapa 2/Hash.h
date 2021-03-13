#ifndef HASH_H_INCLUDED
#define HASH_H_INCLUDED
#include "Data_Casos.h"

public:
    Hash(int tamanho);
    ~Hash();
    int funcaoHash(int tamanho, string data, string codigo);
    void insere(Data_Casos* data, int tamanho);

private:
    int tamanho;
    Data_Casos **data;

#endif // HASH_H_INCLUDED

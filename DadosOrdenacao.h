#ifndef DADOSORDENACAO_H_INCLUDED
#define DADOSORDENACAO_H_INCLUDED

#include <iostream>
using namespace std;

class DadosOrdenacao
{
    public:
        DadosOrdenacao();
        virtual ~DadosOrdenacao();
        void incrementaTrocas();
        int getTrocas();
        void incrementaComparacoes();
        int getComparacoes();
        void clear();
    private:
        int qntComparacoes;
        int qntTrocas;
};

#endif // DADOSORDENACAO_H_INCLUDED
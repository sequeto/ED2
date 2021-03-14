#ifndef ESTATISTICAS_H_INCLUDED
#define ESTATISTICAS_H_INCLUDED

#include <iostream>
using namespace std;

class Estatisticas
{
public:

    Estatisticas()
    {
        qntComparacoes = 0;
    }

    ~Estatisticas()
    {
        qntComparacoes = 0;
    }
    
    void incrementaComparacoes()
    {
        qntComparacoes++;
    }

    int getComparacoes()
    {
        return qntComparacoes;
    }

    void clear()
    {
        qntComparacoes = 0;
    }
private:
    int qntComparacoes;
};

#endif // DADOSORDENACAO_H_INCLUDED

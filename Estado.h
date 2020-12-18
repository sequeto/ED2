#ifndef ESTADO_H_INCLUDED
#define ESTADO_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Cidade.h"

using namespace std;

class Estado
{
    public:
        Estado();
        virtual ~Estado();

        string getNome();
        void setNome(string nome);

        string getCidades();
        void setCidade(Cidade cidade);
        string getCidadeAt(int index);
        
        void ordenaCidades();


    private:
        string nome;
        vector<Cidade> cidades;
};

#endif
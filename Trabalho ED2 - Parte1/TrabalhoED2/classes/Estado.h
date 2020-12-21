/**
    UNIVERSIDADE FEDERAL DE JUIZ DE FORA
    INSTITUTO DE CIÊNCIAS EXATAS
    DEPARTAMENTO DA CIẼNCIA DA COMPUTAÇÃO

    TRABALHO DE ESTRUTURA DE DADOS 2(||) - 2020.3 (ERE)
    PROF.DR.MARCELO CANIATO RENHE

    GRUPO:
    BEATRIZ CUNHA RODRIGUES        MAT 201776
    IVANYLSON HONORIO GONÇALVES    MAT 201776002
    JOÃO PEDRO SEQUETO NASCIMENTO  MAT 201776

    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 main.cpp -o main && ./main brazil_s
    WINDOWS:    cls & g++ -std=c++11 main.cpp -o main & main.exe

    *** Função principal main.cpp ***
        Propósito: Classe com metodos basicos para a leitura

*/
/**
    main feita pelo:
    @author João Pedro Sequeto
    @version 0.1 20/12/20
**/
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

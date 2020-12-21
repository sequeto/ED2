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
#ifndef CIDADE_H_INCLUDED
#define CIDADE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Data_Casos.h"

using namespace std;

class Cidade
{
    public:
        Cidade();
        virtual ~Cidade();

        string getNome();
        void setNome(string nome);

        string getCodigo();
        void setCodigo(string codigo);

        string getDataCasos();
        void setDataCasos(Data_Casos data);
        string getDataCasoAt(int index);

        void ordenaDataCasos();


    private:
        string nome;
        string codigo;
        vector<Data_Casos> dataCasos;
};

#endif

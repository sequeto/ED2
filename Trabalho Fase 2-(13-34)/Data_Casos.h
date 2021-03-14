/**
    UNIVERSIDADE FEDERAL DE JUIZ DE FORA
    INSTITUTO DE CIÊNCIAS EXATAS
    DEPARTAMENTO DA CIẼNCIA DA COMPUTAÇÃO

    TRABALHO DE ESTRUTURA DE DADOS 2(||) - 2020.3 (ERE)
    PROF.DR.MARCELO CANIATO RENHE

    GRUPO:
    BEATRIZ CUNHA RODRIGUES        MAT 201776038
    IVANYLSON HONORIO GONÇALVES    MAT 201776002
    JOÃO PEDRO SEQUETO NASCIMENTO  MAT 201776022

    main.cpp
    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 *.h *.cpp  -o main && ./main brazil_covid19_cities.csv
    WINDOWS:    cls & g++ -std=c++11 *.h *.cpp  -o main & main.exe brazil_covid19_cities.csv

*/

#ifndef DATA_CASOS_H_INCLUDED
#define DATA_CASOS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Data_Casos
{
    public:
        Data_Casos();
        virtual ~Data_Casos();
        string getData();
        void setData(string data);
        int getCasos();
        void setCasos(int casos);
        int getMortes();
        void setMortes(int mortes);
        string getCodigo();
        void setCodigo(string codigo);
        void setEstado(string estado);
        string getEstado();
        void setCidade(string cidade);
        string getCidade();

    private:
        string data;
        int casos;
        int mortes;
        string cidade;
        string codigo_cidade;
        string estado;
};

#endif //DATA_CASOS_H_INCLUDED

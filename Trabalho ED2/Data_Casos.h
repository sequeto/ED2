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
    Data_Casos()
    {

    }

    ~Data_Casos()
    {

    }

// retorna a data (string)
    string getData()
    {
        return this->data;
    }

    void setData(string data)
    {
        this->data = data;
    }

// retorna numero de casos no dia
    int getCasos()
    {
        return this->casos;
    }

    void setCasos(int casos)
    {
        this->casos = casos;
    }

// retorna numero de mortes no dia
    int getMortes()
    {
        return this->mortes;
    }

    void setMortes(int mortes)
    {
        this->mortes = mortes;
    }

    string getCodigo()
    {
        return this->codigo_cidade;
    }

    void setCodigo(string codigo)
    {
        this->codigo_cidade = codigo;
    }

    void setEstado(string estado)
    {
        this->estado = estado;
    }

    string getEstado()
    {
        return this->estado;
    }

    void setCidade(string cidade)
    {
        this->cidade = cidade;
    }

    string getCidade()
    {
        return this->cidade;
    }
private:
    string data;
    int casos;
    int mortes;
    string cidade;
    string codigo_cidade;
    string estado;
};

#endif //DATA_CASOS_H_INCLUDED

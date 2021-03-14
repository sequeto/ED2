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

#include <iostream>
#include <string>
#include <vector>
#include "Data_Casos.h"
using namespace std;


Data_Casos::Data_Casos()
{

}

Data_Casos::~Data_Casos()
{

}

// retorna a data (string)
string Data_Casos::getData()
{
    return this->data;
}

void Data_Casos::setData(string data)
{
    this->data = data;
}

// retorna numero de casos no dia
int Data_Casos::getCasos()
{
    return this->casos;
}

void Data_Casos::setCasos(int casos)
{
    this->casos = casos;
}

// retorna numero de mortes no dia
int Data_Casos::getMortes()
{
    return this->mortes;
}

void Data_Casos::setMortes(int mortes)
{
    this->mortes = mortes;
}

string Data_Casos::getCodigo()
{
    return this->codigo_cidade;
}

void Data_Casos::setCodigo(string codigo)
{
    this->codigo_cidade = codigo;
}

void Data_Casos::setEstado(string estado)
{
    this->estado = estado;
}

string Data_Casos::getEstado()
{
    return this->estado;
}

void Data_Casos::setCidade(string cidade)
{
    this->cidade = cidade;
}

string Data_Casos::getCidade()
{
    return this->cidade;
}
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
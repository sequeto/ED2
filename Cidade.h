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

        void setDataCasos(Data_Casos data);
        Data_Casos getDataCasoAt(int index);
        
        void ordenaDataCasos();


    private:
        string nome;
        string codigo;
        vector<Data_Casos> dataCasos;
};

#endif
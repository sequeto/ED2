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
        int getNumeroCasos();
        
        void ordenaDataCasos();

        void setEstado(string estado);
        string getEstado();

    private:
        string nome;
        string estado;
        string codigo;
        vector<Data_Casos> dataCasos;
};

#endif
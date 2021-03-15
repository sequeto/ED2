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

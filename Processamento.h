#ifndef PROCESSAMENTO_H_INCLUDED
#define PROCESSAMENTO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include <iostream>
using namespace std;

class Processamento
{
    public:
        Processamento();
        virtual ~Processamento();
        void lerArquivo(vector<Data_Casos>* casos, ifstream& file);
        void gerarArquivoProcessado(vector<Data_Casos> casos, ofstream& out);
        void ordenarRegistros(vector<Data_Casos> &vetor, int inicio, int fim);
    private:
        void mergeSort(vector<Data_Casos> &vetor, int esq, int dir);
        void merge(vector<Data_Casos> &vetor, int esq, int meio, int dir);
};

#endif // DADOSORDENACAO_H_INCLUDED
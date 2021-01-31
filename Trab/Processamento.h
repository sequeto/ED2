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

#ifndef PROCESSAMENTO_H_INCLUDED
#define PROCESSAMENTO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Data_Casos.h"
using namespace std;

class Processamento
{
public:
    Processamento()
    {

    }

    ~Processamento()
    {

    }

// Função para leitura do arquivo CSV
    void lerArquivo(vector<Data_Casos>* casos, ifstream& file)
    {
        // Variaveis para guardar as informações do arquivo e passar para a classe
        Data_Casos caso;
        string line;

        // Pulando a primeira linha (header)
        getline(file, line, '\n');
        line.clear();

        while(!file.eof())
        {

            // Lendo Data dos dados - String
            getline(file, line, ',');
            caso.setData(line);
            line.clear();

            // Lendo Estado da Cidade - String
            getline(file, line, ',');
            caso.setEstado(line);
            line.clear();

            // Lendo Nome da Cidade - String
            getline(file, line, ',');
            caso.setCidade(line);
            line.clear();

            // Lendo Código Da Cidade - String
            getline(file, line, ',');
            caso.setCodigo(line);
            line.clear();

            // Lendo Número de Casos na data - Int
            getline(file, line, ',');
            caso.setCasos(atoi(line.c_str()));
            line.clear();

            // Lendo Número de Mortes na data - Int
            getline(file, line, '\n');
            caso.setMortes(atoi(line.c_str()));
            line.clear();

            casos->push_back(caso);
        }
    }

    void gerarArquivoProcessado(vector<Data_Casos> casos, ofstream& out)
    {
        // Transformando o total acumulado em total diário e gerando novo Arquivo.
        int casosAcumulados;
        int mortesAcumulados;
        int auxiliarCasos;
        int auxiliarMortes;
        for (int i = 0; i < casos.size(); i++)
        {
            if (casos[i].getData() == "2020-03-27")
            {
                casosAcumulados = casos[i].getCasos();
                mortesAcumulados = casos[i].getMortes();
            }

            else
            {
                auxiliarCasos = casosAcumulados;
                casosAcumulados = casos[i].getCasos(); // Guarda os casos acumulados do dia atual
                casos[i].setCasos(casos[i].getCasos() - auxiliarCasos); // Subtrai o atual dos acumulados até o dia anterior


                auxiliarMortes = mortesAcumulados;
                mortesAcumulados = casos[i].getMortes(); // Guarda as mortes acumuladas do dia atual
                casos[i].setMortes(casos[i].getMortes() - auxiliarMortes); // Subtrai o atual dos acumulados até o dia anterior

            }

            out << casos[i].getEstado() << ","<< casos[i].getCidade() << "," << casos[i].getData() << "," << casos[i].getCodigo() << "," << casos[i].getCasos() << "," << casos[i].getMortes() << endl;
        }

    }

    void ordenarRegistros(vector<Data_Casos> &vetor, int inicio, int fim)
    {
        mergeSort(vetor, inicio, fim);
    }


private:
    // MergeSort para ordenação do arquivo.
    void mergeSort(vector<Data_Casos> &vetor, int esq, int dir)
    {
        if(esq < (dir-1))
        {
            int meio = (esq + dir)/2;
            mergeSort(vetor, esq, meio);
            mergeSort(vetor, meio, dir);
            merge(vetor, esq, meio, dir);
        }
    }
    void merge(vector<Data_Casos> &vetor, int esq, int meio, int dir)
    {

        int i = esq;
        int j = meio;
        int k = 0;

        vector<Data_Casos> aux;

        while(i < meio && j < dir)
        {
            if(vetor[i].getEstado() < vetor[j].getEstado() ||
                    vetor[i].getEstado() == vetor[j].getEstado() && vetor[i].getCidade() < vetor[j].getCidade() ||
                    vetor[i].getEstado() == vetor[j].getEstado() && vetor[i].getCidade() == vetor[j].getCidade() && vetor[i].getData() < vetor[j].getData())
            {
                aux.push_back(vetor[i]);
                i++;
            }

            else
            {
                aux.push_back(vetor[j]);
                j++;
            }
        }

        while(i < meio)
        {
            aux.push_back(vetor[i]);
            i++;
        }

        while(j < dir)
        {
            aux.push_back(vetor[j]);
            j++;
        }

        for(i = esq; i < dir; i++)
        {
            vetor[i] = aux[i - esq];
        }

    }

};

#endif // DADOSORDENACAO_H_INCLUDED

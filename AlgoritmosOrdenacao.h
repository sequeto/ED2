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

#ifndef ALGORITMOSORDENACAO_H
#define ALGORITMOSORDENACAO_H

#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "Data_Casos.h"
#include "DadosOrdenacao.h"

using namespace std;

class AlgoritmosOrdenacao
{
public:

    // Realiza ordenação pelo Quicksort
    void quickSort(vector<Data_Casos>* vetor, int esq, int dir, DadosOrdenacao* dados)
    {
        int i,j;
        Data_Casos pivo, aux;
        i = esq;
        j = dir - 1;

        // Define o Pivo para comparação no QuickSort
        pivo = vetor->at((esq + dir)/2);
        while(i<=j)
        {
            dados->incrementaComparacoes();
            while(vetor->at(i).getCasos() < pivo.getCasos() && i < dir)
            {
                i++;
            }
            dados->incrementaComparacoes();
            while(vetor->at(j).getCasos() > pivo.getCasos() && j > esq)
            {
                j--;
            }
            if(i <= j)
            {
                aux = vetor->at(i);
                vetor->at(i) = vetor->at(j);
                vetor->at(j) = aux;
                i++;
                j--;
                dados->incrementaTrocas();
            }
        }
        if(j > esq)
        {
            quickSort(vetor,esq,j+1, dados);
        }
        if(i < dir)
        {
            quickSort(vetor,i,dir, dados);
        }
    }

    // Realiza ordenação pelo MergeSort
    void mergeSort(vector<Data_Casos>* vetor, int esq, int dir, DadosOrdenacao* dados)
    {
        if(esq < (dir-1))
        {
            int meio = (esq + dir)/2;
            mergeSort(vetor, esq, meio, dados);
            mergeSort(vetor, meio, dir, dados);
            merge(vetor, esq, meio, dir, dados);
        }
    }



    // Realiza ordenação pelo ShellSort
    void shellSort(vector<Data_Casos>* vetor, int tam, DadosOrdenacao* dados)
    {
        int i, j;
        Data_Casos aux;
        int gap = 1;

        // Define o tamanho do Gap
        while(gap < tam)
        {
            gap = 3*gap+1;
        }
        while ( gap > 1)
        {
            gap = gap / 3; // Reduz o Gap ao longo das interações
            for(i = gap; i < tam; i++)
            {
                aux = vetor->at(i);
                j = i - gap;
                dados->incrementaComparacoes();
                while (j >= 0 && aux.getCasos() < vetor->at(j).getCasos())
                {
                    dados->incrementaTrocas();
                    vetor->at(j + gap) = vetor->at(j);
                    j = j - gap;
                }
                dados->incrementaTrocas();
                vetor->at(j + gap) = aux;
            }
        }
    }

private:
    // Realiza Intercalação no MergeSort 
    void merge(vector<Data_Casos>* vetor, int esq, int meio, int dir, DadosOrdenacao* dados)
    {

        int i = esq;
        int j = meio;
        int k = 0;

        vector<Data_Casos> aux;

        while(i < meio && j < dir)
        {
            if(vetor->at(i).getCasos() < vetor->at(j).getCasos())
            {
                aux.push_back(vetor->at(i));
                i++;
            }

            else
            {
                dados->incrementaTrocas();
                aux.push_back(vetor->at(j));
                j++;
            }

            dados->incrementaComparacoes();
        }

        while(i < meio)
        {
            aux.push_back(vetor->at(i));
            i++;
        }

        while(j < dir)
        {
            aux.push_back(vetor->at(j));
            j++;
        }

        for(i = esq; i < dir; i++)
        {
            vetor->at(i) = aux.at(i - esq);
        }

    }


};


#endif //ALGORITMOSORDENACAO_H


#ifndef ALGORITMOSORDENACAO_H_H
#define ALGORITMOSORDENACAO_H

#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "Data_Casos.h"
#include "DadosOrdenacao.h"

using namespace std;

class AlgoritmosOrdenacao {
    public:
        void quickSort(vector<Data_Casos>* vetor, int esq, int dir, DadosOrdenacao* dados);
        void mergeSort(vector<Data_Casos> &vetor, int esq, int dir, DadosOrdenacao* dados);
    private:
        void merge(vector<Data_Casos> &vetor, int esq, int meio, int dir, DadosOrdenacao* dados);
};


#endif
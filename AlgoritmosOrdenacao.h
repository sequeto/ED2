
#ifndef ALGORITMOSORDENACAO_H_H
#define ALGORITMOSORDENACAO_H

#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>
#include "Data_Casos.h"

using namespace std;

class AlgoritmosOrdenacao {
    public:
        // void quickSort(vector<Data_Casos> vetor, int esq, int dir);
        void mergeSort(vector<Data_Casos> &vetor, int esq, int dir);
    private:
        void merge(vector<Data_Casos> &vetor, int esq, int meio, int dir);
        // int particionamento(vector<Data_Casos> vetor, int esq, int dir);
};


#endif
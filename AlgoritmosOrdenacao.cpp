#include "AlgoritmosOrdenacao.h"
#include "Data_Casos.h"

using namespace std;

// int AlgoritmosOrdenacao::particionamento(vector<Data_Casos> vetor, int esq, int dir){

// }


// void AlgoritmosOrdenacao::quickSort(vector<Data_Casos> vetor, int esq, int dir){

// }

void AlgoritmosOrdenacao::merge(vector<Data_Casos> &vetor, int esq, int meio, int dir){
     
    int i = esq;
    int j = meio;
    int k = 0;

    vector<Data_Casos> aux;

    while(i < meio && j < dir){
        if(vetor[i].getEstado() < vetor[j].getEstado()){
            aux.push_back(vetor[i]);
            i++;
        }

        else{
            aux.push_back(vetor[j]);
            j++;
        }
    }

    while(i < meio){
        aux.push_back(vetor[i]);
        i++;
    }

    while(j < dir){
        aux.push_back(vetor[j]);
        j++;
    }

    for(i = esq; i < dir; i++){
        vetor[i] = aux[i - esq];
    }

}
 

void AlgoritmosOrdenacao::mergeSort(vector<Data_Casos> &vetor, int esq, int dir){
    if(esq < (dir-1)){
        int meio = (esq + dir)/2;
        mergeSort(vetor, esq, meio);
        mergeSort(vetor, meio, dir);
        merge(vetor, esq, meio, dir);
    }
}
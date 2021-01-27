#include "AlgoritmosOrdenacao.h"
#include "Data_Casos.h"

using namespace std;


void AlgoritmosOrdenacao::quickSort(vector<Data_Casos>* vetor, int esq, int dir, DadosOrdenacao* dados){
    int i,j;
    Data_Casos pivo, aux;
    i = esq;
    j = dir - 1;
    pivo = vetor->at((esq + dir)/2);
    while(i<=j){
        while(vetor->at(i).getCasos() < pivo.getCasos() && i < dir){
            dados->incrementaComparacoes();
            i++;
        }
        while(vetor->at(j).getCasos() > pivo.getCasos() && j > esq){
            dados->incrementaComparacoes();
            j--;
        }
        if(i <= j){
            aux = vetor->at(i);
            vetor->at(i) = vetor->at(j);
            vetor->at(j) = aux;
            i++;
            j--;
            dados->incrementaTrocas();
        }
    }
    if(j > esq){
        quickSort(vetor,esq,j+1, dados);
    }
    if(i < dir){
        quickSort(vetor,i,dir, dados);
    }
}

void AlgoritmosOrdenacao::merge(vector<Data_Casos> &vetor, int esq, int meio, int dir, DadosOrdenacao* dados){
     
    int i = esq;
    int j = meio;
    int k = 0;

    vector<Data_Casos> aux;

    while(i < meio && j < dir){
        if(vetor[i].getCasos() < vetor[j].getCasos()){
            aux.push_back(vetor[i]);
            i++;
        }

        else{
            dados->incrementaTrocas();
            aux.push_back(vetor[j]);
            j++;
        }

        dados->incrementaComparacoes();
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
 

void AlgoritmosOrdenacao::mergeSort(vector<Data_Casos> &vetor, int esq, int dir, DadosOrdenacao* dados){
    if(esq < (dir-1)){
        int meio = (esq + dir)/2;
        mergeSort(vetor, esq, meio, dados);
        mergeSort(vetor, meio, dir, dados);
        merge(vetor, esq, meio, dir, dados);
    }
}
#include "AlgoritmosOrdenacao.h"
#include "Data_Casos.h"

using namespace std;


void AlgoritmosOrdenacao::quickSort(vector<Data_Casos>& vetor, int esq, int dir){
    int i,j;
    Data_Casos pivo, aux;
    i = esq;
    j = dir - 1;
    pivo = vetor[(esq + dir)/2];
    while(i<=j){
        while(vetor[i].getEstado() < pivo.getEstado()  && i < dir || 
        vetor[i].getEstado() == pivo.getEstado() && vetor[i].getCidade() < pivo.getCidade() && i < dir || 
        vetor[i].getEstado() == pivo.getEstado() && vetor[i].getCidade() == pivo.getCidade() && vetor[i].getData() < pivo.getData() && i < dir){
            i++;
        }
        while(vetor[j].getEstado() > pivo.getEstado()  && j > esq || 
        vetor[j].getEstado() == pivo.getEstado() && vetor[j].getCidade() > pivo.getCidade() && j > esq || 
        vetor[j].getEstado() == pivo.getEstado() && vetor[j].getCidade() == pivo.getCidade() && vetor[j].getData() > pivo.getData() && j > esq){
            j--;
        }
        if(i <= j){
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            i++;
            j--;
        }
    }
    if(j > esq){
        quickSort(vetor,esq,j+1);
    }
    if(i < dir){
        quickSort(vetor,i,dir);
    }
}

void AlgoritmosOrdenacao::merge(vector<Data_Casos> &vetor, int esq, int meio, int dir){
     
    int i = esq;
    int j = meio;
    int k = 0;

    vector<Data_Casos> aux;

    while(i < meio && j < dir){
        if(vetor[i].getEstado() < vetor[j].getEstado() || 
        vetor[i].getEstado() == vetor[j].getEstado() && vetor[i].getCidade() < vetor[j].getCidade() || 
        vetor[i].getEstado() == vetor[j].getEstado() && vetor[i].getCidade() == vetor[j].getCidade() && vetor[i].getData() < vetor[j].getData()){
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
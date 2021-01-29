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
        dados->incrementaComparacoes();
        while(vetor->at(i).getCasos() < pivo.getCasos() && i < dir){
            i++;
        }
        dados->incrementaComparacoes();
        while(vetor->at(j).getCasos() > pivo.getCasos() && j > esq){
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

void AlgoritmosOrdenacao::merge(vector<Data_Casos>* vetor, int esq, int meio, int dir, DadosOrdenacao* dados){
     
    int i = esq;
    int j = meio;
    int k = 0;

    vector<Data_Casos> aux;

    while(i < meio && j < dir){
        if(vetor->at(i).getCasos() < vetor->at(j).getCasos()){
            aux.push_back(vetor->at(i));
            i++;
        }

        else{
            dados->incrementaTrocas();
            aux.push_back(vetor->at(j));
            j++;
        }

        dados->incrementaComparacoes();
    }

    while(i < meio){
        aux.push_back(vetor->at(i));
        i++;
    }

    while(j < dir){
        aux.push_back(vetor->at(j));
        j++;
    }

    for(i = esq; i < dir; i++){
        vetor->at(i) = aux.at(i - esq);
    }

}
 

void AlgoritmosOrdenacao::mergeSort(vector<Data_Casos>* vetor, int esq, int dir, DadosOrdenacao* dados){
    if(esq < (dir-1)){
        int meio = (esq + dir)/2;
        mergeSort(vetor, esq, meio, dados);
        mergeSort(vetor, meio, dir, dados);
        merge(vetor, esq, meio, dir, dados);
    }
}



void AlgoritmosOrdenacao::shellSort(vector<Data_Casos>* vetor, int tam, DadosOrdenacao* dados)
{   
    int i , j;
    Data_Casos aux;
    int gap = 1;
    while(gap < tam) {
        gap = 3*gap+1; 
    }
    while ( gap > 1) {
        gap = gap / 3;
        for(i = gap; i < tam; i++){
            aux = vetor->at(i);
            j = i - gap;
            dados->incrementaComparacoes();
            while (j >= 0 && aux.getCasos() < vetor->at(j).getCasos()) {
                dados->incrementaTrocas();
                vetor->at(j + gap) = vetor->at(j);
                j = j - gap; 
            }
            dados->incrementaTrocas();
            vetor->at(j + gap) = aux;
        } 
    }
}

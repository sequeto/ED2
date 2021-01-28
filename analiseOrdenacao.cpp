#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>
#include <time.h>
#include <iomanip>
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

// Inclusão dos TADs
#include "Data_Casos.h"
#include "AlgoritmosOrdenacao.h"
#include "DadosOrdenacao.h"
#include "Processamento.h"

using namespace std;


void gerarVetorAleatorio(vector<Data_Casos>* vetor, int tam, vector<Data_Casos>* vetorAleatorio){
    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle (vetor->begin(), vetor->end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < tam; j++){
        vetorAleatorio->push_back(vetor->at(j));
    }
}

void printConsole(int algoritmo, DadosOrdenacao* dados, int tam, double tempo){
    if(algoritmo == 1){
        cout << "Algoritmo QuickSort" << endl;
    }

    else if(algoritmo == 2){
        cout << "Algoritmo ShellSort" << endl;
    }

    if(algoritmo == 3){
        cout << "Algoritmo MergeSort" << endl;
    }

    cout << "Tamanho: " << tam << endl;
    cout << "Tempo de Execucao: " << tempo << " Segundos" << endl;
    cout << "Trocas: " << dados->getTrocas() <<  endl;
    cout << "Comparacoes: " << dados->getComparacoes() << endl;
}

void gerarEstatisticas(int algoritmo, ofstream& out, DadosOrdenacao* dados, int tam, double tempo){
    if(algoritmo == 1){
        out << "Algoritmo QuickSort" << endl;
    }

    else if(algoritmo == 2){
        out << "Algoritmo ShellSort" << endl;
    }

    if(algoritmo == 3){
        out << "Algoritmo MergeSort" << endl;
    }

    out << "Tamanho: " << tam << endl;
    out << "Tempo de Execucao: " << tempo << " Segundos" << endl;
    out << "Trocas: " << dados->getTrocas() <<  endl;
    out << "Comparacoes: " << dados->getComparacoes() << endl;
}


int main(){

    cout << fixed << setprecision(6);

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    ofstream out("saida.txt");
    Processamento processamento;

    if(!csvFile.is_open()){
        cout << "erro";
        return 1;
    }

    // Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

    // Lendo os casos e adicionando no vetor
    cout << "Lendo..." << endl;
    processamento.lerArquivo(&casos, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();


    // Análise
    double inicio, fim;
    int M = 5;
    int N[5] = {10000, 50000, 100000, 500000, 1000000};

    vector<Data_Casos> registrosAleatorios; // Número de Registros aleatórios.

    DadosOrdenacao dados;
    AlgoritmosOrdenacao algoritmo;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < M; j++){
            gerarVetorAleatorio(&casos, N[i], &registrosAleatorios);

            // Medindo Tempo de Ordenação
            cout << "Ordenando..." << endl;
            inicio = double(clock()) / CLOCKS_PER_SEC;
            algoritmo.quickSort(&registrosAleatorios,0, registrosAleatorios.size(), &dados);
            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            printConsole(1, &dados, N[i], (fim-inicio));
            gerarEstatisticas(1, out, &dados, N[i], (fim-inicio));
            cout << endl;

            registrosAleatorios.clear();
            dados.clear();
        }
    }



    for(int i = 0; i < 5; i++){
            for(int j = 0; j < M; j++){
                gerarVetorAleatorio(&casos, N[i], &registrosAleatorios);

                // Medindo Tempo de Ordenação
                cout << "Ordenando..." << endl;
                inicio = double(clock()) / CLOCKS_PER_SEC;
                algoritmo.shellSort(&registrosAleatorios, registrosAleatorios.size(), &dados);
                fim = double(clock()) / CLOCKS_PER_SEC;
                cout << "Ordenado" << endl;

                printConsole(2, &dados, N[i], (fim-inicio));
                gerarEstatisticas(2, out, &dados, N[i], (fim-inicio));
                cout << endl;

                registrosAleatorios.clear();
                dados.clear();
            }
        }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < M; j++){
            gerarVetorAleatorio(&casos, N[i], &registrosAleatorios);

            // Medindo Tempo de Ordenação
            cout << "Ordenando..." << endl;
            inicio = double(clock()) / CLOCKS_PER_SEC;
            algoritmo.mergeSort(registrosAleatorios, 0, registrosAleatorios.size(), &dados);
            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            printConsole(3, &dados, N[i], (fim-inicio));
            gerarEstatisticas(3, out, &dados, N[i], (fim-inicio));
            cout << endl;

            registrosAleatorios.clear();
            dados.clear();
        }
    }

    out.close();
    cout << "Pronto" << endl;
    return 0;
}
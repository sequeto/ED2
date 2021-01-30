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

#ifndef ANALISEORDENACAO_H
#define ANALISEORDENACAO_H
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

int analiseAlgoritmos(){
    cout << fixed << setprecision(6);

    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Abrindo arquivo para leitura
    ifstream csvFile("ArquivosProcessados/brazil_covid19_cities_processado.csv");
    ofstream out("saidaAnalise-de-Algoritmos-de-ordenacao.txt");
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

    double mediaTempo = 0;
    int mediaComp = 0;
    int mediaTrocas = 0;
    DadosOrdenacao dados;
    AlgoritmosOrdenacao algoritmo;

    vector<Data_Casos> registrosAleatorios; // Vetor de Registros aleatórios para ordenação.

    // Interações para o QuickSort
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            out << "Algoritmo QuickSort" << endl;
            out << "Tamanho: " << N[i] << endl;

            shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

            // Adicionando N registros aleatórios ao vetor
            for(int j = 0; j < N[i]; j++){
                registrosAleatorios.push_back(casos[j]);
            }

            // Medindo Tempo de Ordenação
            cout << "Ordenando..." << endl;

            inicio = double(clock()) / CLOCKS_PER_SEC;

            DadosOrdenacao dados;
            AlgoritmosOrdenacao algoritmo;
            algoritmo.quickSort(&registrosAleatorios, 0, registrosAleatorios.size(), &dados);

            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            out << "Tempo de Execucao: " << (fim-inicio) << " Segundos" << endl;
            out << "Trocas: " << dados.getTrocas() <<  endl;
            out << "Comparacoes: " << dados.getComparacoes() << endl;

            // Acumulando as métricas de ordenação
            mediaTempo += (fim-inicio);
            mediaComp += dados.getComparacoes();
            mediaTrocas += dados.getTrocas();

            registrosAleatorios.clear();
            dados.clear();
        }

        // Realizando cálculo da média
        mediaTempo = mediaTempo / M;
        mediaComp = mediaComp / M;
        mediaTrocas = mediaTrocas / M;

        out << "Media de Tempo: " << mediaTempo << endl;
        out << "Media de Comparações: " << mediaComp << endl;
        out << "Media de Trocas: " << mediaTrocas << endl;

        mediaTempo = 0;
        mediaComp = 0;
        mediaTrocas = 0;
    }


    // Interações para o MergeSort
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            out << "Algoritmo MergeSort" << endl;
            out << "Tamanho: " << N[i] << endl;

            shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

            // Adicionando titulos aleatórios ao vetor
            for(int j = 0; j < N[i]; j++){
                registrosAleatorios.push_back(casos[j]);
            }

            // Medindo Tempo de Ordenação
            cout << "Ordenando..." << endl;

            inicio = double(clock()) / CLOCKS_PER_SEC;

            algoritmo.mergeSort(&registrosAleatorios, 0, registrosAleatorios.size(), &dados);

            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            out << "Tempo de Execucao: " << (fim-inicio) << " Segundos" << endl;
            out << "Trocas: " << dados.getTrocas() <<  endl;
            out << "Comparacoes: " << dados.getComparacoes() << endl;

            mediaTempo += (fim-inicio);
            mediaComp += dados.getComparacoes();
            mediaTrocas += dados.getTrocas();

            registrosAleatorios.clear();
            dados.clear();
        }

        mediaTempo = mediaTempo / M;
        mediaComp = mediaComp / M;
        mediaTrocas = mediaTrocas / M;

        out << "Media de Tempo: " << mediaTempo << endl;
        out << "Media de Comparações: " << mediaComp << endl;
        out << "Media de Trocas: " << mediaTrocas << endl;

        mediaTempo = 0;
        mediaComp = 0;
        mediaTrocas = 0;
    }

    // Interações para o ShellSort
    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            out << "Algoritmo ShellSort" << endl;
            out << "Tamanho: " << N[i] << endl;

            shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

            // Adicionando titulos aleatórios ao vetor
            for(int j = 0; j < N[i]; j++){
                registrosAleatorios.push_back(casos[j]);
            }

            // Medindo Tempo de Ordenação
            cout << "Ordenando..." << endl;

            inicio = double(clock()) / CLOCKS_PER_SEC;

            DadosOrdenacao dados;
            AlgoritmosOrdenacao algoritmo;
            algoritmo.shellSort(&registrosAleatorios, registrosAleatorios.size(), &dados);

            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            out << "Tempo de Execucao: " << (fim-inicio) << " Segundos" << endl;
            out << "Trocas: " << dados.getTrocas() <<  endl;
            out << "Comparacoes: " << dados.getComparacoes() << endl;

            mediaTempo += (fim-inicio);
            mediaComp += dados.getComparacoes();
            mediaTrocas += dados.getTrocas();

            registrosAleatorios.clear();
            dados.clear();
        }

        mediaTempo = mediaTempo / M;
        mediaComp = mediaComp / M;
        mediaTrocas = mediaTrocas / M;

        out << "Media de Tempo: " << mediaTempo << endl;
        out << "Media de Comparações: " << mediaComp << endl;
        out << "Media de Trocas: " << mediaTrocas << endl;

        mediaTempo = 0;
        mediaComp = 0;
        mediaTrocas = 0;
    }

    cout << "Pronto" << endl;
    return 0;
}
#endif //ANALISEORDENACAO_H

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

#ifndef MODULOTESTE_H
#define MODULOTESTE_H
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

void sortTeste(int N, int opcao){
    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    Processamento processamento;

    // Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

    // Lendo os casos e adicionando no vetor
    cout << "Lendo..." << endl;
    processamento.lerArquivo(&casos, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    vector<Data_Casos> registrosAleatorios; // Número de Registros aleatórios.

    shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < N; j++){
        registrosAleatorios.push_back(casos[j]);
    }

    AlgoritmosOrdenacao algoritmo;
    DadosOrdenacao dados;

    if(opcao == 1){
        cout << "Algoritmo QuickSort" << endl;
        cout << "Ordenando..." << endl;
        algoritmo.quickSort(&registrosAleatorios, 0, registrosAleatorios.size(), &dados);
        cout << "Ordenado" << endl;
        cout << endl;
    }

    if(opcao == 2){
        cout << "Algoritmo MergeSort" << endl;
        cout << "Ordenando..." << endl;
        algoritmo.mergeSort(&registrosAleatorios, 0, registrosAleatorios.size(), &dados);
        cout << "Ordenado" << endl;
        cout << endl;
    }

    if(opcao == 3){
        cout << "Algoritmo ShellSort" << endl;
        cout << "Ordenando..." << endl;
        algoritmo.shellSort(&registrosAleatorios, registrosAleatorios.size(), &dados);
        cout << "Ordenado" << endl;
        cout << endl;
    }

    if(N == 10){

        //Imprimindo para teste
        for(int m = 0; m < registrosAleatorios.size(); m++){
            cout << registrosAleatorios[m].getEstado() << ", ";
            cout << registrosAleatorios[m].getCidade() << ", ";
            cout << registrosAleatorios[m].getData() << ", ";
            cout << registrosAleatorios[m].getCodigo() << ", ";
            cout << registrosAleatorios[m].getCasos() << ", ";
            cout << registrosAleatorios[m].getMortes() << endl;
        }
    }

    if(N == 100){
        ofstream out("saidaN100-moduloTeste.txt");
        for(int m = 0; m < registrosAleatorios.size(); m++){
            out << registrosAleatorios[m].getEstado() << ", ";
            out << registrosAleatorios[m].getCidade() << ", ";
            out << registrosAleatorios[m].getData() << ", ";
            out << registrosAleatorios[m].getCodigo() << ", ";
            out << registrosAleatorios[m].getCasos() << ", ";
            out << registrosAleatorios[m].getMortes() << endl;
        }
    } 
}

void moduloTeste(ifstream& file){

    int opcao=0;
   while(opcao!=-1){
    cout << "Selecione Uma Opcao: " << endl;
    cout << "1: QuickSort" << endl;
    cout << "2: MergeSort" << endl;
    cout << "3: ShellSort" << endl;

    cin >> opcao;
    
        int N;
        cout << "Selecionar Valor de N: 10 para Saida em console ou 100 Para Saida em Arquivo" << endl;
        cin >> N;
        sortTeste(N, opcao);
   
    cout << "Aperte 1 para retornar ao menu ou -1 para sair" << endl;
    cin >> opcao;
   }       
}
#endif //MODULOTESTE_H

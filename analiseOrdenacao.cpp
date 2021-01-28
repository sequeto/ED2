/* 
Leitura do Arquivo - check
Ordenação dos dados importados em dois níveis: pelo par (estado, cidade) e, dentro de cada par, por data - check.
Transformar os totais acumulados de casos em totais diários.
Salvar em um novo arquivo intitulado brazil_covid19_cities_processado.csv.
*/



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

// Pré-Processamento.
int main(){

    cout << fixed << setprecision(6);

    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    ofstream estatisticasOrdenacao("saida.txt");
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

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < M; j++){
            cout << "Tamanho: " << N[i] << endl;

            shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

            // Adicionando titulos aleatórios ao vetor
            for(int j = 0; j < N[i]; j++){
                registrosAleatorios.push_back(casos[j]);
            }

            // Medindo Tempo de Ordenação
            cout << "Algoritmo quickSort" << endl;
            cout << "Ordenando..." << endl;

            inicio = double(clock()) / CLOCKS_PER_SEC;

            DadosOrdenacao dados;
            AlgoritmosOrdenacao algoritmo;
            algoritmo.quickSort(&registrosAleatorios, 0, registrosAleatorios.size(), &dados);

            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            cout << "Tempo de Execucao: " << (fim-inicio) << " Segundos" << endl;
            cout << "Trocas: " << dados.getTrocas() <<  endl;
            cout << "Comparacoes: " << dados.getComparacoes() << endl;

            //Imprimindo para teste
            // for(int m = 0; m < registrosAleatorios.size(); m++)
            //     cout << registrosAleatorios[m].getCidade() << ", " << registrosAleatorios[m].getCasos()<< endl;

            registrosAleatorios.clear();
            dados.clear();
        }
    }


    /*for(int i = 0; i < 5; i++){
        for(int j = 0; j < M; j++){
            cout << "Tamanho: " << N[i] << endl;

            shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

            // Adicionando titulos aleatórios ao vetor
            for(int j = 0; j < N[i]; j++){
                registrosAleatorios.push_back(casos[j]);
            }

            // Medindo Tempo de Ordenação
            cout << "Algoritmo mergeSort" << endl;
            cout << "Ordenando..." << endl;

            inicio = double(clock()) / CLOCKS_PER_SEC;

            DadosOrdenacao dados;
            AlgoritmosOrdenacao algoritmo;
            algoritmo.mergeSort(registrosAleatorios, 0, registrosAleatorios.size(), &dados);

            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            cout << "Tempo de Execucao: " << (fim-inicio) << " Segundos" << endl;
            cout << "Trocas: " << dados.getTrocas() <<  endl;
            cout << "Comparacoes: " << dados.getComparacoes() << endl;

            //Imprimindo para teste
            // for(int m = 0; m < registrosAleatorios.size(); m++)
            //     cout << registrosAleatorios[m].getCidade() << ", " << registrosAleatorios[m].getCasos()<< endl;

            registrosAleatorios.clear();
            dados.clear();
        }
    }*/

    /*for(int i = 0; i < 5; i++){
        for(int j = 0; j < M; j++){
            cout << "Tamanho: " << N[i] << endl;

            shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

            // Adicionando titulos aleatórios ao vetor
            for(int j = 0; j < N[i]; j++){
                registrosAleatorios.push_back(casos[j]);
            }

            // Medindo Tempo de Ordenação
            cout << "Algoritmo shellSort" << endl;
            cout << "Ordenando..." << endl;

            inicio = double(clock()) / CLOCKS_PER_SEC;

            DadosOrdenacao dados;
            AlgoritmosOrdenacao algoritmo;
            algoritmo.shellSort(&registrosAleatorios, registrosAleatorios.size(), &dados);

            fim = double(clock()) / CLOCKS_PER_SEC;
            cout << "Ordenado" << endl;

            cout << "Tempo de Execucao: " << (fim-inicio) << " Segundos" << endl;
            cout << "Trocas: " << dados.getTrocas() <<  endl;
            cout << "Comparacoes: " << dados.getComparacoes() << endl;

            //Imprimindo para teste
            // for(int m = 0; m < registrosAleatorios.size(); m++)
            //     cout << registrosAleatorios[m].getCidade() << ", " << registrosAleatorios[m].getCasos()<< endl;

            registrosAleatorios.clear();
            dados.clear();
        }
    }*/

    cout << "Pronto" << endl;
    return 0;
}
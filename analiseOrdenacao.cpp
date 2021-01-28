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

using namespace std;

// Pré-Processamento.
int main(){

    cout << fixed << setprecision(6);

    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    ofstream estatisticasOrdenacao("saida.txt");

    if(!csvFile.is_open()){
        cout << "erro";
        return 1;
    }


    string line;
    int deaths, cases;

    // Pulando a primeira linha (header)
    getline(csvFile, line, '\n');
    line.clear();

    // Objetos para guardar as informações do arquivo e passar para os TADS
    Data_Casos caso;

    // Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

    // Lendo os casos e adicionando no vetor
    cout << "Lendo..." << endl;
    while(!csvFile.eof()){

        // Pegando Data dos dados - String
        getline(csvFile, line, ',');
        caso.setData(line);
        line.clear();

        // Pegando Estado da Cidade - String
        getline(csvFile, line, ',');
        caso.setEstado(line);
        line.clear();

        // Pegando Nome da Cidade - String
        getline(csvFile, line, ',');
        caso.setCidade(line);
        line.clear();

        // Pegando Código Da Cidade - String
        getline(csvFile, line, ',');
        caso.setCodigo(line);
        line.clear();

        // Pegando Número de Casos na data - Int
        getline(csvFile, line, ',');
        cases = atoi(line.c_str());
        caso.setCasos(cases);
        line.clear();

        // Pegando Número de Mortes na data - Int
        getline(csvFile, line, '\n');
        deaths = atoi(line.c_str());
        caso.setMortes(deaths);
        line.clear();

        casos.push_back(caso);
    }
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

    cout << "Pronto" << endl;
    return 0;
}
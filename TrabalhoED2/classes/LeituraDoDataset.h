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
    MAC/LINUX:  clear && g++ -std=c++11 main.cpp -o main && ./main brazil_covid19_cities.csv
    WINDOWS:    cls & g++ -std=c++11 main.cpp -o main & main.exe brazil_covid19_cities.csv

    *** Função principal main.cpp ***
        Propósito: Classe com metodos basicos para a leitura

*/
/**
    main feita pelo:
    @author (s) Ivanylson HG e João Pedro Sequeto
    @version 0.1 20/12/20
**/
#ifndef LEITURADODATASET_H
#define LEITURADODATASET_H
#include <iostream>
#include <fstream>
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

using namespace std;
/**
Primeira parte do trabalho,
seu grupo deverá ser capaz de importar o referido conjunto de dados e executar um conjunto de análises de desempenho
ao aplicar algoritmos de ordenação sobre esses dados.
Para esta parte do trabalho, você utilizará apenas o segundo arquivo: brazil_covid19_cities.csv.
A estrutura do arquivo é indicada abaixo:

Data de confirmação;Sigla do estado;Nome da cidade;Código da cidade; Número de casos; Número de óbitos.
**/

class LeituraDoDataset
{
public:
    /// Fazer a leitura e verificar se o caminho está correto
    bool LeituraDoDatasetpCaminho(string caminho)
    {
        setlocale(LC_ALL, "portuguese-brazilian");  ///habilita a acentuação para o português

        /// Abrindo arquivo para leitura
        ifstream csvFile(caminho);

        if(!csvFile.is_open())
        {
            cout << "erro de destino do arquivo " <<endl;

            return 1;
        }


        string line;
        int cases, deaths;

        /// Pulando a primeira linha (header)
        getline(csvFile, line, '\n');
        line.clear();

        /// Lendo registros do CSV
        cout << "Lendo Arquivo CSV Brazil Covid19" << endl;
        while(!csvFile.eof())
        {
            /// Pegando Data dos dados - String
            getline(csvFile, line, ',');
            cout << line << ", ";
            line.clear();

            /// Pegando Estado da Cidade - String
            getline(csvFile, line, ',');
            cout << line << ", ";
            line.clear();

            /// Pegando Nome da Cidade - String
            getline(csvFile, line, ',');
            cout << line << ", ";
            line.clear();

            /// Pegando Código Da Cidade - String
            getline(csvFile, line, ',');
            cout << line << ", ";
            line.clear();

            /// Pegando Número de Casos na data - Int
            getline(csvFile, line, ',');
            cases = atoi(line.c_str());
            cout << cases << ", ";
            line.clear();

            /// Pegando Número de Mortes na data - Int
            getline(csvFile, line, '\n');
            deaths = atoi(line.c_str());
            cout << deaths << endl;
            line.clear();
        }
        cout << "Arquivo Lido" << endl;
        csvFile.close();
        return 0;
    }
};

#endif // LEITURADODATASET_H

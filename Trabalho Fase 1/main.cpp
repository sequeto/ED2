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
    WINDOWS:    cls & g++ -std=c++11 *.h *.cpp  -o main & main brazil_covid19_cities.csv

*/


/**
    main feita e digitado pelo:
    @author (s) Ivanylson HG
    @version 0.1
    Os códigos abaixos foram reotilizaos, suas criações foram de outros programadores que deixaram abertos(livres) para afins de conhecimento e também teram seus nomes
    e sites dos repositorios constatados abaixo e foram adaptados para este projeto.
**/

/** Biblioteca padrão**/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <vector>
#include <cstring>
#include <algorithm>
#include <random>
#include<bits/stdc++.h>

//Inclusão dos TADs
#include "Data_Casos.h"
#include "AlgoritmosOrdenacao.h"
#include "Data_Casos.h"
#include "Processamento.h"
#include "moduloTeste.h"
#include "analiseOrdenacao.h"

using namespace std;


///***Funções****

/**Cabeçalho**/
void prefacioTrabalho() ///Capa do trabalho
{
    cout << "Trabalho de Estrutura de Dados 2 (UFJF/ICE/DCC) 2020.3(ERE)" << endl;
    cout << "Grupo:" << endl;
    cout << "BEATRIZ CUNHA RODRIGUES - MAT 201776038 "<<endl;
    cout << "IVANYLSON HONORIO GONÇALVES - MAT 201776002" <<endl;
    cout << "JOÃO PEDRO SEQUETO NASCIMENTO - MAT 201776022 "<< endl;
    cout << "Observação: Para executar o código segue abaixo: " << endl;
    cout << "MAC/LINUX:  clear && g++ -std=c++11 *.h *.cpp -o main && ./main brazil_covid19_cities.csv " << endl;
    cout << "WINDOWS:    cls & g++ -std=c++11 *h *.cpp -o main & main brazil_covid19_cities.csv" << endl;
    cout <<endl;
}

/**Menu**/
/**
   ********** Módulo de testes

   *(Painel ou Menu)-> Deve ser implementado um módulo de testes simples,
   que realiza algumas operações para garantir que as funções básicas do programa entregam resultados corretos.
   Esse módulo deve conter funções para exibir as saídas das seguintes operações:

   *(Function 1)->Pré-processamento dos dados (ou seja, exibir os registros com os totais recalculados);
   *(Function 2)-> Etapa 2: Análise de algoritmos de ordenação
   **(Function2.1)-> Importação de N registros aleatórios;
   **(Function 2.2(ordenação) 3,4 e 5)Cada um dos algoritmos de ordenação.

   **(Saidas do *)-> Para estes testes, você deverá oferecer ao usuário a possibilidade de exibir a saída no console ou salvá-la em um arquivo.
   Para a saída em console, utilize N = 10. Para a saída em arquivo, utilize N = 100.
   **/
void leitura()
{
    Processamento processamento;

//Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    ofstream out("brazil_covid19_cities_processado.csv");

//Verificando se o arquvio está aberto
    if(!csvFile.is_open())
    {
        cout << "erro";
        exit (1);
    }

//Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

//Lendo os casos e adicionando no vetor
    cout << "Lendo..." << endl;
    processamento.lerArquivo(&casos, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

//Realizando ordenação
    cout << "Ordenando..." << endl;

    processamento.ordenarRegistros(casos, 0, casos.size());
    cout << "Ordenado" << endl;

//Gerando Arquivo Processado
    processamento.gerarArquivoProcessado(casos, out);

    cout << "Pronto" << endl;
}
void mainMenu() ///Menu contendo o que foi pedido no relatório
{
    int opcaoN=0;
    while(opcaoN!=-1) ///Entrando no menu
    {

        cout << "Qual das partes do trabalho voce quer executar?" << endl;
        cout << "(1) -  Etapa 1: Pré-processamento dos dados(ou seja, exibir os registros com os totais recalculados)" << endl;
        cout << "(2) -  Modulo de Teste" << endl;
        cout << "(3) -  Etapa 2: Análise de algoritmos de ordenação" << endl;
        cout << "(-1) - Para a saída " << endl;
        cout << "Numero	 desejado: ";
        cin >> opcaoN; /// Ler a opção N
        cout << endl;
        switch (opcaoN)
        {
        case -1:
        {
            exit(0);
        }
        case 1:
        {
            cout << "(1) - Etapa 1: Pré-processamento dos dados" << endl;
            ifstream csvFile;
            csvFile.open("brazil_covid19_cities_processado.csv", ios::in);
            string line;
            int deaths, cases;
            while(!csvFile.eof())
            {

                // Pegando Estado da Cidade - String
                getline(csvFile, line, ',');
                cout << line << ", ";
                line.clear();

                // Pegando Data dos dados - String
                getline(csvFile, line, ',');
                cout << line << ", ";
                line.clear();

                // Pegando Nome da Cidade - String
                getline(csvFile, line, ',');
                cout << line << ", ";
                line.clear();

                // Pegando Código Da Cidade - String
                getline(csvFile, line, ',');
                cout << line << ", ";
                line.clear();

                // Pegando Número de Casos na data - Int
                getline(csvFile, line, ',');
                cases = atoi(line.c_str());
                cout << cases << ", ";
                line.clear();

                // Pegando Número de Mortes na data - Int
                getline(csvFile, line, '\n');
                deaths = atoi(line.c_str());
                cout << deaths << ",\n";
                line.clear();

            }
            cout << "Arquivo Lido" << endl;
            csvFile.close();
            break;
        }
        case 2:
        {
            cout << "(2) -  Modulo de Teste" << endl;
            int id;
            ifstream arquivo;

            arquivo.open("brazil_covid19_cities.csv", ios::in);
            moduloTeste(arquivo);
            arquivo.close();
            break;
        }

        ///**(Function2)-> Importação de N registros aleatórios;
        ///*(Function(ordenação) 3,4 e 5)Cada um dos algoritmos de ordenação.
        case 3:
        {
            cout << "(3) - Etapa 2: Análise de algoritmos de ordenação" << endl;
            analiseAlgoritmos();
            break;
        }

        default: /// Caso não seja nenhuma opção válida
        {
            cout << "Valor invalido! Insira outro" << endl;
        } ///Fechando default
        }///Fechando switch

    }///Fechando while
}///Fechando função mainMenu


/**Função Principal**/
int main(int argc, char *argv[]) /// Iniciando o programa
{

    if (argc != 2) ///Verificação de entrada do arquivo para execução
    {
        prefacioTrabalho(); ///Cabeçalho
        cout << "ERROR: Expecting: ./<nomePrograma> <arquivoDeEntrada> " << endl;
        cout << "ERROR: Expecting: ./trabed2 brazil_covid19_cities.csv " << endl;
        return 0;
    }
    ///Chamando a função menu Main
    leitura();
    system("clear");
    prefacioTrabalho();
    mainMenu(); /// Encaminhando o arquivo de entrada
    return 0; ///Encerrando
}///Fechando main

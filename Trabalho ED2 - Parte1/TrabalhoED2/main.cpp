/**
    UNIVERSIDADE FEDERAL DE JUIZ DE FORA
    INSTITUTO DE CIÊNCIAS EXATAS
    DEPARTAMENTO DA CIẼNCIA DA COMPUTAÇÃO

    TRABALHO DE ESTRUTURA DE DADOS 2(||) - 2020.3 (ERE)
    PROF.DR.MARCELO CANIATO RENHE

    GRUPO:
    BEATRIZ CUNHA RODRIGUES        MAT 201776
    IVANYLSON HONORIO GONÇALVES    MAT 201776002
    JOÃO PEDRO SEQUETO NASCIMENTO  MAT 201776

    main.cpp
    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 main.cpp -o main && ./main brazil_s
    WINDOWS:    cls & g++ -std=c++11 main.cpp -o main & main.exe

*/

/**
    main feita pelo:
    @author Ivanylson HG
    @version 0.1 20/12/20
**/

/** Biblioteca padrão**/
#include <iostream>
#include <fstream>
#include <string>

/**classe de leitura**/
#include "classes/LeituraDoDataset.h"
#include "classes/Cidade.h"
#include "classes/Data_Casos.h"
#include "classes/Estado.h"


using namespace std;

///***Funções****

/**Cabeçalho**/
void prefacioTrabalho() ///Capa do trabalho
{
    cout << "Trabalho de Estrutura de Dados 2 (UFJF/ICE/DCC) 2020.3(ERE)" << endl;
    cout << "Grupo:" << endl;
    cout << "Beatriz cunha Rodrigues" << endl;
    cout << "Ivanylson Honorio Gonçalves" << endl;
    cout << "João Pedro Sequeto Nascimento" << endl;
    cout << "Observação: Para executar o código segue abaixo: " << endl;
    cout << "MAC/LINUX:  clear && g++ -std=c++11 main.cpp -o main && ./main brazil_covid19_cities.csv " << endl;
    cout << "WINDOWS:    cls & g++ -std=c++11 main.cpp -o main & main.exe brazil_covid19_cities.csv" << endl;
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
void mainMenu(string caminhoDoArquivo) ///Menu contendo o que foi pedido no relatório
{
    int opcaoN = 0; /// Variavel opção serve para escolher uma das opções no menu iniciando com 0(NULL)s
    bool exit = false; ///Serve para colocar verdade ou falso no menu
    LeituraDoDataset ler;
    while(!exit) ///Entrando no menu
    {
        cout << "Qual das partes do trabalho voce quer executar?" << endl;
        cout << "(1)   - Etapa 1: Pré-processamento dos dados" << endl;
        cout << "(2)   - Etapa 2: Análise de algoritmos de ordenação" << endl;
        cout << "(10)  - Exibir a saída em console" << endl;
        cout << "(100) - Para a saída em arquivo" << endl;
        cout << "Numero desejado: ";
        cin >> opcaoN; /// Ler a opção N
        cout << endl;
        switch (opcaoN)
        {
        ///*(Function 1)->Pré-processamento dos dados (ou seja, exibir os registros com os totais recalculados);
        case 1:
        {
            cout << "(1) - Etapa 1: Pré-processamento dos dados" << endl;
            string caminho = caminhoDoArquivo;
            bool respostaDaFuncao = ler.LeituraDoDatasetpCaminho(caminho);
            if(respostaDaFuncao)
                break;
            else
                exit;
        }
        ///*(Function(ordenação) 3,4 e 5)Cada um dos algoritmos de ordenação.
        case 2:
        {
            cout << "(2) - Etapa 2: Análise de algoritmos de ordenação" << endl;
            break;
        }
        /**
        **(Saidas do Menu)-> Para estes testes,
        você deverá oferecer ao usuário a possibilidade de exibir a saída no console ou salvá-la em um arquivo.
        Para a saída em console,  utilize N = 10. Para a saída em arquivo, utilize N = 100.
        **/
        case 10:
        {
            cout <<"Exibindo a saída no console"<< endl;
            exit = true; /// Troca o valor do exit
            break; ///Para o processo
        }
        case 100:
        {
            cout << "Salvando o arquivo"<<endl;
            exit = true; /// Troca o valor do exit
            break; ///Para o processo
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
    string nomeArquivoEntrada(argv[1]); /// Nome do dataset
    ///Chamando a função menu Main
    mainMenu(nomeArquivoEntrada); /// Encaminhando o arquivo de entrada
    return 0; ///Encerrando
}///Fechando main

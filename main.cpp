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
int preprocessamento(ifstream& file){

    Processamento processamento;

    // Abrindo arquivo para leitura
    ofstream out("brazil_covid19_cities_processado.csv");

    // Verificando se o arquvio está aberto
    if(!file.is_open()){
        cout << "erro";
        return 1;
    }

    // Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

    // Lendo os casos e adicionando no vetor
    cout << "Lendo..." << endl;
    processamento.lerArquivo(&casos, file);
    cout << "Arquivo Lido" << endl;
    file.close();


    // Realizando ordenação
    cout << "Ordenando..." << endl;

    processamento.ordenarRegistros(casos, 0, casos.size());

    cout << "Ordenado" << endl;


    // Gerando Arquivo Processado
    processamento.gerarArquivoProcessado(casos, out);
    
    cout << "Arquivo brazil_covid19_cities_processado.csv gerado com sucesso" << endl;

    return 0;
}

void sortTeste(int N, int opcao){
    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");
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

    if(opcao == 2){
        cout << "Algoritmo QuickSort" << endl;
        cout << "Ordenando..." << endl;
        algoritmo.quickSort(&registrosAleatorios, 0, registrosAleatorios.size(), &dados);
        cout << "Ordenado" << endl;
        cout << endl;
    }

    if(opcao == 3){
        cout << "Algoritmo MergeSort" << endl;
        cout << "Ordenando..." << endl;
        algoritmo.mergeSort(&registrosAleatorios, 0, registrosAleatorios.size(), &dados);
        cout << "Ordenado" << endl;
        cout << endl;
    }

    if(opcao == 4){
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
        ofstream out("saida.txt");
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

    int opcao;

    cout << "Selecione Uma Opcao: " << endl;
    cout << "1: Pre-processamento" << endl;
    cout << "2: QuickSort" << endl;
    cout << "3: MergeSort" << endl;
    cout << "4: ShellSort" << endl;

    cin >> opcao;

    if(opcao == 1){
        preprocessamento(file);
    }

    else{
        int N;
        cout << "Selecionar Valor de N: 10 para Saida em console ou 100 Para Saida em Arquivo" << endl;
        cin >> N;
        sortTeste(N, opcao);
    }

    cout << "Aperte 1 para retornar ao menu ou 0 para sair" << endl;
    cin >> opcao;
    if(opcao == 1){
        moduloTeste(file);
    }

    else{
        exit(1);
    }      
}


int main(int argc, char* argv[]){
    // Verificando se possui arquivo txt como argumento
    if(argc < 2) {
        cout << "ERRO: Insira um arquivo csv como parametro" << endl;
        cout << "./ <nome do programa> <nome do arquivo>" << endl;
        return 1;
    }

    ifstream file(argv[1], ios::in);
    moduloTeste(file);
    file.close();
}
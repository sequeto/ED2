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
#include "AVLTree.h"
#include "ArvoreB.h"
#include "QuadTree.h"
#include "City.h"
#include "Hash.h"
#include "Data_Casos.h"
#include "Utils.h"
#include "Estatisticas.h"
#include "Contador.h"

/*
Nesta etapa, você irá comparar o desempenho da operação de busca nas estruturas
implementadas. Para cada estrutura, o seu programa deverá selecionar conjuntos de N
registros aleatórios da tabela hash e inseri-los na estrutura. Você deverá inserir apenas o
código hash na árvore. Os outros campos do registro serão obtidos acessando a posição
correspondente na tabela hash. Após as inserções, você deverá realizar as duas buscas
indicadas abaixo.
S1) Obter o total de casos de uma cidade;
S2) Obter o total de casos nas cidades contidas no intervalo [(x0
, y0
), (x1
, y1
)], onde x0
e x1 são latitudes e y0 e y1 são longitudes.
Note que, para a busca S2, será necessário combinar os dados da quad tree com os dados
da árvore balanceada, ou seja, você deverá primeiro obter a lista de cidades no intervalo e
depois procurá-las na estrutura. Os totais de casos podem ser obtidos consultando o
registro na tabela hash. Permita ao usuário fornecer os dados necessários para as
buscas S1 e S2.
Durante as buscas, deverão ser computados o total de comparações de chaves realizadas.
Além disso, os tempos de execução das inserções e das buscas deverão ser medidos. Para
gerar as estatísticas de desempenho, você deverá executar os passos acima para M
diferentes conjuntos de N registros aleatórios. Minimamente, utilize M = 5. Ao final, compute
as médias de cada uma das métricas (comparações e tempo). Salve todos os resultados
obtidos em um arquivo saida.txt, contendo tanto os resultados individuais quanto a média
final.
Você deverá realizar a simulação descrita acima para os seguintes valores de N:
10.000
DCC012 – Estruturas de Dados II
50.000
100.000
500.000
1.000.000
Assim, em resumo, para cada valor de N, você deve importar M conjuntos distintos de N
registros aleatórios, realizar B buscas e computar métricas conforme especificado. As
estruturas de dados que devem ser implementadas são as seguintes:
*/
// using namespace std;

void analiseBusca1(double* tempoInsercaoB20, double* tempoInsercaoB200, double* tempoBuscaB20, double* tempoBuscaB200, int* comparacoesB20,int* comparacoesB200, double* mediaTempo,double* mediaTempoBusca, int* mediaCompBusca, int* mediaComp, int N,double tempo, double inicio, double fim, Estatisticas* statistics, Estatisticas* statisticsBusca, Hash* hash, vector<Data_Casos> casos){
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    Utils utils;
    AVLTree* avlt = new AVLTree();
    ArvoreB* avb = new ArvoreB(20);
    ArvoreB* avb2 = new ArvoreB(200);

    // Variaveis auxiliares
    string codigo;
    string data;
    int codHash;
    bool busca;

    vector<Data_Casos> registrosAleatorios; // Número de Registros aleatórios.

    cout << "Tamanho: " << N << endl;
    shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < N; j++){
        registrosAleatorios.push_back(casos[j]);
    }

    // Inserções
    for(int i = 0; i < N; i++){
        data = casos[i].getData();
        codigo = casos[i].getCodigo();
        codHash = hash->funcaoHash(data, codigo);

        inicio = double(clock()) / CLOCKS_PER_SEC;
        avlt->insercao(codHash, statistics);
        fim = double(clock()) / CLOCKS_PER_SEC;
        *mediaComp +=  statistics->getComparacoes();
        statistics->clear();
        tempo = (fim-inicio);
        *mediaTempo += tempo;

        inicio = double(clock()) / CLOCKS_PER_SEC;
        avb->insert(codHash);
        fim = double(clock()) / CLOCKS_PER_SEC;
        tempo = (fim-inicio);
        *tempoInsercaoB20 += tempo;

        inicio = double(clock()) / CLOCKS_PER_SEC;
        avb2->insert(codHash);
        fim = double(clock()) / CLOCKS_PER_SEC;
        tempo = (fim-inicio);
        *tempoInsercaoB200 += tempo;
    }
    
    // buscas
    for(int i = 0; i < 5; i++){
        codigo = casos[i].getCodigo();
        data = casos[i].getData();
        codHash = hash->funcaoHash(data, codigo);
        inicio = double(clock()) / CLOCKS_PER_SEC;
        busca = avlt->busca(codHash, statisticsBusca);
        fim = double(clock()) / CLOCKS_PER_SEC;
        tempo = (fim-inicio);
        *mediaTempoBusca += tempo;
        *mediaCompBusca += statisticsBusca->getComparacoes();
        statistics->clear();

        inicio = double(clock()) / CLOCKS_PER_SEC;
        avb->procura(codHash);
        fim = double(clock()) / CLOCKS_PER_SEC;
        tempo = (fim-inicio);
        *tempoBuscaB20 += tempo;
        *comparacoesB20 += Contador::getInstance().getNumComparacoes();

        inicio = double(clock()) / CLOCKS_PER_SEC;
        avb2->procura(codHash);
        fim = double(clock()) / CLOCKS_PER_SEC;
        tempo = (fim-inicio);
        *tempoBuscaB200 += tempo;
        *comparacoesB200 += Contador::getInstance().getNumComparacoes();
    }

    *mediaTempoBusca = *mediaTempoBusca/5;
    *mediaCompBusca = *mediaCompBusca/5;

    *tempoBuscaB20 = *tempoBuscaB20/5;
    *comparacoesB20 = *comparacoesB20/5;

    *tempoBuscaB200 = *tempoBuscaB200/5;
    *comparacoesB200 = *comparacoesB200/5;

    delete avlt;
    delete avb;
    delete avb2;
}

bool analise(){
    cout << fixed << setprecision(9);

    // Estruturas
    Utils utils;
    QuadTree* quadtree = new QuadTree();
    Estatisticas* statistics = new Estatisticas();
    Estatisticas* statisticsBusca = new Estatisticas();

    int mediaCompBusca = 0;
    int mediaComp = 0;

    double mediaTempoBusca = 0;
    double mediaTempo = 0;

    int comparacoesB20 = 0;
    int comparacoesB200 = 0;

    double tempoInsercaoB20 = 0;
    double tempoInsercaoB200 = 0;

    double tempoBuscaB20 = 0;
    double tempoBuscaB200 = 0;

    // Inserindo na QuadTree - Etapa 1
    cout << "Etapa 1" << endl;
    ifstream coordFile("brazil_cities_coordinates.csv");
    if(!coordFile.is_open())
    {
        cout << "erro";
        exit (1);
    }

    City* cidades = new City[5570];
    cout << "Lendo..." << endl;
    utils.lerArquivoCoordenadas(cidades, coordFile);
    cout << "Arquivo Lido" << endl;
    coordFile.close();
    utils.inserirNaQuadTree(quadtree, cidades, 5570);
    delete [] cidades;

    // Inserindo na Hash - Etapa 2
    cout << "Etapa 2" << endl; 
    ifstream csvFile("brazil_covid19_cities_processado.csv");
    if(!csvFile.is_open()){
        cout << "erro";
        return 1;
    }
    vector<Data_Casos> casos;
    Hash* hash = new Hash(1431489);
    utils.lerArquivoProcessado(&casos, csvFile);
    for(int i = 0; i < 1431489; i++){
        hash->insere(&casos[i]);
    }
    cout << "pronto" << endl;

    // Arquivo para registro das métricas
    ofstream out("saidaAnalise.txt");

    // Análise
    double inicio, fim;
    int M = 5;
    int N[5] = {1000, 5000, 10000, 50000, 100000};

    double tempo = 0;

    for(int i = 0; i< M; i++){
        analiseBusca1(&tempoInsercaoB20, &tempoInsercaoB200, &tempoBuscaB20, &tempoBuscaB200, &comparacoesB20, &comparacoesB200,&mediaTempo, &mediaTempoBusca, &mediaCompBusca, &mediaComp, N[i], tempo, inicio, fim, statistics, statisticsBusca, hash, casos);
        out << "Tamanho: " << N[i] << endl;
        out << "Tempo De Busca AVL: " << mediaTempoBusca << endl;
        cout << "Tempo De Busca AVL: " << mediaTempoBusca << endl;
        out << "Comparacoes na busca AVL: " << mediaCompBusca << endl;
        cout << "Comparacoes na busca AVL: " << mediaCompBusca << endl;
        out << "Tempo De Insercao AVL: " << mediaTempo << endl;
        cout << "Tempo De Insercao AVL: " << mediaTempo << endl;
        out << "Comparacoes na insercao AVL: " << mediaComp << endl;
        cout << "Comparacoes na insercao AVL: " << mediaComp << endl;
        statistics->clear();
        mediaTempo = 0;
        mediaComp = 0;
        mediaTempoBusca = 0;
        mediaCompBusca = 0;

        cout << endl;
        out << "Tamanho: " << N[i] << endl;
        out << "Tempo De Busca B(20): " << tempoBuscaB20 << endl;
        cout << "Tempo De Busca B(20): " << tempoBuscaB20 << endl;
        out << "Comparacoes B(20): " << comparacoesB20 << endl;
        cout << "Comparacoes B(20): " << comparacoesB20 << endl;
        out << "Tempo De Insercao B(20): " << tempoInsercaoB20 << endl;
        cout << "Tempo De Insercao B(20): " << tempoInsercaoB20 << endl;
        tempoBuscaB20 = 0;
        tempoInsercaoB20 = 0;
        comparacoesB20 = 0;

        cout << endl;
        out << "Tamanho: " << N[i] << endl;
        out << "Tempo De Busca B(200): " << tempoBuscaB200 << endl;
        cout << "Tempo De Busca B(200): " << tempoBuscaB200 << endl;
        out << "Comparacoes B(200): " << comparacoesB200 << endl;
        cout << "Comparacoes B(200): " << comparacoesB200 << endl;
        out << "Tempo De Insercao B(200): " << tempoInsercaoB200 << endl;
        cout << "Tempo De Insercao B(200): " << tempoInsercaoB200 << endl;
        tempoBuscaB200 = 0;
        tempoInsercaoB200 = 0;
        comparacoesB200 = 0;
    }

    return true; 
}
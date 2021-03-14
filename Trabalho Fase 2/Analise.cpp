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

void analise(int N,double mediaTempo, double inicio, double fim, Estatisticas* statistics, Hash* hash, vector<Data_Casos> casos){
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

    // Inserindo na Arvore AVL
    for(int i = 0; i < N; i++){
        data = casos[i].getData();
        codigo = casos[i].getCodigo();
        codHash = hash->funcaoHash(data, codigo);
        avlt->insercao(codHash);
        avb->insert(codHash);
        avb2->insert(codHash);
    }
    
    codigo = casos[0].getCodigo();
    data = casos[0].getData();
    codHash = hash->funcaoHash(data, codigo);
    inicio = double(clock()) / CLOCKS_PER_SEC;
    busca = avlt->busca(codHash, statistics);
    fim = double(clock()) / CLOCKS_PER_SEC;
    mediaTempo = (fim-inicio);
    cout << "Tempo de Busca: " << mediaTempo << endl;
    cout << statistics->getComparacoes() << endl;
    statistics->clear();
}

int main(){
    cout << fixed << setprecision(6);

    // Estruturas
    Utils utils;
    QuadTree* quadtree = new QuadTree();
    Estatisticas* statistics = new Estatisticas();

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

    // Arquivo para registro das métricas
    ofstream out("saidaAnalise.txt");

    // Análise
    double inicio, fim;
    int M = 5;
    int N[5] = {10000, 50000, 100000, 500000, 1000000};

    double mediaTempo = 0;

    for(int i = 0; i< M; i++){
        for(int j = 0; j < M; j++){
            analise(N[i], mediaTempo, inicio, fim, statistics, hash, casos);
        }
        statistics->clear();
    }    
}
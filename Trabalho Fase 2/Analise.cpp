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

int main(){
    Utils utils;
    QuadTree* quadtree = new QuadTree();
    AVLTree* avlt = new AVLTree();
    ArvoreB* avb = new ArvoreB(20);
    ArvoreB* avb2 = new ArvoreB(200);

    // Variaveis auxiliares
    string codigo;
    string data;
    int codHash;
    bool busca;

    // Inserindo na QuadTree
    //Abrindo arquivo para leitura
    ifstream coordFile("brazil_cities_coordinates.csv");

    //Verificando se o arquvio está aberto
    if(!coordFile.is_open())
    {
        cout << "erro";
        exit (1);
    }

    //Vetor que guarda todos os registros do arquivo
    City* cidades = new City[5570];

    //Lendo os registros e adicionando no vetor
    cout << "Lendo..." << endl;
    utils.lerArquivoCoordenadas(cidades, coordFile);
    cout << "Arquivo Lido" << endl;
    coordFile.close();

    utils.inserirNaQuadTree(quadtree, cidades, 5570);

    cout << fixed << setprecision(6);

    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");
    ofstream out("saidaAnalise.txt");

    if(!csvFile.is_open()){
        cout << "erro";
        return 1;
    }

    // Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

    // Lendo os casos e adicionando no vetor
    cout << "Lendo..." << endl;
    utils.lerArquivoProcessado(&casos, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    // Análise
    double inicio, fim;
    int M = 5;
    int N[5] = {10000, 50000, 100000, 500000, 1000000};

    double mediaTempo = 0;

    vector<Data_Casos> registrosAleatorios; // Número de Registros aleatórios.
    Hash* hash;

    for(int i = 0; i < M; i++){
        for(int j = 0; j < M; j++){
            out << "Tamanho: " << N[i] << endl;
            hash = new Hash(N[i]);

            shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

            // Adicionando titulos aleatórios ao vetor
            for(int j = 0; j < N[i]; j++){
                registrosAleatorios.push_back(casos[j]);
            }

            for(int j = 0; j < N[i]; j++){
                hash->insere(&casos[j]);
            }

            for(int i = 0; i < N[i]; i++){
                data = casos[i].getData();
                codigo = casos[i].getCodigo();
                codHash = hash->funcaoHash(data, codigo);
                avlt->insercao(codHash);
                avb->insert(codHash);
            }
            
            codigo = casos[0].getCodigo();
            cout << codigo << endl;
            data = casos[0].getData();
            cout << data << endl;
            codHash = hash->funcaoHash(data, codigo);
            busca = avlt->busca(codHash);
            cout << "busca: " << busca << endl;
        }
        registrosAleatorios.clear();
    }
    
}
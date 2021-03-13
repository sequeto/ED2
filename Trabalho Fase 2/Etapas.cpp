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
#include "Utils.h"

using namespace std;

QuadTree* Etapa1()
{

    Utils utils;
    cout << "Etapa 1" << endl; 
    //Abrindo arquivo para leitura
    ifstream csvFile("brazil_cities_coordinates.csv");

    //Verificando se o arquvio está aberto
    if(!csvFile.is_open())
    {
        cout << "erro";
        exit (1);
    }

    //Vetor que guarda todos os registros do arquivo
    City* cidades = new City[5570];

    //Lendo os registros e adicionando no vetor
    cout << "Lendo..." << endl;
    utils.lerArquivoCoordenadas(cidades, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    QuadTree* quadtree = new QuadTree();

    utils.inserirNaQuadTree(quadtree, cidades, 5570);
    
    // Leitura finalizada
    cout << "Pronto" << endl;
    delete [] cidades;

    return quadtree;
}


Hash* Etapa2()
{
    Utils utils;
    cout << "Etapa 2" << endl; 
    //Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");

    vector<Data_Casos> casos;
    Hash* hash = new Hash(1431489);

    utils.lerArquivoProcessado(&casos, csvFile);
    for(int i = 0; i < 1431489; i++){
        hash->insere(&casos[i]);
    }

    cout << "Finalizado" << endl;
    return hash;
}

void Etapa3()
{
    Utils utils;
    cout << "Etapa 3" << endl; 
    //Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");

    string codigo;
    string data;
    int codHash;
    AVLTree* avlt = new AVLTree();
    ArvoreB* avb = new ArvoreB(20);

    vector<Data_Casos> casos;
    Hash* hash = new Hash(1431489);

    utils.lerArquivoProcessado(&casos, csvFile);

    for(int i = 0; i < 1431489; i++){
        data = casos[i].getData();
        codigo = casos[i].getCodigo();
        codHash = hash->funcaoHash(data, codigo);
        avlt->insercao(codHash);
        avb->insert(codHash);
    }

    cout << "Finalizado" << endl;
}

int mopdulo(){
    QuadTree* qt = Etapa1();
    Hash* hash = Etapa2();
    Etapa3();

    return  0;
}

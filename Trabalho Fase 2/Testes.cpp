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
#include "QuadTree.h"
#include "ArvoreB.h"
#include "Hash.h"
#include "Utils.h"
#include "Testes.h"

using namespace std;

Testes::Testes(){

}

Testes::~Testes(){
    
}

void embaralhar(City* vet, int tam)
{
    City temp;
    int r;
	for (int i = 0; i < tam; i++)
	{
		r = rand() % tam;

		temp = vet[i];
		vet[i] = vet[r];
		vet[r] = temp;
	}
}

void Testes::testeQuadtree(int n)
{
    Utils utils;
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
    City* cidadesAleatorias = new City[n];

    //Lendo os registros e adicionando no vetor
    cout << "Lendo..." << endl;
    utils.lerArquivoCoordenadas(cidades, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    embaralhar(cidades, 5570);

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < n; j++){
        cidadesAleatorias[j] = cidades[j];
    }

    QuadTree* quadtree = new QuadTree();

    utils.inserirNaQuadTree(quadtree, cidades, n);

    if(n < 20){
        quadtree->imprime();
    }

    if(n > 20){
        // ofstream out("saidaN100-moduloTeste.txt");
        quadtree->imprime();
    }
    
    // Leitura finalizada
    cout << "Pronto" << endl;

    delete [] cidades;
}

void Testes::testeHash(int n)
{
    Utils utils;
    Data_Casos* caso;
    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");

    //Verificando se o arquvio está aberto
    if(!csvFile.is_open())
    {
        cout << "erro";
        exit (1);
    }

    //Vetor que guarda todos os registros do arquivo
    vector<Data_Casos> casos;
    vector<Data_Casos> registrosAleatorios;

    //Lendo os registros e adicionando no vetor
    cout << "Lendo..." << endl;
    utils.lerArquivoProcessado(&casos, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < n; j++){
        registrosAleatorios.push_back(casos[j]);
    }

    Hash* hash = new Hash(n);

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < n; j++){
        hash->insere(&registrosAleatorios[j]);
    }

    if(n < 20){
        for(int j = 0; j < n; j++){
            caso = hash->busca(&registrosAleatorios[j])->getInfo();
            cout << caso->getCidade() << endl;
        }
    }

    if(n > 20){
        // ofstream out("saidaN100-moduloTeste.txt");
        // quadtree->imprime();
    }
    
    // Leitura finalizada
    cout << "Pronto" << endl;
}


void Testes::testeAVL(int n)
{
    Utils utils;
    AVLTree avlt;
    string codigo;
    string data;
    int codHash;
    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");

    //Verificando se o arquvio está aberto
    if(!csvFile.is_open())
    {
        cout << "erro";
        exit (1);
    }

    //Vetor que guarda todos os registros do arquivo
    vector<Data_Casos> casos;
    vector<Data_Casos> registrosAleatorios;

    //Lendo os registros e adicionando no vetor
    cout << "Lendo..." << endl;
    utils.lerArquivoProcessado(&casos, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < n; j++){
        registrosAleatorios.push_back(casos[j]);
    }

    Hash* hash = new Hash(n);

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < n; j++){
        codigo = registrosAleatorios[j].getCodigo();
        data = registrosAleatorios[j].getData();
        codHash = hash->funcaoHash(data, codigo);
        avlt.insercao(codHash);
    }

    if(n < 20){
        avlt.imprime();
    }

    if(n > 20){
        // ofstream out("saidaN100-moduloTeste.txt");
        // quadtree->imprime();
    }
    
    // Leitura finalizada
    cout << "Pronto" << endl;
}


void Testes::testeB(int n)
{
    Utils utils;
    ArvoreB avb(20);
    string codigo;
    string data;
    int codHash;
    // Seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    //Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");

    //Verificando se o arquvio está aberto
    if(!csvFile.is_open())
    {
        cout << "erro";
        exit (1);
    }

    //Vetor que guarda todos os registros do arquivo
    vector<Data_Casos> casos;
    vector<Data_Casos> registrosAleatorios;

    //Lendo os registros e adicionando no vetor
    cout << "Lendo..." << endl;
    utils.lerArquivoProcessado(&casos, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    shuffle (casos.begin(), casos.end(), default_random_engine(seed)); // Embaralha todo o vetor de registros

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < n; j++){
        registrosAleatorios.push_back(casos[j]);
    }

    Hash* hash = new Hash(n);

    // Adicionando titulos aleatórios ao vetor
    for(int j = 0; j < n; j++){
        codigo = registrosAleatorios[j].getCodigo();
        data = registrosAleatorios[j].getData();
        codHash = hash->funcaoHash(data, codigo);
        avb.insert(codHash);
    }

    if(n < 20){
        cout << "imprimindo" << endl;
    }

    if(n > 20){
        // ofstream out("saidaN100-moduloTeste.txt");
        // quadtree->imprime();
    }
    
    // Leitura finalizada
    cout << "Pronto" << endl;
}
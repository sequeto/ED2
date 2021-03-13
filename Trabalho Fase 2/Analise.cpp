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

using namespace std;


// Função para leitura do arquivo CSV
void lerArquivoProcessado(vector<Data_Casos>* casos, ifstream& file)
{
    // Variaveis para guardar as informações do arquivo e passar para a classe
    Data_Casos caso;
    string line;

    // Pulando a primeira linha (header)
    getline(file, line, '\n');
    line.clear();

    while(!file.eof())
    {

        // Lendo Data dos dados - String
        getline(file, line, ',');
        caso.setEstado(line);
        line.clear();

        // Lendo Estado da Cidade - String
        getline(file, line, ',');
        caso.setCidade(line);
        line.clear();

        // Lendo Nome da Cidade - String
        getline(file, line, ',');
        caso.setData(line);
        line.clear();

        // Lendo Código Da Cidade - String
        getline(file, line, ',');
        caso.setCodigo(line);
        line.clear();

        // Lendo Número de Casos na data - Int
        getline(file, line, ',');
        caso.setCasos(atoi(line.c_str()));
        line.clear();

        // Lendo Número de Mortes na data - Int
        getline(file, line, '\n');
        caso.setMortes(atoi(line.c_str()));
        line.clear();

        casos->push_back(caso);
    }
}

// Função para leitura do arquivo CSV Coordinates
void lerArquivo(City* cidades, ifstream& file)
{
    // Variaveis para guardar as informações do arquivo e passar para a classe
    // 5571
    int count = 0;
    string line;

    // Pulando a primeira linha (header)
    getline(file, line, '\n');
    line.clear();

    while(!file.eof())
    {

        // Lendo codigo do estado - int
        getline(file, line, ',');
        cidades[count].setState(atoi(line.c_str()));
        line.clear();

        // Lendo codigo da Cidade - int
        getline(file, line, ',');
        cidades[count].setCity(atoi(line.c_str()));
        line.clear();

        // Lendo Nome da Cidade - String
        getline(file, line, ',');
        cidades[count].setName(line);
        line.clear();

        // Lendo latitude Da Cidade - float
        getline(file, line, ',');
        cidades[count].setLatitude(atof(line.c_str()));
        line.clear();

        // Lendo longitude Da Cidade - float
        getline(file, line, ',');
        cidades[count].setLongitude(atof(line.c_str()));
        line.clear();

        // Lendo Se a cidade é capital - bool
        getline(file, line, '\n');
        if(line == "FALSE"){
            cidades[count].setCapital(false);
        }

        else{
            cidades[count].setCapital(true);
        }

        line.clear();

        count++;
    }
}

void inserirNaQuadTree(QuadTree* tree, City* cidades, int tam){
    // Inserção Na Árvore QuadTree
    City* city;
    for(int i = 0; i < tam; i++){
        city = &cidades[i];
        tree->insert(city);
    }
}

QuadTree* Etapa1()
{

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
    lerArquivo(cidades, csvFile);
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    QuadTree* quadtree = new QuadTree();

    inserirNaQuadTree(quadtree, cidades, 5570);
    
    // Leitura finalizada
    cout << "Pronto" << endl;
    delete [] cidades;

    return quadtree;
}


Hash* Etapa2()
{

    cout << "Etapa 2" << endl; 
    //Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities_processado.csv");

    vector<Data_Casos> casos;
    Hash* hash = new Hash(1431489);

    lerArquivoProcessado(&casos, csvFile);
    for(int i = 0; i < 1431489; i++){
        hash->insere(&casos[i]);
    }

    cout << "Finalizado" << endl;
    return hash;
}

void Etapa3()
{

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

    lerArquivoProcessado(&casos, csvFile);

    for(int i = 0; i < 1431489; i++){
        data = casos[i].getData();
        codigo = casos[i].getCodigo();
        codHash = hash->funcaoHash(data, codigo);
        avlt->insercao(codHash);
        avb->insert(codHash);
    }

    cout << "Finalizado" << endl;
}

int main(){
    QuadTree* qt = Etapa1();
    Hash* hash = Etapa2();
    Etapa3();
}
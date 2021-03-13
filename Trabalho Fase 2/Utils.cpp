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


using namespace std;

Utils::Utils(){

}

Utils::~Utils(){
    
}

// Função para leitura do arquivo CSV
void Utils::lerArquivoCoordenadas(City* cidades, ifstream& file)
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

// Função para leitura do arquivo CSV
void Utils::lerArquivoProcessado(vector<Data_Casos>* casos, ifstream& file)
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

void Utils::inserirNaQuadTree(QuadTree* tree, City* cidades, int tam){
    // Inserção Na Árvore QuadTree
    City* city;
    for(int i = 0; i < tam; i++){
        city = &cidades[i];
        tree->insert(city);
    }
}
#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

// Inclusão dos TADs
#include "Estado.h"
#include "Cidade.h"
#include "Data_Casos.h"

using namespace std;

// PRINCIPAL
int main(){

    setlocale(LC_ALL, "portuguese-brazilian");  //habilita a acentuação para o português

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    ofstream saida("saida.txt");

    if(!csvFile.is_open()){
        cout << "erro";
        return 1;
    }


    string line;
    int cases, deaths;

    // Pulando a primeira linha (header)
    getline(csvFile, line, '\n');
    line.clear();

    // Objetos para guardar as informações do arquivo e passar para os TADS
    Estado* estado = new Estado();
    Cidade* cidade;
    Data_Casos* caso;

    // Vector que guarda todos os estados do arquivo
    vector<Estado> file_estados;

    estado->setNome("AC");
    int count = 0;
    
    // inicializando estados e cidades
    while(count < 27){

        cidade = new Cidade();

        // Pegando Data dos dados - String
        getline(csvFile, line, ',');
        line.clear();

        // Pegando Estado da Cidade - String
        getline(csvFile, line, ',');
        cidade->setEstado(line);

        if(line != estado->getNome()){
            file_estados.push_back(*estado);
            estado = new Estado();
            estado->setNome(line);
            count++;
        }

        line.clear();

        // Pegando Nome da Cidade - String
        getline(csvFile, line, ',');
        cidade->setNome(line);
        line.clear();

        // Pegando Código Da Cidade - String
        getline(csvFile, line, ',');
        cidade->setCodigo(line);
        line.clear();

        // Pegando Número de Casos na data - Int
        getline(csvFile, line, ',');
        line.clear();

        // Pegando Número de Mortes na data - Int
        getline(csvFile, line, '\n');
        line.clear();

        if(count != 27){
            estado->setCidade(*cidade);
        }
    }

    // retornando ponteiro para a primeira posição no arquivo
    csvFile.seekg(0);

    // Pulando a primeira linha (header)
    getline(csvFile, line, '\n');
    line.clear();

    count = 0;

    // while(!csvFile.eof())

    // Lendo os casos e adicionando no vetor das cidades (a Corrigir)
    while(count < 3){

        for(int i=0; i<file_estados.size(); i++){
            for(int j=0; j <file_estados[i].getNumeroCidades(); j++){
                caso = new Data_Casos();

                // Pegando Data dos dados - String
                getline(csvFile, line, ',');
                // cout << line << ", ";
                caso->setData(line);
                line.clear();

                // Pegando Estado da Cidade - String
                getline(csvFile, line, ',');
                // cout << line << ", ";
                // cidade->setEstado(line);
                line.clear();

                // Pegando Nome da Cidade - String
                getline(csvFile, line, ',');
                // cout << line << ", ";
                line.clear();

                // Pegando Código Da Cidade - String
                getline(csvFile, line, ',');
                // cout << line << ", ";
                line.clear();

                // Pegando Número de Casos na data - Int
                getline(csvFile, line, ',');
                cases = atoi(line.c_str());
                // cout << cases << ", ";
                caso->setCasos(cases);
                line.clear();

                // Pegando Número de Mortes na data - Int
                getline(csvFile, line, '\n');
                deaths = atoi(line.c_str());
                // cout << deaths << endl;
                caso->setMortes(deaths);
                line.clear();
                
                // cidade->setDataCasos(*caso);
            }
        }

        count++;
    }

    // Teste 1
    for(int i = 0; i < file_estados.size(); i++){
        cout << file_estados[i].getNome() << endl;
        cout << file_estados[i].getNumeroCidades() <<endl;
    }

    // Teste 2
    for(int j = 0; j < file_estados[2].getNumeroCidades(); j++){
        cout << file_estados[0].getCidadeAt(j).getNome() << endl;
    }

    cout << "Arquivo Lido" << endl;
    csvFile.close();

    return 0;
}

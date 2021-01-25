/* 
Leitura do Arquivo - check
Ordenação dos dados importados em dois níveis: pelo par (estado, cidade) e, dentro de cada par, por data.
Transformar os totais acumulados de casos em totais diários.
Salvar em um novo arquivo intitulado brazil_covid19_cities_processado.csv.
*/



#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

// Inclusão dos TADs
#include "Data_Casos.h"
#include "AlgoritmosOrdenacao.h"

using namespace std;

// PRINCIPAL
int main(){

    setlocale(LC_ALL, "portuguese-brazilian");  //habilita a acentuação para o português

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    // ofstream saida("saida.txt");

    if(!csvFile.is_open()){
        cout << "erro";
        return 1;
    }


    string line;
    int deaths, cases;
    int count = 0;

    // Pulando a primeira linha (header)
    getline(csvFile, line, '\n');
    line.clear();

    // Objetos para guardar as informações do arquivo e passar para os TADS
    Data_Casos caso;

    // Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

    cout << "Lendo..." << endl;
    // Lendo os casos e adicionando no vetor
    while(count < 1000000){
        // cout << "Registro: " << count + 1 << endl;
        // cout << endl;

        // Pegando Data dos dados - String
        getline(csvFile, line, ',');
        // cout << line << ", ";
        caso.setData(line);
        line.clear();

        // Pegando Estado da Cidade - String
        getline(csvFile, line, ',');
        // cout << line << ", ";
        caso.setEstado(line);
        line.clear();

        // Pegando Nome da Cidade - String
        getline(csvFile, line, ',');
        // cout << line << ", ";
        caso.setCidade(line);
        line.clear();

        // Pegando Código Da Cidade - String
        getline(csvFile, line, ',');
        // cout << line << ", ";
        caso.setCodigo(line);
        line.clear();

        // Pegando Número de Casos na data - Int
        getline(csvFile, line, ',');
        cases = atoi(line.c_str());
        // cout << cases << ", ";
        caso.setCasos(cases);
        line.clear();

        // Pegando Número de Mortes na data - Int
        getline(csvFile, line, '\n');
        deaths = atoi(line.c_str());
        // cout << deaths << endl;
        caso.setMortes(deaths);
        line.clear();
        
        // cout << caso.getData() << endl;
        // cout << caso.getCasos() << endl;
        // cout << caso.getMortes() << endl;
        // cout << caso.getCidade() << endl;
        // cout << caso.getCodigo() << endl;
        // cout << caso.getEstado() << endl;
        // cout << endl;

        casos.push_back(caso);

        count++;
    }
    cout << "Arquivo Lido" << endl;


    // for(int i = 0; i < casos.size(); i++){
    //     cout << casos[i].getData() << endl;
    //     cout << casos[i].getEstado() << endl;
    //     cout << casos[i].getCidade() << endl;
    //     cout << casos[i].getCodigo() << endl;
    //     cout << casos[i].getCasos() << endl;
    //     cout << casos[i].getMortes() << endl;
    //     cout << endl;
    // }

    cout << "Ordenando..." << endl;
    AlgoritmosOrdenacao algoritmo;

    algoritmo.mergeSort(casos, 0, casos.size());

    
    for(int i = 0; i < casos.size(); i++){
        cout << casos[i].getData() << ", " << casos[i].getEstado() << endl;
        // cout << casos[i].getCodigo() << endl;
        // cout << casos[i].getCidade() << endl;
        // cout << casos[i].getCasos() << endl;
        // cout << casos[i].getMortes() << endl;
        // cout << endl;
    }

    cout << "Pronto" << endl;

    csvFile.close();

    return 0;
}

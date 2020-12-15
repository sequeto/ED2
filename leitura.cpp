#include <iostream>
#include <fstream>
#include <string>
#include <locale.h>

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

    // Lendo registros do CSV
    cout << "Lendo Arquivo CSV Brazil Covid19" << endl;
    while(!csvFile.eof()){
        // Pegando Data dos dados - String
        getline(csvFile, line, ',');
        cout << line << ", ";
        line.clear();

        // Pegando Estado da Cidade - String
        getline(csvFile, line, ',');
        cout << line << ", ";
        line.clear();

        // Pegando Nome da Cidade - String
        getline(csvFile, line, ',');
        cout << line << ", ";
        line.clear();

        // Pegando Código Da Cidade - String
        getline(csvFile, line, ',');
        cout << line << ", ";
        line.clear();

        // Pegando Número de Casos na data - Int
        getline(csvFile, line, ',');
        cases = atoi(line.c_str());
        cout << cases << ", ";
        line.clear();

        // Pegando Número de Mortes na data - Int
        getline(csvFile, line, '\n');
        deaths = atoi(line.c_str());
        cout << deaths << endl;
        line.clear();
    }
    cout << "Arquivo Lido" << endl;
    csvFile.close();

    return 0;
}

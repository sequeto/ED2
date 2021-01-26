/* 
Leitura do Arquivo - check
Ordenação dos dados importados em dois níveis: pelo par (estado, cidade) e, dentro de cada par, por data - check.
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

// Pré-Processamento.
int main(){

    setlocale(LC_ALL, "portuguese-brazilian");  //habilita a acentuação para o português

    // Abrindo arquivo para leitura
    ifstream csvFile("brazil_covid19_cities.csv");
    ofstream out("brazil_covid19_cities_processado.csv");

    if(!csvFile.is_open()){
        cout << "erro";
        return 1;
    }


    string line;
    int deaths, cases;

    // Pulando a primeira linha (header)
    getline(csvFile, line, '\n');
    line.clear();

    // Objetos para guardar as informações do arquivo e passar para os TADS
    Data_Casos caso;

    // Vector que guarda todos os registros do arquivo
    vector<Data_Casos> casos;

    cout << "Lendo..." << endl;
    // Lendo os casos e adicionando no vetor
    while(!csvFile.eof()){

        // Pegando Data dos dados - String
        getline(csvFile, line, ',');
        caso.setData(line);
        line.clear();

        // Pegando Estado da Cidade - String
        getline(csvFile, line, ',');
        caso.setEstado(line);
        line.clear();

        // Pegando Nome da Cidade - String
        getline(csvFile, line, ',');
        caso.setCidade(line);
        line.clear();

        // Pegando Código Da Cidade - String
        getline(csvFile, line, ',');
        caso.setCodigo(line);
        line.clear();

        // Pegando Número de Casos na data - Int
        getline(csvFile, line, ',');
        cases = atoi(line.c_str());
        caso.setCasos(cases);
        line.clear();

        // Pegando Número de Mortes na data - Int
        getline(csvFile, line, '\n');
        deaths = atoi(line.c_str());
        caso.setMortes(deaths);
        line.clear();
    
        casos.push_back(caso);
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
    cout << "Ordenado" << endl;

    // for(int i = 0; i < casos.size(); i++){
    //     cout << casos[i].getEstado() << ", " << casos[i].getCidade() << ", " << casos[i].getData() << endl;
    //     // << casos[i].getCodigo() << ", "
    //     // << casos[i].getCasos() << ", "
    //     // << casos[i].getMortes() << endl;
    // }

    // Transformando o total acumulado em total diário.
    int casosAcumulados;
    int mortesAcumulados;
    int auxiliarCasos;
    int auxiliarMortes;
    for (int i = 0; i < casos.size(); i++)
    {
        if (casos[i].getData() == "2020-03-27"){
            casosAcumulados = casos[i].getCasos();
            mortesAcumulados = casos[i].getMortes();
        }

        else
        {
            auxiliarCasos = casosAcumulados;
            casosAcumulados = casos[i].getCasos(); // Guarda os casos acumulados do dia atual
            casos[i].setCasos(casos[i].getCasos() - auxiliarCasos); // Subtrai o atual dos acumulados até o dia anterior


            auxiliarMortes = mortesAcumulados;
            mortesAcumulados = casos[i].getMortes(); // Guarda as mortes acumuladas do dia atual
            casos[i].setMortes(casos[i].getMortes() - auxiliarMortes); // Subtrai o atual dos acumulados até o dia anterior

        }
        
        out << casos[i].getEstado() << ","<< casos[i].getCidade() << "," << casos[i].getData() << "," << casos[i].getCodigo() << "," << casos[i].getCasos() << "," << casos[i].getMortes() << endl;
    }
    
    cout << "Pronto" << endl;

    csvFile.close();

    return 0;
}

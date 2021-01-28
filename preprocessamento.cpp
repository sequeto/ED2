
// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>

// // Inclusão dos TADs
// #include "Data_Casos.h"
// #include "Processamento.h"

// using namespace std;

// // Pré-Processamento.
// int main(){

//     Processamento processamento;

//     // Abrindo arquivo para leitura
//     ifstream csvFile("brazil_covid19_cities.csv");
//     ofstream out("brazil_covid19_cities_processado.csv");

//     // Verificando se o arquvio está aberto
//     if(!csvFile.is_open()){
//         cout << "erro";
//         return 1;
//     }

//     // Vector que guarda todos os registros do arquivo
//     vector<Data_Casos> casos;

//     // Lendo os casos e adicionando no vetor
//     cout << "Lendo..." << endl;
//     processamento.lerArquivo(&casos, csvFile);
//     cout << "Arquivo Lido" << endl;
//     csvFile.close();


//     // Realizando ordenação
//     cout << "Ordenando..." << endl;

//     processamento.ordenarRegistros(casos, 0, casos.size());

//     cout << "Ordenado" << endl;


//     // Gerando Arquivo Processado
//     processamento.gerarArquivoProcessado(casos, out);
    
//     cout << "Pronto" << endl;

//     return 0;
// }

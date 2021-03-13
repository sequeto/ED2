// /**
//     UNIVERSIDADE FEDERAL DE JUIZ DE FORA
//     INSTITUTO DE CIÊNCIAS EXATAS
//     DEPARTAMENTO DA CIẼNCIA DA COMPUTAÇÃO
//     TRABALHO DE ESTRUTURA DE DADOS 2(||) - 2020.3 (ERE)
//     PROF.DR.MARCELO CANIATO RENHE
//     GRUPO:
//     BEATRIZ CUNHA RODRIGUES        MAT 201776038
//     IVANYLSON HONORIO GONÇALVES    MAT 201776002
//     JOÃO PEDRO SEQUETO NASCIMENTO  MAT 201776022
//     main.cpp
//     *** comando pra rodar ***
//     MAC/LINUX:  clear && g++ -std=c++11 *.h *.cpp  -o main && ./main brazil_covid19_cities.csv
//     WINDOWS:    cls & g++ -std=c++11 *.h *.cpp  -o main & main brazil_covid19_cities.csv
// */


// #include <iostream>
// #include <fstream>
// #include <string>
// #include <locale.h>
// #include <time.h>
// #include <iomanip>
// #include <algorithm>
// #include <chrono>
// #include <random>
// #include <vector>

// // Inclusão dos TADs
// #include "AVLTree.h"
// #include "QuadTree.h"
// #include "City.h"
// #include "Hash.h"

// using namespace std;

// void embaralhar(City* vet, int tam)
// {
//     City temp;
//     int r;
// 	for (int i = 0; i < tam; i++)
// 	{
// 		r = rand() % tam;

// 		temp = vet[i];
// 		vet[i] = vet[r];
// 		vet[r] = temp;
// 	}
// }

// // Função para leitura do arquivo CSV
// void lerArquivo(City* cidades, ifstream& file)
// {
//     // Variaveis para guardar as informações do arquivo e passar para a classe
//     // 5571
//     int count = 0;
//     string line;

//     // Pulando a primeira linha (header)
//     getline(file, line, '\n');
//     line.clear();

//     while(!file.eof())
//     {

//         // Lendo codigo do estado - int
//         getline(file, line, ',');
//         cidades[count].setState(atoi(line.c_str()));
//         line.clear();

//         // Lendo codigo da Cidade - int
//         getline(file, line, ',');
//         cidades[count].setCity(atoi(line.c_str()));
//         line.clear();

//         // Lendo Nome da Cidade - String
//         getline(file, line, ',');
//         cidades[count].setName(line);
//         line.clear();

//         // Lendo latitude Da Cidade - float
//         getline(file, line, ',');
//         cidades[count].setLatitude(atof(line.c_str()));
//         line.clear();

//         // Lendo longitude Da Cidade - float
//         getline(file, line, ',');
//         cidades[count].setLongitude(atof(line.c_str()));
//         line.clear();

//         // Lendo Se a cidade é capital - bool
//         getline(file, line, '\n');
//         if(line == "FALSE"){
//             cidades[count].setCapital(false);
//         }

//         else{
//             cidades[count].setCapital(true);
//         }

//         line.clear();

//         count++;
//     }
// }

// void inserirNaQuadTree(QuadTree* tree, City* cidades, int tam){
//     // Inserção Na Árvore QuadTree
//     City* city;
//     for(int i = 0; i < tam; i++){
//         city = &cidades[i];
//         tree->insert(city);
//     }
// }

// void leituraInsercaoQuadTree(int n)
// {

//     // Seed
//     unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

//     //Abrindo arquivo para leitura
//     ifstream csvFile("brazil_cities_coordinates.csv");

//     //Verificando se o arquvio está aberto
//     if(!csvFile.is_open())
//     {
//         cout << "erro";
//         exit (1);
//     }

//     //Vetor que guarda todos os registros do arquivo
//     City* cidades = new City[5570];
//     City* cidadesAleatorias = new City[n];

//     //Lendo os registros e adicionando no vetor
//     cout << "Lendo..." << endl;
//     lerArquivo(cidades, csvFile);
//     cout << "Arquivo Lido" << endl;
//     csvFile.close();

//     embaralhar(cidades, 5570);

//     // Adicionando titulos aleatórios ao vetor
//     for(int j = 0; j < n; j++){
//         cidadesAleatorias[j] = cidades[j];
//     }

//     QuadTree* quadtree = new QuadTree();

//     inserirNaQuadTree(quadtree, cidades, n);

//     if(n < 20){
//         quadtree->imprime();
//     }

//     if(n > 20){
//         // ofstream out("saidaN100-moduloTeste.txt");
//         quadtree->imprime();
//     }
    
//     // Leitura finalizada
//     cout << "Pronto" << endl;

//     delete [] cidades;
// }


// void teste(int N, int opcao){
//     if(opcao == 1){
//         leituraInsercaoQuadTree(N);
//     }
// }

// int main(){

//     string data = "27-03-2020";
//     cout << data << endl;
//     data.replace(2,1,"");
//     data.replace(4,1,"");
//     cout << data << endl;
//     int dataConv = stoi(data);
//     cout << dataConv << endl;

    
//     int opcao=0;
//     while(opcao != -1){
//         cout << "Selecione Uma Opcao: " << endl;
//         cout << "1: QuadTree" << endl;
//         cout << "2: Hash" << endl;
//         cout << "3: Arvore AVL" << endl;
//         cout << "4: Arvore B" << endl;

//         cin >> opcao;
        
//             int N;
//             cout << "Selecionar Valor de N <= 20 para Saida em console ou N>20 Para Saida em Arquivo" << endl;
//             cin >> N;
//             teste(N, opcao);
    
//         cout << "Aperte 1 para retornar ao menu ou -1 para sair" << endl;
//         cin >> opcao;
//    }       
// }
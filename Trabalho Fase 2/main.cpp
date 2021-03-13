// #include <iostream>
// #include <fstream>
// #include <string>
// #include "City.h"
// #include "QuadTree.h"
// #include "AVLTree.h"

// using namespace std;

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

// void leituraInsercao()
// {
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

//     //Lendo os registros e adicionando no vetor
//     cout << "Lendo..." << endl;
//     lerArquivo(cidades, csvFile);
//     cout << "Arquivo Lido" << endl;
//     csvFile.close();

//     QuadTree* quadtree = new QuadTree();

//     inserirNaQuadTree(quadtree, cidades, 20);
//     quadtree->imprime();
    
//     // Leitura finalizada
//     cout << "Pronto" << endl;

//     delete [] cidades;
// }



// int main(){
//     leituraInsercao();

//     AVLTree* avlt = new AVLTree();

//     avlt->insercao(5);
//     avlt->insercao(3);
//     avlt->insercao(2);
//     avlt->insercao(6);
//     avlt->insercao(8);
//     avlt->insercao(7);

//     avlt->imprime();
// }
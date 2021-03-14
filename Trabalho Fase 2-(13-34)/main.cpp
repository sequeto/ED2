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
#include "Data_Casos.h"
#include "Utils.h"
#include "Estatisticas.h"
#include "Analise.h"
#include "moduloTestes.h"
using namespace std;


///***Funções****

/**Cabeçalho**/
void prefacioTrabalho() ///Capa do trabalho
{
    cout << "Trabalho de Estrutura de Dados 2 (UFJF/ICE/DCC) 2020.3(ERE)" << endl;
    cout << "Grupo:" << endl;
    cout << "BEATRIZ CUNHA RODRIGUES - MAT 201776038 "<<endl;
    cout << "IVANYLSON HONORIO GONÇALVES - MAT 201776002" <<endl;
    cout << "JOÃO PEDRO SEQUETO NASCIMENTO - MAT 201776022 "<< endl;
    cout << "Observação: Para executar o código segue abaixo: " << endl;
    cout << "MAC/LINUX:  clear && g++ -std=c++11 *.h *.cpp -o main && ./main  " << endl;
    cout << "WINDOWS:    cls & g++ -std=c++11 *h *.cpp -o main & main " << endl;
    cout <<endl;
}


void mainMenu() ///Menu contendo o que foi pedido no relatório
{
    int opcaoN=0;
    while(opcaoN!=-1) ///Entrando no menu
    {

        cout << "Qual das partes do trabalho voce quer executar?" << endl;
        cout << "(1) -  Modulo de Testes:" << endl;
        cout << "(2) -  Análise das estruturas balanceadas:" << endl;
        cout << "(-1) - Para a saída " << endl;
        cout << "Numero	 desejado: ";
        cin >> opcaoN; /// Ler a opção N
        cout << endl;
        switch (opcaoN)
        {
        case -1:
        {
            exit(0);
        }
        case 1:
        {
        	modulo();
            break;
        }
        case 2:
        {
        	analise();
            break;
        }

        default: /// Caso não seja nenhuma opção válida
        {
            cout << "Valor invalido! Insira outro" << endl;
        } ///Fechando default
        }///Fechando switch

    }///Fechando while
}///Fechando função mainMenu

int main()
{
	prefacioTrabalho();
	mainMenu();
	return 0;
}

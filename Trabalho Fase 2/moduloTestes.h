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
#include "QuadTree.h"
#include "ArvoreB.h"
#include "Hash.h"
#include "Utils.h"
#include "Testes.h"

using namespace std;

void teste(int N, int opcao){
    Testes teste;
    if(opcao == 1){
        teste.testeQuadtree(N);
    }

    else if(opcao == 2){
        teste.testeHash(N);
    }

    else if(opcao == 3){
        teste.testeAVL(N);
    }

    else if(opcao == 4){
        teste.testeB(N);
    }

    else{
        cout << "Opção Inválida" << endl;
    }
}

bool modulo(){
    int opcao=0;
    while(opcao != -1){
        cout << "Selecione Uma Opcao: " << endl;
        cout << "1: QuadTree" << endl;
        cout << "2: Hash" << endl;
        cout << "3: Arvore AVL" << endl;
        cout << "4: Arvore B" << endl;

        cin >> opcao;
        
            int N;
            cout << "Selecionar Valor de N <= 20 para Saida em console ou N>20 Para Saida em Arquivo" << endl;
            cin >> N;
            teste(N, opcao);
    
        cout << "Aperte 1 para retornar ao menu ou -1 para sair" << endl;
        cin >> opcao;
   }     

   return true;  
}
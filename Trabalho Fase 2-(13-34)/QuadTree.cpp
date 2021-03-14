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
#include <string>
#include "QuadTree.h"
#include "NodeQ.h"
#include "City.h"

using namespace std;


// -----------------------------------------------------------
// Construtor
QuadTree::QuadTree(){
    this->root = NULL;
}

// -----------------------------------------------------------
// Destrutor

QuadTree::~QuadTree(){

}

// -----------------------------------------------------------
// Retorna valor na Raiz da Árvore
string QuadTree::getRoot(){
    if(this->root == NULL){
        cout << "Arvore Vazia" << endl;
        return "vazia";
    }

    else{
        return this->root->getCity()->getName();
    }
}

// -----------------------------------------------------------
// Verifica se Árvore está vazia
bool QuadTree::isEmpty(){
    return(this->root == NULL);
}

// -----------------------------------------------------------
// Verifica se o valor está na Árvore
// bool QuadTree::search(int value){
//     return auxSearch(this->root, value);
// }

// // -----------------------------------------------------------
// bool QuadTree::auxSearch(NodeQ* p, int value){
//     if(p == NULL){
//         return false;
//     }

//     else if(p->getInfo() == value){
//         return true;
//     }

//     else{
//         // Implementar
//     }
// }


string QuadTree::comparaQuadrantes(NodeQ* r, City* p){
    string quadrante = "";
    if(p->getLatitude() < r->getCoordX()){
        if(p->getLongitude() < r->getCoordY()){
            quadrante = "SW";
        }
        else{
            quadrante = "NW";
        }
    }
    else{
        if(p->getLongitude() < r->getCoordY()){
            quadrante = "SE";
        }
        else{
            quadrante = "NE";
        }
    }

    return quadrante;
}

// // -----------------------------------------------------------
// // Insere um elemento na árvore com o valor definido
void QuadTree::insert(City* city){
    this->root = auxInsert(this->root, city);
}

// -----------------------------------------------------------
NodeQ* QuadTree::auxInsert(NodeQ* p, City* city){
    if(p == NULL){
        p = new NodeQ();
        p->setCity(city);
        p->setCoordX(city->getLatitude());
        p->setCoordY(city->getLongitude());
        p->setSW(NULL);
        p->setSE(NULL);
        p->setNW(NULL);
        p->setNE(NULL);
    }

    else {
        string quadrante = this->comparaQuadrantes(p, city);
        if(quadrante == "SW"){
            p->setSW(auxInsert(p->getSW(), city));
        }

        else if(quadrante == "SE"){
            p->setSE(auxInsert(p->getSE(), city));
        }

        else if(quadrante == "NW"){
            p->setNW(auxInsert(p->getNW(), city));
        }

        else{
            p->setNE(auxInsert(p->getNE(), city));
        }
    }

    return p;
}








void QuadTree::imprime()
{
    cout << endl << endl;
    cout << "******************** ARVORE **************************" << endl << endl;
    auxImprime(this->root, 0);
    cout << endl << endl;
    cout << "******************************************************";
    cout << endl << endl;
}

void QuadTree::auxImprime(NodeQ* p, int k)
{
    if(p != NULL)
    {
        auxImprime(p->getNE(), k+1);
        auxImprime(p->getNW(), k+1);
        for(int i = 0; i < k; i++)
            cout << '\t';
        cout << p->getCity()->getName() << endl;
        auxImprime(p->getSW(), k+1);
        auxImprime(p->getSE(), k+1);
    }
}
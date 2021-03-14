#include <iostream>
#include <fstream>
#include "AVLTree.h"
#include "NodeAVL.h"

using namespace std;

AVLTree::AVLTree(){
    this->raiz = NULL;
}

AVLTree::~AVLTree(){
    this->raiz = NULL;
}

bool AVLTree::busca(int info, Estatisticas* statistics){
    return auxBusca(this->raiz, info, statistics);
}

bool AVLTree::auxBusca(NodeAVL* p, int info, Estatisticas* statistics){
    if(p == NULL){
        return false;
    }

    else if(p->getInfo() == info){
        statistics->incrementaComparacoes();
        return true;
    }

    else{
        if(info < p->getInfo()){
            statistics->incrementaComparacoes();
            return auxBusca(p->getEsq(), info, statistics);
        }

        else{
            statistics->incrementaComparacoes();
            return auxBusca(p->getDir(), info, statistics);
        }
    }
}

NodeAVL*  AVLTree::rotacaoEsquerda(NodeAVL * p){
	NodeAVL* q = p->getDir();
	p->setDir(q->getEsq());
	q->setEsq(p);
    p->setFatorBalanceamento(auxGetAltura(p->getDir()) - auxGetAltura(p->getEsq()));
    q->setFatorBalanceamento(auxGetAltura(q->getDir()) - auxGetAltura(q->getEsq()));
    return q;
}

NodeAVL*  AVLTree::rotacaoDireita(NodeAVL * p){
	NodeAVL * q = p->getEsq();
	p->setEsq(q->getDir());
	q->setDir(p);
    p->setFatorBalanceamento(auxGetAltura(p->getDir()) - auxGetAltura(p->getEsq()));
    q->setFatorBalanceamento(auxGetAltura(q->getDir()) - auxGetAltura(q->getEsq()));
    return q;
}

int AVLTree::getAltura(){
    return auxGetAltura(this->raiz);
} 

int AVLTree::auxGetAltura(NodeAVL* p){

    if(p == NULL)
        return -1;
    else{
        int altEsq = auxGetAltura(p->getEsq());
        int altDir = auxGetAltura(p->getDir());

        if(altEsq < altDir)
            return altDir + 1;
        else 
            return altEsq + 1;
    }
}

// Insere um elemento na árvore com o valor definido
void AVLTree::insercao(int value){
    this->raiz = auxInsercao(this->raiz, NULL, value);
}

// -----------------------------------------------------------
NodeAVL* AVLTree::auxInsercao(NodeAVL* p, NodeAVL* pai, int value){
    if(p == NULL){
        p = new NodeAVL();
        p->setInfo(value);
        p->setEsq(NULL);
        p->setDir(NULL);
        p->setFatorBalanceamento(0);
    }

    else {
        if(value < p->getInfo()){
            p->setEsq(auxInsercao(p->getEsq(), p,  value));
        }
        else{
            p->setDir(auxInsercao(p->getDir(), p, value));
        }
    }

    p->setFatorBalanceamento(auxGetAltura(p->getDir()) - auxGetAltura(p->getEsq()));

    return verificaBalanceamento(p);
}

NodeAVL* AVLTree::verificaBalanceamento(NodeAVL* p)
{
    if(p->getFatorBalanceamento() >= 2){
        if(p->getDir()->getFatorBalanceamento() == 1 || p->getDir()->getFatorBalanceamento() == 0){
            return rotacaoEsquerda(p);
        }
        else if(p->getDir()->getFatorBalanceamento() == -1){
            p->setDir(rotacaoDireita(p->getDir()));
            return rotacaoEsquerda(p);
        }
    }
    else if(p->getFatorBalanceamento() ==-2){
        if(p->getEsq()->getFatorBalanceamento() == -1 || p->getEsq()->getFatorBalanceamento() == 0 ){
            return rotacaoDireita(p);
        }
        else if(p->getEsq()->getFatorBalanceamento() == 1){
             p->setEsq(rotacaoEsquerda(p->getEsq()));
            return rotacaoDireita(p);
        }
    }
    return p;
}


void AVLTree::imprime()
{
    cout << endl << endl;
    cout << "******************** ARVORE **************************" << endl << endl;
    auxImprime(this->raiz, 0);
    cout << endl << endl;
    cout << "******************************************************";
    cout << endl << endl;
}

void AVLTree::auxImprime(NodeAVL* p, int k)
{
    if(p != NULL)
    {
        auxImprime(p->getDir(), k+1);
        for(int i = 0; i < k; i++)
            cout << '\t';
        cout << p->getInfo()<< endl;
        auxImprime(p->getEsq(), k+1);
    }
}

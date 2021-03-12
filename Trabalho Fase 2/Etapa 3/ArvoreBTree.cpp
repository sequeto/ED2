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
    MAC/LINUX:  clear && g++ -std=c++11 *.h *.cpp  -o main && ./main 
    WINDOWS:    cls & g++ -std=c++11 *.h *.cpp  -o main & main 

    ** Feito por: IVANYLSON HONORIO GONÇALVES **
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <chrono>
#include <sstream>
#include <algorithm> 
#include <climits>
#include "ArvoreBTree.h"
#include "Data_Casos.h"

using namespace std;

/// Construção
ArvoreBTree::ArvoreBTree(int tamanho)
{
    raiz = NULL;
    tamanhodoDoNo = tamanho;
}

/// Destrutor da ArvoreB
ArvoreBTree::~ArvoreBTree()
{
    remove(raiz);
}

/// Remove NoArvoreBTree da ArvoreB
void ArvoreBTree::remove(NNoArvoreBTreeoB* p)
{
  if(p == nullptr)
  {
    return;
  }
  if(p->get_folha())
  {
    delete p;
  }
  else
  {
    for(int i = 0; i <= p->get_n(); i++)
    {
      remove(p->get_filho(i));
      p->set_filho(i,nullptr);
    }
    delete p;
  }
}

/// Retorna t da ArvoreBTree
int ArvoreBTree::get_t()
{
  return t;
}

/// Atualizar t da ArvoreBTree
void ArvoreBTree::set_t(int T)
{
  this->t = t;
}

/// Retorna raiz  
NoArvoreBTree* ArvoreBTree::get_raiz()
{
  return raiz;
} 

/// Atualiza raiz 
void ArvoreBTree::set_raiz(NoArvoreBTree* raiz)
{
  this->raiz = raiz;
}

/// Imprime as chaves contidas na raiz da arvore
void ArvoreBTree::imprimir_raiz()
{
  cout << endl << "Imprimindo Raiz:" << endl;
  for(int i = 0; i < raiz->get_n(); i++)
  {
    cout << " " <<raiz->get_chave_i(i)->get_id();
  }
  cout << endl << endl;
}

/// Insere chave 
void ArvoreBTree::insercao(Data_Casos *tabela)
{
  if(raiz == nullptr)
  {
    NoArvoreBTree* p = new NoArvoreBTree(t);
    raiz = p;
    raiz->set_n(1);
    raiz->set_chave_i(0, tabela);
  }
  else
  {
    NoArvoreBTree *aux2 = new NoArvoreBTree(raiz->get_t());
    ///caso que arvore n vazia
    if(raiz->get_n() == ((t*2)-1)) ///caso que n eh cisao
    {
      cisao(tabela, raiz);
    }
    else
    {
      raiz->aux_insere(tabela, &num_comparacoes, &num_copias);
    }
  }
}

/// Chama a cisão dentro do no
void ArvoreBTree::cisao(Data_Casos *tabela, NoArvoreBTree* d)
{
  NoArvoreBTree* aux = new NoArvoreBTree(t);

  aux->set_folha(false);
  aux->set_filho(0, d);

  aux->overflow(0, d, &num_copias);
  
  int i = 0;

  if(aux->get_chave_i(0)->get_id() < tabela->get_id())
    i++; 
  aux->get_filho(i)->aux_insere(tabela, &num_comparacoes, &num_copias);
  raiz = aux;
}

/// Remove chave
NoArvoreBTree* ArvoreBTree::remocao(Data_Casos *tabela)
{ 
    if (raiz == nullptr) 
    { 
        cout << "A arvore esta vazia" << endl; 
        return nullptr; 
    } 
 
    raiz->remove(tabela); 

    if (raiz->get_n() == 0) 
    { 
        NoArvoreBTree *aux = new NoArvoreBTree(t);
        aux = raiz; 
        if (raiz->get_folha()) 
            raiz = NULL; 
        else
            raiz = raiz->get_filho(0); 

        delete aux; 
    } 
    return raiz; 
} 

/// Busca 
NoArvoreBTree* ArvoreBTree::busca(Data_Casos *tabela, NoArvoreBTree *p)
{
  NoArvoreBTree* no;
  no = raiz->busca(*tabela, raiz, &num_comparacoes_busca);
  if(no == nullptr)
  {
    return nullptr;
  }
  else
  {
    int i = 0;
    while((i < (no->get_n())) && (no->get_chave_i(i)->get_id() < info->get_id()))
    {
      i++;
    }
    if(i < no->get_n())
    {
      if(no->get_chave_i(i)->get_id() == info->get_id())
      {
        return no->get_chave_i(i);
      }
    }
    return NULL;
  }
}

 /// Insere chave2 
void ArvoreBTree::insereArvoreB(int chave,Data_Casos *tabela)
{
    if(raiz == NULL)
    {   
        
        raiz = new NoArvoreBTree(tamanhodoNo,true);
        raiz->setChave(0, chave);
        raiz->setN(1);
        //cout<<"tam: "<<raiz->getN()<<endl;

            
    }else{

        if(raiz->getN() == 2*tamanhodoNo-1){
            
            //Se raiz estiver cheia
          
            NoArvoreBTree *p = new NoArvoreBTree(tamanhodoNo, false);
            p->setFilhos(0,raiz);
            p->split(0,raiz,tabela);

            //Aumenta o index para a achar a chave corresponde
            //que seja maior do que a chave que quer ser inserida assim ligando a folha correta
            int i = 0;
            
            if(p->chaves[0]<chave){
                i++; 
            }

            p->getFilhos(i)->insertFilho(chave,tabela);
            raiz = p;
        }else
            //cout<<"Raiz n ta cheia"<<endl;
            raiz->insertFilho(chave,tabela);
        
    }
}
 
/// Imprime a arvore
void ArvoreBTree::imprimeArvoreB()
{
    if(raiz!=NULL)
    {
        raiz->imprime();
    }

    for (int i = 0; i < raiz->getN(); i++)
    {
        cout<<" /"<<raiz->chaves[i];
    }
    
}

/// Buscar na arvore
NoArvoreBTree* ArvoreBTree::busca(int chave,Data_Casos tabela)
{
    return (raiz == NULL) ? NULL : raiz->busca_no_No(chave,tabela);
}


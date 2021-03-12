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
    
    Função Principal
    main.cpp
    *** comando pra rodar ***
    MAC/LINUX:  clear && g++ -std=c++11 *.h *.cpp  -o main && ./main 
    WINDOWS:    cls & g++ -std=c++11 *.h *.cpp  -o main & main 

    ** Feito por: IVANYLSON HONORIO GONÇALVES **
*/
#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "NoArvoreBTree.h"
#include "Data_Casos.h"


using namespace std;

/// Construtor NoArvoreBTree
NoArvoreBTree::NoArvoreBTree(int tamanho,bool f)
{
    tam = tamanho;
    t = tamanho;
    folha = f;
    chaves = new int [2*tam-1];
    filhos = new NoArvoreBTree * [2*tam];
    key = new Data_Casos* [(tamanho*2)-1];
    for(int i = 0; i < tamanho*2- 1; i++)
    {
      filhos[i] = NULL;
      key[i] = NULL;
    }
    filhos[tamanho] = NULL;
    n = 0;
}
/// Destrutor NoArvoreBTree
NoArvoreBTree::~NoArvoreBTree()
{
    delete [] key;
    delete [] filhos;
}

/// Retorna n do NoArvoreBTree
int NoArvoreBTree::get_n() 
{
  return n; 
}

/// Retorna t do NoArvoreBTree
int NoArvoreBTree::get_t() 
{
  return t;
}

/// Retorna chava[i] do NoArvoreBTree
Data_Casos* NoArvoreBTree::get_chave_i(int i)
{
  return key[i];
}

/// Retorna filho[i] do NoArvoreBTree
NoArvoreBTree* NoArvoreBTree::get_filho(int i)
{
  return filhos[i];
}
    
/// Retorna se o NoArvoreBTree é folha ou não
bool NoArvoreBTree::get_folha()
{
  return folha; 
}

/// Atualiza o t do NoArvoreBTree
void NoArvoreBTree::set_t(int T)
{
  t = T;
}

/// Atualiza o n do NoArvoreBTree
void NoArvoreBTree::set_n(int N) 
{ 
  n = N;
}

/// Atualiza se o NoArvoreBTree é folha ou não
void NoArvoreBTree::set_folha(bool ehFolha)
{
  folha = ehFolha;
}

/// Atualiza chave[i] no NoArvoreBTree
void NoArvoreBTree::set_chave_i(int i, Data_Casos* novo)
{
  this->key[i] = novo;
}

/// Atualiza filho[i] no NoArvoreBTree
void NoArvoreBTree::set_filho(int i, NoArvoreBTree* novo)
{
  filhos[i] = novo;
}

/// Imprime
void NoArvoreBTree::imprime() 
{ 
    int i;
    for (i = 0; i < n; i++) 
    {
      if (folha == false) 
        filhos[i]->imprime();  
      cout << " " << key[i]->get_id() << "::" << n; 
    } 
    cout << endl;
    if (folha == false) 
      filhos[i]->imprime(); 
}

/// Auxiliar da inserção
void NoArvoreBTree::aux_insere(Data_Casos *info, int* num_comparacoes, int* num_copias)
{
  int i = this->n - 1;
  if(this->folha)
  {
    while(i >= 0 && this->key[i]->get_id() > info->get_id())
    {
      this->key[i+1] = this->key[i] ;
      i--;
      *num_comparacoes = *num_comparacoes + 1;
    } 
    this->key[i+1] = info;
    this->n = n+1;
  }
  else
  {
    while(i >= 0 && this->key[i]->get_id() > info->get_id())
    {
      *num_comparacoes = *num_comparacoes + 1;
      i--;
    }
    if(this->filhos[i+1]->get_n() == 2*t - 1)
    {
      overflow(i+1, this->filhos[i+1], num_copias);
      if(this->key[i+1]->get_id() < info->get_id())
        i++;
    }
    this->filhos[i+1]->aux_insere(info, num_comparacoes, num_copias);
  }
}

/// Função que executa a cisão do NoArvoreBTree
void NoArvoreBTree::overflow(int i, NoArvoreBTree *aux, int* num_copias)
{
  NoArvoreBTree *aux2 = new NoArvoreBTree(t);
  aux2->set_n(t - 1);
  int g = 0;
  while(g < (t - 1))
  {
    aux2->set_chave_i(g, aux->get_chave_i(g+t));
    g = g + 1;
    *num_copias = *num_copias + 1;
  }
   
  if(!aux->get_folha())
  {
    int j = 0;
    while(j < t)
    {
      aux2->set_filho(j, aux->get_filho(j + t));
      j++;
      *num_copias = *num_copias + 1;
    }
  }

  aux->set_n(t - 1);

  for(int j = n; j >= i+1; j--)
  {
    filhos[j + 1] = filhos[j];
    *num_copias = *num_copias + 1;
  }

  filhos[i + 1] = aux2;

  for (int j = n - 1; j >= i; j--) 
  {
    key[j+1] = key[j];
    *num_copias = *num_copias + 1;
  }
  
  key[i] = aux->get_chave_i(t-1);

  n = n + 1;
}

/// Acha posição em que a chave ficaria no NoArvoreBTree
int NoArvoreBTree::acha_posicao(Data_Casos* info) 
{ 
    int i = 0;
    while (i < n && key[i]->get_id() < info->get_id()) 
        i++;
    return i; 
} 

/// Funçao de remoção do NoArvoreBTree
void NoArvoreBTree::remove(Data_Casos* info)
{
  int i = acha_posicao(info);

  if(i < n && key[i]->get_id() == info->get_id())
  {
    if(folha)
    {
      remove_folha(i);
    }
    else
      remove_nao_folha(i);
  }
  else
  {
    if(this->folha == true)
    {
      return;
    }
    bool ehFilho;
    if(i == n)
      ehFilho = true;
    else
      ehFilho = false;
  
    if(filhos[i]->get_n() < t)
    {
      preenche(i);
    }
    if(ehFilho && i > n)
    {
      filhos[i-1]->remove(info);
    }
    else
    {
      filhos[i]->remove(info);
    }
  }
}

/// Remove se o NoArvoreBTree for folha
void NoArvoreBTree::remove_folha(int i)
{
  for(int j = i+1; j < n; j++)
  {
    key[j-1] = key[j];
  }
  n--;
}

/// Chega na folha pegando o filho a esquerda do NoArvoreBTree
Data_Casos* NoArvoreBTree::get_anterior(int i)
{
  NoArvoreBTree* aux = filhos[i];
  while(aux->get_folha() == false)
  {
    aux = aux->get_filho(aux->get_n());
  }
  return aux->get_chave_i(aux->get_n() - 1);
}

/// Chega na folha pegando o filho a direita do NoArvoreBTree
Data_Casos* NoArvoreBTree::get_proximo(int i)
{
  NoArvoreBTree* aux = filhos[i + 1];
  while(aux->get_folha() == false)
  {
    aux = aux->get_filho(0);
  }
  return aux->get_chave_i(0);
}

/// Remove se o NoArvoreBTree não for folha
void NoArvoreBTree::remove_nao_folha(int i)
{
  Data_Casos* k = key[i];
  if(filhos[i]->get_n() >= t)
  {
    Data_Casos* anterior = get_anterior(i);
    key[i] = anterior;
    filhos[i]->remove(anterior);
  } 
  else if(filhos[i+1]->get_n() >= t)
  {
    Data_Casos* proximo = get_proximo(i);
    key[i] = proximo;
    filhos[i+1]->remove(proximo);
  }
  else
  {
    juncao(i);
    filhos[i]->remove(k);
  }
}

/// Seleciona qual procedimento executar: redistribuição ou junção
void NoArvoreBTree::preenche(int i) 
{ 
    if (i != 0 && filhos[i-1]->get_n() >= t)
    {
      redistribuicao_anterior(i); 
    }
    else if (i != n && filhos[i+1]->get_n() >= t)
    { 
      redistribuicao_proximo(i); 
    }
    else
    { 
        if (i != n) 
            juncao(i);
        else
            juncao(i-1); 
    }
} 

/// Junção 
void NoArvoreBTree::juncao(int i)
{
  NoArvoreBTree* filho = filhos[i];
  NoArvoreBTree* irmao = filhos[i+1];
  filho->set_chave_i(t-1, key[i]);
  for(int j = 0; j < irmao->get_n(); j++)
  {
    filho->set_chave_i(t+j, irmao->get_chave_i(j));
  }
  if(!filho->get_folha())
  {
    for(int j = 0; j <= irmao->get_n(); j++)
    {
      filho->set_filho(j+t, irmao->get_filho(j));
    }
  }
  for(int j = i+1; j < n; j++)
  {
    key[j-1] = key[j];
  }
  for(int j = i+2; j <= n; j++)
  {
    filho[j-1] = filho[j];
  }
  int aux_n;
  aux_n = filho->get_n() + irmao->get_n() + 1;
  filho->set_n(aux_n);
  n = n-1;
}

/// Redistribui no NoArvoreBTree anterior
void NoArvoreBTree::redistribuicao_anterior(int i) 
{ 
    NoArvoreBTree *f = filhos[i]; 
    NoArvoreBTree *irmao = filhos[i-1];  
 
    for (int j = f->get_n()-1; j >= 0; j--) 
        f->set_chave_i(j+1, f->get_chave_i(j)); 
   
    if (f->get_folha() == false) 
    { 
      for(int j = f->get_n(); j >= 0; j--) 
        f->set_filho(i+1, f->get_filho(i)); 
    } 
    f->set_chave_i(0, key[i-1]); 

    if(f->get_folha() == false) 
        f->set_filho(0, irmao->get_filho(irmao->get_n())); 
  
    key[i-1] = irmao->get_chave_i(irmao->get_n()-1); 
  
    f->set_n(f->get_n() + 1); 
    irmao->set_n(irmao->get_n() - 1);
} 

/// Redistribui no NoArvoreBTree posterior
void NoArvoreBTree::redistribuicao_proximo(int i) 
{ 
  
    NoArvoreBTree *f = filhos[i]; 
    NoArvoreBTree *irmao = filhos[i+1]; 
  
    f->set_chave_i((f->get_n()), key[i]); 
  
    if (!(f->get_folha())) 
    {
        f->set_filho((f->get_n())+1, irmao->get_filho(0)); 
    } 
    
   
    key[i] = irmao->get_chave_i(0); 
  
    for (int j = 1; j < irmao->get_n(); j++) 
    {
        irmao->set_chave_i(j-1, irmao->get_chave_i(j)); 
    }
  
    if (!irmao->get_folha()) 
    { 
        for(int j = 1; j <= irmao->get_n(); j++) 
            irmao->set_filho(j-1, irmao->get_filho(j)); 
    } 
  
    f->set_n(f->get_n() + 1); 
    irmao->set_n(irmao->get_n() - 1); 
} 

//Buscar  
NoArvoreBTree* NoArvoreBTree::busca(Data_Casos info, NoArvoreBTree* p, int* numero_comparacoes)
{
    *numero_comparacoes = *numero_comparacoes + 1;
    int i = 0;
    while (i < n && info.get_id() > key[i]->get_id())
    {
        i++;
    }
    if(i < n)
    {
      if (key[i]->get_id() == info.get_id())
          return p;
    }
    if (folha == true)
      return nullptr;
    return filhos[i]->busca(info, filhos[i], numero_comparacoes);
}

//Split
void NoArvoreBTree::split(int i,NoArvoreBTree *r, Data_Casos *tabela)
{
    cout<<"Split"<<endl;
    NoArvoreBTree *q = new NoArvoreBTree(r->getTam(),r->getFolha());
    q->setN(tam-1);
    
    int k;
    for(int j=0;j<tam-1;j++)
    {   
        //Transfere as chaves com valores maiores para o novo No
        q->setChave(j,r->getChaves(j+tam));
        //cout<<"Chaves K: "<<q->getChaves(j)<<endl;
        //cout<<"Chaves J: "<<r->getChaves(j+tam)<<endl;
    }

    if(r->getFolha()==false)
    {
        for(int j=0;j<tam;j++){
            q->setFilhos(j,r->getFilhos(j+tam));
        }

    }
    
    r->setN(tam-1);
    

    for(int j=n;j>=i+1;j--)
    {
        filhos[j+1]=filhos[j];
        this->setFilhos(j+1,this->getFilhos(j));
    }
    
    this->setFilhos(i+1,q);
   

    for (int j=n-1; j >= i; j--)
    {
       this->setChave(j + 1, this->getChaves(j)); 
    }
       
    
    this->setChave(i, r->getChaves(tam-1)); 
    //chaves[i]=q->chaves[tam-1];
    n=n + 1;
}

//Inserir Filho
void NoArvoreBTree::insertFilho(int k, Data_Casos *tabela)
{
    int i = n-1;

    //cout<<"N: "<<n<<endl;
    //Se for folha inseria a chave na posição correta 
    if(folha==true){
        
        while (i>=0 && chaves[i]>k)
        {   
            //Ajusta as chaves dentro do No
            chaves[i+1]=chaves[i];
            i--;
        }

        
        chaves[i+1] = k;
        n=n+1;
        /*
        int aux=chaves[0];
          for (int i = 0; i < tam; i++)
            {
                for (int j = 0; j < tam; j++)
                {
                    if (chaves[i] < chaves[j])
                    {
                        aux = chaves[i];
                        chaves[i] = chaves[j];
                        chaves[j] = aux;
                    }
                }
            }
        n++;
        */
    }else{
        
        
        while (i>=0 && this->chaves[i]>k)
        {
            i--;
        }
       
        if(filhos[i+1]->getN()==2*tam-1)
        {
            split(i+1,filhos[i+1],tabela);

            if(chaves[i+1]<k)
                i++;
        }
       filhos[i+1]->insertFilho(k,tabela);
    }
   
}

//Buscar o No
NoArvoreBTree* NoArvoreBTree::busca_no_No(int k,Data_Casos tabela)
{
   int i=0;
    
    while (i<n && k>chaves[i])
    {
       i++;
    }

    if(chaves[i] == k){
        //cout<<"Chave encotrada: "<<chaves[i]<<endl;
        //cout<<"Nome: "<<tabela.buscaNome(k);
        return this;
    }
    
    if(folha == true)
        return NULL;
    
    return filhos[i]->busca_no_No(k,tabela);
}

//Imprimmir
void NoArvoreBTree::imprime()
{   
    int i;
    for(i = 0; i<this->n;i++)
    {
        if(this->folha == false)
        {
            this->filhos[i]->imprime();
        }

        cout<<"Ch: "<< this->chaves[i] <<endl;

    }

    if(this->folha == false){
        this->filhos[i]->imprime();
    }
}

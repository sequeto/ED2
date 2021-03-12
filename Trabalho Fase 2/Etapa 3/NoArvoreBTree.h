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

#ifndef NOARVOREBTREE_H_INCLUDED
#define NOARVOREBTREE_H_INCLUDED
#include <iostream> 
#include <cmath>
#include <cstdlib>
#include <stdio.h>
#include <algorithm>
#include <vector>

#include "Data_Casos.h"


using namespace std; 


class NoArvoreBTree
{
private:
    
    //Chaves
    int *chaves;
    // Filhos
    NoArvoreBTree **filhos;
    //Data Casos
    Data_Casos **key;
    // N
    int n;
    //Folha
    bool folha;
    //Tamanhos
    int tam;
    int t;

public:
   
   /// Construtor NoArvoreBTree
    NoArvoreBTree(int tamanho,bool f);

   /// Destrutor NoArvoreBTree
    ~NoArvoreBTree();

   /// Retorna n do NoArvoreBTree
    int get_n();

    /// Retorna t do NoArvoreBTree
    int get_t();

    /// Retorna se o NoArvoreBTree é folha ou não
    bool get_folha();

    /// Retorna chava[i] do NoArvoreBTree
    Data_Casos* get_chave_i(int i);

    /// Retorna filho[i] do NoArvoreBTree
    NoArvoreBTree* get_filho(int i);

    /// Auxiliar da inserção
    void aux_insere(Data_Casos *info, int* num_comparacoes, int* num_copias);

    /// Função que executa a cisão do NoArvoreBTree
    void overflow(int i, NoArvoreBTree *aux, int* num_copias);

    /// Imprime
    void imprime();

    /// Atualiza o n do NoArvoreBTree
    void set_n(int N);

    /// Atualiza o t do NoArvoreBTree
    void set_t(int T);

    /// Atualiza se o NoArvoreBTree é folha ou não
    void set_folha(bool ehFolha);

    /// Atualiza chave[i] no NoArvoreBTree
    void set_chave_i(int i, Data_Casos* novo);

    /// Atualiza filho[i] no NoArvoreBTree
    void set_filho(int i, NoArvoreBTree *novo);

    /// Acha posição em que a chave ficaria no NoArvoreBTree
    int acha_posicao(Data_Casos* info);

    /// Chega na folha pegando o filho a esquerda do NoArvoreBTree
    Data_Casos* get_anterior(int i);

    /// Chega na folha pegando o filho a direita do NoArvoreBTree
    Data_Casos* get_proximo(int i);

    /// Funçao de remoção do NoArvoreBTree
    void remove(Data_Casos* info);

    /// Remove se o NoArvoreBTree for folha
    void remove_folha(int i);

    /// Remove se o NoArvoreBTree não for folha
    void remove_nao_folha(int i);

    /// Seleciona qual procedimento executar: redistribuição ou junção
    void preenche(int i);

    /// Junção 
    void juncao(int i);

    /// Redistribui no NoArvoreBTree anterior
    void redistribuicao_anterior(int i);

    /// Redistribui no NoArvoreBTree posterior
    void redistribuicao_proximo(int i);

    //Buscar
    NoArvoreBTree* busca(Data_Casos info, NoArvoreBTree* p, int* num_comparacoes);

    //Inserir Filho
    void insertFilho(int k,Data_Casos *tabela);

    //Split
    void split(int i,NoArvoreBTree *p,Data_Casos *tabela);
    
    //Imprimmir
    void imprime();
    
    //Pegar N
    int getN(){return n;};
    
    //Pegar Tam
    int getTam(){return tam;};
    
    // Pegar Folha
    bool getFolha(){return folha;};
    
    // colocar N
    void setN(int i){n=i;};
    
    // colocar Filho
    void setFilhos(int i, NoArvoreBTree *f){filhos[i]=f;};
    
    // colocar Chave
    void setChave(int i,int ch){chaves[i]=ch;};
    
    // Pegar Filhos
    NoArvoreBTree* getFilhos(int i){return filhos[i];};
    
    // Pegar chave
    int getChaves(int i){return chaves[i];};
    
    //Compara chave do DataCasos
    int comparaChaveDataCasos(int ch,Data_Casos *tabela);

    //Buscar o No
    NoArvoreBTree* busca_no_No(int k,Data_Casos *tabela); 
    
   
    //Amigos da tabela ArvoreBTree
    friend class ArvoreBTree;

};#endif // NOARVOREBTREE_H


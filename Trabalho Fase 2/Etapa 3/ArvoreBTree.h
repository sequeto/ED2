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
#ifndef ARVOREBTREE_H_INCLUDED
#define ARVOREBTREE_H_INCLUDED
#include <iostream>
#include <cstdlib>
#include <math.h>
#include "NoArvoreBTree.h"
#include "Data_Casos.h"


using namespace std;

class ArvoreBTree
{
private:
    // raiz
    NoArvoreBTree *raiz;
    
    // Tamanho do No
    int tamanhodoDoNo;

public:
    /// Construção
    ArvoreBTree(int tamanho); //OK
   
    /// Destrutor da ArvoreB
    ~ArvoreBTree(); //OK

    /// Retorna t da ArvoreBTree
    int get_t();//OK

    /// Atualizar t da ArvoreBTree
    void set_t(int T);//OK

   /// Retorna raiz  
    NoArvoreBTree* get_raiz(); //OK

    /// Atualiza raiz 
    void set_raiz(NoArvoreBTree* raiz);//OK

   /// Imprime as chaves contidas na raiz da arvore
    void imprimir_raiz();//OK
   
    /// Remove NoArvoreBTree da ArvoreB
    void remove(NoArvoreBTree* p);//OK

    /// Insere chave 
    void insercao(Data_Casos *tabela); //OK

    /// Remove chave
    NoArvoreBTree* remocao(Data_Casos *tabela);//OK

    /// Busca 
    NoArvoreBTree* busca(Data_Casos *tabela, NoArvoreBTree *p);//OK

    /// Chama a cisão dentro do no
    void cisao(Data_Casos *tabela, NoArvoreBTree* d); //OK 
        
     /// Insere chave2 
    void insereArvoreB(int chave, Data_Casos *tabela); //OK

    /// Imprime a arvore
    void imprimeArvoreB(); //OK

     /// Buscar na arvore
    NoArvoreBTree* busca(int chave,Data_Casos *tabela); //OK

    ///Comparações //OK
    int num_comparacoes = 0;
    int num_comparacoes_busca = 0;
    int num_copias = 0;
   
    //NoArvoreBTree* buscaArvB(int chave, NoArvB *p);
};

#endif // ARVOREBTREE_H

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
/**
    Universidade Federal de Juiz de Fora
    Contador.h
    Propósito: Registra contagem da arvore b.
    @author Ivanylson HG
  
*/

#ifndef CONTADOR_H
#define CONTADOR_H

#include <iostream>
#include <string>

using namespace std;

class Contador {

public:
    static Contador& getInstance()
    {
        static Contador instance; // Guaranteed to be destroyed.
                                // Instantiated on first use.
        return instance;
    }

private:
    Contador() {} // Constructor? (the {} brackets) are needed here.
    ~Contador(){
        // Destructor
        resetContadores();
    }

    // C++ 03
    // ========
    // Don't forget to declare these two. You want to make sure they
    // are unacceptable otherwise you may accidentally get copies of
    // your singleton appearing.
    Contador(Contador const&);       // Don't Implement
    void operator=(Contador const&); // Don't implement

    int numComparacoes;
    int numCopias;

public:

    /**
     * Obtem o numero de comparacoes
     * @return int
     */
    int getNumComparacoes(){
        return numComparacoes;
    }

    /**
     * Obtem o numero de copias
     * @return int
     */
    int getNumCopias(){
        return numCopias;
    }

    /**
     * Reseta os contadores de estatisticas
     */
    void resetContadores(){
        numComparacoes = 0;
        numCopias = 0;
    }

    /**
     * Registra a comparacao, esse metodo deve ser chamado no codigo onde
     * tiver uma comparação entre elementos da arvore
     */
    void registraComparacao(){
        numComparacoes++;
    }

    /**
     * Registra a copia, esse metodo deve ser chamado no codigo onde
     * tiver uma copia entre elementos da arvore
     */
    void registraCopia(){
        numCopias++;
    }

    
};


#endif //CONTADOR_H

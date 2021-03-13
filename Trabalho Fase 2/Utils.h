#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

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

using namespace std;

class Utils
{
    public:
        Utils();
        virtual ~Utils();
        void lerArquivoCoordenadas(City* cidades, ifstream& file);
        void inserirNaQuadTree(QuadTree* tree, City* cidades, int tam);
        void lerArquivoProcessado(vector<Data_Casos>* casos, ifstream& file);
        
};

#endif //UTILS_H_INCLUDED

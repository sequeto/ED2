#ifndef TESTES_H_INCLUDED
#define TESTES_H_INCLUDED

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

class Testes
{
    public:
        Testes();
        ~Testes();
        void testeQuadtree(int n);
        void testeHash(int n);
        void testeAVL(int n);
        void testeB(int n);
};

#endif //TESTES_H_INCLUDED
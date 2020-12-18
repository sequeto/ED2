#ifndef DATA_CASOS_H_INCLUDED
#define DATA_CASOS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Data_Casos
{
    public:
        Data_Casos();
        virtual ~Data_Casos();

        string getData();
        void setData(string data);

        int getCasos();
        void setCasos(int casos);
        
        int getMortes();
        void setMortes(int mortes);


    private:
        string data;
        int casos;
        int mortes;
};

#endif
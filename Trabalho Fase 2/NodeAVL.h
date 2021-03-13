#ifndef NODEAVL_H_INCLUDED
#define NODEAVL_H_INCLUDED

#include <iostream>



class NodeAVL{
    public:
        NodeAVL();
        virtual ~NodeAVL();
        int getInfo();
        void setInfo(int info);

        int getFatorBalanceamento();
        void setFatorBalanceamento(int fator);

        NodeAVL* getEsq();
        void setEsq(NodeAVL* p);

        NodeAVL* getDir();
        void setDir(NodeAVL* p);


    private:
        int info;
        int fatorBalanceamento;
        NodeAVL* esq;
        NodeAVL* dir;
};

#endif
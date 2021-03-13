#include <iostream>

class Node{
    public:
        Node();
        virtual ~Node();
        int getInfo();
        void setInfo(int info);

        int getFatorBalanceamento();
        void setFatorBalanceamento(int fator);

        Node* getEsq();
        void setEsq(Node* p);

        Node* getDir();
        void setDir(Node* p);


    private:
        int info;
        int fatorBalanceamento;
        Node* esq;
        Node* dir;
};
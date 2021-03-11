#include <iostream>

class Node{
    public:
        Node(int info);
        virtual ~Node();
        int getInfo();
        void setInfo(int info);

        int getFatorBalanceamento();
        void setFatorBalanceamento(int fator);

        Node* getEsq();
        void setEsq(Node* p);

        Node* getDir();
        void setDir(Node* p);

        Node* getPai();
        void setPai(Node* p);

    private:
        int info;
        int fatorBalanceamento;
        Node* pai;
        Node* esq;
        Node* dir;
};
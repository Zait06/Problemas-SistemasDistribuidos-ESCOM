#ifndef NUMERO_H_
#define NUMERO_H_

class Numero{
    private:
        bool primo;
        int num;
    public:
        Numero(bool f,int m);
        void getNumero();
        bool getPrimo();
        int getSoloNumero();
        void setPrimo(bool f);
};

#endif
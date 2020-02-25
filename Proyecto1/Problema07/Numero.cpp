#include "Numero.h"
#include <iostream>
using namespace std;

Numero::Numero(bool f,int m){
    primo=f;
    num=m;
}

void Numero::getNumero(){
    cout<<"Primo: "<<primo<<"\t Numero: "<<num<<endl;
}

bool Numero::getPrimo(){
    return primo;
}

int Numero::getSoloNumero(){
    return num;
}

void Numero::setPrimo(bool f){
    primo=f;
}
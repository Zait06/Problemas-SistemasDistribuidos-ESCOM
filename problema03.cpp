#include <iostream>
using namespace std;

int main(){
    int numero,hh,mm,ss,aux;
    cout<<"Ingrese un tiempo equivalente en segundos: ";
    cin>>numero;

    hh=numero/3600;
    aux=numero%3600;
    mm=aux/60;
    ss=aux%60;

    cout<<"El tiempo es de: "<<hh<<" horas "<<mm<<" minutos y "<<ss<<" segundos."<<endl;

    return 0;
}
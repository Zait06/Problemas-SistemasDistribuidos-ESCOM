#include <iostream>
using namespace std;

double sacarRaiz(double x);

int main(){
    double numero;
    cout<<"Ingrese el numero al que desee sacar su raiz cuadrada: ";
    cin>>numero;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    cout<<"La raiz cuadrada de "<<(int)numero<<" es: "<<sacarRaiz(numero)<<endl;

    return 0;
}

double sacarRaiz(double x){
    double r=x,t=0;
    while (t!=r){
        t=r;
        r=((x/r)+r)*0.5;
    }
    return r;
}
#include <iostream>
#include <vector>
#include <cmath>
#include "Numero.h"
using namespace std;

int main(int argc, char *argv[]){
    if(argc != 2){
        cout << "Forma de uso: " << argv[0] <<" valor_de_n\n";
        exit(0);
	}
    int n=strtol(argv[1],NULL,10);
    int j,h,raiz;
    vector<Numero> numeros;             // Vector de objetos Numero
    vector<Numero>::iterator i;         // Iterador del vector

    numeros.reserve(n);                 // Reservo espacio
    for(j=0; j<=n; j++)                 // Se crean un vector de numeros
        numeros[j]=Numero(true,j);

    for(j=2;j*j<=n;j++) {
        if(numeros[j].getPrimo()){
            for(h=2;j*h<=n;h++)
                numeros[j*h].setPrimo(false);
        }
    }

    for(i=numeros.begin();i<=numeros.begin()+n;i++){
        Numero aux=*i;
        aux.getNumero();
    }

    return 0;
}
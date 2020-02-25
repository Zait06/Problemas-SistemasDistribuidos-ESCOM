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
    int j,k,raiz;
    vector<Numero> numeros;             // Vector de objetos Numero
    vector<Numero>::iterator i;         // Iterador del vector

    numeros.reserve(n);                 // Reservo espacio
    for(j=0; j<=n; j++)                 // Se crean un vector de numeros
        numeros[j]=Numero(true,j);

    raiz=(int)(sqrt(n));

    for(i=numeros.begin()+2;i<=(numeros.begin()+raiz)+1;i++){
        Numero aux=*i;
        if(!aux.getPrimo()==false){
            for(k=aux.getSoloNumero()+2;k<=(n/aux.getSoloNumero())+1;k++){
                numeros[k].setPrimo(false);
            }
        }
    }

    for(i=numeros.begin();i<numeros.begin()+n+1;i++){
        Numero aux=*i;
        aux.getNumero();
    }

    return 0;
}
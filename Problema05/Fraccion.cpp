#include "Fraccion.h"
#include <iostream>
using namespace std;

Fraccion::Fraccion(int nm, int dm){
    numerador=nm;
    denominador=dm;
}

void Fraccion::inicializaFraccion(int nm, int dm){
    numerador=nm;
    denominador=dm;
}

void Fraccion::muestraFraccion(){
    cout<<"Fraccion: "<<numerador<<"/"<<denominador<<endl;
}

double Fraccion::division(){
    return ((double)numerador)/((double)denominador);
}

void Fraccion::fraccionMinima(){
    int div;
    int nm=numerador;   // Copia del numerador
    int dm=denominador; // Copia del denominador
    if(nm>dm){
        div=dm;
    }else{
        div=nm;
    }
    for(div;div>0;div--){
        if(nm%div==0 and dm%div==0){
            nm=nm/div;
            dm=dm/div;
            break;
        }
    }
    cout<<"Fraccion minima: "<<nm<<"/"<<dm<<endl;
}
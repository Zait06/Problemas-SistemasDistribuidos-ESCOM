#include "PoligonoIrreg.h"
#include "Coordenada.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int PoligonoIrreg::getNumVertices(){
    return numVertices;
}

PoligonoIrreg::PoligonoIrreg(int reserva){
    coordenadas.reserve(reserva);
    numVertices=reserva;
}

void PoligonoIrreg::anadeVertice(double xx, double yy){
    coordenadas.push_back(Coordenada(xx,yy));
}

void PoligonoIrreg::imprimeVertices(){
    int i;
    for(i=0;i<numVertices;i++){
        cout<<"Vertice ("<<coordenadas[i].obtenerX()<<","<<coordenadas[i].obtenerY()<<") "<<flush;
        cout<<"Angulo: "<<coordenadas[i].obtenerTheta()*180/M_PI<<" °"<<endl;
    }
}

int PoligonoIrreg::obtenerXdeCoordenada(int i){
    return coordenadas[i].obtenerX();
}

int PoligonoIrreg::obtenerYdeCoordenada(int i){
    return coordenadas[i].obtenerY();
}

bool funcionOrden(Coordenada i,Coordenada j) {
    double a=i.obtenerTheta();
    double b=j.obtenerTheta();
    if(i.obtenerX()<0 and i.obtenerY()<0){
        a+=180;
    }else if(i.obtenerX()>0 and i.obtenerY()<0){
        a+=360;
    }else if(i.obtenerX()<0 and i.obtenerY()>0){
        a+=180;
    }

    if(j.obtenerX()<0 and j.obtenerY()<0){
        b+=180;
    }else if(j.obtenerX()>0 and j.obtenerY()<0){
        b+=360;
    }else if(j.obtenerX()<0 and j.obtenerY()>0){
        b+=180;
    }


    return (a<b);
}

void PoligonoIrreg::ordenaAngulo(){
    sort(coordenadas.begin(),coordenadas.begin()+numVertices,funcionOrden);
}
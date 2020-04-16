#include "Asteroide.h"
#include "Coordenada.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double tam[]={10,20,25,30,50,60};           // Tamaño del asteroide

int Asteroide::getNumVertices(){
    return numVertices;
}

Asteroide::Asteroide(int reserva, int azar){
    coordenadas.reserve(reserva);
    numVertices=reserva;
    tamanio=tam[azar];
}

void Asteroide::iniciarAsteroide(int rr){
    
    veloX=30/tamanio;            // Calculo de la velocidad (Inverso a su tamaño)
    if(rand()%2)                        // Decisión para saber si la velocidad será creciente o 
        veloX=(-1)*veloX;         // decreciente

    posiX=rand()%800;                // Ubicación del asteroide en un rango de 0 a 600
    posiY=rand()%800;                // Ubicación del asteroide en un rango de 0 a 600
    if(veloX<0){                      // Si la velocidad es negativa, entonces empezará en un 
        posiX=800-posiX;          // sitio positivo el asteroide
        posiY=800-posiY;          // sitio positivo el asteroide
    }

    switch(rr){                   // Tres casos para desplazar el asteroide
        case 1:
            veloY=veloX;
            veloX=0;
        break;
        case 2:
            veloY=0;
        break;
        case 3:
            veloY=(-1)*veloX;
        break;
        default:
            veloY=veloX;
        break;
    }

    int k=0;
    double cx=0.0, cy=0.0;
    while(k<numVertices){
        cx=(rand()%2-1)+((rand()%200-99)*.01);
        cy=(rand()%2-1)+((rand()%200-99)*.01);
        double r=pow(cx,2)+pow(cy,2);
        if(r<=1.0 && r>=0.85){
            anadeVertice(cx*tamanio,cy*tamanio);
            k++;
        }
    }
}

void Asteroide::anadeVertice(double xx, double yy){
    coordenadas.push_back(Coordenada(xx,yy));
}

void Asteroide::imprimeVertices(){
    int i;
    for(i=0;i<numVertices;i++){
        cout<<"Vertice ("<<coordenadas[i].obtenerX()<<","<<coordenadas[i].obtenerY()<<") "<<flush;
        cout<<"Angulo: "<<coordenadas[i].obtenerTheta()*180/M_PI<<" °"<<endl;
    }
}

int Asteroide::obtenerXdeCoordenada(int i){
    return coordenadas[i].obtenerX();
}

int Asteroide::obtenerYdeCoordenada(int i){
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

void Asteroide::ordenaAngulo(){
    sort(coordenadas.begin(),coordenadas.begin()+numVertices,funcionOrden);
}

double Asteroide::obtenerTam(){
    return tamanio;
}

double Asteroide::obtenerVeloX(){
    return veloX;
}
double Asteroide::obtenerVeloY(){
    return veloY;
}
double Asteroide::obtenerPosiX(){
    return posiX;
}
double Asteroide::obtenerPosiY(){
    return posiY;
}
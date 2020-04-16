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
    coordenadas.reserve(reserva);   // Se reserva y se guarda el numero
    numVertices=reserva;            // de vertices en el asteroide
    tamanio=tam[azar];              // Se elije un tamaño del asteroide
}

void Asteroide::iniciarAsteroide(int sino, int rr){
    
    veloX=30/tamanio;           // Calculo de la velocidad (Inverso a su tamaño)
    if(sino)                    // Decisión para saber si la velocidad será creciente o 
        veloX=(-1)*veloX;       // decreciente

    posiX=rand()%800;           // Ubicación del asteroide en un rango de 0 a 600
    posiY=rand()%800;           // Ubicación del asteroide en un rango de 0 a 600
    if(veloX<0){                // Si la velocidad es negativa, entonces empezará en un 
        posiX=800-posiX;        // sitio positivo el asteroide
        posiY=800-posiY;        // sitio positivo el asteroide
    }

    switch(rr){                 // Tres casos para desplazar el asteroide
        case 1:                 // Solamente desplazamiento en Y
            veloY=veloX;        
            veloX=0;
        break;
        case 2:
            veloY=0;            // Solamente desplazamiento en X
        break;
        case 3:
            veloY=(-1)*veloX;   // La velocidad es igual pero de forma decreciente
        break;
        default:
            veloY=veloX;        // Velocidades iguales
        break;
    }

    int k=0;
    double cx=0.0, cy=0.0;
    /*
        En esta parte se generan una coordenada (x,y) que tenga un valor
        de -1 a 1, esto para ver si uno de estos valores se encuentra de un
        circulo unitario, pero que caigan especificamente en los valores 
        0.85 a 1.00, más menos, para poder tener una figura un poco similar
        a un circulo (Inspiracion del metodo de monte carlo para saber
        si un punto está dento o no de un circulo unitario).
    */
    while(k<numVertices){
        cx=(rand()%2-1)+((rand()%200-99)*.01);
        cy=(rand()%2-1)+((rand()%200-99)*.01);
        double r=pow(cx,2)+pow(cy,2);
        if(r<=1.0 && r>=0.85){
            anadeVertice(cx*tamanio,cy*tamanio);
            k++;
        }
    }

    ordenaAngulo(); // Se ordenan los vertices por su angulo de inclinacion
}

void Asteroide::anadeVertice(double xx, double yy){
    coordenadas.push_back(Coordenada(xx,yy));
}

void Asteroide::imprimeVertices(){  
    int i;
    for(i=0;i<numVertices;i++){
        cout<<"Vertice ("<<coordenadas[i].obtenerX()<<","<<coordenadas[i].obtenerY()<<") "<<flush;  // Imprime las coordenadas del vertice i
        cout<<"Angulo: "<<coordenadas[i].obtenerTheta()*180/M_PI<<" °"<<endl;                       // junto con su angulo de inclinacion
    }
}

int Asteroide::obtenerXdeCoordenada(int i){
    return coordenadas[i].obtenerX();
}

int Asteroide::obtenerYdeCoordenada(int i){
    return coordenadas[i].obtenerY();
}

bool funcionOrden(Coordenada i,Coordenada j) {      // Algorimo de ordeanmiento para los angulos, dependiendo en que parte
    double a=i.obtenerTheta();                      // del planio cartesiano esta
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
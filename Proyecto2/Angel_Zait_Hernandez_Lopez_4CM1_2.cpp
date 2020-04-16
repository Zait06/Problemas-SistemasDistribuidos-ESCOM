#include "gfx.h"
#include <unistd.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Coordenada{
	private:
		double x;		// Punto X
		double y;		// Punto Y
		double r;		// Distancia de la coordenada al origen
		double theta;	// Angulo de inclinacion
	public:
		Coordenada(double = 0, double = 0);
		double obtenerX();		// Devuelven el punto X
		double obtenerY();		// Devuelven el punto Y
		double obtenerTheta();	// DEvuelven el angulo de inclinacion
};

Coordenada::Coordenada(double xx, double yy){ 
	x=xx; y=yy;
	r=sqrt(pow(xx,2)+pow(yy,2));		// Distancia del origen al punto
	theta=atan(yy/xx);					// Angulo del punto
}

double Coordenada::obtenerX(){
	return x;
}

double Coordenada::obtenerY(){
	return y;
}

double Coordenada::obtenerTheta(){
	return theta;
}

class Asteroide{
        private:
                vector<Coordenada> coordenadas; // Vector de coordenadas que representan los vertices
                int numVertices;                // Numero de vertices del asteroide
                double tamanio;                 // Tamanio del asteroide
                double veloX, veloY;            // Velocidades del asteroide
                double posiX, posiY;            // Posición del asteroide inicial
	public:
                int getNumVertices();                           // Devuelve el numero de vertices
                Asteroide(int reserva, int azar);               // Constructor de la clase
                void iniciarAsteroide(int sino, int rr);        // Inicialización de las variables
                void anadeVertice(double xx, double yy);        // Agregar vertices
                void imprimeVertices();                         // Imprimir los vertices
                int obtenerXdeCoordenada(int i);                // Devuelve punto X de la coordenada del vertice i
                int obtenerYdeCoordenada(int i);                // Devuelve punto Y de la coordenada del vertice i
                void ordenaAngulo();                            // Ordena todas las coordenadas por su angulo
                double obtenerTam();                            // Devuelve el tamanio del asteroide
                double obtenerVeloX();                          // Devuelve la velocidad X del asteroide
                double obtenerVeloY();                          // Devuelve la velocidad Y del asteroide
                double obtenerPosiX();                          // Devuelve la posicion X del asteroide
                double obtenerPosiY();                          // Devuelve la posicion Y del asteroide
};

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

int main(int argc, char* argv[]){
    if(argc != 2) {
		cout<<"Forma de uso: "<<argv[0]<<" n_asteroides"<<endl;
		exit(0);
	}

    srand(time(NULL)); 
    int numAste=atoi(argv[1]);              // Numero de asteroides
    int t,i,j,vert=35;                      // Variables auxiliares
    double cx=0.0,cy=0.0;                   // Variable auxiliar par dibuar las lineas
    vector<Asteroide> asteroides;           // Almacenamiento de los asteroides
    asteroides.reserve(numAste);            // Reserva de asteroides
    
    i=0;
    while(i<numAste){                               // Creación de los asteroides
        Asteroide ast(vert,rand()%5);               // Creación de un objeto Asteroide con 25 vertices
        ast.iniciarAsteroide(rand()%2,rand()%4);    // Iniciar el resto de los valores
        asteroides[i]=ast;                          // Se agrega al vector los asteroides
        i++;
    }

    gfx_open(800, 600, "Astoriodes HLAZ");
    gfx_color(0,200,100);
    int ox=0,oy=0;
    
    for(t = 0; t < 200; t++){
        gfx_clear();

        /*
            En esta parte, se recorren todos los asteroides, para poder 
            verlos en pantalla, cada uno tiene una velocidad en X, Y y una
            posición inicial, para que cuanto t, se esté desplazando, este se 
            mueva con todas las lineas. Esto porque se trató de hacer una figua
            cerrada para poder simular un asteroide.
        */
        for(j=0;j<numAste;j++){
            cx=asteroides[j].obtenerXdeCoordenada(0);
            cy=asteroides[j].obtenerYdeCoordenada(0);
            for(i=1;i<vert;i++){
                ox=asteroides[j].obtenerXdeCoordenada(i);
                oy=asteroides[j].obtenerYdeCoordenada(i);
                gfx_line(cx+t*asteroides[j].obtenerVeloX()+asteroides[j].obtenerPosiX(),
                         cy+t*asteroides[j].obtenerVeloY()+asteroides[j].obtenerPosiY(),
                         ox+t*asteroides[j].obtenerVeloX()+asteroides[j].obtenerPosiX(),
                         oy+t*asteroides[j].obtenerVeloY()+asteroides[j].obtenerPosiY());
                cx=ox; cy=oy;
            }
            gfx_line(cx+t*asteroides[j].obtenerVeloX()+asteroides[j].obtenerPosiX(),
                     cy+t*asteroides[j].obtenerVeloY()+asteroides[j].obtenerPosiY(),
                     asteroides[j].obtenerXdeCoordenada(0)+t*asteroides[j].obtenerVeloX()+asteroides[j].obtenerPosiX(),
                     asteroides[j].obtenerYdeCoordenada(0)+t*asteroides[j].obtenerVeloY()+asteroides[j].obtenerPosiY());
        }
        
        gfx_flush();
        usleep(52000);
    }
    return 0;
}
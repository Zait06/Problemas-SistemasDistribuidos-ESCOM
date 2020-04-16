#include "gfx.h"
#include "Asteroide.h"
#include <unistd.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
    if(argc != 2) {
		cout<<"Forma de uso: "<<argv[0]<<" n_asteroides"<<endl;
		exit(0);
	}

    srand(time(NULL)); 
    int numAste=atoi(argv[1]);              // Numero de asteroides
    int t,i,j,vert=30;              // Variables auxiliares
    double cx=0.0,cy=0.0;                   // Variable auxiliar par dibuar las lineas
    vector<Asteroide> asteroides;       // Almacenamiento de los asteroides
    asteroides.reserve(numAste);            // Reserva de asteroides
    
    i=0;
    while(i<numAste){                       // Creación de los asteroides
        Asteroide ast(vert,rand()%5);            // Creación de un objeto PoligonoIrregular
        ast.iniciarAsteroide(rand()%4);
        ast.ordenaAngulo();
        asteroides[i]=ast;
        i++;
    }

    gfx_open(800, 600, "Astoriodes HLAZ");
    gfx_color(0,200,100);
    int ox=0,oy=0;
    
    for(t = 0; t < 200; t++){
        gfx_clear();

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
        
        // gfx_line(100,500-t*5,300,600-t*5);
        // gfx_line(100-t*2,500,300-t*2,600);
        // gfx_line( t+posix[0][0], t+posix[0][1], t+posix[0][2], t+posix[0][3] );
        // gfx_line(t*5+80, t*3+40, t*3+40, t*5+80);
        gfx_flush();
        //usleep(52083); //24 por segundo
        usleep(42000);
    }
    return 0;
}
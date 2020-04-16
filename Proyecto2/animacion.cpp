#include "gfx.h"
#include "PoligonoIrreg.h"
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
    int t,i,j,k,AzarA,vert=30;              // Variables auxiliares
    double tam[]={10,20,25,30,50,60};           // Tamaño del asteroide
    double cx=0.0,cy=0.0;                   // Variable auxiliar par dibuar las lineas
    vector<PoligonoIrreg> asteroides;       // Almacenamiento de los asteroides
    asteroides.reserve(numAste);            // Reserva de asteroides
    double posiX[numAste],posiY[numAste];                     // Posición inicial del asteroide
    double veloX[numAste],veloY[numAste];    // Velocidades en el eje X y Y
    
    i=0;
    while(i<numAste){                       // Creación de los asteroides
        PoligonoIrreg ast(vert);            // Creación de un objeto PoligonoIrregular
        AzarA=rand()%5;                     // Numero al azar entre 0 y 4
        veloX[i]=30/tam[AzarA];            // Calculo de la velocidad (Inverso a su tamaño)
        if(rand()%2)                        // Decisión para saber si la velocidad será creciente o 
            veloX[i]=(-1)*veloX[i];         // decreciente

        posiX[i]=rand()%800;                // Ubicación del asteroide en un rango de 0 a 600
        posiY[i]=rand()%800;                // Ubicación del asteroide en un rango de 0 a 600
        if(veloX[i]<0){                      // Si la velocidad es negativa, entonces empezará en un 
            posiX[i]=800-posiX[i];          // sitio positivo el asteroide
            posiY[i]=800-posiY[i];          // sitio positivo el asteroide
        }

        switch(rand()%4){                   // Tres casos para desplazar el asteroide
            case 1:
                veloY[i]=veloX[i];
                veloX[i]=0;
            break;
            case 2:
                veloY[i]=0;
            break;
            case 3:
                veloY[i]=(-1)*veloX[i];
            break;
            default:
                veloY[i]=veloX[i];
            break;
        }

        k=0;
        while(k<vert){
            cx=(rand()%2-1)+((rand()%200-99)*.01);
            cy=(rand()%2-1)+((rand()%200-99)*.01);
            double r=pow(cx,2)+pow(cy,2);
            if(r<=1.0 && r>=0.85){
                ast.anadeVertice(cx*tam[AzarA],cy*tam[AzarA]);
                k++;
            }
        }

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
                gfx_line(cx+t*veloX[j]+posiX[j],
                         cy+t*veloY[j]+posiY[j],
                         ox+t*veloX[j]+posiX[j],
                         oy+t*veloY[j]+posiY[j]);
                cx=ox; cy=oy;
            }
            gfx_line(cx+t*veloX[j]+posiX[j],
                     cy+t*veloY[j]+posiY[j],
                     asteroides[j].obtenerXdeCoordenada(0)+t*veloX[j]+posiX[j],
                     asteroides[j].obtenerYdeCoordenada(0)+t*veloY[j]+posiY[j]);
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
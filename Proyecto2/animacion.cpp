#include "gfx.h"
#include "PoligonoIrreg.h"
#include <unistd.h>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;
int main()
{
    srand(time(NULL));
    int t,vert=30;
    double cx=0.0,cy=0.0;
    PoligonoIrreg ast(vert);

    t=0;
    while(t<vert){
        cx=(rand()%2-1)+((rand()%200-99)*.01);
        cy=(rand()%2-1)+((rand()%200-99)*.01);
        double r=pow(cx,2)+pow(cy,2);
        if(r<=1.0 && r>=0.8){
            ast.anadeVertice(cx*100,cy*100);
            t++;
        }
    }
    
    ast.ordenaAngulo();
    //ast.imprimeVertices();

    gfx_open(800, 600, "Ejemplo Micro Animacion GFX");
    gfx_color(0,200,100);
    int ox=0,oy=0;
    int aux=rand()%5;
    if(rand()%1)
        aux+=rand()%600;
    for(t = 0; t < 200; t++){
        gfx_clear();

        cx=ast.obtenerXdeCoordenada(0);
        cy=ast.obtenerYdeCoordenada(0);
        for(int i=1;i<vert;i++){
            ox=ast.obtenerXdeCoordenada(i);
            oy=ast.obtenerYdeCoordenada(i);
            gfx_line(cx+t+100,cy+t+100,ox+t+100,oy+t+100);
            cx=ox; cy=oy;
        }
        gfx_line(cx+t+100,cy+t+100,ast.obtenerXdeCoordenada(0)+t+100,ast.obtenerYdeCoordenada(0)+t+100);

        
        // gfx_line(80+t,100+t,200,100);
        // gfx_line( t*1+80, t*2+40, t*2+40, t*3+80 );
        // gfx_line(t*5+80, t*3+40, t*3+40, t*5+80);
        gfx_flush();
        usleep(52083); //24 por segundo
    }
    return 0;
}
#include "Coordenada.h"
#ifndef RECTANGULO_H_
#define RECTANGULO_H_

class Rectangulo
{
    private:
        Coordenada superiorIzq;
        Coordenada inferiorDer;
    public:
        Rectangulo();
        Rectangulo(double xSupIzq, double ySupIzq, double zSupIzq, double xInfDer, double yInfDer, double zInfDer);
        void imprimeEsq();
        Coordenada obtieneSupIzq();
        Coordenada obtieneInfDer();
        double obtieneArea();
 };

 #endif
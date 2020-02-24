#include "Coordenada.h"
#include "Rectangulo.h"
#include <iostream>
using namespace std;

Rectangulo::Rectangulo() : superiorIzq(0,0,0), inferiorDer(0,0,0)
{ }

Rectangulo::Rectangulo(double xSupIzq, double ySupIzq, double zSupIzq,
                    double xInfDer, double yInfDer, double zInfDer):superiorIzq(xSupIzq,ySupIzq,zSupIzq), 
                                                                    inferiorDer(xInfDer,yInfDer,zInfDer)
{ }

Coordenada Rectangulo::obtieneSupIzq(){
    return superiorIzq;
}

Coordenada Rectangulo::obtieneInfDer(){
    return inferiorDer;
}
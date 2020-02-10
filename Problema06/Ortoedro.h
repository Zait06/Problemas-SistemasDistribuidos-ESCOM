#include "Rectangulo.h"
#ifndef ORTOEDRO_H_
#define ORTOEDRO_H_

class Ortoedro
{
    private:
        Rectangulo rectangulo00;
        Rectangulo rectangulo01;
        Rectangulo rectangulo02;
        Rectangulo rectangulo03;
        Rectangulo rectangulo04;
        Rectangulo rectangulo05;
    public:
        Ortoedro();
        void obtieneVertices();
        double obtieneArea();
        double obtieneVolumen();
 };

 #endif
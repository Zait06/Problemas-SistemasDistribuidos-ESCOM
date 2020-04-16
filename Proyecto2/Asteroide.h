#include "Coordenada.h"
#include <vector>
using namespace std;
#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_

class Asteroide{
        private:
                vector<Coordenada> coordenadas;
                int numVertices;
                double tamanio;
                double veloX, veloY;
                double posiX, posiY;
	public:
                int getNumVertices();
                Asteroide(int reserva, int azar);
                void iniciarAsteroide(int rr);
                void anadeVertice(double xx, double yy);
                void imprimeVertices();
                int obtenerXdeCoordenada(int i);
                int obtenerYdeCoordenada(int i);
                void ordenaAngulo();
                double obtenerTam();
                double obtenerVeloX();
                double obtenerVeloY();
                double obtenerPosiX();
                double obtenerPosiY();
};

#endif
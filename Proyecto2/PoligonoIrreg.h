#include "Coordenada.h"
#include <vector>
using namespace std;
#ifndef POLIGONOIRREG_H_
#define POLIGONOIRREG_H_

class PoligonoIrreg{
        private:
                vector<Coordenada> coordenadas;
                int numVertices;
	public:
                int getNumVertices();
                PoligonoIrreg(int reserva);
                void anadeVertice(double xx, double yy);
                void imprimeVertices();
                int obtenerXdeCoordenada(int i);
                int obtenerYdeCoordenada(int i);
                void ordenaAngulo();
};

#endif
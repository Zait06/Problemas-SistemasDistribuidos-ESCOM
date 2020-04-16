#include "Coordenada.h"
#include <vector>
using namespace std;
#ifndef ASTEROIDE_H_
#define ASTEROIDE_H_

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

#endif
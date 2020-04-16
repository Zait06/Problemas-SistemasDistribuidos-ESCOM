#include "Coordenada.h"
#include <cmath>
#include <iostream>
using namespace std;

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
#include "Coordenada.h"
#include <cmath>
#include <iostream>
using namespace std;

Coordenada::Coordenada(double xx, double yy){ 
	x=xx; y=yy;
	r=sqrt(pow(xx,2)+pow(yy,2));
	theta=atan(yy/xx);
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
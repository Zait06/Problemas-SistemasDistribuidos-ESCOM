#ifndef COORDENADA_H_
#define COORDENADA_H_
class Coordenada
{
	private:
		double x;		// Punto X
		double y;		// Punto Y
		double r;		// Distancia de la coordenada al origen
		double theta;	// Angulo de inclinacion
	public:
		Coordenada(double = 0, double = 0);
		double obtenerX();		// Devuelven el punto X
		double obtenerY();		// Devuelven el punto Y
		double obtenerTheta();	// DEvuelven el angulo de inclinacion
};

#endif
#ifndef COORDENADA_H_
#define COORDENADA_H_
class Coordenada
{
	private:
		double x;
		double y;
		double r;
		double theta;	
	public:
		Coordenada(double = 0, double = 0);
		double obtenerX();
		double obtenerY();
		double obtenerTheta();
};

#endif
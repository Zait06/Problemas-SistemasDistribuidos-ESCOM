animacion: gfx.o PoligonoIrreg.o Coordenada.o animacion.o
	g++ gfx.o PoligonoIrreg.o Coordenada.o animacion.o -o animacion -lX11
animacion.o: animacion.cpp gfx.h
	g++ animacion.cpp -c
PoligonoIrreg.o: PoligonoIrreg.cpp Coordenada.o PoligonoIrreg.h
	g++ PoligonoIrreg.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c
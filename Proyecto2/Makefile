animacion: gfx.o Asteroide.o Coordenada.o animacion.o
	g++ gfx.o Asteroide.o Coordenada.o animacion.o -o animacion -lX11
animacion.o: animacion.cpp gfx.h
	g++ animacion.cpp -c
Asteroide.o: Asteroide.cpp Coordenada.o Asteroide.h
	g++ Asteroide.cpp -c
Coordenada.o: Coordenada.cpp Coordenada.h
	g++ Coordenada.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c
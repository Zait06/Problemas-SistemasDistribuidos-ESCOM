animacion: gfx.o animacion.o
	g++ gfx.o animacion.o -o animacion -lX11
animacion.o: animacion.cpp gfx.h
	g++ animacion.cpp -c
gfx.o: gfx.c gfx.h
	gcc gfx.c -c
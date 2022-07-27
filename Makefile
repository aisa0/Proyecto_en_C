all:
	gcc -o exe proyectoFinalVersion.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

run:
	./exe
clean:
	rm exe

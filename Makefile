all:
#	gcc -o tiCtactoe proyecto.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
#	gcc `pkg-config --cflags --libs gtk+-3.0` proyecto.c -o exe `pkg-config --libs gtk+-3.0` -export-rdynamic
	gcc -o exe proyecto.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

run:
	./exe
clean:
	rm exe

all:
	gcc -o tiCtactoe proyecto.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic
run:
	./tiCtactoe
clean:
	rm tiCtactoe

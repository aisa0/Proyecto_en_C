# Proyecto_en_C
/* Proyecto en C para el curso IE-0117 Programación Bajo Plataformas Abiertas
Elaborado por:
Ariel Mora
Isabel Sabater
Jose Acevedo
Este proyecto consiste en la creación de un juego de Gato (3 en línea o Tic Tac Toe)
El juego cuenta con una interfaz gráfica desarrollada en GTK, su modo de juego consiste
en inicializarlo mediante el botón de Iniciar juego, y crea un tablero para dos
jugadores, uno asociado a la letra X y el otro asociado a la letra O.
El objetivo es conseguir que tres de las letras coincidan en una fila vertical,
horizontal o diagonal, gana el primero que lo consiga.
Código basado en el programa realizado por Gokul Vasudeva
https://www.github.com/gokulvsd/tictactoe
*/

Archivo Makefile incluye:
all:
	gcc -o exe proyectoFinalVersion.c -Wall `pkg-config --cflags --libs gtk+-3.0` -export-dynamic

run:
	./exe
clean:
	rm exe

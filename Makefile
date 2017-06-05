all: dinamico

main.o: main.c
	gcc -Wall -c main.c -o $@

libcypher.so: cifrado.c
	gcc -shared -o libcypher.so -fPIC cifrado.c

dinamico: main.o codificacion.o libcypher.so
	gcc -L./ -I./ main.o codificacion.o -lm -lcifrado -lcodificacion -o $@
 
